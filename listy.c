
//#include <stdio.h>
//#include <stdlib.h>
//
//struct pomiar {
//    int wartosc;
//    struct pomiar* nastepny;
//    struct pomiar* poprzedni;
//};
//
//struct pomiar* dodaj_pomiar(int wartosc) {
//    struct pomiar* nowy_pomiar = nowy_pomiar = malloc(sizeof(struct pomiar));
//    if (nowy_pomiar != NULL)
//    {
//        nowy_pomiar->wartosc = wartosc;
//        nowy_pomiar->nastepny = NULL;
//        nowy_pomiar->poprzedni = NULL;
//    }
//    return nowy_pomiar;
//}
//
//void dealokuj(struct pomiar* pierwszy) {
//    struct pomiar* aktualny = pierwszy;
//    while (aktualny != NULL) {
//        struct pomiar* temp = aktualny;
//        aktualny = aktualny->nastepny;
//        free(temp);
//    }
//}
//
//void wypisz_liste(struct pomiar* pierwszy) {
//    struct pomiar* aktualny = pierwszy;
//    while (aktualny != NULL) {
//        printf("%d\n", aktualny->wartosc);
//        aktualny = aktualny->nastepny;
//    }
//}
//
//struct lista {
//    struct pomiar* pierwszy;
//    struct pomiar* ostatni;
//};
//
//struct lista utworz_liste(int wartosc) {
//    struct lista lista;
//    struct pomiar* pierwszy = dodaj_pomiar(1);
//    struct pomiar* ostatni = pierwszy;
//    if (pierwszy != NULL)
//    {
//        for (int i = 2; i < 6; i++)
//        {
//            struct pomiar* nowy_pomiar = dodaj_pomiar(i);
//            if (nowy_pomiar != NULL)
//            {
//                ostatni->nastepny = nowy_pomiar;
//                nowy_pomiar->poprzedni = ostatni;
//                ostatni = nowy_pomiar;
//            }
//            else
//            {
//                break;
//            }
//        }
//    }
//    lista.pierwszy = pierwszy;
//    lista.ostatni = ostatni;
//    return lista;
//}
//
//void reverse(struct pomiar* ostatni) {
//    struct pomiar* aktualny = ostatni;
//    while (aktualny != NULL)
//    {
//        printf("%d\n", aktualny->wartosc);
//        aktualny = aktualny->poprzedni;
//    }
//}
//
//void przenies_poczatek(struct pomiar** wsk_pierwszy, struct pomiar* element) {
//    struct pomiar* pierwszy = *wsk_pierwszy;
//    if (element == pierwszy)
//    {
//        return;
//    }
//    element->poprzedni->nastepny = element->nastepny;
//    if (element->nastepny != NULL) {
//        element->nastepny->poprzedni = element->poprzedni;
//    }
//    element->poprzedni = NULL;
//    pierwszy->poprzedni = element;
//    element->nastepny = pierwszy;
//    *wsk_pierwszy = element;
//}
//
//void przenies_koniec(struct pomiar** wsk_ostatni, struct pomiar** wsk_pierwszy, struct pomiar* element) {
//    struct pomiar* ostatni = *wsk_ostatni;
//    struct pomiar* pierwszy = *wsk_pierwszy;
//    if (ostatni == element)
//    {
//        return;
//    }
//    if (element->poprzedni == NULL)
//    {
//        struct pomiar* nowy_pierwszy = element->nastepny;
//        ostatni->nastepny = element;
//        element->poprzedni = ostatni;
//        element->nastepny = NULL;
//        *wsk_ostatni = element;
//        nowy_pierwszy->poprzedni = NULL;
//        *wsk_pierwszy = nowy_pierwszy;
//        return;
//    }
//    else
//    {
//        element->poprzedni->nastepny = element->nastepny;
//        element->nastepny->poprzedni = element->poprzedni;
//        ostatni->nastepny = element;
//        element->poprzedni = ostatni;
//        element->nastepny = NULL;
//        *wsk_ostatni = element;
//        return;
//    }
//}
//
//void dodaj_koniec(struct pomiar** wsk_ostatni, struct pomiar* element) {
//    struct pomiar* ostatni = *wsk_ostatni;
//    ostatni->nastepny = element;
//    element->poprzedni = ostatni;
//    element->nastepny = NULL;
//    *wsk_ostatni = element;
//}
//
//void dodaj_poczatek(struct pomiar** wsk_pierwszy, struct pomiar* element) {
//    struct pomiar* pierwszy = *wsk_pierwszy;
//    pierwszy->poprzedni = element;
//    element->nastepny = pierwszy;
//    element->poprzedni = NULL;
//    *wsk_pierwszy = element;
//}
//
//void dodaj_po_elemencie(struct pomiar* pierwszy, struct pomiar** ostatni, int klucz, struct pomiar* element) {
//    struct pomiar* aktualny = pierwszy;
//    while (aktualny != NULL)
//    {
//        if (aktualny->wartosc == klucz)
//        {
//            if (aktualny->nastepny == NULL)
//            {
//                aktualny->nastepny = element;
//                element->poprzedni = aktualny;
//                element->nastepny = NULL;
//                *ostatni = element;
//                break;
//            }
//            element->nastepny = aktualny->nastepny;
//            element->poprzedni = aktualny;
//            aktualny->nastepny->poprzedni = element;
//            aktualny->nastepny = element;
//            break;
//        }
//        else
//        {
//            aktualny = aktualny->nastepny;
//        }
//    }
//}
//
//void dodaj_przed_elementem(struct pomiar** pierwszy, int klucz, struct pomiar* element) {
//    struct pomiar* aktualny = *pierwszy;
//    while (aktualny != NULL)
//    {
//        if (aktualny->wartosc == klucz) {
//            if (aktualny->poprzedni == NULL)
//            {
//                aktualny->poprzedni = element;
//                element->nastepny = aktualny;
//                element->poprzedni = NULL;
//                *pierwszy = element;
//                break;
//            }
//            element->poprzedni = aktualny->poprzedni;
//            element->nastepny = aktualny;
//            aktualny->poprzedni->nastepny = element;
//            aktualny->poprzedni = element;
//            break;
//        }
//        else
//        {
//            aktualny = aktualny->nastepny;
//        }
//    }
//}
//
//void zamien_elementy(struct pomiar* element1, struct pomiar* element2) {
//    struct pomiar* poprzednik1 = element1->poprzedni;
//    struct pomiar* nastepnik1 = element1->nastepny;
//    struct pomiar* poprzednik2 = element2->poprzedni;
//    struct pomiar* nastepnik2 = element2->nastepny;
//
//    element1->poprzedni = poprzednik2;
//    poprzednik2->nastepny = element1;
//    element1->nastepny = nastepnik2;
//    nastepnik2->poprzedni = element1;
//
//    element2->poprzedni = poprzednik1;
//    poprzednik1->nastepny = element2;
//    element2->nastepny = nastepnik1;
//    nastepnik1->poprzedni = element2;
//}
//
//struct pomiar* znajdz(struct pomiar* pierwszy, int klucz) {
//    struct pomiar* aktualny = pierwszy;
//    while (aktualny != NULL)
//    {
//        if (aktualny->wartosc == klucz)
//        {
//
//            return aktualny;
//        }
//        else
//        {
//            aktualny = aktualny->nastepny;
//        }
//    }
//    printf("Nie znaleziono\n");
//    return NULL;
//}
//
//void usun_element(struct pomiar** pierwszy, struct pomiar** ostatni, int klucz) {
//    struct pomiar* aktualny = *pierwszy;
//    if ((*pierwszy)->wartosc == klucz)
//    {
//        struct pomiar* temp = *pierwszy;
//        *pierwszy = (*pierwszy)->nastepny;
//        free(temp);
//        return;
//    }
//    while (aktualny != NULL)
//    {
//        if (aktualny->wartosc == klucz)
//        {
//            if (aktualny->nastepny == NULL)
//            {
//                struct pomiar* temp = aktualny;
//                aktualny->poprzedni->nastepny = NULL;
//                *ostatni = aktualny->poprzedni;
//                free(aktualny);
//                break;
//            }
//            else
//            {
//                struct pomiar* temp = aktualny;
//                aktualny->poprzedni->nastepny = aktualny->nastepny;
//                aktualny->nastepny->poprzedni = aktualny->poprzedni;
//                free(temp);
//                break;
//            }
//
//        }
//        aktualny = aktualny->nastepny;
//    }
//}
//
//int main(void) {
//    struct lista lista = utworz_liste(1);
//
//    /*przenies_poczatek(&lista.pierwszy, znajdz(lista.pierwszy, 2));*/
//
//    /*przenies_koniec(&lista.ostatni, &lista.pierwszy, znajdz(lista.pierwszy, 5));*/
//
//    /*dodaj_koniec(&lista.ostatni, dodaj_pomiar(13));*/
//
//    /*dodaj_poczatek(&lista.pierwszy, dodaj_pomiar(24));*/
//
//    /*dodaj_po_elemencie(lista.pierwszy, &lista.ostatni, 5, dodaj_pomiar(128));*/
//
//    /*dodaj_przed_elementem(&lista.pierwszy, 5, dodaj_pomiar(72));*/
//
//    /*zamien_elementy(znajdz(lista.pierwszy, 2), znajdz(lista.pierwszy, 4));*/  //Krancowe nie dzialaja
//
//    /*usun_element(&lista.pierwszy, &lista.ostatni, 5);*/
//
//
//
//    wypisz_liste(lista.pierwszy);
//    printf("\n");
//    reverse(lista.ostatni);
//
//
//    dealokuj(lista.pierwszy);
//    return 0;
//}