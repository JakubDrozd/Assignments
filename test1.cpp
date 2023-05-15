////#include <stdio.h>
////#include <stdlib.h>
////
////struct pomiar {
////	unsigned int nr_pomiaru;
////	unsigned int nr_czujnika;
////	char data_i_czas[20];
////	double temp;
////	struct pomiar* nastepny;
////	struct pomiar* poprzedni;
////};
////
////struct pomiar* dodaj_pomiar(unsigned int nr_pomiaru,
////	unsigned int nr_czujnika,
////	char data_i_czas[20],
////	double temp) {
////
////}
////
////struct pomiar* wczytaj_plik(char nazwa[20]) {
////	FILE* wejscie;
////	struct pomiar* pierwszy = NULL;
////	struct pomiar* ostatni = NULL;
////	if (fopen_s(&wejscie, nazwa, "r") != 0)
////	{
////		printf("\nBlad wczytywania pliku\n");
////		exit(0);
////	}
////	else
////	{
////		printf("\nOtwarto plik\n");
////	}
////	unsigned int nr_pomiaru;
////	unsigned int nr_czujnika;
////	char data_i_czas[20];
////	double temp;
////	while (fscanf_s(wejscie, "%d %d %s %lf", &nr_pomiaru, &nr_czujnika, data_i_czas, (unsigned)sizeof(data_i_czas), &temp) == 4)
////	{
////
////	}
////}
////
////int main() {
////	return 0;
////}
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <assert.h>
//#include <time.h>
//#include <conio.h>
//#include <string.h>
//#include <Windows.h>
//
//
//int main() {
//	time_t start;
//	time_t finish;
//	char czas_str[30];
//	struct tm local_start;
//	struct tm local_finish;
//	time(&start);
//	localtime_s(&local_start, &start);
//	for (int i = 0; i < 10000; i++)
//	{
//		printf("%d\n", i);
//	}
//	time(&finish);
//	localtime_s(&local_finish, &finish);
//	double czas;
//	strftime(czas_str, sizeof(czas_str), "%H:%M:%S", &local_start);
//	printf("Start: %s\n", czas_str);
//	strftime(czas_str, sizeof(czas_str), "%H:%M:%S", &local_finish);
//	printf("Finish: %s\n", czas_str);
//	printf("%lf", czas = difftime(finish, start));
//}