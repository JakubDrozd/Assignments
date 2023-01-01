/*===========================================================================*/
/*                               ZADANIE 82                                  */
/*===========================================================================*/


//#include <stdio.h>
//
//#define MAX 100
//
//void info() {
//	printf("Program wczytuje n liczb calkowitych i sprawdza czy wsrod nich znajduje sie para.\nAutor: Jakub Drozd.\n");
//	printf("Ile liczb chcesz podac? [1,100]\n");
//}
//
//int wczytajIlosc(void) {
//	int liczba;
//	while (scanf_s("%d", &liczba)!=1 || liczba < 0 || liczba > 100 || getchar()!='\n')
//	{
//		printf("Bledne dane, podaj liczbe calkowita [1,100]: ");
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
//		printf("Bledne dane, podaj liczbe calkowita [1,100]: ");
//		int c;
//		while ((c = getchar()) != '\n' && c != EOF)
//			;
//	}
//	return liczba;
//}
//
//void wczytajDoTab(int tab[], int n) {
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d. ", i+1);
//		tab[i] = wczytajLiczbe();
//	}
//}
//
//void wypiszTab(int tab[], int n) {
//	printf("Podales liczby:\n");
//	for (int i = 0; i < n; i++)
//	{
//		if (i == n-1)
//		{
//			printf("%d", tab[i]);
//		}
//		else
//		{
//			printf("%d, ", tab[i]);
//		}
//	}
//}
//
//void czyPara(int tab[], int n) {
//	int iloscPar = 0;
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = i+1; j < n ; j++)
//		{
//			if (tab[j] == tab[i])
//			{
//				iloscPar++;
//			}
//		}
//	}
//	if (iloscPar > 0)
//	{
//		printf("\nW podanych liczbach znajduje sie para");
//	}
//	else
//	{
//		printf("\nW podanych liczbach nie ma pary\n");
//	}
//}
//
//int main()
//{
//	info();
//	int ilosc = wczytajIlosc();
//	int tab[MAX];
//	printf("Podaj liczby:\n");
//	wczytajDoTab(tab, ilosc);
//	wypiszTab(tab, ilosc);
//	czyPara(tab, ilosc);
//	printf("\n\nKoniec programu.\n\n");
//	return 0;
//}


/*===========================================================================*/
/*                               ZADANIE 83                                  */
/*===========================================================================*/


//#include <stdio.h>
//
//int main()
//{
//
//}


/*===========================================================================*/
/*                               ZADANIE 84                                  */
/*===========================================================================*/


#include <stdio.h>

void info() {
	printf("Program oblicza (n k), gdzie n i k sa podane przez uzytkownika.\nAutor: Jakub Drozd\n");
}

int wczytajLiczbe(void) {
	int liczba;
	while (scanf_s("%d", &liczba) != 1 || getchar() != '\n')
	{
		printf("Bledne dane, podaj liczbe: ");
		int c;
		while ((c = getchar()) != '\n' && c != EOF)
			;
	}
	return liczba;
}

int newton(int n, int k) {
	return factorial(n) / (factorial(k) * factorial(n - k));
}

int factorial(int n) {
	int factorial = 1;
	for (int i = 1; i <= n; i++)
	{
		factorial *= i;
	}
	return factorial;
}


int main()
{
	info();
	int n = wczytajLiczbe();
	int k = wczytajLiczbe();
	printf("n = %d\nk = %d\n", n, k);
	printf("Newton: %d\n\n", newton(n, k));
}


/*===========================================================================*/
/*                               ZADANIE 85                                  */
/*===========================================================================*/


//#include <stdio.h>
//
//int main()
//{
//
//}


/*===========================================================================*/
/*                               ZADANIE 86                                  */
/*===========================================================================*/


//#include <stdio.h>
//
//int main()
//{
//
//}

