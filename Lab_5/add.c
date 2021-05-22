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
        printf("�������� ��� ����� ��������\n");
        printf("1. ������������\n");
        printf("2. ������������\n");
        scanf("%d", &message);
        fflush(stdin);
        switch(message)
        {
        case LIGHT:
            strcpy(light1.type, "������������� ");
            working = 0;
            break;
        case STORE:
            strcpy(light1.type, "������������ ");
            working = 0;
            break;
        default:
            printf("����������, ���������� ��� ���\n");
        }
    }
    working = 1;
    while(working)
    {
        printf("������� ��������(��)\n");
        scanf("%d", &message);
        fflush(stdin);
        if (message >= 0 && message <= 150)
        {
            light1.power = message;
            working = 0;
        }
        else
            printf("����������, ���������� ��� ���\n");
    }
    working = 1;
    while(working)
    {
        printf("������� �������\n");
        scanf("%d", &message);
        fflush(stdin);
        if (message >= 0 && message <= 240)
        {
            light1.voltage = message;
            working = 0;
        }
        else
            printf("����������, ���������� ��� ���\n");
    }
    working = 1;
    while(working)
    {
        printf("������� ����\n");
        scanf("%d", &message);
        fflush(stdin);
        if (message >= 0 && message <= 530000)
        {
            light1.cost = message;
            working = 0;
        }
        else
            printf("����������, ���������� ��� ���\n");
    }
    light1.el_force = light1.power*pow(light1.voltage, -1)*1000;
    file = fopen("C:/Users/������������/Desktop/Projects/Lab_5/info.txt", "a+");
    fwrite(&light1, sizeof(struct light), 1, file);
    fclose(file);
    printf("\r���� �������� ���� ������� ���������!\n\n");
}
