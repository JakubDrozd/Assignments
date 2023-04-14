
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <conio.h>

char podaj_nick(char nick[]) {
	nick[24] = '\0';
	scanf_s("%s", nick, 25);
	return *nick;
}

int podaj_liczbe() {
	int liczba;
	scanf_s("%d", &liczba);
	assert(liczba >= 1);
	return liczba;
}

void wypisz_tab(double tab[], int m) {
	for (int i = 0; i < m; i++)
	{
		printf("%lf ", tab[i]);
	}
}

void test_start(int liczba, double wyniki[], int* punkty) {
	time_t start;
	time_t koniec;
	double czas;
	char odpowiedz;

	for (int i = 0; i < liczba ; i++)
	{
		char litera = rand() % (122 + 1 - 97) + 97;
		printf("%c\n", litera);
		time(&start);
		odpowiedz = _getch();
		time(&koniec);
		if (odpowiedz == litera)
		{
			(*punkty)++;
		}
		czas = difftime(koniec, start);
		wyniki[i] = czas;
	}
}

int main() {
	srand((unsigned)time(NULL));
	char nick[25];
	podaj_nick(nick);
	printf("Nick: %s\n", nick);
	int liczba = podaj_liczbe();
	printf("Liczba: %d\n", liczba);
	double* wyniki = malloc(liczba * sizeof(double));
	int punkty = 0;
	test_start(liczba, wyniki, &punkty);
	printf("\n\n");
	wypisz_tab(wyniki, liczba);
	printf("\nWynik: %d", punkty);
	return 0;
}