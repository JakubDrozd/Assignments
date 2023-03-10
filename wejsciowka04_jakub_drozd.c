#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 5 // max array size
//C:\\Users\\PATOX\\Desktop\\uczniowie.txt
 struct para
{
    char name[15];
    int grade;
};

int read(FILE* file, struct para tab[], int m,  int *k) {
    FILE* output;
    char path[80];
    printf("Enter input file path: ");
    scanf_s("%s", path, 80);
    file = fopen(path, "r");
    if (file == NULL)
    {
        printf("\nError opening input file\n");
        return 1;
    }
    else
    {
        char path[80];
        printf("Enter output file path: ");
        scanf_s("%s", path, 80);
        output = fopen(path, "w");
        if (output == NULL)
        {
            printf("\nError opening output file\n");
            return 1;
        }
        for (int i = 0; i < m; i++)
        {
            if (!feof(file))
            {
                int index;
                char name[15];
                int grade;
                fscanf(file, "%d %s %d", &index, name, &grade);
                strcpy(tab[i].name, name);
                tab[i].grade = grade;
                fprintf(output, "%s %d\n", name, grade);
                (*k)++;
            }
        }
    }
    fclose(file);
    fclose(output);
    return 0;
}



void print_array(struct para tab[], int m) {
    for (int i = 0; i < m; i++)
    {
        printf("%s %d\n", tab[i].name, tab[i].grade);
    }

}


int main() {
    int k = 0;                  //data counter
    FILE* file;
    struct para tab[MAX];
    read(&file, tab, MAX, &k);
    print_array(tab, k);
    return 0;
}