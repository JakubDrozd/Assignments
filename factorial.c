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


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_ARR_SIZE 50


int bin2int(char* napis) {
    int liczba = 0;
    int dlugosc = (int)strlen(napis);
    int potega = dlugosc - 1;
    for (int i = 0; i < dlugosc; i++)
    {
        if (napis[i] == '1')
        {
            int temp = (int)pow(2, potega);
            liczba += temp;
            potega--;
        }
        else
        {
            potega--;
        }
    }
    return liczba;
}


void wypisz_tab_2W(char **tab, int m, int n) {
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (tab[i][j]!=NULL)
            {
                printf("%c", tab[i][j]);
            }
        }
    }
}

int wczytaj_int() {
    static int liczba_wywolan = 0;
    int liczba;
    printf("Podaj liczbe %s: ", (liczba_wywolan > 0) ? "kolumn" : "wierszy");
    while (scanf_s("%d", &liczba)!=1 || getchar()!='\n')
    {
        printf("Bledne dane, podaj liczbe %s: ", (liczba_wywolan > 0) ? "kolumn" : "wierszy");
        int c;
        while ((c = getchar()) != '\n' && c != EOF)
            ;
    }
    liczba_wywolan++;
    return liczba;
}

int main() {
    int m = wczytaj_int();
    int n = wczytaj_int();
    char** tab = malloc(m * sizeof(char*));
    for (int i = 0; i < m; i++)
    {
        tab[i] = malloc(n * sizeof(char));
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            tab[i][j] = NULL;
        }
    }
    FILE* input;
    FILE* output;
    if (fopen_s(&input, "C:\\Users\\PATOX\\Desktop\\dane.txt", "r") != 0)
    {
        printf("Bledne odczytywanie pliku input");
    }
    if (fopen_s(&output, "C:\\Users\\PATOX\\Desktop\\dane2.txt", "w") != 0)
    {
        printf("Bledne odczytywanie pliku output");
    }
    int i = 0;
    int dlugosc_stringa = n - 1;
    char* napis = malloc(dlugosc_stringa * sizeof(char));
    while (!feof(input) && i < m) {
        fgets(napis, dlugosc_stringa, input);
        for (int j = 0; j < strlen(napis); j++)
        {
            tab[i][j] = napis[j];
        }
        i++;
    }
    wypisz_tab_2W(tab, m, n);
    return 0;
}
