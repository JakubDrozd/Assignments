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

#include <stdio.h>
#define MAX 10

void info() {
	printf("Program wczytuje ablice 10x10 i sprawdza, czy posiada ona okreslona wlasnosc.\nAutor: Jakub Drozd\n");
}

int wczytajLiczbe() {
	int liczba;
	while (scanf_s("%d", &liczba)!=1 || getchar()!='\n')
	{
		printf("Bledne dane, podaj dowolna liczbe calkowita: ");
		int c;
		while ((c = getchar()) != '\n' && c != EOF)
			;
	}
	return liczba;
}

void wypiszTab2D(int tab[][MAX], int m, int n);

void wczytajTab(int tab[][MAX], int m, int n) {
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("Podaj element tablicy: ");
			tab[i][j] = wczytajLiczbe();
		}
	}
}

void wypiszTab1D(int tab[], int m) {
	for (int i = 0; i < m; i++)
	{
		printf("%2d ", tab[i]);
	}
}

void wypiszTab2D(int tab[][MAX], int m, int n) {
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%2d ", tab[i][j]);
		}
		printf("\n");
	}
}

void sprawdzWarunek(int tab[][MAX], int m, int n, int tab_failed[]) {
	int k = 0;
	for (int i = 0; i < m; i++)
	{
		int sumaWiersza = 0;
		int liczbaNaPrzekatnej;
		for (int j = 0; j < n; j++)
		{
			if (i == j)
			{
				liczbaNaPrzekatnej = tab[i][j];
			}
			if (tab[i][j] > 0 && i!=j)
			{
				sumaWiersza += tab[i][j];
			}
		}
		if (!(liczbaNaPrzekatnej > sumaWiersza))
		{
			tab_failed[k] = i;
			k++;
		}
	}
}

int main() {
	info();
	int tab[MAX][MAX] = { 0 };
	int tab_failed[MAX] = { -1 };
	wczytajTab(tab, MAX, MAX);
	wypiszTab2D(tab, MAX, MAX);
	sprawdzWarunek(tab, MAX, MAX, tab_failed);
	if (tab_failed[0] < 0)
	{
		printf("Tablica spelnia wlanosc.");
	}
	else
	{
		printf("Numery wierszy, ktore nie spelnily warunku:\n");
		wypiszTab1D(tab_failed, MAX);
	}
	printf("\n\nKoniec programu\n\n");
	return 0;
}