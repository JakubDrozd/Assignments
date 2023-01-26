

/*===========================================================================*/
/*                 ZADANIE z egzaminu z 2016/17 r., termin 1                 */
/*===========================================================================*/

// zadanie napisac z podzialem na funkcje

//#include <stdio.h>
//#include <stdlib.h>
//#define MAX 15
//#define MAX_LICZB 19
//
//void info() {
//	printf("Program wczytuje liczbe wierszy, tworzy tablice kwadratowa i uzupelnia ja wedlug polecenia.\nAutor: Jakub Drozd");
//}
//
//void stworzTab(int tab[][MAX], int n, int m) {
//	for (int i = 0; i < n; i++)
//	{
//		for (int  j = 0; j < m; j++)
//		{
//			if (i == 0)
//			{
//				tab[i][j] = j;
//			}
//			else if (j == 0)
//			{
//				tab[i][j] = i;
//			}
//			else
//			{
//				tab[i][j] = 0;
//			}
//		}
//	}
//}
//
//void wypiszTab(int tab[][MAX], int n, int m) {
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			printf("%4d ", tab[i][j]);
//		}
//		printf("\n");
//	}
//}
//
//int wczytajInt() {
//	int liczba;
//	while (scanf_s("%d", &liczba) != 1 || liczba < 5 || liczba > 15|| getchar() != '\n') {
//		printf("Bledne dane, podaj liczbe z przedzialu [5, 15]");
//		int c;
//		while ((c = getchar()) != '\n' && c != EOF)
//			;
//	}
//	return liczba;
//}
//
//void wypelnijTab(int tab[][MAX], int n, int m) {
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			if (tab[i][j] == 0)
//			{
//				int a = tab[i - 1][j];
//				int b = tab[i][j - 1];
//				tab[i][j] = abs(a - b) % 20;
//			}
//		}
//	}
//}
//
//void policzLiczby(int tab[][MAX], int n, int m, int tabCounter[MAX_LICZB]) {
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			if (i < j)
//			{
//				tabCounter[tab[i][j]] += 1;
//			}
//		}
//	}
//}
//
//void wypiszPoliczone(int tabCounter[MAX_LICZB], int n) {
//	for (int i = 0; i < n; i++)
//	{
//		if (tabCounter[i] > 0)
//		{
//			printf("%d: %d\n", i,  tabCounter[i]);
//		}
//	}
//}
//
//
//int main()
//{
//	info();
//	int tabCounter[MAX_LICZB] = {0};
//	int tab[MAX][MAX];
//	printf("\nPodaj liczbe wierszy [5, 15]: ");
//	int wiersze = wczytajInt();
//	printf("\n");
//	stworzTab(tab, wiersze, wiersze);
//	printf("\nPrzed wypelnieniem:\n");
//	wypiszTab(tab, wiersze, wiersze);
//	wypelnijTab(tab, wiersze, wiersze);
//	printf("\nPo wypelnieniu:\n");
//	wypiszTab(tab, wiersze, wiersze);
//	printf("\n");
//	policzLiczby(tab, wiersze, wiersze, &tabCounter);
//	wypiszPoliczone(tabCounter, MAX_LICZB);
//}


/*===========================================================================*/
/*                 ZADANIE z egzaminu z 2016/17 r., termin 2                 */
/*===========================================================================*/

// zadanie napisac z podzialem na funkcje


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 30
#define MAX_KORD 300

void info() {
	printf("Program wypisuje ilosc mozliwosci rozmieszczenia figury w kwadracie zdefiniowanym przez uzytkownika.\nAutor: Jakub Drozd\n");
}

int wczytajRozmiar() {
	int liczba;
	while (scanf_s("%d", &liczba)!=1 || liczba < 4 || liczba > 30 || getchar()!='\n')
	{
		printf("Bledne dane, podaj rozmiar kwadratu od 4 do 30: ");
		int c;
		while ((c = getchar())!='\n' && c!=EOF)
			;
	}
	return liczba;
}

void wczytajTablice(int tab[][MAX], int n, int m) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (i % 3 == 0)
			{
				tab[i][j] = rand() % (2 + 1 - 1) + 1;
			}
			else if (i % 3 == 1)
			{
				tab[i][j] = rand() % (3 + 1 - 2) + 2;
			}
			else
			{
				tab[i][j] = rand() % (3 + 1 - 1) + 1;
			}
		}
	}
}

void wypiszTablice(int tab[][MAX], int n, int m) {
	printf("%2s |", " ");
	for (int j = 0; j < m; j++)
	{
		printf("%3d", j);
	}
	printf("\n");
	for (int k = 0; k < 3 * n + 4; k++)
	{
		printf("-");
	}
	printf("\n");
	for (int i = 0; i < n; i++)
	{
		printf("%2d |", i);
		for (int j = 0; j < m; j++)
		{
			printf("%3d", tab[i][j]);
		}
		printf("\n");
	}
}


void ileFigur(int tab[][MAX], int n, int m) {
	int ilosc = 0;
	int iloscZWarunkiem = 0;
	int kordyX[MAX_KORD];
	int kordyY[MAX_KORD];
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (tab[i][j + 1] > 0 && tab[i + 1][j] > 0)
			{
				ilosc++;
			}
			if (tab[i][j+1] > 0 && tab[i][j+1]!=tab[i][j] && tab[i+1][j] > 0 && tab[i+1][j]!=tab[i][j] && tab[i+1][j]!=tab[i][j+1])
			{
				iloscZWarunkiem++;
				kordyX[k] = i+1;
				kordyY[k] = j;
				k++;
			}
		}
	}
	printf("\nWspolrzedne lewego dolnego rogu figur spelniajacych warunek:\n");
	for (int i = 0; i < k; i++)
	{
		printf("(%2d, %2d)\n", kordyX[i], kordyY[i]);
	}
	printf("ilosc wszystkich figur: %14d\n", ilosc);
	printf("ilosc figur spelniajacych warunek: %3d\n", iloscZWarunkiem);
}

int main()
{
	srand((unsigned)time(NULL));
	info();
	printf("Podaj rozmiar kwadratu: ");
	int tab[MAX][MAX];
	int rozmiar = wczytajRozmiar();
	wczytajTablice(tab, rozmiar, rozmiar);
	wypiszTablice(tab, rozmiar, rozmiar);
	ileFigur(tab, rozmiar, rozmiar);
}


/*===========================================================================*/
/*                 ZADANIE z egzaminu z 2017/18 r., termin 1                 */
/*===========================================================================*/

// zadanie napisac z podzialem na funkcje

//#include <stdio.h>
//
//int main()
//{
//
//}


/*===========================================================================*/
/*                 ZADANIE z egzaminu z 2017/18 r., termin 2                 */
/*===========================================================================*/

// zadanie napisac z podzialem na funkcje


//#include <stdio.h>
//
//int main()
//{
//
//}


/*===========================================================================*/
/*                 ZADANIE z egzaminu z 2018/19 r., termin 1                 */
/*===========================================================================*/

// zadanie napisac z podzialem na funkcje

//#include <stdio.h>
//
//int main()
//{
//
//}


/*===========================================================================*/
/*                 ZADANIE z egzaminu z 2018/19 r., termin 2                 */
/*===========================================================================*/

// zadanie napisac z podzialem na funkcje


//#include <stdio.h>
//
//int main()
//{
//
//}
