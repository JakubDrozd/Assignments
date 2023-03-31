#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pomiar {
	unsigned int nr_pomiaru;
	unsigned int nr_czujnika;
	char data_i_czas[20];
	double temp;
	struct pomiar* nastepny;
	struct pomiar* poprzedni;
};

struct pomiar* dodaj_pomiar(unsigned int nr_pomiaru,unsigned int nr_czujnika,char data_i_czas[20],
	double temp) {

	struct pomiar* nowy_pomiar = malloc(sizeof(struct pomiar));
	nowy_pomiar->nr_pomiaru = nr_pomiaru;
	nowy_pomiar->nr_czujnika = nr_czujnika;
	strcpy_s(nowy_pomiar->data_i_czas, sizeof(nowy_pomiar->data_i_czas), data_i_czas);
	nowy_pomiar->temp = temp;
	nowy_pomiar->poprzedni = NULL;
	nowy_pomiar->nastepny = NULL;
	return nowy_pomiar;
}

void wypisz_liste(struct pomiar* pierwszy) {
	struct pomiar* aktualny = pierwszy;
	while (aktualny != NULL)
	{
		printf("%d %d %s %lf\n", aktualny->nr_pomiaru, aktualny->nr_czujnika, aktualny->data_i_czas, aktualny->temp);
		aktualny = aktualny->nastepny;
	}
}

void reverse(struct pomiar* ostatni) {
	struct pomiar* aktualny = ostatni;
	while (aktualny != NULL)
	{
		printf("%d %d %s %lf\n", aktualny->nr_pomiaru, aktualny->nr_czujnika, aktualny->data_i_czas, aktualny->temp);
		aktualny = aktualny->poprzedni;
	}
}

struct pomiar* znajdz_ostatni(struct pomiar* pierwszy) {
	if (pierwszy == NULL)
	{
		return NULL;
	}
	struct pomiar* aktualny = pierwszy;
	while (aktualny->nastepny != NULL)
	{
		aktualny = aktualny->nastepny;
	}
	return aktualny;
}

void dodaj_koniec(struct pomiar** ostatni, struct pomiar* element) {
	(*ostatni)->nastepny = element;
	element->poprzedni = *ostatni;
	*ostatni = element;
}


void rozdziel_liste(struct pomiar **pierwszy, struct pomiar** czujnik1, struct pomiar** czujnik2, struct pomiar** czujnik3, struct pomiar** czujnik4){
	struct pomiar* aktualny = *pierwszy;
	while (aktualny != NULL)
	{
		struct pomiar* nastepny = aktualny->nastepny;
		aktualny->poprzedni = NULL;
		aktualny->nastepny = NULL;
		if (aktualny->nr_czujnika == 1)
		{
			if (*czujnik1 == NULL)
			{
				*czujnik1 = aktualny;
			}
			else
			{
				struct pomiar* ostatni = znajdz_ostatni(*czujnik1);
				dodaj_koniec(&ostatni, aktualny);
			}
		} else if (aktualny->nr_czujnika == 2)
		{
			if (*czujnik2 == NULL)
			{
				*czujnik2 = aktualny;
			}
			else
			{
				struct pomiar* ostatni = znajdz_ostatni(*czujnik2);
				dodaj_koniec(&ostatni, aktualny);
			}
		}
		else if(aktualny->nr_czujnika == 3)
		{
			if (*czujnik3 == NULL)
			{
				*czujnik3 = aktualny;
			}
			else
			{
				struct pomiar* ostatni = znajdz_ostatni(*czujnik3);
				dodaj_koniec(&ostatni, aktualny);
			}
		}
		else if (aktualny->nr_czujnika == 4)
		{
			if (*czujnik4 == NULL)
			{
				*czujnik4 = aktualny;
			}
			else
			{
				struct pomiar* ostatni = znajdz_ostatni(*czujnik4);
				dodaj_koniec(&ostatni, aktualny);
			}
		}
		else
		{
			printf("\n\n\n!!!Nieznany nr czujnika!!!\n\n\n");
		}
		aktualny = nastepny;
	}
	*pierwszy = NULL;
}

void ile_pomiarow(struct pomiar* pierwszy) {
	int ilosc_pomiarow = 0;
	struct pomiar* minimalny = pierwszy;
	struct pomiar* maksymalny = pierwszy;
	struct pomiar* aktualny = pierwszy;
	while (aktualny != NULL)
	{
		if (aktualny->temp < minimalny->temp)
		{
			minimalny = aktualny;
		}
		if (aktualny->temp > maksymalny->temp)
		{
			maksymalny = aktualny;
		}
		ilosc_pomiarow++;
		aktualny = aktualny->nastepny;
	}
	printf("\nIlosc pomiarow: %d\n", ilosc_pomiarow);
	printf("Maksymalna | %d %d %s %lf\n", maksymalny->nr_pomiaru, maksymalny->nr_czujnika, maksymalny->data_i_czas, maksymalny->temp);
	printf("Minimalna | %d %d %s %lf\n\n\n", minimalny->nr_pomiaru, minimalny->nr_czujnika, minimalny->data_i_czas, minimalny->temp);
}

struct pomiar* wczytaj_plik(char nazwa[20]) {
	FILE* wejscie;
	struct pomiar* pierwszy = NULL;
	struct pomiar* ostatni = NULL;
	if (fopen_s(&wejscie, nazwa, "r") != 0)
	{
		printf("Nie udalo sie otworzyc pliku");
		exit(0);
	}
	else
	{
		printf("Suckes\n");
	}
	unsigned int nr_pomiaru;
	unsigned int nr_czujnika;
	char data_i_czas[20];
	double temp;
	while (fscanf_s(wejscie, "%d %d %s %lf", &nr_pomiaru, &nr_czujnika, data_i_czas, (unsigned)sizeof(data_i_czas), &temp) == 4)
	{
		if (pierwszy == NULL)
		{
			pierwszy = dodaj_pomiar(nr_pomiaru, nr_czujnika, data_i_czas, temp);
			if (pierwszy != NULL)
			{
				ostatni = pierwszy;
			}
		}
		else
		{
			ostatni->nastepny = dodaj_pomiar(nr_pomiaru, nr_czujnika, data_i_czas, temp);
			if (ostatni->nastepny != NULL)
			{
				struct pomiar* temp = ostatni;
				ostatni = ostatni->nastepny;
				ostatni->poprzedni = temp;
			}
		}
	}
	return pierwszy;
}

void wpisz_plik(FILE* wyjscie, struct pomiar* pierwszy) {
	struct pomiar* aktualny = pierwszy;
	while (aktualny != NULL)
	{
		fprintf_s(wyjscie, "%d %d %s %lf\n", aktualny->nr_pomiaru, aktualny->nr_czujnika, aktualny->data_i_czas, aktualny->temp);
		aktualny = aktualny->nastepny;
	}
}

void dealokuj_liste(struct pomiar** pierwszy) {
	struct pomiar* aktualny = *pierwszy;
	while (aktualny != NULL)
	{
		struct pomiar* temp = aktualny;
		aktualny = aktualny->nastepny;
		free(temp);
	}
	*pierwszy = NULL;
}

int main(){
	FILE* wyjscie1 = NULL;
	FILE* wyjscie2 = NULL;
	FILE* wyjscie3 = NULL;
	FILE* wyjscie4 = NULL;
	struct pomiar* pierwszy = wczytaj_plik("dane.txt");
	struct pomiar* ostatni = znajdz_ostatni(pierwszy);
	struct pomiar* czujnik1 = NULL;
	struct pomiar* czujnik2 = NULL;
	struct pomiar* czujnik3 = NULL;
	struct pomiar* czujnik4 = NULL;
	rozdziel_liste(&pierwszy, &czujnik1, &czujnik2, &czujnik3, &czujnik4);
	ile_pomiarow(czujnik1);
	ile_pomiarow(czujnik2);
	ile_pomiarow(czujnik3);
	ile_pomiarow(czujnik4);
	char nazwa[20];
	printf("Podaj nazwe pliku: ");
	scanf_s("%s", nazwa, 20);
	for (int i = 1; i <= 4 ; i++)
	{
		char pelna_nazwa[30];
		sprintf_s(pelna_nazwa, 30, "%s%d.txt", nazwa, i);
		printf("%s\n", pelna_nazwa);
		if (i == 1)
		{
			fopen_s(&wyjscie1, pelna_nazwa, "w");
			wpisz_plik(wyjscie1, czujnik1);
		}
		else if (i == 2)
		{
			fopen_s(&wyjscie2, pelna_nazwa, "w");
			wpisz_plik(wyjscie2, czujnik2);
		} 
		else if (i == 3)
		{
			fopen_s(&wyjscie3, pelna_nazwa, "w");
			wpisz_plik(wyjscie3, czujnik3);
		} 
		else if (i == 4)
		{
			fopen_s(&wyjscie4, pelna_nazwa, "w");
			wpisz_plik(wyjscie4, czujnik4);
		}
	}
	dealokuj_liste(&czujnik1);
	dealokuj_liste(&czujnik2);
	dealokuj_liste(&czujnik3);
	dealokuj_liste(&czujnik4);
}