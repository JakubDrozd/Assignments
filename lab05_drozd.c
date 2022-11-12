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


//#include <stdio.h>
//#include <math.h>
//
//int main()
//{
//	printf("Program sluzy do obliczania wartosci funkcji f(x, y) = y + sqrt(x^2+y^2) + (x^2 + y^2)/(cos(x^2))\ndla x i y podanych przez uzytkownika.\nAutor: Jakub Drozd");
//	printf("\nProsze podac x i y, dla x < |1| i y < |1|: \n");
//	double x;
//	double y;
//	if (scanf_s("%lf", &x)!=1 || getchar()!='\n' || x >= abs(1))
//	{
//		printf("Bledne dane.");
//		printf("\nKoniec programu.");
//		return 0;
//	}
//	else if (scanf_s("%lf", &y)!=1 || getchar()!='\n' || y >= abs(1))
//	{
//		printf("Bledne dane.");
//		printf("\nKoniec programu.");
//		
//	}
//	else {
//		printf("x = %.2lf", x);
//		printf("\ny = %.2lf", y);
//		x = x * x;
//		y = y * y;
//		x = sqrt(y) + sqrt(x + y) + ((x + y) / (cos(x)));
//		printf("\nf(x, y) = %.2lf", x);
//		printf("\nKoniec programu.");
//		return 0;
//	}
//}


/*===========================================================================*/
/*                               ZADANIE 38.1                                */
/*===========================================================================*/


//#include <stdio.h>
//
//int main()
//{
//	printf("Program wykonuje operacje arytmetyczne.\nAutor: Jakub Drozd");
//	printf("\nPodaj pierwsza liczbe: ");
//	double pierwszaLiczba;
//	double drugaLiczba;
//	int wybor;
//	if (scanf_s("%lf", &pierwszaLiczba) != 1 || getchar() != '\n')
//	{
//		printf("Bledne dane.");
//		printf("\nKoniec programu.");
//		return 0;
//	}
//	printf("Podaj druga liczbe: ");
//	if (scanf_s("%lf", &drugaLiczba) != 1 || getchar() != '\n')
//	{
//		printf("Bledne dane.");
//		printf("\nKoniec programu.");
//	}
//	else {
//		printf("\nPierwsza liczba: %.2lf", pierwszaLiczba);
//		printf("\nDruga liczba: %.2lf", drugaLiczba);
//		printf("\n\nJakie dzialanie chcesz wykonac?");
//		printf("\n1. dodawanie");
//		printf("\n2. odejmowanie");
//		printf("\n3. mnozenie");
//		printf("\n4. dzielenie\n");
//		if (scanf_s("%d", &wybor) != 1 || getchar() != '\n' || wybor > 4 && wybor < 1)
//		{
//			printf("Wybrana operacja nie istnieje");
//			printf("\nKoniec programu.");
//			return 0;
//		}
//		else if (wybor == 1)
//		{
//			printf("\nWybrano operacje dodawania\n");
//			printf("%.2lf + %.2lf = %.2lf", pierwszaLiczba, drugaLiczba, pierwszaLiczba + drugaLiczba);
//		}
//		else if (wybor == 2)
//		{
//			printf("\nWybrano operacje odejmowania\n");
//			printf("%.2lf - %.2lf = %.2lf", pierwszaLiczba, drugaLiczba, pierwszaLiczba - drugaLiczba);
//		}
//		else if (wybor == 3)
//		{
//			printf("\nWybrano operacje mnozenia\n");
//			printf("%.2lf * %.2lf = %.2lf", pierwszaLiczba, drugaLiczba, pierwszaLiczba * drugaLiczba);
//		}
//		else if (wybor == 4)
//		{
//			printf("\nWybrano operacje dzielenia\n");
//			if (drugaLiczba == 0)
//			{
//				printf("Nie mozna dzielic przez '0'\n");
//			}
//			else
//			{
//				printf("%.2lf / %.2lf = %.2lf\n", pierwszaLiczba, drugaLiczba, pierwszaLiczba / drugaLiczba);
//			}
//		}
//		printf("\nKoniec programu.\n");
//		return 0;
//		}
//	}

/*===========================================================================*/
/*                               ZADANIE 38.2                                */
/*===========================================================================*/


//#include <stdio.h>
//
//int main()
//{
//	printf("Program wykonuje operacje arytmetyczne.\nAutor: Jakub Drozd");
//	double pierwszaLiczba;
//	double drugaLiczba;
//	int wybor;
//	printf("\nPodaj pierwsza liczbe: ");
//	if (scanf_s("%lf", &pierwszaLiczba) != 1 || getchar() != '\n')
//	{
//		printf("Bledne dane.");
//		printf("\nKoniec programu.\n");
//		return 0;
//	}
//	printf("Podaj druga liczbe: ");
//	if (scanf_s("%lf", &drugaLiczba)!=1 || getchar()!='\n')
//	{
//		printf("Bledne dane.");
//		printf("\nKoniec programu.\n");
//	}
//	else
//	{
//		printf("Pierwsza liczba %.2lf", pierwszaLiczba);
//		printf("\nDruga liczba %.2lf", drugaLiczba);
//		printf("\n\nJakie dzialanie chcesz wykonac?");
//		printf("\n1. dodawanie");
//		printf("\n2. odejmowanie");
//		printf("\n3. mnozenie");
//		printf("\n4. dzielenie\n");
//		if (scanf_s("%d", &wybor)!=1 || getchar()!='\n')
//		{
//			printf("Bledne dane.");
//			printf("\nKoniec programu.\n");
//		}
//		else {
//			switch (wybor)
//			{
//			case 1:
//				printf("\nWybrano operacje dodawania\n");
//				printf("%.2lf + %.2lf = %.2lf", pierwszaLiczba, drugaLiczba, pierwszaLiczba + drugaLiczba);
//				break;
//			case 2:
//				printf("\nWybrano operacje odejmowania\n");
//				printf("%.2lf - %.2lf = %.2lf", pierwszaLiczba, drugaLiczba, pierwszaLiczba - drugaLiczba);
//				break;
//			case 3:
//				printf("\nWybrano operacje mnozenia\n");
//				printf("%.2lf * %.2lf = %.2lf", pierwszaLiczba, drugaLiczba, pierwszaLiczba * drugaLiczba);
//				break;
//			case 4:
//				printf("\nWybrano operacje dzielenia\n");
//				if (drugaLiczba == 0)
//				{
//					printf("Nie mozna dzielic przez '0'\n");
//				}
//				else
//				{
//					printf("%.2lf / %.2lf = %.2lf", pierwszaLiczba, drugaLiczba, pierwszaLiczba / drugaLiczba);
//				}
//				break;
//			default:
//				printf("Wybrana operacja nie istnieje");
//				break;
//			}
//		}
//		printf("\nKoniec programu.\n");
//		return 0;
//	}
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



