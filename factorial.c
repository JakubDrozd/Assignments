#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
enum {a = 3, b = 5, c = 11};

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


int main() {
	int **tab;
	int n = 3;
	int m = 4;
	tab = (int*)malloc(n * sizeof(int));
	if (tab == NULL)
	{
		printf("BRAK PAMIECI");
		return 0;
	}
	for (int i = 0; i < n; i++)
	{
		tab[i] = (int*)malloc(m * sizeof(int));
		if (tab[i] == NULL)
		{
			printf("BRAK PAMIECI");
			for (int j = 0; j < i; j++)
			{
				free(tab[j]);
			}
			free(tab);
			return 0;
		}
	}
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			tab[i][j] = k;
			printf("%2d ", tab[i][j]);
			k++;
		}
		printf("\n");
	}
	printf("\n\nKoniec programu\n\n");
	return 0;
}