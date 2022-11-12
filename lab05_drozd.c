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
//#include <math.h>
//
//int main()
//{
//	printf("Program oblicza wartosc funkcji f(x) = 2^x dla x > 0, -1 w p.p dla x podanego przez u¿ytkownika.\nAutor: Jakub Drozd");
//	printf("\nProsze o podanie liczby zmiennopozycyjnej: ");
//	double x;
//	if (scanf_s("%lf", &x)!=1 || getchar()!='\n')
//	{
//		printf("Bledne dane.");
//		printf("\nKoniec programu.\n");
//		return 0;
//	}
//	else {
//		int warunek = (int)x > 0;
//		printf("x = %.2lf", x);
//		switch (warunek)
//		{
//		case 1:
//			x = pow(2, x);
//			break;
//		default:
//			x = -1;
//			break;
//		}
//		printf("\nf(x) = %.2lf", x);
//	}
//	printf("\nKoniec programu.");
//	return 0;
//}


/*===========================================================================*/
/*                               ZADANIE 40                                  */
/*===========================================================================*/


//#include <stdio.h>
//#include <math.h>
//
//int main()
//{
//	printf("Program oblicza odleglosc punktu (x, y) od poczatku ukladu wspolrzednych, gdzie x i y podaje uzytkownik.\nAutor: Jakub Drozd");
//	printf("\nPodaj wspolrzedna x: ");
//	double x;
//	double y;
//	double R;
//	double drugieR;
//	if (scanf_s("%lf", &x) != 1 || getchar()!='\n')
//	{
//		printf("Bledne dane.");
//		printf("\nKoniec programu.\n");
//		return 0;
//	}
//	printf("Podaj wspolrzedna y: ");
//	if (scanf_s("%lf", &y) != 1 || getchar() != '\n')
//	{
//		printf("Bledne dane.");
//		printf("\nKoniec programu.\n");
//		return 0;
//	}
//	else
//	{
//		R = sqrt(pow(x,2)+pow(y,2));
//		if (x == 0)
//		{
//			drugieR = abs(y);
//		}
//		else if (abs(x) >= abs(y) && x!= 0)
//		{
//			drugieR = abs(x) * (sqrt(1 + pow((y / x), 2)));
//		}
//		else
//		{
//			drugieR = abs(y) * (sqrt(1 + pow((x / y), 2)));
//		}
//		if (R == drugieR)
//		{
//			printf("\nOBA ALGORYTMY DAJA TEN SAM WYNIK.");
//			printf("\nOdleglosc punktu (%.2lf, %.2lf) od (0, 0) wynosi %.2lf", x, y, R);
//		}
//		else
//		{
//			printf("\nALGORYTMY DAJA ROZNE WYNIKI.");
//			printf("\nOdleglosc punktu (%.2lf, %.2lf) od (0, 0) wynosi: ", x, y);
//			printf("\nwg \"klasycznego\" algorytmu %.17lf", R);
//			printf("\nwg \"specjalnego\" algorytmu %.17lf", drugieR);
//			printf("\nWartosc bezwzgledna roznicy miedzy wynikami: %E", abs(R - drugieR));
//		}
//	}
//	return 0;
//}


/*===========================================================================*/
/*                               ZADANIE 41                                  */
/*===========================================================================*/


//#include <stdio.h>
//
//int main()
//{
//	printf("Program sprawdza czy dwa wektory o wspolrzednych podanych przez uzytkownika sa do siebie prostopadle czy rownolegle.\nAutor: Jakub Drozd ");
//	printf("\nPodaj wspolrzedne pierwszego wektora: ");
//	int pX;
//	int pY;
//	int dX;
//	int dY;
//	if (scanf_s("%d", &pX)!=1 || getchar()!='\n')
//	{
//		printf("Bledne dane.");
//		printf("\nKoniec programu.\n");
//		return 0;
//	}
//	if (scanf_s("%d", &pY) != 1 || getchar() != '\n')
//	{
//		printf("Bledne dane.");
//		printf("\nKoniec programu.\n");
//		return 0;
//	}
//	printf("\nPierwszy wektor: [%d, %d]\n", pX, pY);
//	printf("\nPodaj wspolrzedne drugiego wektora: ");
//	if (scanf_s("%d", &dX) != 1 || getchar() != '\n')
//	{
//		printf("Bledne dane.");
//		printf("\nKoniec programu.\n");
//		return 0;
//	}
//	if (scanf_s("%d", &dY) != 1 || getchar() != '\n')
//	{
//		printf("Bledne dane.");
//		printf("\nKoniec programu.\n");
//		return 0;
//	}
//	printf("Drugi wektor: [%d, %d]\n", dX, dY);
//	if (((pX * dY) - (dX * pY)) == 0) {
//		printf("Wektory [%d, %d] i [%d, %d] sa rownolegle", pX, pY, dX, dY);
//	}
//	else if (((pX * dX) + (pY * dY)) == 0) {
//		printf("Wektory [%d, %d] i [%d, %d] sa prostopadle", pX, pY, dX, dY);
//	}
//	else {
//		printf("Wektory [%d, %d] i [%d, %d] nie sa ani prostopadle ani rownolegle wobec siebie", pX, pY, dX, dY);
//	}
//	printf("\nKoniec programu.\n");
//	return 0;
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
//	printf("Program pokazuje uzytkownikowi ktora z trzech podanych przez niego liczb jest najmniejsza.\nAutor: Jakub Drozd");
//	printf("\nPodaj trzy liczby: \n");
//	double pierwsza;
//	double druga;
//	double trzecia;
//	if (scanf_s("%lf", &pierwsza)!=1 || getchar()!='\n')
//	{
//		printf("Bledne dane.");
//		printf("\nKoniec programu.\n");
//	}
//	if (scanf_s("%lf", &druga) != 1 || getchar() != '\n')
//	{
//		printf("Bledne dane.");
//		printf("\nKoniec programu.\n");
//	}
//	if (scanf_s("%lf", &trzecia) != 1 || getchar() != '\n')
//	{
//		printf("Bledne dane.");
//		printf("\nKoniec programu.\n");
//	}
//	if (pierwsza >= druga && pierwsza >= trzecia)
//	{
//		printf("Najwieksza liczba to %.5lf", pierwsza);
//	}
//	else if (druga >= pierwsza && druga >= trzecia) {
//		printf("Najwieksza liczba to %.5lf", druga);
//	}
//	else if (trzecia >= pierwsza && trzecia >= druga)
//	{
//		printf("Najwieksza liczba to %.5lf", trzecia);
//	}
//	printf("\nKoniec programu.\n");
//	return 0;
//}



