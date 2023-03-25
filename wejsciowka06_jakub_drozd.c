#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pomiar {
	unsigned int nr_pomiaru;
	unsigned int nr_czujnika;
	char data_i_czas[20];
	double temp;
	struct pomiar* nastepny;
};

struct pomiar *dodaj_pomiar(unsigned int nr_pomiaru, unsigned int nr_czujnika, char data_i_czas[20], double temp) {
	struct pomiar* nowy_pomiar = NULL;
	nowy_pomiar = malloc(sizeof(struct pomiar));
	nowy_pomiar->nr_pomiaru = nr_pomiaru;
	nowy_pomiar->nr_czujnika = nr_czujnika;
	strcpy_s(nowy_pomiar->data_i_czas, sizeof(nowy_pomiar->data_i_czas), data_i_czas);
	nowy_pomiar->temp = temp;
	nowy_pomiar->nastepny = NULL;
	return nowy_pomiar;
}

void wypisz_liste(struct pomiar *pierwszy) {
	struct pomiar* aktualny = pierwszy;
	while (aktualny != NULL) {
		printf("%d %d %s %lf\n", aktualny->nr_pomiaru, aktualny->nr_czujnika, aktualny->data_i_czas, aktualny->temp);
		aktualny = aktualny->nastepny;
	}
}

void wpisz_liste_do_pliku(struct pomiar* pierwszy, FILE *wyjscie) {
	struct pomiar* aktualny = pierwszy;
	while (aktualny != NULL)
	{
		fprintf_s(wyjscie, "%d %d %s %lf\n", aktualny->nr_pomiaru, aktualny->nr_czujnika, aktualny->data_i_czas, aktualny->temp);
		aktualny = aktualny->nastepny;
	}
}

void przenies_pomiar(struct pomiar** pierwszy, struct pomiar** czujnik1, struct pomiar** czujnik2, struct pomiar** czujnik3, struct pomiar** czujnik4) {
	struct pomiar* aktualny;
	while (*pierwszy != NULL)
	{
		aktualny = *pierwszy;
		*pierwszy = aktualny->nastepny;
		aktualny->nastepny = NULL;
		if (aktualny->nr_czujnika == 1)
		{
			if (*czujnik1 == NULL)
			{
				*czujnik1 = aktualny;
			}
			else
			{
				struct pomiar* kolejny = *czujnik1;
				while (kolejny->nastepny != NULL)
				{
					kolejny = kolejny->nastepny;
				}
				kolejny->nastepny = aktualny;
			}
		}
		else if (aktualny->nr_czujnika == 2)
		{
			if (*czujnik2 == NULL)
			{
				*czujnik2 = aktualny;
			}
			else
			{
				struct pomiar* kolejny = *czujnik2;
				while (kolejny->nastepny != NULL)
				{
					kolejny = kolejny->nastepny;
				}
				kolejny->nastepny = aktualny;
			}
		} else if (aktualny->nr_czujnika == 3)
		{
			if (*czujnik3 == NULL)
			{
				*czujnik3 = aktualny;
			}
			else
			{
				struct pomiar* kolejny = *czujnik3;
				while (kolejny->nastepny != NULL)
				{
					kolejny = kolejny->nastepny;
				}
				kolejny->nastepny = aktualny;
			}
		} else if (aktualny->nr_czujnika == 4)
		{
			if (*czujnik4 == NULL)
			{
				*czujnik4 = aktualny;
			}
			else
			{
				struct pomiar* kolejny = *czujnik4;
				while (kolejny->nastepny != NULL)
				{
					kolejny = kolejny->nastepny;
				}
				kolejny->nastepny = aktualny;
			}
		}
	}
}

int policz_rozmiar(struct pomiar* pierwszy) {
	int rozmiar = 0;
	struct pomiar* aktualny = pierwszy;
	while (aktualny != NULL) {
		rozmiar++;
		aktualny = aktualny->nastepny;
	}
	return rozmiar;
}

void zdealokuj_liste(struct pomiar* pierwszy) {
	struct pomiar* aktualny = pierwszy;
	while (aktualny != NULL)
	{
		struct pomiar* temp = aktualny;
		aktualny = aktualny->nastepny;
		free(temp);
	}
}

int main(){
	FILE* wejscie;
	char sciezka[90];
	printf("Podaj sciezke pliku: ");
	while (scanf_s("%89s", sciezka, 89)!=1 || getchar()!='\n')
	{
		printf("Podaj sciezke pliku: ");
		int c;
		while ((c = getchar()) != '\n' && c != EOF)
			;
	}
	sciezka[89] = '\0';
	if (fopen_s(&wejscie, sciezka, "r")!= 0)
	{
		printf("Nie udalo sie otworzyc pliku wejsciowego.");
		exit(0);
	}
	else
	{
		printf("\nPomyslnie otworzono plik\n");
	}
	unsigned int nr_pomiaru;
	unsigned int nr_czujnika;
	char data_i_czas[20];
	double temp;
	struct pomiar* nastepny = NULL;
	struct pomiar* pierwszy = NULL;
	struct pomiar* nowy = NULL;
	struct pomiar* czujnik1 = NULL;
	struct pomiar* czujnik2 = NULL;
	struct pomiar* czujnik3 = NULL;
	struct pomiar* czujnik4 = NULL;
	while (fscanf_s(wejscie, "%d %d %s %lf", &nr_pomiaru, &nr_czujnika, data_i_czas, (unsigned)sizeof(data_i_czas), &temp) == 4)
	{
		if (pierwszy == NULL)
		{
			pierwszy = dodaj_pomiar(nr_pomiaru, nr_czujnika, data_i_czas, temp);
			if (pierwszy != NULL)
			{
				nowy = pierwszy;
			}
		}
		else
		{
			nowy->nastepny = dodaj_pomiar(nr_pomiaru, nr_czujnika, data_i_czas, temp);
			if (nowy->nastepny != NULL)
			{
				nowy = nowy->nastepny;
			}
		}
	}
	przenies_pomiar(&pierwszy, &czujnik1, &czujnik2, &czujnik3, &czujnik4);
	printf("Ilosc pomiarow dla kazdego czujnika:\nCzujnik 1: %d\nCzujnik 2: %d\nCzujnik 3: %d\nCzujnik 4: %d\n", policz_rozmiar(czujnik1), policz_rozmiar(czujnik2), policz_rozmiar(czujnik3), policz_rozmiar(czujnik4));
	char nazwa[70];
	char nazwa_pliku[80];
	printf("\nPodaj nazwe pliku wyjsciowego: \n");
	scanf_s("%s", nazwa, 70);
	FILE* wyjscie1 = NULL;
	FILE* wyjscie2 = NULL;
	FILE* wyjscie3 = NULL;
	FILE* wyjscie4 = NULL;
	for (int i = 1; i <= 4; i++)
	{
		sprintf_s(nazwa_pliku, sizeof(nazwa_pliku), "%s%d.txt", nazwa, i);
		if (i == 1)
		{
			fopen_s(&wyjscie1, nazwa_pliku, "w");
			wpisz_liste_do_pliku(czujnik1, wyjscie1);

		} 
		else if (i == 2)
		{
			fopen_s(&wyjscie2, nazwa_pliku, "w");
			wpisz_liste_do_pliku(czujnik2, wyjscie2);

		}
		else if (i == 3)
		{
			fopen_s(&wyjscie3, nazwa_pliku, "w");
			wpisz_liste_do_pliku(czujnik3, wyjscie3);

		}
		else if (i == 4)
		{
			fopen_s(&wyjscie4, nazwa_pliku, "w");
			wpisz_liste_do_pliku(czujnik4, wyjscie4);

		}
	}
	fclose(wejscie);
	fclose(wyjscie1);
	fclose(wyjscie2);
	fclose(wyjscie3);
	fclose(wyjscie4);
	zdealokuj_liste(czujnik1);
	zdealokuj_liste(czujnik2);
	zdealokuj_liste(czujnik3);
	zdealokuj_liste(czujnik4);
	printf("\nKoniec programu\n");
	return 0;
}