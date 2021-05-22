#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
#include "structure.h"
#include "node.h"

#define SVET 1
#define KEEP 2
#define POWER 3
#define VOLT 4
#define COST 5
#define EL 6
#define REV 7
#define LENGHT 8

typedef struct light Data;
typedef struct Node
{
    Data value;
    struct Node* next;
    struct Node* prev;
}Node;


void find()
{
    setlocale(LC_ALL, "");
    struct light light1;
    int lenght = 0;
    int n = 0;
    int i = 0;
    int message = 0;
    int working = 1;
    FILE *file = fopen("C:/Users/Пользователь/Desktop/Projects/Lab_5/info.txt", "r");
    //Определение количества товаров
    while(fread(&light1, sizeof(struct light), 1, file))
    {
        lenght += 1;
    }
    fclose(file);

    //Создание циклического списка
    Node start;
    Node* list = &start;
    Node* all = (Node*)malloc(sizeof(Node));
    Node* pointer = NULL;
    FILE *files = fopen("C:/Users/Пользователь/Desktop/Projects/Lab_5/info.txt", "r");
    //Заполнение списка
    while(fread(&light1, sizeof(struct light), 1, files))
    {
        Node* tmp = (Node*)malloc(sizeof(Node));
        tmp->prev = pointer;
        tmp->next = NULL;
        tmp->value = light1;
        pointer = tmp;
        all = tmp;
    }
    Node* tail = pointer;
    Node* pointer_now;
    //Распределение указателей
    for (int i = 0; i < lenght-1; i++)
    {
        pointer_now = pointer;
        pointer->prev->next = pointer_now;
        pointer_now = pointer_now->prev;
        pointer = pointer_now;
    }
    //Основной указатель
    Node* checker = list;
    checker->prev = tail;
    checker->next = pointer_now;

    fclose(files);

    printf("По какому параметру хотите отсортировать запросы?\n");
    printf("1.По виду(Светодиоидные)\n");
    printf("2.По виду(Накапливающие)?\n");
    printf("3.По мощности?\n");
    printf("4.По вольтажу?\n");
    printf("5.По цене?\n");
    printf("6.По потребляемому току?\n");
    printf("7.Перевернуть список?\n");
    printf("8.Вычислить длину списка?\n");
    scanf("%d", &message);
    fflush(stdin);
    int count = 0;
    int list_lenght = 0;
    Node* iter = checker->next;
    int* mas = (int*)calloc(lenght, sizeof(int));
    switch(message)
    {
    case SVET:
        for (int i = 0; i < lenght; i++)
        {
            if (strcmp("Светодиоидная ", iter->value.type) != 0)
            {
                printf("");
                iter = iter->next;
            }
            else
            {
                printf("Вид: %s, Мощность:%d Вт, Вольтаж:%d В, Цена:%d руб, Потребление тока:%.4f мА/с\n", iter->value.type, iter->value.power, iter->value.voltage, iter->value.cost, iter->value.el_force);
                iter = iter->next;
            }
        }
        break;
    case KEEP:
        for (int i = 0; i < lenght; i++)
        {
            if (strcmp("Накапливания ", iter->value.type) != 0)
            {
                printf("");
                iter = iter->next;
            }
            else
            {
                printf("Вид: %s, Мощность:%d Вт, Вольтаж:%d В, Цена:%d руб, Потребление тока:%.4f мА/с\n", iter->value.type, iter->value.power, iter->value.voltage, iter->value.cost, iter->value.el_force);
                iter = iter->next;
            }
        }
        break;
    case POWER:
        printf("");
        for (int i = 0; i < lenght; i++)
        {
            mas[i] = iter->value.power;
            iter = iter->next;
        }
        for(int i = 0; i < lenght; i++)
            for(int j= i + 1; j < lenght; j++)
                if(mas[i] < mas[j])
                {
                    int k = mas[i];
                    mas[i] = mas[j];
                    mas[j] = k;
                }
        for (int i = 0; i < lenght; i++)
        {
            iter = checker->next;
            for (int j = 0; j < lenght; j++)
            {
                if (mas[i] == iter->value.power)
                {
                    printf("Вид: %s, Мощность:%d Вт, Вольтаж:%d В, Цена:%d руб, Потребление тока:%.4f мА/с\n", iter->value.type, iter->value.power, iter->value.voltage, iter->value.cost, iter->value.el_force);
                }
                iter = iter->next;
            }
        }
        free(mas);
        printf("\n");
        break;
    case VOLT:
        printf("");
        for (int i = 0; i < lenght; i++)
        {
            mas[i] = iter->value.voltage;
            iter = iter->next;
        }
        for(int i = 0; i < lenght; i++)
            for(int j= i + 1; j < lenght; j++)
                if(mas[i] < mas[j])
                {
                    int k = mas[i];
                    mas[i] = mas[j];
                    mas[j] = k;
                }
        for (int i = 0; i < lenght; i++)
        {
            iter = checker->next;
            for (int j = 0; j < lenght; j++)
            {
                if (mas[i] == iter->value.voltage)
                {
                    printf("Вид: %s, Мощность:%d Вт, Вольтаж:%d В, Цена:%d руб, Потребление тока:%.4f мА/с\n", iter->value.type, iter->value.power, iter->value.voltage, iter->value.cost, iter->value.el_force);
                }
                iter = iter->next;
            }
        }
        free(mas);
        printf("\n");
        break;
    case COST:
        printf("");
        for (int i = 0; i < lenght; i++)
        {
            mas[i] = iter->value.cost;
            iter = iter->next;
        }
        for(int i = 0; i < lenght; i++)
            for(int j= i + 1; j < lenght; j++)
                if(mas[i] < mas[j])
                {
                    int k = mas[i];
                    mas[i] = mas[j];
                    mas[j] = k;
                }
        for (int i = 0; i < lenght; i++)
        {
            iter = checker->next;
            for (int j = 0; j < lenght; j++)
            {
                if (mas[i] == iter->value.cost)
                {
                    printf("Вид: %s, Мощность:%d Вт, Вольтаж:%d В, Цена:%d руб, Потребление тока:%.4f мА/с\n", iter->value.type, iter->value.power, iter->value.voltage, iter->value.cost, iter->value.el_force);
                }
                iter = iter->next;
            }
        }
        free(mas);
        printf("\n");
        break;
    case EL:
        printf("");
        for (int i = 0; i < lenght; i++)
        {
            mas[i] = iter->value.el_force;
            iter = iter->next;
        }
        for(int i = 0; i < lenght; i++)
            for(int j= i + 1; j < lenght; j++)
                if(mas[i] < mas[j])
                {
                    int k = mas[i];
                    mas[i] = mas[j];
                    mas[j] = k;
                }
        for (int i = 0; i < lenght; i++)
        {
            iter = checker->next;
            for (int j = 0; j < lenght; j++)
            {
                if (mas[i] == iter->value.el_force)
                {
                    printf("Вид: %s, Мощность:%d Вт, Вольтаж:%d В, Цена:%d руб, Потребление тока:%.4f мА/с\n", iter->value.type, iter->value.power, iter->value.voltage, iter->value.cost, iter->value.el_force);
                }
                iter = iter->next;
            }
        }
        free(mas);
        printf("\n");
        break;
    case REV:
        printf("");
        Node new_start;
        Node* new_list = &new_start;
        Node* new_all = (Node*)malloc(sizeof(Node));
        Node* new_pointer = NULL;
        FILE *files = fopen("C:/Users/Пользователь/Desktop/Projects/Lab_5/info.txt", "r");
        while(fread(&light1, sizeof(struct light), 1, files))
        {
            Node* new_tmp = (Node*)malloc(sizeof(Node));
            new_tmp->prev = new_pointer;
            new_tmp->next = NULL;
            new_tmp->value = light1;
            new_pointer = new_tmp;
            new_all = new_tmp;
        }
        fclose(files);

        Node* new_tail = new_pointer;
        Node* new_pointer_now;

        for (int i = 0; i < lenght-1; i++)
        {
            new_pointer_now = new_pointer;
            new_pointer->prev->next = new_pointer_now;
            new_pointer_now = new_pointer_now->prev;
            new_pointer = new_pointer_now;
        }
        Node* new_checker = new_list;
        new_checker->prev = new_tail;
        new_checker->next = new_pointer_now;
        Node* ret = new_tail;
        for (int i = 0; i < lenght; i++)
        {
            iter->value = ret->value;
            iter = iter->next;
            ret = ret->prev;
        }
        iter = checker->next;

        printf("Ваш новый список:\n");
        for (int i = 0; i < lenght; i++)
        {
            count++;
            printf("%d. Вид: %s, Мощность:%d Вт, Вольтаж:%d В, Цена:%d руб, Потребление тока:%.4f мА/с\n", count, iter->value.type, iter->value.power, iter->value.voltage, iter->value.cost, iter->value.el_force);
            iter = iter->next;
        }
        count = 0;
        printf("\n");
        break;
    case LENGHT:
        for (int i = 0;;i++)
        {
            if (iter == tail)
            {
                list_lenght++;
                iter = iter->next;
                break;
            }
            else
            {
                list_lenght++;
                iter = iter->next;
            }
        }
        printf("Длина списка равна:%d\n", list_lenght);
        break;
    }
    free(all);
}
