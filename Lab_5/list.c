#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <locale.h>
#include "structure.h"
#include "list.h"

void list()
{
    setlocale(LC_ALL, "");
    struct light light1;
    light1.type = (char*)malloc(100*sizeof(char));
    int size = 0;
    FILE* file;
    int count = 1;
    file = fopen("C:/Users/Пользователь/Desktop/Projects/Lab_5/info.txt", "rb");
    printf("Ваш товар:\n");
    while(fread(&light1, sizeof(struct light), 1, file))
        printf("%s\n", light1.type);
    fclose(file);
    printf("\n");
}
