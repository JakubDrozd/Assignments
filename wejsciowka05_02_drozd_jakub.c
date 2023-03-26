//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//
//struct student {
//    int indeks;
//    char imie[25];
//    int ocena;
//    struct student* nastepny;
//};
//
//struct student* dodajStudenta(int indeks, char imie[], int ocena) {
//    struct student* nowyStudent = NULL;
//    nowyStudent = malloc(sizeof(struct student));
//    if (nowyStudent != NULL)
//    {
//        nowyStudent->indeks = indeks;
//        strcpy_s(nowyStudent->imie, sizeof(nowyStudent->imie), imie);
//        nowyStudent->ocena = ocena;
//        nowyStudent->nastepny = NULL;
//        printf("\nDodano studenta pod adresem %p\n", nowyStudent);
//    }
//    else
//    {
//        printf("Blad alokowania pamieci");
//    }
//    return nowyStudent;
//}
//
//void wypiszStudenta(struct student* student) {
//    if (student == NULL)
//    {
//        printf("Student nie istnieje");
//    }
//    else
//    {
//        printf("\n[Indeks]: %d\n[Imie]: %s\n[Ocena]: %d\n[Nastepny]: %p\n",
//            student->indeks,
//            student->imie,
//            student->ocena,
//            student->nastepny
//        );
//    }
//}
//
//void wypiszStudentow(struct student* pierwszy) {
//    struct student* aktualny = pierwszy;
//    while (aktualny != NULL)
//    {
//        wypiszStudenta(aktualny);
//        aktualny = aktualny->nastepny;
//    }
//}
//
//void dodajNaKoniec(struct student* pierwszy, int indeks, char imie[], int ocena, int* i) {
//    struct student* nowyStudent = dodajStudenta(indeks, imie, ocena);
//    if (nowyStudent != NULL)
//    {
//        if (pierwszy == NULL)
//        {
//            pierwszy = nowyStudent;
//        }
//        else
//        {
//            struct student* aktualny = pierwszy;
//            while (aktualny->nastepny != NULL)
//            {
//                aktualny = aktualny->nastepny;
//            }
//            aktualny->nastepny = nowyStudent;
//        }
//    }
//    (*i)++;
//}
//
//void dodajNaPoczatek(struct student** pierwszy, int indeks, char imie[], int ocena, int* i) {          //** bo modifikujemy zmienna pierwszy zadeklarowana w main
//    struct student* nowyStudent = dodajStudenta(indeks, imie, ocena);
//    if (nowyStudent != NULL)
//    {
//        if (pierwszy == NULL)
//        {
//            pierwszy = nowyStudent;
//        }
//        else
//        {
//            nowyStudent->nastepny = *pierwszy;
//            *pierwszy = nowyStudent;
//        }
//    }
//    (*i)++;
//}
//
//void dodajPo(struct student* pierwszy, int id, int indeks, char imie[], int ocena, int* i) {
//    struct student* nowyStudent = dodajStudenta(indeks, imie, ocena);
//    struct student* aktualny = pierwszy;
//    while (aktualny->nastepny != NULL)
//    {
//        if (aktualny->indeks == id)
//        {
//            nowyStudent->nastepny = aktualny->nastepny;
//            aktualny->nastepny = nowyStudent;
//            (*i)++;
//            break;
//        }
//        else
//        {
//            aktualny = aktualny->nastepny;
//        }
//    }
//}
//
//void usunPoId(struct student* pierwszy, int id, int* i) {
//    struct student* aktualny = pierwszy;
//    while (aktualny->nastepny != NULL)
//    {
//        if (aktualny->nastepny->indeks == id)
//        {
//            struct student* doUsuniecia = aktualny->nastepny;
//            aktualny->nastepny = aktualny->nastepny->nastepny;
//            free(doUsuniecia);
//            (*i)--;
//            break;
//        }
//        else
//        {
//            aktualny = aktualny->nastepny;
//        }
//    }
//}
//
//void dealokacjaStudentow(struct student* pierwszy) {
//    struct student* aktualny = pierwszy;
//    while (aktualny != NULL)
//    {
//        struct student* aux = aktualny;
//        aktualny = aktualny->nastepny;
//        free(aux);
//    }
//}
//
//int main(void) {
//    FILE* input;
//    int i = 0;
//    struct student* pierwszy = NULL;    //Wskazuje na pierwszy element z listy
//    struct student* aktualny = NULL;    //Wskazuje na ostatnio dodany element z listy
//    if (fopen_s(&input, "C:\\Users\\PATOX\\Desktop\\dane.txt", "r") != 0)
//    {
//        printf("Blad wczytywania pliku");
//        return 1;
//    }
//    int indeks = 0;
//    char imie[25];
//    int ocena = 0;
//    while (fscanf_s(input, "%d %s %d", &indeks, imie, (unsigned)sizeof(imie), &ocena) == 3)  //Dopóki jest w w stanie odczytać dane w formacie, pętla się wykonuje
//    {
//        if (pierwszy == NULL)
//        {
//            pierwszy = dodajStudenta(indeks, imie, ocena);                                //Jeżeli lista nie posiada jeszcze pierwszego elementu, tworzy go
//            if (pierwszy != NULL)
//            {
//                aktualny = pierwszy;                                                        //Jeżeli alokacja w pamięci się udała, ustaw dodaną daną jako dodaną
//                i++;
//            }
//        }
//        else
//        {
//            aktualny->nastepny = dodajStudenta(indeks, imie, ocena);                        //Jeżeli lista zawiera już pierwszy element, dodaje kolejny
//            if (aktualny->nastepny != NULL)
//            {
//                aktualny = aktualny->nastepny;
//                i++;
//            }
//        }
//    }
//    dodajNaKoniec(pierwszy, 123477, "Sebastian", 3, &i);
//    dodajNaPoczatek(&pierwszy, 123466, "Mateusz", 4, &i);           //Modyfikujemy zmienna w main, wiec podajemy adres zmiennej pierwszy
//    dodajPo(pierwszy, 123466, 123444, "Kacper", 2, &i);
//    usunPoId(pierwszy, 123479, &i);
//    wypiszStudentow(pierwszy);
//    printf("\n[Ilosc studentow]: %d\n", i);
//    dealokacjaStudentow(pierwszy);
//    pierwszy = NULL;
//    aktualny = NULL;
//    return 0;
//}
