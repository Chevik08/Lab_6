#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <locale.h>
#include "structure.h"
#include "delete.h"
#include "list.h"

void delete()
{
    setlocale(LC_ALL, "");
    struct light light1;
    int lenght = 0;
    int n = 0;
    int message = 0;
    int working = 1;
    list();
    FILE *file = fopen("C:/Users/Пользователь/Desktop/Projects/Lab_5/info.txt", "r");
    while(fread(&light1, sizeof(struct light), 1, file))
    {
        lenght += 1;
    }
    fclose(file);
    struct light* mas = malloc(lenght*sizeof(light1));
    FILE *files = fopen("C:/Users/Пользователь/Desktop/Projects/Lab_5/info.txt", "r");
    while(fread(&light1, sizeof(struct light), 1, files))
    {
        mas[n] = light1;
        n++;
    }
    fclose(files);
    printf("Выберите цифру варианта, который хотите удалить\n");
    while(working)
    {
        scanf("%d", &message);
        fflush(stdin);
        if (message > lenght || message <= 0)
            printf("Попробуйте ещё раз\n");
        else
            working = 0;
    }
    FILE *file_t = fopen("C:/Users/Пользователь/Desktop/Projects/Lab_5/info.txt", "w");
    close(file);
    FILE *file2 = fopen("C:/Users/Пользователь/Desktop/Projects/Lab_5/info.txt", "a+");
    for (int i = 0; i < lenght; i++)
        if (i != message-1)
            fwrite(&mas[i], sizeof(struct light), 1, file2);
    fclose(file2);
    free(mas);
}
