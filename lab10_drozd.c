/*===========================================================================*/
/*                               ZADANIE 75                                  */
/*===========================================================================*/


#include <stdio.h>

void info() {
	printf("Program wczytuje do tablicy liczby i wypisuje ja na dwa sposoby.\nAutor: Jakub Drozd\n");
}

int wczytaj_int(void) {
	int liczba;
	while (scanf_s("%d", &liczba)!=1 || getchar()!='\n')
	{
		printf("Bledne dane, popraw:\t\t");
		int c;
		while ((c = getchar()) != '\n' && c != EOF)
			;
	}
	return liczba;
}

void wczytaj_int_1W(int tab[], int n) {
	for (int i = 0; i < n; i++)
	{
		printf("Liczba %d: ", i + 1);
		tab[i] = wczytaj_int();
	}
}

void wypisz_liczby(int tab[], int n) {
	printf("Podane liczby: [");
	for (int i = 0; i < n; i++)
	{
		if (i == n-1)
		{
			printf("%d", tab[i]);
		}
		else
		{
		printf("%d, ", tab[i]);

		}
	}
	printf("]\n");
	printf("Podane liczby (odwrocone): [");
	for (int i = n-1; i >=0; --i)
	{
		if (i == 0)
		{
			printf("%d", tab[i]);
		}
		else
		{
			printf("%d, ", tab[i]);
		}
	}
	printf("]");
}

#define ILE 10 // ilosc pobranych liczb

int main()
{
	info();
	int liczby[ILE] = {0};
	wczytaj_int_1W(liczby, ILE);
	wypisz_liczby(liczby, ILE);
	return 0;
}


/*===========================================================================*/
/*                               ZADANIE 76                                  */
/*===========================================================================*/




/*===========================================================================*/
/*                               ZADANIE 77                                  */
/*===========================================================================*/


//#include <stdio.h>
//
//int main()
//{
//}


/*===========================================================================*/
/*                               ZADANIE 78                                  */
/*===========================================================================*/


//#include <stdio.h>
//
//int main()
//{
//
//}


/*===========================================================================*/
/*                               ZADANIE 79                                  */
/*===========================================================================*/


//#include <stdio.h>
//
//int main()
//{
//
//}


/*===========================================================================*/
/*                               ZADANIE 80                                  */
/*===========================================================================*/


//#include <stdio.h>
//
//int main()
//{
//
//}


/*===========================================================================*/
/*                               ZADANIE 81                                  */
/*===========================================================================*/


//#include <stdio.h>
//
//int main()
//{
//
//}


