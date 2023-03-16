#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_ARR_SIZE 50


int bin2int(char* napis) {                          //Obliczanie wartosci liczbowej dla ciagu binarnego
    int liczba = 0;
    int dlugosc = (int)strlen(napis);
    int potega = dlugosc - 1;
    for (int i = 0; i < dlugosc; i++)
    {
        if (napis[i] == '1')
        {
            int temp = (int)pow(2, potega);
            liczba += temp;
            potega--;
        }
        else
        {
            potega--;
        }
    }
    return liczba;
}


void wypisz_tab_2W(char** tab, int m) {
    for (int i = 0; i < m; i++)
    {
        if (*tab[i] != '\0')                                 //Ignorowanie pustych wierszy tablicy dynamicznej
        {
            printf("%d\t[%s]\n", bin2int(tab[i]), tab[i]);
        }
    }
}

void zamien(char** a, char** b) {
    char* temp = *a;
    *a = *b;
    *b = temp;
}

void sortowanie(char** tab, int m) {                                //Algorytm sortujacy przez wybor (malejaco)
    for (int i = 0; i < m - 1; i++) {
        int max_index = i;
        for (int j = i + 1; j < m; j++) {
            if (bin2int(tab[j]) > bin2int(tab[max_index])) {
                max_index = j;
            }
        }
        if (max_index != i) {
            zamien(&tab[i], &tab[max_index]);
        }
    }
}

int wczytaj_int() {                                                        //Funkcja wczytywania liczby z klawiatury
    static int liczba_wywolan = 0;
    int liczba;
    printf("Podaj liczbe %s: ", (liczba_wywolan > 0) ? "kolumn" : "wierszy");
    while (scanf_s("%d", &liczba) != 1 || getchar() != '\n')
    {
        printf("Bledne dane, podaj liczbe %s: ", (liczba_wywolan > 0) ? "kolumn" : "wierszy");
        int c;
        while ((c = getchar()) != '\n' && c != EOF)
            ;
    }
    liczba_wywolan++;
    return liczba;
}

void zwolnij_tab_2W(char** tab, int m) {
    for (int i = 0; i < m; i++)
    {
        free(tab[i]);
    }
    free(tab);
}

int main() {
    //Tworzenie tablicy dynamicznej
    int m = wczytaj_int();
    int n = wczytaj_int();
    char** tab = malloc(m * sizeof(char*));
    for (int i = 0; i < m; i++)
    {
        tab[i] = malloc(n * sizeof(char));
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            tab[i][j] = '\0';
        }
    }
    //Wczytywanie pliku do odczytu
    FILE* input;
    if (fopen_s(&input, "C:\\Users\\PATOX\\Desktop\\dane.txt", "r") != 0)
    {
        printf("Bledne odczytywanie pliku input");
        return 1;
    }
    int i = 0;
    char* napis = malloc(n * sizeof(char));                 //Tymczasowa zmienna do przypisywania ciągów
    if (input!=0)
    {
        while (!feof(input) && i < m) {                         //Odczytywanie danych z pliku
            if (fgets(napis, n, input) != NULL)
            {
                for (int j = 0; j < strlen(napis); j++)
                {
                    if (napis[j] != '\n')                             //Ignorowanie znaku nowej linii
                    {
                        tab[i][j] = napis[j];
                    }
                }
                i++;
            }
        }
    }
    free(napis);                                            //Zwolnienie tymczasowej zmiennej z pamięci 
    printf("\nPrzed sortowaniem:\n");
    wypisz_tab_2W(tab, m);
    sortowanie(tab, m);
    printf("\nPo sortowaniu:\n");
    wypisz_tab_2W(tab, m);
    zwolnij_tab_2W(tab, m);                                 //Zwolnienie tablicy dynamicznej 
    fclose(input);
    return 0;
}
