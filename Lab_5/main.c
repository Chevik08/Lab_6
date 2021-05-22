#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
#include "add.h"
#include "list.h"
#include "structure.h"

#define FIND 2
#define START 1
#define ADD 3
#define DELETE 4
#define EXIT 5

int main()
{
    struct light light1;
    setlocale(LC_ALL, "");
    int working = 1;
    int message = 0;
    while (working)
    {
        printf("����� ���������� � ���������!\n");
        printf("1.������� ������ ��������\n");
        printf("2.����� ��������\n");
        printf("3.�������� ��������\n");
        printf("4.������� ��������\n");
        printf("5.�����\n");
        scanf("%d", &message);
        fflush(stdin);
        switch(message)
        {
        case START:
            list();
            break;
        case FIND:
            find();
            break;
        case ADD:
            add();
            break;
        case DELETE:
            delete();
            break;
        case EXIT:
            working = 0;
            printf("�������...\n");
            break;
        default:
            printf("������ �� ������\n");
        }
    }
    return 0;
}
