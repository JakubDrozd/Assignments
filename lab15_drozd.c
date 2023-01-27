

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


//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//
//#define MAX 30
//#define MAX_KORD 300
//
//void info() {
//	printf("Program wypisuje ilosc mozliwosci rozmieszczenia figury w kwadracie zdefiniowanym przez uzytkownika.\nAutor: Jakub Drozd\n");
//}
//
//int wczytajRozmiar() {
//	int liczba;
//	while (scanf_s("%d", &liczba)!=1 || liczba < 4 || liczba > 30 || getchar()!='\n')
//	{
//		printf("Bledne dane, podaj rozmiar kwadratu od 4 do 30: ");
//		int c;
//		while ((c = getchar())!='\n' && c!=EOF)
//			;
//	}
//	return liczba;
//}
//
//void wczytajTablice(int tab[][MAX], int n, int m) {
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			if (i % 3 == 0)
//			{
//				tab[i][j] = rand() % (2 + 1 - 1) + 1;
//			}
//			else if (i % 3 == 1)
//			{
//				tab[i][j] = rand() % (3 + 1 - 2) + 2;
//			}
//			else
//			{
//				tab[i][j] = rand() % (3 + 1 - 1) + 1;
//			}
//		}
//	}
//}
//
//void wypiszTablice(int tab[][MAX], int n, int m) {
//	printf("%2s |", " ");
//	for (int j = 0; j < m; j++)
//	{
//		printf("%3d", j);
//	}
//	printf("\n");
//	for (int k = 0; k < 3 * n + 4; k++)
//	{
//		printf("-");
//	}
//	printf("\n");
//	for (int i = 0; i < n; i++)
//	{
//		printf("%2d |", i);
//		for (int j = 0; j < m; j++)
//		{
//			printf("%3d", tab[i][j]);
//		}
//		printf("\n");
//	}
//}
//
//
//void ileFigur(int tab[][MAX], int n, int m) {
//	int ilosc = 0;
//	int iloscZWarunkiem = 0;
//	int kordyX[MAX_KORD];
//	int kordyY[MAX_KORD];
//	int k = 0;
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			if (tab[i][j + 1] > 0 && tab[i + 1][j] > 0)
//			{
//				ilosc++;
//			}
//			if (tab[i][j+1] > 0 && tab[i][j+1]!=tab[i][j] && tab[i+1][j] > 0 && tab[i+1][j]!=tab[i][j] && tab[i+1][j]!=tab[i][j+1])
//			{
//				iloscZWarunkiem++;
//				kordyX[k] = i+1;
//				kordyY[k] = j;
//				k++;
//			}
//		}
//	}
//	printf("\nWspolrzedne lewego dolnego rogu figur spelniajacych warunek:\n");
//	for (int i = 0; i < k; i++)
//	{
//		printf("(%2d, %2d)\n", kordyX[i], kordyY[i]);
//	}
//	printf("ilosc wszystkich figur: %14d\n", ilosc);
//	printf("ilosc figur spelniajacych warunek: %3d\n", iloscZWarunkiem);
//}
//
//int main()
//{
//	srand((unsigned)time(NULL));
//	info();
//	printf("Podaj rozmiar kwadratu: ");
//	int tab[MAX][MAX];
//	int rozmiar = wczytajRozmiar();
//	wczytajTablice(tab, rozmiar, rozmiar);
//	wypiszTablice(tab, rozmiar, rozmiar);
//	ileFigur(tab, rozmiar, rozmiar);
//}


/*===========================================================================*/
/*                 ZADANIE z egzaminu z 2017/18 r., termin 1                 */
/*===========================================================================*/

// zadanie napisac z podzialem na funkcje

//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//
//#define MAX 10
//#define MAX_KORDOW 6
//
//void info() {
//	printf("Program symuluje prosta gre w statki.\nAutor: Jakub Drozd\n");
//}
//
//void rozmiescStatki(int plansza[][MAX], int n, int m) {
//	int iloscStatkow = 0;
//	int tabKordowX[MAX_KORDOW] = {0};
//	int tabKordowY[MAX_KORDOW] = {0};
//	int k = 0;
//	printf("Pierwsza liczba w parze oznacza nr wiersza, a druga kolumny. Numeracja od 0.\n\n");
//	printf("Ustawianie - proby losowan:\n\n");
//	while (iloscStatkow < 6)
//	{
//		int kordX = rand() % (7 + 1 - 1) + 1;
//		int kordY = rand() % (7 + 1 - 1) + 1;
//		if (plansza[kordX][kordY] == 0 && plansza[kordX + 1][kordY + 1] == 0)
//		{
//			plansza[kordX][kordY] = 1;
//			plansza[kordX + 1][kordY + 1] = 1;
//			iloscStatkow++;
//			tabKordowX[k] = kordX;
//			tabKordowY[k] = kordY;
//			printf("(%d, %d)ok ", kordX, kordY);
//			k++;
//		}
//		else
//		{
//			printf("(%d, %d) ", kordX, kordY);
//		}
//	}
//	printf("\nRozmieszczenie statkow\n(podano wspolrzedne lewego gornego pola):\n\n");
//	for (int i = 0; i < k; i++)
//	{
//		printf("(%d, %d) ", tabKordowX[i], tabKordowY[i]);
//	}
//	printf("\n");
//}
//
//void wypiszTablice(int plansza[][MAX], int n, int m) {
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			printf("%2d", plansza[i][j]);
//		}
//		printf("\n");
//	}
//}
//
//void strzelaj(int plansza[][MAX], int n, int m) {
//	int iloscTrafien = 0;
//	int tabKordowX[MAX_KORDOW] = { 0 };
//	int tabKordowY[MAX_KORDOW] = { 0 };
//	int k = 0;
//	printf("Strzaly:\n");
//	for (int i = 0; i < 40; i++)
//	{
//		int kordX = rand() % (7 + 1 - 1) + 1;
//		int kordY = rand() % (7 + 1 - 1) + 1;
//		if (plansza[kordX][kordY] == 1 && (plansza[kordX + 1][kordY + 1] == 1 && (plansza[kordX - 1][kordY - 1])))
//		{
//			plansza[kordX][kordY] = 0;
//			plansza[kordX - 1][kordY - 1] = 0;
//			iloscTrafien++;
//			printf("(%d, %d) trafiony(%d)\n", kordX, kordY, iloscTrafien);
//		}
//		else if (plansza[kordX][kordY] == 1 && (plansza[kordX + 1][kordY + 1] == 1))
//		{
//			plansza[kordX][kordY] = 0;
//			plansza[kordX + 1][kordY + 1] = 0;
//			iloscTrafien++;
//			printf("(%d, %d) trafiony(%d)\n", kordX, kordY, iloscTrafien);
//		}
//		else if (plansza[kordX][kordY] == 1 && (plansza[kordX - 1][kordY - 1] == 1))
//		{
//			plansza[kordX][kordY] = 0;
//			plansza[kordX - 1][kordY - 1] = 0;
//			iloscTrafien++;
//			printf("(%d, %d) trafiony(%d)\n", kordX, kordY, iloscTrafien);
//		}
//		else
//		{
//			printf("(%d, %d) pudlo\n", kordX, kordY);
//		}
//	}
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			if (plansza[i][j] == 1 && plansza[i+1][j+1] == 1)
//			{
//				tabKordowX[k] = i;
//				tabKordowY[k] = j;
//				k++;
//			}
//		}
//	}
//	if (iloscTrafien == 6)
//	{
//		printf("Wygrales!.");
//	}
//	else
//	{
//		printf("\nRozmieszczenie pozostalych statkow\n(podano wspolrzedne lewego gornego pola):\n\n");
//		for (int i = 0; i < k; i++)
//		{
//			printf("(%d, %d) ", tabKordowX[i], tabKordowY[i]);
//		}
//		printf("\n");
//		printf("\nNiestety przegrales...\n");
//	}
//}
//
//int main()
//{
//	info();
//	srand((unsigned)time(NULL));
//	int plansza[MAX][MAX] = { 0 };
//	printf("\n");
//	rozmiescStatki(plansza, MAX, MAX);
//	printf("\n");
//	wypiszTablice(plansza, MAX, MAX);
//	printf("\n");
//	strzelaj(plansza, MAX, MAX);
//	wypiszTablice(plansza, MAX, MAX);
//	printf("\n\nKoniec programu\n\n");
//	return 0;
//}


/*===========================================================================*/
/*                 ZADANIE z egzaminu z 2017/18 r., termin 2                 */
/*===========================================================================*/

// zadanie napisac z podzialem na funkcje


//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//#define MAX_ROWS 100
//#define MAX_COLS 49
//#define MAX_NUMERKI 6
//
//
//void info() {
//	printf("Program symuluje gre w totolotka.\nAutor: Jakub Drozd\n");
//}
//
//
//
//
//void wypiszArray1D(int los[], int n) {
//	for (int i = 0; i < n; i++)
//	{
//		if (i == n-1)
//		{
//			printf("%d", los[i]);
//		}
//		else
//		{
//		printf("%d, ", los[i]);
//		}
//	}
//	printf("\n");
//}
//
//void zakreslanie(int tab[][MAX_COLS], int n, int m) {
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < MAX_NUMERKI; j++)
//		{
//			int random = rand() % (47 + 1 - 1) + 1;
//			tab[i][random] = 1;
//		}
//	}
//}
//
//void losujNumerki(int los[MAX_NUMERKI], int n) {
//	int coBylo[MAX_COLS] = {0};
//	for (int i = 0; i < n; i++)
//	{
//		int losowaLiczba = rand() % (49 + 1 - 1) + 1;
//		for (int j = 0; j < MAX_COLS; j++)
//		{
//			if (coBylo[j] == losowaLiczba);
//			else
//			{
//				los[i] = losowaLiczba;
//			}
//		}
//	}
//}
//
//void sprawdzanieWygranych(int kupony[][MAX_COLS], int los[MAX_NUMERKI], int n, int m) {
//	int iloscWin = 0;
//	int iloscUczestnikow = MAX_ROWS;
//	for (int i = 0; i < n; i++)
//	{
//		int liczby[MAX_NUMERKI] = { 0 };
//		int k = 0;
//		for (int j = 0; j < m; j++)
//		{
//			if (kupony[i][j] == 1)
//			{
//				liczby[k] = j + 1;
//				k++;
//			}
//		}
//		if (k < MAX_NUMERKI)
//		{
//			for (int l = 0; l < k; l++)
//			{
//				printf("%6d ", liczby[l]);
//			}
//			iloscUczestnikow--;
//			printf("%6s - blednie wypelniony kupon\n", " ");
//		}
//		else
//		{
//			int iloscTrafien = 0;
//			for (int l = 0; l < k; l++)
//			{
//				printf("%6d ", liczby[l]);
//			}
//			for (int o = 0; o < MAX_NUMERKI; o++)
//			{
//				for (int p = 0;  p < MAX_NUMERKI;  p++)
//				{
//					if (liczby[o] == los[p])
//					{
//						iloscTrafien++;
//					}
//				}
//			}
//			if (iloscTrafien == MAX_NUMERKI)
//			{
//				printf(" - ilosc trafien: %d [Wygrana!]", iloscTrafien);
//				printf("\n");
//				iloscWin++;
//			}
//			else
//			{
//			printf(" - ilosc trafien: %d", iloscTrafien);
//			printf("\n");
//			}	
//		}
//	}
//	printf("\n\nIlosc zwyciezcow: %d/%d\n\n", iloscWin, iloscUczestnikow);
//}
//
//int main()
//{
//	srand((unsigned)time(NULL));
//	info();
//	int kupony[MAX_ROWS][MAX_COLS] = { 0 };
//	int los[MAX_NUMERKI];
//	zakreslanie(kupony, MAX_ROWS, MAX_COLS);
//	losujNumerki(los, MAX_NUMERKI);
//	printf("\n\nMaszyna wylosowala nastepujace liczby:\n\n");
//	wypiszArray1D(los, MAX_NUMERKI);
//	printf("\n");
//	sprawdzanieWygranych(kupony, los, MAX_ROWS, MAX_COLS);
//	printf("\n\nKoniec programu.\n\n");
//	return 0;
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
