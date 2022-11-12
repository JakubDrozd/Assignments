/*===========================================================================*/
/*                               ZADANIE 36                                  */
/*===========================================================================*/


//#include <stdio.h>
//
//int main()
//{	
//	printf("Program sluzy do obliczania wartosci funckji f(x) = 13(x-2) + 17(x-2)^2 + 23(x-2)^3 dla x podanego przez uzytkownika.\nAutor: Jakub Drozd");
//	printf("\nPodaj wartosc x: ");
//	double x;
//	if (scanf_s("%lf", &x)!=1 || getchar()!='\n')
//	{
//		printf("Bledne dane.");
//		printf("\nKoniec programu.");
//		return 0;
//	}
//	printf("x = %.2lf", x);
//	double common = (x - 2);
//	x = common * (13 + (17 * common) + (23 * common * common));
//	printf("\nf(x) = %.2lf", x);
//	printf("\nKoniec programu.");
//	return 0;
//}


/*===========================================================================*/
/*                               ZADANIE 37                                  */
/*===========================================================================*/


#include <stdio.h>
#include <math.h>

int main()
{
	printf("Program sluzy do obliczania wartosci funkcji f(x, y) = y + sqrt(x^2+y^2) + (x^2 + y^2)/(cos(x^2))\ndla x i y podanych przez uzytkownika.\nAutor: Jakub Drozd");
	printf("\nProsze podac x i y, dla x < |1| i y < |1|: \n");
	double x;
	double y;
	if (scanf_s("%lf", &x)!=1 || getchar()!='\n' || x >= abs(1))
	{
		printf("Bledne dane.");
		printf("\nKoniec programu.");
		return 0;
	}
	else if (scanf_s("%lf", &y)!=1 || getchar()!='\n' || y >= abs(1))
	{
		printf("Bledne dane.");
		printf("\nKoniec programu.");
		
	}
	else {
		printf("x = %.2lf", x);
		printf("\ny = %.2lf", y);
		x = x * x;
		y = y * y;
		x = sqrt(y) + sqrt(x + y) + ((x + y) / (cos(x)));
		printf("\nf(x) = %.2lf", x);
		printf("\nKoniec programu.");
		return 0;
	}
}


/*===========================================================================*/
/*                               ZADANIE 38                                  */
/*===========================================================================*/


//#include <stdio.h>
//
//int main()
//{
//
//}


/*===========================================================================*/
/*                               ZADANIE 39                                  */
/*===========================================================================*/


//#include <stdio.h>
//
//int main()
//{
//
//}


/*===========================================================================*/
/*                               ZADANIE 40                                  */
/*===========================================================================*/


//#include <stdio.h>
//
//int main()
//{
//
//}


/*===========================================================================*/
/*                               ZADANIE 41                                  */
/*===========================================================================*/


//#include <stdio.h>
//
//int main()
//{
//
//}


/*===========================================================================*/
/*                               ZADANIE 42                                  */
/*===========================================================================*/


//#include <stdio.h>
//
//int main()
//{
//
//}


/*===========================================================================*/
/*                               ZADANIE 43                                  */
/*===========================================================================*/


//#include <stdio.h>
//
//int main()
//{
//
//}



