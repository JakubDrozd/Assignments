
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include <Windows.h>

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

void test_start(int liczba, int* punkty, double *czas_testu) {
	time_t start_testu;
	time_t koniec_testu;
	char odpowiedz;
	time(&start_testu);
	for (int i = 0; i < liczba ; i++)
	{
		char litera = rand() % (122 + 1 - 97) + 97;
		printf("%c\n", litera);
		odpowiedz = _getch();
		if (odpowiedz == litera)
		{
			(*punkty)++;
		}
	}
	time(&koniec_testu);
	*czas_testu = difftime(koniec_testu, start_testu);
	printf("Czas testu : %.1lf%c\n", *czas_testu, 's');
	printf("Wynik: %d\n", *punkty);
}

int main() {
	srand((unsigned)time(NULL));
	FILE* wyjscie;
	double czas_testu;
	char nick[25];
	podaj_nick(nick);
	printf("Nick: %s\n", nick);
	int liczba = podaj_liczbe();
	printf("Liczba: %d\n", liczba);
	int punkty = 0;
	test_start(liczba, &punkty, &czas_testu);
	char sciezka[30];
	sciezka[29] = '\0';
	strcpy_s(sciezka, sizeof(sciezka), nick);
	strcat_s(sciezka, sizeof(sciezka), ".txt");
	if (fopen_s(&wyjscie, sciezka, "r") != 0)
	{
		printf("!!!Plik nie istnieje, tworzenie nowego pliku!!!\n");
		wchar_t cwd[MAX_PATH];
		if (GetCurrentDirectory(MAX_PATH, cwd) != 0) {
			wprintf(L"Sciezka: %ls\n", cwd);
		}
		printf("\nNazwa pliku: %s\n", sciezka);
		fopen_s(&wyjscie, sciezka, "w");
	}
	else
	{
		printf("\nPlik juz instnieje\n");
		fclose(wyjscie);
		fopen_s(&wyjscie, sciezka, "a");
	}
	if (wyjscie == NULL)
	{
		printf("\nBlad otwarcia pliku\n");
		exit(0);
	}
	fprintf_s(wyjscie, "Czas: %.1lf%c | Punkty: %d/%d\n", czas_testu, 's', punkty, liczba);
	fclose(wyjscie);
	return 0;
}