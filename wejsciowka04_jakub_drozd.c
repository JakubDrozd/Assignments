#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 5 // max array size
//C:\\Users\\PATOX\\Desktop\\uczniowie.txt
typedef struct
{
    char name[80];
    int grade;
}para;

void read(FILE* file, para tab[], int m) {
    char path[80];
    printf("Enter the file path: ");
    scanf_s("%s", path, 80);
    file = fopen(path, "r");

    if (file == NULL)
    {
        printf("Error\n");
    }
    else
    {
        for (int i = 0; i < m; i++)
        {
            int index;
            char name[80];
            int grade;
            fscanf(file, "%d %80s %d", &index, name, &grade);
            strcpy(tab[i].name, name);
            tab[i].grade = grade;
        }
    }
    if (file != NULL)
    {
        fclose(file);
    }
}

void print_array(para tab[], int m) {
    for (int i = 0; i < m; i++)
    {
        printf("%s %d\n", tab[i].name, tab[i].grade);
    }

}


int main() {
    FILE* file;
    para tab[5];
    read(&file, tab, MAX);
    print_array(tab, MAX);
    return 0;
}