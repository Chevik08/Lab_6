#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <locale.h>
#include "structure.h"
#include "add.h"

#define LIGHT 1
#define STORE 2

void add()
{
    char chr;
    setlocale(LC_ALL, "");
    int working = 1;
    struct light light1;
    int message = 0;
    FILE* file;
    while(working)
    {
        light1.type = (char*)malloc(13*sizeof(char));
        printf("Выберите тип вашей лампочки\n");
        printf("1. Светодиодная\n");
        printf("2. Накапливания\n");
        scanf("%d", &message);
        fflush(stdin);
        switch(message)
        {
        case LIGHT:
            strcpy(light1.type, "Светодиоидная ");
            working = 0;
            break;
        case STORE:
            strcpy(light1.type, "Накапливания ");
            working = 0;
            break;
        default:
            printf("Пожалуйста, попробуйте ещё раз\n");
        }
    }
    working = 1;
    while(working)
    {
        printf("Введите мощность(Вт)\n");
        scanf("%d", &message);
        fflush(stdin);
        if (message >= 0 && message <= 150)
        {
            light1.power = message;
            working = 0;
        }
        else
            printf("Пожалуйста, попробуйте ещё раз\n");
    }
    working = 1;
    while(working)
    {
        printf("Введите вольтаж\n");
        scanf("%d", &message);
        fflush(stdin);
        if (message >= 0 && message <= 240)
        {
            light1.voltage = message;
            working = 0;
        }
        else
            printf("Пожалуйста, попробуйте ещё раз\n");
    }
    working = 1;
    while(working)
    {
        printf("Введите цену\n");
        scanf("%d", &message);
        fflush(stdin);
        if (message >= 0 && message <= 530000)
        {
            light1.cost = message;
            working = 0;
        }
        else
            printf("Пожалуйста, попробуйте ещё раз\n");
    }
    light1.el_force = light1.power*pow(light1.voltage, -1)*1000;
    file = fopen("C:/Users/Пользователь/Desktop/Projects/Lab_5/info.txt", "a+");
    fwrite(&light1, sizeof(struct light), 1, file);
    fclose(file);
    printf("\rВаша лампочка была успешно добавлена!\n\n");
}
