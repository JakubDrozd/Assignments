//
//#include <stdio.h>
//#include <stdlib.h>
//#include <assert.h>
//#include <time.h>
//#include <conio.h>
//#include <string.h>
//#include <Windows.h>
//
//void loguj(char* akcja) {
//	FILE* log;
//	time_t czas;
//	char czas_str[30];
//	char err_msg[100];
//	time(&czas);
//	struct tm local_time;
//	if (localtime_s(&local_time, &czas) != 0) {
//		strerror_s(err_msg, sizeof(err_msg), errno);
//		fprintf(stderr, "Blad funkcji localtime_s: %s\n", err_msg);
//		return;
//	}
//	if (strftime(czas_str, sizeof(czas_str), "%Y-%m-%d %H:%M:%S", &local_time) == 0) {
//		fprintf(stderr, "Blad funkcji strftime\n");
//		return;
//	}
//	errno_t err;
//	if ((err = fopen_s(&log, "log.txt", "a")) != 0) {
//		strerror_s(err_msg, sizeof(err_msg), err);
//		fprintf(stderr, "Blad otwarcia pliku: %s\n", err_msg);
//		return;
//	}
//	if (log != NULL) {
//		fprintf(log, "[%s] | %s\n", czas_str, akcja);
//		fclose(log);
//	}
//	else {
//		strerror_s(err_msg, sizeof(err_msg), errno);
//		fprintf(stderr, "Blad funkcji fopen_s: %s\n", err_msg);
//	}
//}
//
//char podaj_nick(char nick[]) {
//	nick[24] = '\0';
//	scanf_s("%s", nick, 25);
//	return *nick;
//}
//
//int podaj_liczbe() {
//	int liczba;
//	scanf_s("%d", &liczba);
//	assert(liczba >= 1);
//	return liczba;
//}
//
//void wypisz_tab(double tab[], int m) {
//	for (int i = 0; i < m; i++)
//	{
//		printf("%lf ", tab[i]);
//	}
//}
//
//void test_start(int liczba, int* punkty, double *czas_testu) {
//	time_t start_testu;
//	time_t koniec_testu;
//	char odpowiedz;
//	time(&start_testu);
//	for (int i = 0; i < liczba ; i++)
//	{
//		char litera = rand() % (122 + 1 - 97) + 97;
//		printf("%c\n", litera);
//		loguj("Wypisanie litery na ekran");
//		odpowiedz = _getch();
//		if (odpowiedz == litera)
//		{
//			(*punkty)++;
//			loguj("Podanie poprawnej odpowiedzi");
//		}
//		else
//		{
//			loguj("Podanie blednej odpowiedzi");
//		}
//	}
//	time(&koniec_testu);
//	*czas_testu = difftime(koniec_testu, start_testu);
//	printf("Czas testu : %.1lf%c\n", *czas_testu, 's');
//	printf("Wynik: %d\n", *punkty);
//}
//
//int main() {
//	srand((unsigned)time(NULL));
//	FILE* wyjscie;
//	double czas_testu;
//	char nick[25];
//	podaj_nick(nick);
//	printf("Nick: %s\n", nick);
//	loguj("Pobranie nick'a");
//	int liczba = podaj_liczbe();
//	printf("Liczba: %d\n", liczba);
//	loguj("Pobranie liczby");
//	int punkty = 0;
//	test_start(liczba, &punkty, &czas_testu);
//	char sciezka[30];
//	sciezka[29] = '\0';
//	strcpy_s(sciezka, sizeof(sciezka), nick);
//	strcat_s(sciezka, sizeof(sciezka), ".txt");
//	if (fopen_s(&wyjscie, sciezka, "r") != 0)
//	{
//		printf("!!!Plik nie istnieje, tworzenie nowego pliku!!!\n");
//		wchar_t cwd[MAX_PATH];
//		if (GetCurrentDirectory(MAX_PATH, cwd) != 0) {
//			wprintf(L"Sciezka: %ls\n", cwd);
//		}
//		printf("\nNazwa pliku: %s\n", sciezka);
//		fopen_s(&wyjscie, sciezka, "w");
//	}
//	else
//	{
//		printf("\nPlik juz instnieje\n");
//		fclose(wyjscie);
//		fopen_s(&wyjscie, sciezka, "a");
//	}
//	if (wyjscie == NULL)
//	{
//		printf("\nBlad otwarcia pliku\n");
//		exit(0);
//	}
//	fprintf_s(wyjscie, "Czas: %.1lf%c | Punkty: %d/%d\n", czas_testu, 's', punkty, liczba);
//	fclose(wyjscie);
//	return 0;
//}