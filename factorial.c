//#include <stdio.h>
//#include <stdlib.h>
//#include <ctype.h>
//#include <time.h>
//enum {a = 3, b = 5, c = 11};

//int a;						/*1*/
//main() {						/*2*/
//	int x;						/*3*/
//	...							/*4*/
//		if (...) {				/*5*/
//			static int i;		 /*6*/
//			int y, z;			 /*7*/
//			...					/*8*/
//		}						/*9*/
//}

//1. lokalne: x, i, y, z		globalne: a
//2. a(1-10), x(3-10), i(6-9), y(7-9), z(7-9)
//3. statyczne: a, i		dynamiczne ze stosu: x, y, z
//4. a - alokacja PWP (w stercie), dealokacja przy wykonaniu
//	 x - alokacja 3, dealokacja 10
//	 i - alokacja PWP (w stercie), dealokacja przy wykonaniu
//   y, z - alokacja 7, dealokacja 9

//main() {
//	int x = 2, y = 3, * w1, * w2; /*1*/
//	w1 = &x; /*2*/
//	w2 = w1; /*3*/
//	y = *w1; /*4*/
//	*w2 = 7; /*5*/
//	w2 = &y; /*6*/
//	*w2 = 8; /*7*/
//	*w2 = *w1; /*8*/
//	printf("%d %d", x, y);
//	return 0;
//}

//x = 7
//y = 7
//w1 = x
//w2 = y

//int main() {
//	int* wsk;
//	int x;
//	wsk = (int*)malloc(sizeof(int));
//	if (wsk == NULL)
//	{
//		printf("Blad alokacji.\n");
//		return 0;
//	}
//	*wsk = 7;
//	free(wsk);
//	wsk = &x;
//	*wsk = 8;
//	printf("%d", x);
//	return 0;
//}

//main() { /*0*/
//	int* w1, * w2; /*1*/
//	w1 = (int*)malloc(sizeof(int)); /*2*/
//	w2 = w1; /*3*/
//	free(w1); /*4*/
//	/*5*/
//}/*7*/

//enum {D = 2, E, F =2 , G};
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//int main() {
//	srand((unsigned)time(NULL));
//	int** tab;
//	int n = 3;
//	int m = 10;
//	tab = (int*)malloc(n * sizeof(int));
//	if (tab == NULL)
//	{
//		printf("Brak pamieci");
//		return 0;
//	}
//	tab[0] = (int*)malloc(n * m * sizeof(int));
//	if (tab[0] == NULL)
//	{
//		printf("Brak pamieci");
//		free(tab);
//		return 0;
//	}
//	for (int i = 1; i < n; i++)
//	{
//		tab[i] = tab[0] + i * n;
//	}
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j  < m; j ++)
//		{
//			tab[i][j] = rand() % (10 + 1 - 1) + 1;
//			printf("%3d ", tab[i][j]);
//		}
//		printf("\n");
//	}
//	printf("%d ", (-3) / 2);
//	printf("\n\nKoniec programu\n\n");
//	return 0;
//}

//#include <stdio.h>
//main (){
//enum {x, y} a = -1, b = -2;
//printf("%d %d", a, b);
//}


//#include <stdio.h>
//
//int main() {
//	char dd = 'd';
//	printf("%d", dd++ - 'c');
//}

//#include <stdio.h>
//
//int main() {
//	static int a = 0;
//	static int b = 1;
//	switch (2 * a + 1) {
//	case 1:
//		b += 2;
//		break;
//	case 2:
//		b += 4;
//	case 3:
//		b += 3;
//		break;
//	}
//	printf("a = %d, b = %d\n", a, b);
//	return 0;
//}

//#include <stdio.h>
//#define MAX 40
//
//void info() {
//	printf("Program pobiera od uzytkownika liczbe z przedzialu [2,20] i uklada tablie w okreslony sposob.\nAutor: Jakub Drozd");
//}
//
//int wczytajLiczbe() {
//	int liczba;
//	while (scanf_s("%d", &liczba) != 1 || liczba < 2 || liczba > 20 || getchar() != '\n') {
//		printf("Bledne dane, podaj liczbe calkowita z przedzialu [2,20]: ");
//		int c;
//		while ((c = getchar()) != '\n' && c != EOF)
//			;
//	}
//	return liczba;
//}
//
//void wczytajTab(int tab[][MAX], int m, int n) {
//	int polowa = n / 2;
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			if (j < polowa && i >=j)
//			{
//				tab[i][j] = i + 1;
//			}
//			else if (j >= polowa && i + j >= n - 1)
//			{
//				tab[i][j] = i + 1;
//			}
//			else
//			{
//				tab[i][j] = 0;
//			}
//		}
//	}
//}
//
//void wypiszTab(int tab[][MAX], int m, int n) {
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			printf("%2d ", tab[i][j]);
//		}
//		printf("\n");
//	}
//}
//
//int main() {
//	info();
//	printf("\nPodaj dowolna liczbe calkowita z przedzialu [2, 20]: ");
//	int tab[MAX][MAX];
//	int n = wczytajLiczbe();
//	wczytajTab(tab, n, n * 2);
//	wypiszTab(tab, n, n * 2);
//	printf("\n\nKoniec programu\n\n");
//	return 0;
//}

//#include <stdio.h>
//#define MAX 10
//
//void info() {
//	printf("Program wczytuje ablice 10x10 i sprawdza, czy posiada ona okreslona wlasnosc.\nAutor: Jakub Drozd\n");
//}
//
//int wczytajLiczbe() {
//	int liczba;
//	while (scanf_s("%d", &liczba)!=1 || getchar()!='\n')
//	{
//		printf("Bledne dane, podaj dowolna liczbe calkowita: ");
//		int c;
//		while ((c = getchar()) != '\n' && c != EOF)
//			;
//	}
//	return liczba;
//}
//
//void wypiszTab2D(int tab[][MAX], int m, int n);
//
//void wczytajTab(int tab[][MAX], int m, int n) {
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			printf("Podaj element tablicy: ");
//			tab[i][j] = wczytajLiczbe();
//		}
//	}
//}
//
//void wypiszTab1D(int tab[], int m) {
//	for (int i = 0; i < m; i++)
//	{
//		printf("%2d ", tab[i]);
//	}
//}
//
//void wypiszTab2D(int tab[][MAX], int m, int n) {
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			printf("%2d ", tab[i][j]);
//		}
//		printf("\n");
//	}
//}
//
//void sprawdzWarunek(int tab[][MAX], int m, int n, int tab_failed[]) {
//	int k = 0;
//	for (int i = 0; i < m; i++)
//	{
//		int sumaWiersza = 0;
//		int liczbaNaPrzekatnej;
//		for (int j = 0; j < n; j++)
//		{
//			if (i == j)
//			{
//				liczbaNaPrzekatnej = tab[i][j];
//			}
//			if (tab[i][j] > 0 && i!=j)
//			{
//				sumaWiersza += tab[i][j];
//			}
//		}
//		if (!(liczbaNaPrzekatnej > sumaWiersza))
//		{
//			tab_failed[k] = i;
//			k++;
//		}
//	}
//}
//
//int main() {
//	info();
//	int tab[MAX][MAX] = { 0 };
//	int tab_failed[MAX] = { -1 };
//	wczytajTab(tab, MAX, MAX);
//	wypiszTab2D(tab, MAX, MAX);
//	sprawdzWarunek(tab, MAX, MAX, tab_failed);
//	if (tab_failed[0] < 0)
//	{
//		printf("Tablica spelnia wlanosc.");
//	}
//	else
//	{
//		printf("Numery wierszy, ktore nie spelnily warunku:\n");
//		wypiszTab1D(tab_failed, MAX);
//	}
//	printf("\n\nKoniec programu\n\n");
//	return 0;
//}

//#include <limits.h>
//#include <stdio.h>
//
//#define MAX 100
//
//void info() {
//	printf("Program daje uzytkownikowi stworzyc tablie prostokatna, znajduje najwieksza wartosc w ostatniej kolumnie i wypisuje wiersze, ktorych wszystkie elementy sa mniejsze od tej wartosci.\nAutor: Jakub Drozd\n");
//}
//
//int wczytajRozmiar() {
//	int liczba;
//	while (scanf_s("%d", &liczba)!=1 || liczba < 2 || liczba > 100 || getchar()!='\n')
//	{
//		printf("Bledne dane, podaj rozmiar z przedzialu [2,100]: ");
//		int c;
//		while ((c = getchar()) != '\n' && c != EOF)
//			;
//	}
//	return liczba;
//}
//
//int wczytajLiczbe() {
//	int liczba;
//	while (scanf_s("%d", &liczba) != 1 || getchar() != '\n')
//	{
//		printf("Bledne dane, podaj rozmiar z przedzialu [2,100]: ");
//		int c;
//		while ((c = getchar()) != '\n' && c != EOF)
//			;
//	}
//	return liczba;
//}
//
//void wczytajTab(int tab[][MAX], int m, int n) {
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			printf("Podaj wartosc dla [%d][%d] elementu: ", i, j);
//			tab[i][j] = wczytajLiczbe();
//		}
//	}
//}
//
//void wypiszTab1D(int tab[], int k) {
//	for (int i = 0; i < k; i++)
//	{
//		printf("%2d ", tab[i]);
//	}
//}
//
//void znajdzMaxa(int tab[][MAX], int m, int n, int* max) {
//	*max = tab[0][n - 1];
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			if (j == (n-1))
//			{
//				if (tab[i][j] > *max)
//				{
//					*max = tab[i][j];
//				}
//			}
//		}
//	}
//}
//
//void sprawdzWiersze(int tab[][MAX], int m, int n, int* k, int max, int tab_wierszy[]) {
//	for (int i = 0; i < m; i++)
//	{
//		int maxWiersza = INT_MIN;
//		for (int j = 0; j < n; j++)
//		{
//			if (tab[i][j] > maxWiersza)
//			{
//				maxWiersza = tab[i][j];
//			}
//		}
//		if (maxWiersza < max)
//		{
//			tab_wierszy[*k] = i;
//			(*k)++;
//		}
//	}
//}
//
//int tab[MAX][MAX];
//int tab_wierszy[MAX];
//
//int main() {
//	int max = 0;
//	int k = 0;
//	info();
//	printf("Podaj ilosc wierszy: ");
//	int m = wczytajRozmiar();
//	printf("Podaj ilosc kolumn: ");
//	int n = wczytajRozmiar();
//	while (n == m)
//	{
//		printf("\nTablica musi byc prostokatna, podaj inna ilosc kolumn:\n");
//		n = wczytajRozmiar();
//	}
//	wczytajTab(tab, m, n);
//	znajdzMaxa(tab, m, n, &max);
//	sprawdzWiersze(tab, m, n, &k, max, tab_wierszy);
//	printf("\nWiersze, ktore spelnily warunek:\n");
//	wypiszTab1D(tab_wierszy, k);
//	printf("\nKoniec programu\n");
//	return 0;
//}


//#include <stdio.h>
//#define MAX 30
//
//void info() {
//	printf("Program tworzy tablice 30x30, czesciowo zdefiniowana przez uzytknownika i sprawdza czy zachodzi okreslona wlasnosc.\nAutor: Jakub Drozd\n");
//}
//
//int wczytajLiczbe() {
//	int liczba;
//	while (scanf_s("%d", &liczba)!=1 || getchar()!='\n')
//	{
//		printf("Bledne dane, podaj dowolna liczbe calkowita: ");
//		int c;
//		while ((c = getchar()) != '\n' && c != EOF)
//			;
//	}
//	return liczba;
//}
//
//void wczytajTab(int tab[][MAX], int m, int n) {
//	int l = 1;
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			if (j % 2 == 0)
//			{
//				tab[i][j] = l;
//				l++;
//			}
//			else
//			{
//				printf("Podaj [%d][%d] element tab: ", i, j);
//				tab[i][j] = wczytajLiczbe();
//			}
//		}
//	}
//}
//
//void sprawdzWlasnosc(int tab[][MAX], int m, int n, int tabWarunkow[]) {
//	int k = 0;
//	for (int i = 0; i < m; i++)
//	{
//		int sumaWiersza = 0;
//		for (int j = 0; j < n; j++)
//		{
//			sumaWiersza += tab[i][j];
//		}
//		tabWarunkow[k] = sumaWiersza;
//		k++;
//	}
//	int licznik = 0;
//	for (int i = 1; i < m; i++)
//	{
//		printf("\n%d | %d\n", tabWarunkow[i-1], tabWarunkow[i]);
//		if (!(tabWarunkow[i-1] < tabWarunkow[i]))
//		{
//			printf("\nWlasnosc nie zachodzi.\n");
//			break;
//		}
//		else
//		{
//			licznik++;
//		}
//	}
//	if (licznik == m - 1)
//	{
//		printf("\nWlasnosc zachodzi.\n");
//	}
//}
//
//int main() {
//	info();
//	int tab[MAX][MAX];
//	printf("Wypelnij elementy tablicy:\n");
//	wczytajTab(tab, MAX, MAX);
//	int tabWarunkow[MAX];
//	sprawdzWlasnosc(tab, MAX, MAX, tabWarunkow);
//	printf("\n\nKoniec programu\n\n");
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//
//#define MAX 40
//
//void info() {
//	printf("Program wypisuje numery kolumn tablicy zdefiniowanej przez uzytkownika, w ktorych znajduje sie element maksymalny.\nAutor: Jakub Drozd\n");
//}
//
//int wczytajLiczbe() {
//	int liczba;
//	while (scanf_s("%d", &liczba) != 1 || liczba < 1 || liczba > 20 || getchar() != '\n')
//	{
//		printf("Bledne dane, podaj liczbe calkowita z przedzialu [1, 20]: ");
//		int c;
//		while ((c = getchar()) != '\n' && c != EOF)
//			;
//	}
//	return liczba;
//}
//
//void wczytajTab(int tab[][MAX], int m, int n) {
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			tab[i][j] = rand() % (10 + 1 + 10) - 10;
//		}
//	}
//}
//
//void wypiszKolumny(int const tab[], int k) {
//	for (int i = 0; i < k; i++)
//	{
//		printf("%d ", tab[i]);
//	}
//}
//
//int wyznaczMax(int tab[][MAX], int m, int n) {
//	int max = -20;
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			if ((j > i) && (tab[i][j] > max))
//			{
//				max = tab[i][j];
//			}
//		}
//	}
//	return max;
//}
//
//void wyznaczKolumny(int tab[][MAX], int m, int n, int max, int* k, int kolumny[]) {
//	for (int j = 0; j < n; j++)
//	{
//		for (int i = 0; i < m; i++)
//		{
//			if (tab[i][j] == max)
//			{
//				kolumny[*k] = j;
//				(*k)++;
//				break;
//			}
//		}
//	}
//}
//
//int main() {
//	srand((unsigned)time(NULL));
//	printf("Podaj liczbe kolumn: ");
//	int n = wczytajLiczbe();
//	int m = 2 * n;
//	int tab[MAX][MAX];
//	wczytajTab(tab, m, n);
//	int max = wyznaczMax(tab, m, n);
//	int k = 0;
//	int kolumny[MAX];
//	wyznaczKolumny(tab, m, n, max, &k, kolumny);
//	wypiszKolumny(kolumny, k);
//	printf("\nKoniec programu\n");
//	return 0;
//
//}


//#include <stdio.h>
//#include <stdlib.h>
//
//void zwolnij_int_2D(int** tab, int m)
//{
//	for (int i = 0; i < m; i++) {
//		free(tab[i]);
//	}
//	free(tab);
//}
//
//int** alokuj_int_2D(int m, int n)
//{
//	int** tab; // adres poczatku tablicy
//	tab = (int**)malloc(m * sizeof(int*));
//	if (tab == NULL) {
//		return NULL;
//	}
//	for (int i = 0; i < m; i++) {
//		tab[i] = (int*)malloc(n * sizeof(int));
//		if (tab[i] == NULL) {
//			zwolnij_int_2D(tab, i);
//			return NULL;
//		}
//	}
//	return tab;
//}
//
//int main() {
//	int** tab = alokuj_int_2D(1, 2);
//	tab[0][0] = 1;
//	printf("%d", tab[0][0]);
//	free(tab);
//}


//#include <stdio.h>
//#define MAX 20
//
//void info() {
//	printf("Program tworzy tablice czesciowo zdefiniowana przez uzytkownika i wykonuje na niej okreslone operacje.\nAutor: Jakub Drozd\n");
//}
//
//int wczytajLiczbe() {
//	int liczba;
//	while (scanf_s("%d", &liczba)!=1 || getchar()!='\n')
//	{
//		printf("Bledne dane\n");
//		int c;
//		while ((c = getchar()) != '\n' && c != EOF)
//			;
//	}
//	return liczba;
//}
//
//void wczytajTab(int tab[][MAX], int m) {
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			if (i == j)
//			{
//				tab[i][j] = 1;
//			}
//			if (j > i)
//			{
//				tab[i][j] = tab[i][j - 1] + 1;
//			}
//			if (i > j)
//			{
//				printf("Podaj [%d][%d] element: ", i, j);
//				tab[i][j] = wczytajLiczbe();
//			}
//		}
//	}
//}
//
//void dodajKolumny(int tab[][MAX], int m) {
//	for (int i = 0; i < m; i++)
//	{
//		int pierwsza = tab[i][0];
//		for (int j = 1; j < m; j++)
//		{
//			tab[i][j] += pierwsza;
//		}
//	}
//}
//
//void wypisz2D(int tab[][MAX], int m) {
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			printf("%4d ", tab[i][j]);
//		}
//		printf("\n");
//	}
//}
//
//int main() {
//	info();
//	int tab[MAX][MAX];
//	printf("Podaj ilosc wierszy: ");
//	int m = wczytajLiczbe();
//	while (m < 2 || m > 20)
//	{
//		printf("Liczba wierszy musi byc z zakresu [2, 20]: ");
//		m = wczytajLiczbe();
//	}
//	wczytajTab(tab, m);
//	wypisz2D(tab, m);
//	dodajKolumny(tab, m);
//	printf("\n");
//	wypisz2D(tab, m);
//	printf("\n\nKoniec programu\n\n");
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//
//#define MAX 90
//
//void info() {
//	printf("Program sporzadza histogram par losowych liczb, oblicza maksymalna wartosc w histogramie i zeruje okreslone pary.\nAutor: Jakub Drozd\n");
//}
//
//void red() {
//	printf("\033[1;31m");
//}
//
//void reset() {
//	printf("\033[0m");
//}
//
//void wczytajPary(int tabX[], int tabY[], int m) {
//	for (int i = 0; i < m; i++)
//	{
//		tabX[i] = rand() % (5 + 1 - 1) + 1;
//	}
//	for (int i = 0; i < m; i++)
//	{
//		tabY[i] = rand() % (7 + 1 - 2) + 2;
//	}
//}
//
//void wypiszPary(int tabX[], int tabY[], int m) {
//	for (int i = 0; i < m; i++)
//	{
//		if ((i + 1 ) % 5 == 0)
//		{
//				printf("(%d, %d)\n", tabX[i], tabY[i]);
//		}
//		else
//		{
//			printf("(%d, %d) ", tabX[i], tabY[i]);
//		}
//	}
//}
//
//void obliczHistogram(int tabX[], int tabY[], int histogram[][6], int m) {
//	for (int i = 0; i < m; i++)
//	{
//		(histogram[tabX[i] - 1][tabY[i] - 2])++;
//	}
//}
//void wypiszHistogram(int histogram[][6], int m, int n) {
//	printf("%4s", " ");
//	for (int i = 2; i < 8; i++)
//	{
//		printf("%3d", i);
//	}
//	printf("\n");
//	for (int i = 0; i < 7 ; i++)
//	{
//		printf("---");
//	}
//	printf("\n");
//	for (int i = 0; i < m; i++)
//	{
//		printf("%2d |", i + 1);
//		for (int j = 0; j < n; j++)
//		{
//			printf("%3d", histogram[i][j]);
//		}
//		printf("\n");
//	}
//}
//
//void znajdzMax(int histogram[][6], int m, int n, int para[]) {
//	int max = histogram[0][0];
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			if (histogram[i][j] > max)
//			{
//				max = histogram[i][j];
//				para[0] = i + 1;
//				para[1] = j + 2;
//			}
//		}
//	}
//	printf("Wartosc max wynosi %d, para (%d, %d).", max, para[0], para[1]);
//}
//
//
//void wyzeruj(int tabX[], int tabY[], int para[], int m) {
//	int indeksy[90];
//	int k = 0;
//	for (int i = 0; i < m; i++)
//	{
//		if (tabX[i] == para[0] && tabY[i] == para[1])
//		{
//			tabX[i] = 0;
//			tabY[i] = 0;
//			indeksy[k] = i;
//			k++;
//		}
//	}
//	printf("\nIndeksy w w tablicach z danymi,\ndla ktorych wartosci wyzerowano:\n\n");
//	for (int i = 0; i < k; i++)
//	{
//		printf("%d ", indeksy[i]);
//	}
//}
//
//int main() {
//	info();
//	int tabX[MAX];
//	int tabY[MAX];
//	srand((unsigned)time(NULL));
//	wczytajPary(tabX, tabY, MAX);
//	wypiszPary(tabX, tabY, MAX);
//	printf("\n");
//	int histogram[5][6] = { 0 };
//	obliczHistogram(tabX, tabY, histogram, MAX);
//	wypiszHistogram(histogram, 5, 6);
//	int para[2] = { 0 };
//	znajdzMax(histogram, 5, 6, para);
//	wyzeruj(tabX, tabY, para, MAX);
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//
//#define MAX 15
//
//void uzupelnijObraz(int tab[][MAX], int m) {
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			tab[i][j] = rand() % (255 + 1 - 0) + 0;
//		}
//	}
//}
//
//void uzupelnijMaske(int obraz[][MAX], int maska[][15], int m) {
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			if (obraz[i][j] > 200)
//			{
//				maska[i][j] = 1;
//			}
//		}
//	}
//}
//
//void uzupelnijKordy(int maska[][MAX], int m, int tabI[], int tabJ[], int* k) {
//	int ktora = 0;
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			if (maska[i][j] == 1 && ktora % 3 == 0)
//			{
//				tabI[*k] = i;
//				tabJ[*k] = j;
//				ktora++;
//				(*k)++;
//			}
//			else if (maska[i][j] == 1 && ktora % 3 !=0)
//			{
//				ktora++;
//			}
//		}
//	}
//}
//
//void wypiszKordy(int tabI[], int tabJ[], int k) {
//	for (int i = 0; i < k; i++)
//	{
//		printf("(%d, %d)\n", tabI[i], tabJ[i]);
//	}
//}
//void info(void) {
//	printf("Program. . .Autor: Jakub Drozd\n");
//}
//
//int wczytaj_int(int lewy, int prawy) {
//	int liczba;
//	while (scanf_s("%d", &liczba)!=1 || liczba < lewy || liczba > prawy || getchar()!='\n')
//	{
//		printf("Bledne dane, podaj liczbe z zakresu [%d,%d]: ", lewy, prawy);
//		int c;
//		while ((c = getchar()) != '\n' && c != EOF)
//			;
//	}
//	return liczba;
//}
//
//void wypisz_tab_2W(int tab[][MAX], int m) {
//	printf("%3s", "");
//	for (int j = 0; j < m; j++)
//	{
//		printf("%4d", j);
//	}
//	printf("\n");
//	for (int j = 0; j < m; j++)
//	{
//		printf("-----");
//	}
//	printf("\n");
//	for (int i = 0; i < m; i++)
//	{
//		printf("%2d|", i);
//		for (int j = 0; j < m; j++)
//		{
//			printf("%4d", tab[i][j]);
//		}
//		printf("\n");
//	}
//}
//
//int main() {
//	srand((unsigned)time(NULL));
//	info();
//	int tabI[MAX]; int tabJ[MAX];
//	printf("Podaj rozmiar obrazu (nie wiekszy niz 15): ");
//	int m = wczytaj_int(2, 15);
//	int obraz[MAX][MAX];
//	int maska[MAX][MAX] = { 0 };
//	uzupelnijObraz(obraz, m);
//	uzupelnijMaske(obraz, maska, m);
//	printf("OBRAZ:\n");
//	wypisz_tab_2W(obraz, m);
//	printf("MASKA:\n");
//	wypisz_tab_2W(maska, m);
//	printf("Wybrano jedynki o ponizszych wspolrzednych:\n\n");
//	int k = 0;
//	uzupelnijKordy(maska, m, tabI, tabJ, &k);
//	wypiszKordy(tabI, tabJ, k);
//	return 0;
//}

/*#include <limits.h>
#include <math.h>
#include <stdio.h>
#define MAX 5

typedef struct {
    char czyBudowa;
    double poleFigury;
    int nrFigury;
} Dane;

void wypisz_tab_1W_double(double const tab[], int m) {
    for (int i = 0; i < m; i++) {
        printf("[%d] %.2lf\n", i, tab[i]);
    }
}

double znajdz_min_tab_1W_double(double const tab[], int m) {
    double min = INT_MAX;
    for (int i = 0; i < m; i++) {
        if (tab[i] < min && tab[i] != -1) {
            min = tab[i];
        }
    }
    return min;
}

int znajdz_index_o_wartosci_1W(double const tab[], int m, double wartosc) {
    int index = -1;
    for (int i = 0; i < m; i++) {
        if (fabs(tab[i] - wartosc) < 0.00001) {
            index = i;
        }
    }
    return index;
}

Dane sprawdzanie(int tab[][3], int m) {
    Dane dane_trojkatow = { 'n', -1, -1 };
    double tablica_pol[MAX];
    int k = 0;
    for (int i = 0; i < m; i++) {
        double a = (double)tab[i][0];
        double b = (double)tab[i][1];
        double c = (double)tab[i][2];
        if (a < 1 || b < 1 || c < 1) {
            tablica_pol[k] = -1;
            k++;
        }
        else if ((a + b > c || a + c > b || b + c > a) && (fabs((pow(a, 2) + pow(b, 2)) - pow(c, 2)) < 0.00001)) {
                dane_trojkatow.czyBudowa = 't';
                tablica_pol[k] = (a * b) / 2;
                k++;
        }
    }
    wypisz_tab_1W_double(tablica_pol, k);
    double min = znajdz_min_tab_1W_double(tablica_pol, k);
    int szukany_index = znajdz_index_o_wartosci_1W(tablica_pol, k, min);
    dane_trojkatow.nrFigury = szukany_index;
    dane_trojkatow.poleFigury = min;
    return dane_trojkatow;
}

int main(void) {
    int tab[MAX][3] = { {1, 4, 9}, {1, 2, 3}, {5, 12, 13}, {-2, 1, 2}, {3, 4, 5} };
    Dane dane_trojkatow = sprawdzanie(tab, MAX);
    printf("\nCzy z podanych bokow da sie ulozyc chociaz jeden trojkat "
        "prostokatny? [%c]",
        dane_trojkatow.czyBudowa);
    printf("\nJakie jest najmniejsze pole z podanych trojkatow? [%.2lf]",
        dane_trojkatow.poleFigury);
    printf("\nJaki jest indeks figury o tym polu? [%d] (od 0)",
        dane_trojkatow.nrFigury);
    printf("\n\nKoniec programu\n\n");
    return 0;
}*/

//#include <stdio.h>
//#include <string.h>
//#include <ctype.h>
//#define MAX_STRING_SIZE 100
//#define MAX_ARR_SIZE 50
////C:\\Users\\PATOX\\Desktop\\uczniowie.txt
//
//struct data {
//    int index;
//    char string[25];
//    int grade;
//};
//
//void encrypt(char string[MAX_STRING_SIZE], int key) {
//    char c;
//    int i = 0;
//    while (string[i])
//    {
//        c = string[i];
//        if (isalpha(c))
//        {
//            c = toupper(c);
//            c = 'A' + (c - 'A' + key) % 26;
//        }
//        string[i] = c;
//        i++;
//    }
//}
//
//int verse(FILE* input, FILE* output, struct data tab[]) {
//    int length = strlen(tab);
//    for (int i = 0; i < length; i++)
//    {
//        char name[MAX_STRING_SIZE];
//        int index;
//        int grade;
//        name[99] = '\0';
//        if (fscanf_s(input,"%d %100s %d", &index, name, (unsigned)sizeof(name), &grade)!=3)
//        {
//            if (!feof(input))
//            {
//                printf("\nError loading input data\n");
//                fclose(input);
//                fclose(output);
//                return 1;
//            }
//            break;
//        }
//        encrypt(name, 17);
//        strcpy_s(tab[i].string, sizeof(tab[i].string), name);
//        tab[i].index = index;
//        tab[i].grade = grade;
//        fprintf(output, "%d %s %d\n", tab[i].index, tab[i].string, tab[i].grade);
//    }
//    fclose(input);
//    fclose(output);
//}
//
//int main() {
//    FILE* input = NULL;
//    FILE* output = NULL;
//    char path[80];
//    struct data tab[MAX_ARR_SIZE];
//    printf("Enter reading input file path: ");
//    if (scanf_s("%80s", path, 80) != 1 || getchar() != '\n')
//    {
//        printf("Error reading input file path");
//        return 0;
//    }
//    path[79] = '\0';
//    if (fopen_s(&input, path, "r")!=0)
//    {
//        printf("Error reading input file");
//        return 0;
//    }
//    printf("Enter output input file path: ");
//    if (scanf_s("%80s", path, 80) != 1 || getchar() != '\n')
//    {
//        printf("Error reading output file path");
//        fclose(input);
//        return 0;
//    }
//    path[79] = '\0';
//    if (fopen_s(&output, path, "w")!=0)
//    {
//        printf("Error reading output file");
//        fclose(input);
//        return 0;
//    }
//    verse(input, output, tab);
//    return 0;
//}


//#include <stdio.h>
//#include <string.h>
//#include <ctype.h>
//#include <stdlib.h>
//#include <time.h>
//#define MAX_STR_SIZE 25
//#define MAX_ARR_SIZE 50
////C:\\Users\\PATOX\\Desktop\\uczniowie.txt
//
//struct data {
//	int index;
//	char string[MAX_STR_SIZE];
//	int grade;
//};
//
//void sort(struct data tab[], int m) {
//	struct data temp;
//	for (int i = 0; i < m - 1; i++)
//	{
//		for (int j = 0; j < m - i - 1; j++)
//		{
//			if (strcmp(tab[j].string, tab[j + 1].string) > 0)
//			{
//				temp.index = tab[j].index;
//				tab[j].index = tab[j + 1].index;
//				tab[j + 1].index = temp.index;
//				temp.grade = tab[j].grade;
//				tab[j].grade = tab[j + 1].grade;
//				tab[j + 1].grade = temp.grade;
//				strcpy_s(temp.string, sizeof(tab[j].string), tab[j].string);
//				strcpy_s(tab[j].string, sizeof(tab[j + 1].string), tab[j + 1].string);
//				strcpy_s(tab[j + 1].string, sizeof(temp.string), temp.string);
//			}
//		}
//	}
//}
//
//void encrypt(char string[], int key) {
//	int i = 0;
//	char c = string[i];
//	while (string[i])
//	{
//		if (isalpha(c))
//		{
//			c = toupper(c);
//			c = 'A' + (c - 'A' + key) % 26;
//		}
//		string[i] = c;
//		i++;
//	}
//}
//
//void verse(FILE* input, FILE* output, struct data tab[]) {
//	int k = 0;
//	size_t length = strlen(tab);
//	int index;
//	char name[MAX_STR_SIZE];
//	int grade;
//	name[24] = '\0';
//	for (int i = 0; i < length; i++)
//	{
//		if (fscanf_s(input, "%d %s %d", &index, name, (unsigned)sizeof(name), &grade) != 3)
//		{
//			if (!feof(input))
//			{
//				printf("\nError reading file content\n");
//				fclose(input);
//				fclose(output);
//			}
//			break;
//		}
//		strcpy_s(tab[i].string, sizeof(name), name);
//		tab[i].index = index;
//		tab[i].grade = grade;
//		k++;
//	}
//	sort(tab, k);
//	for (int i = 0; i < k; i++)
//	{
//		int key = rand() % (48 + 1 - 1) + 1;
//		encrypt(tab[i].string, key);
//		fprintf(output, "[%d] %d %s %d\n", i + 1, tab[i].index, tab[i].string, tab[i].grade);
//	}
//	printf("\nSuccessfully copied formatted data to the output file\n");
//	fclose(input);
//	fclose(output);
//}
//
//int main() {
//	srand((unsigned)time(NULL));
//	FILE* input;
//	FILE* output;
//	struct data tab[MAX_ARR_SIZE];
//	char path[80];
//	path[79] = '\0';
//	if (scanf_s("%79s", path, 80) != 1 || getchar() != '\n')
//	{
//		printf("Error reading input file path\n");
//		return 0;
//	}
//	if (fopen_s(&input, path, "r") != 0)
//	{
//		printf("\nError reading input file\n");
//		return 0;
//	}
//	if (scanf_s("%80s", path, 80) != 1 || getchar() != '\n')
//	{
//		printf("Error reading output file path\n");
//		fclose(input);
//		return 0;
//	}
//	if (fopen_s(&output, path, "w") != 0)
//	{
//		printf("\nError reading output file\n");
//		fclose(input);
//		return 0;
//	}
//	verse(input, output, tab);
//	return 0;
//}

//#include <ctype.h>
//#include <stdio.h>
//#include <string.h>
//
//#define MAX_STR_SIZE 25
//
////C:\\Users\\PATOX\\Desktop\\dane.txt
//
//
//void konwersja(char napis[]){
//    size_t dlugosc = strlen(napis);
//   
//    for (int i = 0; i < dlugosc; i++)
//    {
//        char c = napis[i];
//        if (isalpha(c) && islower(c))
//        {
//            c = '_';
//        }
//        else if (isalpha(c) && isupper(c))
//        {
//            c = tolower(c);
//        }
//        napis[i] = c;
//    }
//}
//
//int main() {
//    FILE* wejscie;
//    FILE* wyjscie;
//    char sciezka[80];
//    sciezka[79] = '\0';
//    scanf_s("%79s", sciezka, 80);
//    fopen_s(&wejscie, sciezka, "r");
//    scanf_s("%79s", sciezka, 80);
//    fopen_s(&wyjscie, sciezka, "w");
//    char napis[MAX_STR_SIZE];
//    if (wejscie!=0 && wyjscie !=0)
//    {
//        while (!feof(wejscie))
//        {
//            fgets(napis, MAX_STR_SIZE, wejscie);
//            konwersja(napis);
//            fprintf_s(wyjscie, "%s", napis);
//        }
//    }
//    return 0;
//}

//#include <ctype.h>
//#include <stdio.h>
//#include <string.h>
//
//#define MAX_STR_SIZE 25
//
////C:\\Users\\PATOX\\Desktop\\dane.txt
//
//void szyfruj(char napis[], int key) {
//    size_t dlugosc = strlen(napis);
//    for (int i = 0; i < dlugosc; i++) {
//        char c = napis[i];
//        if (isalpha(c)) {
//            if (c >= 'a' && c <= 'z') {
//                c = 'a' + (c - 'a' + key) % 26;
//            }
//            else if (c >= 'A' && c <= 'Z') {
//                c = 'A' + (c - 'A' + key) % 26;
//            }
//        }
//        napis[i] = c;
//    }
//}
//
//
//
//int main() {
//    FILE* wejscie;
//    FILE* wyjscie;
//    char sciezka[80];
//    sciezka[79] = '\0';
//    scanf_s("%79s", sciezka, 80);
//    fopen_s(&wejscie, sciezka, "r");
//    scanf_s("%79s", sciezka, 80);
//    fopen_s(&wyjscie, sciezka, "w");
//    char napis[MAX_STR_SIZE];
//    printf("Podaj klucz do szyfrowania: ");
//    int klucz;
//    while (scanf_s("%d", &klucz) != 1 || getchar()!='\n')
//    {
//        printf("Bledne dane, podaj klucz: ");
//        int c;
//        while ((c = getchar()) != '\n' && c != EOF)
//            ;
//    }
//    if (wejscie != 0 && wyjscie != 0)
//    {
//        while (!feof(wejscie))
//        {
//            fgets(napis, MAX_STR_SIZE, wejscie);
//            szyfruj(napis, klucz);
//            fprintf_s(wyjscie, "%s", napis);
//        }
//    }
//    return 0;
//}

//#include <math.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#define MAX 25
//
//int bin2int(char* napis) {
//    int liczba = 0;
//    int dlugosc = strlen(napis);
//    int potega = dlugosc - 1;
//    for (int i = 0; i < dlugosc; i++) {
//        if (napis[i] == '1') {
//            int temp = (int)pow(2, potega);
//            liczba += temp;
//            potega--;
//        }
//        else {
//            potega--;
//        }
//    }
//    return liczba;
//}
//
//void zamiana(char** a, char** b) {
//    char* temp = *a;
//    *a = *b;
//    *b = temp;
//}
//
//void sortowanie(char** tab, int m, int n) {
//    int max_index = 0;
//    for (int i = 0; i < m - 1; i++) {
//        max_index = 0;
//        for (int j = i + 1; j < m; j++) {
//            if (bin2int(tab[j]) > bin2int(tab[max_index])) {
//                max_index = j;
//            }
//        }
//        if (max_index != i) {
//            zamiana(&tab[max_index], &tab[i]);
//        }
//    }
//}
//
//int wczytaj_int() {
//    int liczba;
//    while (scanf_s("%d", &liczba) != 1 || getchar() != '\n') {
//        int c;
//        while ((c = getchar()) != '\n' && c != EOF)
//            ;
//    }
//    return liczba;
//}
//
//void wypisz_tab_2W(char** tab, int m, int n) {
//    int ilosc_danych = 0;
//    for (int i = 0; i < m; i++) {
//        if (tab[i] != '\0') {
//            printf("%s\n", tab[i]);
//        }
//    }
//}
//
//int main() {
//    int m, n;
//    printf("Podaj wymiary tablicy:");
//    m = wczytaj_int();
//    n = wczytaj_int();
//    FILE* input;
//    if (fopen_s(&input, "C:\\Users\\PATOX\\Desktop\\dane.txt", "r") != 0) {
//        printf("Error wczytywania pliku");
//        return 1;
//    }
//    char** tab = malloc(m * sizeof(char**));
//    for (int i = 0; i < m; i++) {
//        tab[i] = malloc(n * sizeof(char));
//    }
//    for (int i = 0; i < m; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            tab[i][j] = '\0';
//        }
//    }
//    char napis[MAX];
//    int i = 0;
//    while (!feof(input)) {
//        fscanf_s(input, "%s", napis, (unsigned)sizeof(napis));
//        strcpy_s(tab[i], sizeof(napis), napis);
//        i++;
//    }
//    sortowanie(tab, m, n);
//    for (int i = 0; i < m; i++) {
//        if (tab[i] != '\0' && bin2int(tab[i])!=0) {
//            printf("%d\t[%s]\n", bin2int(tab[i]), tab[i]);
//        }
//    }
//    return 0;
//}

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
// void wypiszStudenta(struct student *student) {
//     if (student == NULL)
//     {
//         printf("Student nie istnieje");
//     }
//     else
//     {
//         printf("\n[Indeks]: %d\n[Imie]: %s\n[Ocena]: %d\n[Nastepny]: %p\n",
//             student->indeks,
//             student->imie,
//             student->ocena,
//             student->nastepny
//             );
//     }
// }
//
// void wypiszStudentow(struct student* pierwszy) {
//     struct student* aktualny = pierwszy;
//         while (aktualny != NULL)
//         {
//             wypiszStudenta(aktualny);
//             aktualny = aktualny->nastepny;
//         }
//}
//
// void dodajNaKoniec(struct student* pierwszy, int indeks, char imie[], int ocena, int *i) {
//     struct student* nowyStudent = dodajStudenta(indeks, imie, ocena);
//     if (nowyStudent != NULL)
//     {
//         if (pierwszy == NULL)
//         {
//             pierwszy = nowyStudent;
//         }
//         else
//         {
//             struct student* aktualny = pierwszy;
//             while (aktualny->nastepny != NULL)
//             {
//                 aktualny = aktualny->nastepny;
//             }
//             aktualny->nastepny = nowyStudent;
//         }
//     }
//     (*i)++;
// }
//
// void dodajNaPoczatek(struct student** pierwszy, int indeks, char imie[], int ocena, int *i) {          //** bo modifikujemy zmienna pierwszy zadeklarowana w main
//     struct student* nowyStudent = dodajStudenta(indeks, imie, ocena);
//     if (nowyStudent!=NULL)
//     {
//         if (pierwszy == NULL)
//         {
//             pierwszy = nowyStudent;
//         }
//         else
//         {
//             nowyStudent->nastepny = *pierwszy;
//             *pierwszy = nowyStudent;
//         }
//     }
//     (*i)++;
// }
//
// void dodajPo(struct student* pierwszy, int id, int indeks, char imie[], int ocena, int *i) {
//     struct student* nowyStudent = dodajStudenta(indeks, imie, ocena);
//     struct student* aktualny = pierwszy;
//     while (aktualny->nastepny != NULL)
//     {
//         if (aktualny->indeks == id)
//         {
//             nowyStudent->nastepny = aktualny->nastepny;
//             aktualny->nastepny = nowyStudent;
//             (*i)++;
//             break;
//         }
//         else
//         {
//             aktualny = aktualny->nastepny;
//         }
//     }
// }
//
// void usunPoId(struct student* pierwszy, int id, int* i) {
//     struct student* aktualny = pierwszy;
//     while (aktualny->nastepny != NULL)
//     {
//         if (aktualny->nastepny->indeks == id)
//         {
//             struct student* doUsuniecia = aktualny->nastepny;
//             aktualny->nastepny = aktualny->nastepny->nastepny;
//             free(doUsuniecia);
//             (*i)--;
//             break;
//         }
//         else
//         {
//             aktualny = aktualny->nastepny;
//         }
//     }
// }
//
// void dealokacjaStudentow(struct student* pierwszy) {
//     struct student* aktualny = pierwszy;
//     while (aktualny != NULL)
//     {
//         struct student* aux = aktualny;
//         aktualny = aktualny->nastepny;
//         free(aux);
//     }
// }
//
//int main(void) {
//    FILE* input;
//    int i = 0;
//    struct student* pierwszy = NULL;    //Wskazuje na pierwszy element z listy
//    struct student* aktualny = NULL;    //Wskazuje na ostatnio dodany element z listy
//    if (fopen_s(&input, "C:\\Users\\PATOX\\Desktop\\dane.txt", "r")!=0)
//    {
//        printf("Blad wczytywania pliku");
//        return 1;
//    }
//    int indeks = 0;
//    char imie[25];
//    int ocena = 0;
//    while (fscanf_s(input,"%d %s %d", &indeks, imie, (unsigned)sizeof(imie), &ocena)==3)  //Dopóki jest w w stanie odczytać dane w formacie, pętla się wykonuje
//    {
//        if (pierwszy == NULL)                                                             
//        {
//            pierwszy = dodajStudenta(indeks, imie, ocena);                                //Jeżeli lista nie posiada jeszcze pierwszego elementu, tworzy go
//            if (pierwszy!=NULL)                                                           
//            {
//                aktualny = pierwszy;                                                        //Jeżeli alokacja w pamięci się udała, ustaw dodaną daną jako dodaną
//                i++;
//            }
//        }
//        else
//        {
//            aktualny->nastepny = dodajStudenta(indeks, imie, ocena);                        //Jeżeli lista zawiera już pierwszy element, dodaje kolejny
//            if (aktualny->nastepny!=NULL)
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

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//#define NAZWA_MAX 50
//#define OPIS_MAX 200
//#define MAX_KSIAZEK 300
//
//struct ksiazka {
//    int id;
//    char nazwa[NAZWA_MAX];
//    char opis[OPIS_MAX];
//    int rok;
//    struct ksiazka *nastepny;
//};
//
//struct ksiazka *dodaj_ksiazke(int id, char nazwa[], char opis[], int rok) {
//    struct ksiazka *nowa_ksiazka = NULL;
//    nowa_ksiazka = malloc(sizeof(struct ksiazka));
//    if (nowa_ksiazka != NULL)
//    {
//        nowa_ksiazka->id = id;
//        strcpy_s(nowa_ksiazka->nazwa, sizeof(nowa_ksiazka->nazwa), nazwa);
//        strcpy_s(nowa_ksiazka->opis, sizeof(nowa_ksiazka->opis), opis);
//        nowa_ksiazka->rok = rok;
//        nowa_ksiazka->nastepny = NULL;
//        printf("\nDodano nowa ksiazke\n");
//    }
//    else
//    {
//        printf("Blad alokowania w pamieci");
//        exit(1);
//    }
//    return nowa_ksiazka;
//}
//
//void wypisz_ksiazki(struct ksiazka *pierwsza) {
//    struct ksiazka *aktualna = pierwsza;
//    while (aktualna != NULL)
//    {
//        printf("\n[ID]: %d\n[NAZWA]: %s\n[OPIS]: %s\n[ROK]: %d\n[NASTEPNA]: %p\n",
//            aktualna->id,
//            aktualna->nazwa,
//            aktualna->opis,
//            aktualna->rok,
//            aktualna->nastepny
//            );
//        aktualna = aktualna->nastepny;
//    }
//}
//
//void dealokacja_ksiazek(struct ksiazka* pierwsza) {
//    struct ksiazka* aktualna = pierwsza;
//    while (aktualna != NULL)
//    {
//        struct ksiazka *do_usuniecia = aktualna;
//        aktualna = aktualna->nastepny;
//        free(do_usuniecia);
//    }
//}
//
//void dodaj_na_poczatek(struct ksiazka** pierwsza, int id, char nazwa[], char opis[], int rok) {
//    struct ksiazka* nowa_ksiazka = dodaj_ksiazke(id, nazwa, opis, rok);
//    if (pierwsza == NULL)
//    {
//        if (nowa_ksiazka != NULL)
//        {
//            *pierwsza = nowa_ksiazka;
//        }
//    }
//    else
//    {
//        if (nowa_ksiazka != NULL)
//        {
//            nowa_ksiazka->nastepny = *pierwsza;
//            *pierwsza = nowa_ksiazka;
//        }
//    }
//}
//
//void dodaj_po_danym_id(struct ksiazka* pierwsza, int szukane_id, int id, char nazwa[], char opis[], int rok) {
//    struct ksiazka* nowa_ksiazka = dodaj_ksiazke(id, nazwa, opis, rok);
//    struct ksiazka *aktualna = pierwsza;
//    while (aktualna != NULL)
//    {
//        if (aktualna->id == szukane_id)
//        {
//            nowa_ksiazka->nastepny = aktualna->nastepny;
//            aktualna->nastepny = nowa_ksiazka;
//            break;
//        }
//        else
//        {
//            aktualna = aktualna->nastepny;
//        }
//    }
//}
//
//void dodaj_na_koniec(struct ksiazka* pierwsza, int id, char nazwa[], char opis[], int rok) {
//    struct ksiazka* nowa_ksiazka = dodaj_ksiazke(id, nazwa, opis, rok);
//    struct ksiazka* aktualna = pierwsza;
//    while (aktualna->nastepny != NULL)
//    {
//        aktualna = aktualna->nastepny;
//    }
//    aktualna->nastepny = nowa_ksiazka;
//}
//
//
//int main() {
//    FILE* input;
//    struct ksiazka *pierwsza = NULL;
//    struct ksiazka *aktualna = NULL;
//    fopen_s(&input,"C:\\Users\\PATOX\\Desktop\\dane.txt", "r");
//    if (input == NULL)
//    {
//        printf("Blad przy otwieraniu pliku");
//        return 1;
//    }
//    int id;
//    char nazwa[NAZWA_MAX];
//    char opis[OPIS_MAX];
//    int rok;
//    while (fscanf_s(input, "%d %s %s %d", &id, nazwa, (unsigned)sizeof(nazwa), opis, (unsigned)sizeof(opis), &rok) == 4)
//    {
//        if (pierwsza == NULL)
//        {
//            pierwsza = dodaj_ksiazke(id, nazwa, opis, rok);
//            if (pierwsza != NULL)
//            {
//                aktualna = pierwsza;
//            }
//        }
//        else
//        {
//            aktualna->nastepny = dodaj_ksiazke(id, nazwa, opis, rok);
//            if (aktualna->nastepny != NULL)
//            {
//                aktualna = aktualna->nastepny;
//            }
//        }
//    }
//    dodaj_na_poczatek(&pierwsza, 2, "Wladca_Pierscieni", "Ksiazka_o_pierscieniu", 1947);
//    dodaj_na_koniec(pierwsza, 3, "Gra_o_Tron", "Ksiazka_o_walce_rodow", 1987);
//    dodaj_po_danym_id(pierwsza, 3, 4, "Narnia", "Ksiazka_o_szafie", 1876);
//    wypisz_ksiazki(pierwsza);
//    dealokacja_ksiazek(pierwsza);
//    fclose(input);
//    return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//struct pojazd {
//    char marka[40];
//    char model[40];
//    int rok_produkcji;
//    float pojemnosc_silnika;
//};
//
//int ile_wierszy(FILE *plik) {
//    int ilosc = 0;
//    while (!feof(plik)) {
//        char napis[100];
//        fgets(napis, sizeof(napis), plik);
//        ilosc++;
//    }
//    rewind(plik);
//    return ilosc;
//}
//
//struct dane {
//    int rozmiar;
//    struct pojazd* wskaznik;
//};
//
//struct dane druga(FILE* plik) {
//    if (plik == NULL)
//    {
//        printf("Blad");
//        exit(0);
//    }
//    struct dane a;
//    int ilosc = ile_wierszy(plik);
//    struct pojazd* tab = malloc(ilosc * sizeof(struct pojazd));
//    for (int i = 0; i < ilosc; i++)
//    {
//        if (fscanf_s(plik, "%s %s %d %f", tab[i].marka, (unsigned)sizeof(tab[i].marka), tab[i].model, (unsigned)sizeof(tab[i].model), &tab[i].rok_produkcji, &tab[i].pojemnosc_silnika) != 4)
//        {
//            printf("Blad odczytu");
//            exit(0);
//        }
//    }
//    a.rozmiar = ilosc;
//    a.wskaznik = tab;
//    return a;
//}
//
//void wypisz_pojazdy(struct pojazd* tab, int rozmiar) {
//    for (int i = 0; i < rozmiar; i++)
//    {
//        printf("%s %s %d %f\n", tab[i].marka, tab[i].model, tab[i].rok_produkcji, tab[i].pojemnosc_silnika);
//    }
//}
//
//struct pojazd* czwarta(struct pojazd *tab, int rozmiar) {
//    struct pojazd* nowa;
//    if ((tab = realloc(tab, (rozmiar + 1) * sizeof(struct pojazd))) == NULL)
//    {
//        printf("\nBlad realokacji, tworzenie nowej tablicy...\n");
//        nowa = malloc((rozmiar + 1) * sizeof(struct pojazd));
//        memmove(nowa, tab, sizeof((rozmiar + 1) * sizeof(struct pojazd)));
//        printf("\nPoszerzanie tablicy...\n");
//        printf("Podaj nowe auto:\n");
//        scanf_s("%s %s %d %f", tab[rozmiar].marka, 40, tab[rozmiar].model, 40, &tab[rozmiar].rok_produkcji, &tab[rozmiar].pojemnosc_silnika);
//        free(tab);
//        return nowa;
//    }
//    else
//    {
//        printf("\nPoszerzanie tablicy...\n");
//        printf("Podaj nowe auto:\n");
//        scanf_s("%s %s %d %f", tab[rozmiar].marka, 40, tab[rozmiar].model, 40, &tab[rozmiar].rok_produkcji, &tab[rozmiar].pojemnosc_silnika);
//        return tab;
//    }
//
//}
//
//int main() {
//    FILE* wejscie;
//    FILE* wyjscie;
//    fopen_s(&wejscie, "C:\\Users\\PATOX\\Desktop\\dane.txt", "r");
//    struct dane wynik = druga(wejscie);
//    wypisz_pojazdy(wynik.wskaznik, wynik.rozmiar);
//    wynik.wskaznik = czwarta(wynik.wskaznik, wynik.rozmiar);
//    fopen_s(&wyjscie, "C:\\Users\\PATOX\\Desktop\\dane2.txt", "w");
//    for (int i = 0; i < wynik.rozmiar + 1; i++)
//    {
//        fprintf(wyjscie,"%s %s %d %.2f\n", wynik.wskaznik[i].marka, wynik.wskaznik[i].model, wynik.wskaznik[i].rok_produkcji, wynik.wskaznik[i].pojemnosc_silnika);
//    }
//    free(wynik.wskaznik);
//    fclose(wejscie);
//    fclose(wyjscie);
//    return 0;
//}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct pomiar {
    unsigned int nr_pomiaru;
    unsigned int nr_czujnika;
    char data_i_czas[20];
    double temp;
    struct pomiar* nastepny;
};

struct pomiar* dodaj_pomiar(unsigned int nr_pomiaru, unsigned int nr_czujnika, char data_i_czas[20], double temp) {
    struct pomiar* nowy_pomiar = NULL;
    nowy_pomiar = malloc(sizeof(struct pomiar));
    nowy_pomiar->nr_pomiaru = nr_pomiaru;
    nowy_pomiar->nr_czujnika = nr_czujnika;
    strcpy_s(nowy_pomiar->data_i_czas, sizeof(nowy_pomiar->data_i_czas), data_i_czas);
    nowy_pomiar->temp = temp;
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

void ile_pomiarow(struct pomiar* pierwszy) {
    int ile = 0;
    struct pomiar* aktualny = pierwszy;
    while (aktualny != NULL)
    {
        if ((aktualny == pierwszy)  || (aktualny->nastepny == NULL) || (aktualny->nastepny->nastepny == NULL))
        {
            printf("\n|%d %d %s %lf|\n", aktualny->nr_pomiaru, aktualny->nr_czujnika, aktualny->data_i_czas, aktualny->temp);
        }
        ile++;
        aktualny = aktualny->nastepny;
    }
    printf("\n!!!Ilosc pomiarow: %d!!!\n\n\n\n", ile);
}


struct rozdzielone {
    struct pomiar* czujnik1;
    struct pomiar* czujnik2;
    struct pomiar* czujnik3;
    struct pomiar* czujnik4;
};


struct rozdzielone rozdziel_liste(struct pomiar* pierwszy) {
    struct pomiar* czujnik1 = NULL;
    struct pomiar* czujnik2 = NULL;
    struct pomiar* czujnik3 = NULL;
    struct pomiar* czujnik4 = NULL;
    struct rozdzielone listy;

    for (struct pomiar* aktualny = pierwszy; aktualny != NULL; aktualny = aktualny->nastepny) {
        struct pomiar* nowy = (struct pomiar*)malloc(sizeof(struct pomiar));
        nowy->nr_pomiaru = aktualny->nr_pomiaru;
        nowy->nr_czujnika = aktualny->nr_czujnika;
        strcpy_s(nowy->data_i_czas, sizeof(nowy->data_i_czas), aktualny->data_i_czas);
        nowy->temp = aktualny->temp;
        nowy->nastepny = NULL;

        if (aktualny->nr_czujnika == 1) {
            if (czujnik1 == NULL) {
                czujnik1 = nowy;
            }
            else {
                struct pomiar* ostatni = czujnik1;
                while (ostatni->nastepny != NULL) {
                    ostatni = ostatni->nastepny;
                }
                ostatni->nastepny = nowy;
            }
        }
        else if (aktualny->nr_czujnika == 2) {
            if (czujnik2 == NULL) {
                czujnik2 = nowy;
            }
            else {
                struct pomiar* ostatni = czujnik2;
                while (ostatni->nastepny != NULL) {
                    ostatni = ostatni->nastepny;
                }
                ostatni->nastepny = nowy;
            }
        }
        else if (aktualny->nr_czujnika == 3) {
            if (czujnik3 == NULL) {
                czujnik3 = nowy;
            }
            else {
                struct pomiar* ostatni = czujnik3;
                while (ostatni->nastepny != NULL) {
                    ostatni = ostatni->nastepny;
                }
                ostatni->nastepny = nowy;
            }
        }
        else if (aktualny->nr_czujnika == 4) {
            if (czujnik4 == NULL) {
                czujnik4 = nowy;
            }
            else {
                struct pomiar* ostatni = czujnik4;
                while (ostatni->nastepny != NULL) {
                    ostatni = ostatni->nastepny;
                }
                ostatni->nastepny = nowy;
            }
        }
    }
    listy.czujnik1 = czujnik1;
    listy.czujnik2 = czujnik2;
    listy.czujnik3 = czujnik3;
    listy.czujnik4 = czujnik4;
    return listy;
}


struct pomiar* wczytajPlik(char nazwa_pliku[]) {
    FILE* wejscie = NULL;
    struct pomiar *pierwszy = NULL;
    struct pomiar* nowy = NULL;
    if (fopen_s(&wejscie, nazwa_pliku, "r")!=0)
    {
        printf("\nNie znaleziono pliku\n");
        exit(0);
    }
    else
    {
        printf("\nPomyslnie otwarto plik\n");
    }
    unsigned int nr_pomiaru;
    unsigned int nr_czujnika;
    char data_i_czas[20];
    double temp;
    while (fscanf_s(wejscie,"%d %d %s %lf", &nr_pomiaru, &nr_czujnika, data_i_czas, (unsigned)sizeof(data_i_czas), &temp) == 4)
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
    fclose(wejscie);
    if (pierwszy == NULL)
    {
        return NULL;
    }
    else
    {
        return pierwszy;
    }
}

void dealokuj_liste(struct pomiar* pierwszy) {
    struct pomiar* aktualny = pierwszy;
    while (aktualny != NULL)
    {
        struct pomiar* temp = aktualny;
        aktualny = aktualny->nastepny;
        free(temp);
    }
    pierwszy = NULL;
}

void usun_element(struct pomiar* pierwszy, int nr_pomiaru) {
    struct pomiar* aktualny = pierwszy;
    while (aktualny->nastepny != NULL)
    {
        if (aktualny->nastepny->nr_pomiaru == nr_pomiaru)
        {
            struct pomiar* temp = aktualny->nastepny;
            aktualny->nastepny = aktualny->nastepny->nastepny;
            free(temp);
        }
        aktualny = aktualny->nastepny;
    }
}

void dodaj_element(struct pomiar* pierwszy, struct pomiar* element) {
    struct pomiar* aktualny = pierwszy;
    while (aktualny->nastepny != NULL)
    {
        aktualny = aktualny->nastepny;
    }
    aktualny->nastepny = element;
}

struct pomiar* dodaj_min_max(struct pomiar* pierwszy) {
    struct pomiar* aktualny = pierwszy;

    struct pomiar* minimalny = (struct pomiar*)malloc(sizeof(struct pomiar));
    minimalny->nr_pomiaru = aktualny->nr_pomiaru;
    minimalny->nr_czujnika = aktualny->nr_czujnika;
    strcpy_s(minimalny->data_i_czas, sizeof(minimalny->data_i_czas), aktualny->data_i_czas);
    minimalny->temp = aktualny->temp;
    minimalny->nastepny = NULL;

    struct pomiar* maksymalny = (struct pomiar*)malloc(sizeof(struct pomiar));
    maksymalny->nr_pomiaru = aktualny->nr_pomiaru;
    maksymalny->nr_czujnika = aktualny->nr_czujnika;
    strcpy_s(maksymalny->data_i_czas, sizeof(maksymalny->data_i_czas), aktualny->data_i_czas);
    maksymalny->temp = aktualny->temp;
    maksymalny->nastepny = NULL;

    struct pomiar* pomoc = pierwszy->nastepny;
    while (aktualny != NULL)
    {
        if (aktualny->temp < minimalny->temp)
        {
            minimalny->nr_pomiaru = aktualny->nr_pomiaru;
            minimalny->nr_czujnika = aktualny->nr_czujnika;
            strcpy_s(minimalny->data_i_czas, sizeof(minimalny->data_i_czas), aktualny->data_i_czas);
            minimalny->temp = aktualny->temp;
            minimalny->nastepny = NULL;
        }
        if (aktualny->temp > maksymalny->temp)
        {
            maksymalny->nr_pomiaru = aktualny->nr_pomiaru;
            maksymalny->nr_czujnika = aktualny->nr_czujnika;
            strcpy_s(maksymalny->data_i_czas, sizeof(maksymalny->data_i_czas), aktualny->data_i_czas);
            maksymalny->temp = aktualny->temp;
            maksymalny->nastepny = NULL;
        }
        aktualny = aktualny->nastepny;
    }
    printf("\n[Minimalna temp: %d %d %s %lf]\n", minimalny->nr_pomiaru, minimalny->nr_czujnika, minimalny->data_i_czas, minimalny->temp);
    printf("\n[Maksymalna temp: %d %d %s %lf]\n", maksymalny->nr_pomiaru, maksymalny->nr_czujnika, maksymalny->data_i_czas, maksymalny->temp);
    dodaj_element(pierwszy, maksymalny);
    dodaj_element(pierwszy, minimalny);
    return pierwszy;
}

struct pomiar* usun_min_max(struct pomiar* pierwszy){
    struct pomiar* aktualny = pierwszy;
    struct pomiar* minimalny = pierwszy;
    struct pomiar* maksymalny = pierwszy;
    struct pomiar* pomoc = pierwszy->nastepny;
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
        aktualny = aktualny->nastepny;
    }
    printf("\n[Minimalna temp: %d %d %s %lf]\n", minimalny->nr_pomiaru, minimalny->nr_czujnika, minimalny->data_i_czas, minimalny->temp);
    printf("\n[Maksymalna temp: %d %d %s %lf]\n", maksymalny->nr_pomiaru, maksymalny->nr_czujnika, maksymalny->data_i_czas, maksymalny->temp);
    usun_element(pierwszy, minimalny->nr_pomiaru);
    usun_element(pierwszy, maksymalny->nr_pomiaru);
    if (pierwszy != NULL)
    {
        return pierwszy;
    }
    else
    {
        return pomoc;
    }
}

int main() {
    struct pomiar* pierwszy = wczytajPlik("dane.txt");
    ile_pomiarow(pierwszy);
    struct rozdzielone listy = rozdziel_liste(pierwszy);
    dealokuj_liste(pierwszy);

    printf("\n[CZUJNIK 1]\n");
    ile_pomiarow(listy.czujnik1);
    dodaj_min_max(listy.czujnik1);
    ile_pomiarow(listy.czujnik1);

    printf("\n[CZUJNIK 2]\n");
    ile_pomiarow(listy.czujnik2);
    dodaj_min_max(listy.czujnik2);
    ile_pomiarow(listy.czujnik2);

    printf("\n[CZUJNIK 3]\n");
    ile_pomiarow(listy.czujnik3);
    dodaj_min_max(listy.czujnik3);
    ile_pomiarow(listy.czujnik3);

    printf("\n[CZUJNIK 4]\n");
    ile_pomiarow(listy.czujnik4);
    dodaj_min_max(listy.czujnik4);
    ile_pomiarow(listy.czujnik4);
}