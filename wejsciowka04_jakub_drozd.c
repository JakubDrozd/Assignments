//#include <stdio.h>
//#include <string.h>
//#include <ctype.h>
//#define MAX_ARRAY_SIZE 5 // max array size
////C:\\Users\\PATOX\\Desktop\\uczniowie.txt
// struct para
//{
//    char name[15];
//    int grade;
//};
//
// void switch_vowels(char string[]) {
//     size_t length = strlen(string);
//     for (int i = 0; i < length; i++)
//     {
//         if (string[i] == 'a' || string[i] == 'e' || string[i] == 'i' || string[i] == 'o' || string[i] == 'u')
//         {
//             string[i] = '*';
//         }
//     }
// }
//
// int read(FILE* file, struct para tab[], int m, int* k) {
//     FILE* output;
//     FILE* input;
//     char path[80];
//     printf("Enter input file path: ");
//     if (scanf_s("%79s", path, 80) != 1)
//     {
//         printf("Error reading input file path\n");
//         return 1;
//     }
//     path[79] = '\0';
//     if (fopen_s(&input, path, "r") != 0)
//     {
//         printf("\nError opening input file\n");
//         return 1;
//     }
//     printf("Enter output file path: ");
//     if (scanf_s("%79s", path, 80) != 1)
//     {
//         printf("\nError reading output file path\n");
//         fclose(input);
//         return 1;
//     }
//     path[79] = '\0';
//     if (fopen_s(&output, path, "w") != 0)
//     {
//         printf("\nError opening output file\n");
//         fclose(input);
//         return 1;
//     }
//     for (int i = 0; i < m; i++) {
//         char name[15];
//         int grade;
//         if (fscanf_s(input, "%*d %14s %d", name, (unsigned)sizeof(name), &grade) != 2) {
//             if (!feof(input)) {
//                 printf("\nError reading input\n");
//                 fclose(input);
//                 fclose(output);
//                 return 1;
//             }
//             break;
//         }
//         name[14] = '\0';
//         strcpy_s(tab[i].name, sizeof(tab[i].name), name);
//         tab[i].grade = grade;
//         switch_vowels(name);
//         fprintf(output, "%s %d\n", name, grade);
//         (*k)++;
//     }
//     fclose(input);
//     fclose(output);
//     return 0;
// }
//
//
//void print_array(struct para tab[], int m) {
//    for (int i = 0; i < m; i++)
//    {
//        printf("%s %d\n", tab[i].name, tab[i].grade);
//    }
//
//}
//
//
//int main() {
//    int k = 0;                  //data counter
//    FILE* file = NULL;
//    struct para tab[MAX_ARRAY_SIZE];
//    if (read(file, tab, MAX_ARRAY_SIZE, &k) == 0)
//    {
//        print_array(tab, k);
//    }
//    else
//    {
//        printf("\nError\n");
//        return 1;
//    }
//    return 0;
//}