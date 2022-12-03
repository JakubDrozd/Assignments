/*===========================================================================*/
/*                               ZADANIE 60                                  */
/*===========================================================================*/


//#include <stdio.h>
//#include <limits.h>
//#include <math.h>
//int main()
//{
//	printf("Program oblicza pole trojkata na podstawie danych zapewnionych przez uzytkownika.\nAutor: Jakub Drozd\n");
//	int wybor = INT_MAX;
//	int wyborKata = INT_MAX;
//	int c;
//
//	double aOdH = 0;
//	double hOdH = 0;
//
//	double pierwszyBok = 0;
//	double drugiBok = 0;
//	double katMiedzyBokami;
//
//	double bokJeden = 0;
//	double bokDwa = 0;
//	double bokTrzy = 0;
//
//	while (wybor != 0)
//	{
//		printf("\n0. Zakoncz program");
//		printf("\n1. Wczytaj bok i spuszczona nan wysokosc");
//		printf("\n2. Wczytaj dwa boki i kat miedzy nimi");
//		printf("\n3. Wczytaj trzy boki\n");
//		while (scanf_s("%d", &wybor) != 1 || wybor < 0 || wybor > 3 || getchar() != '\n')
//		{
//			while ((c = getchar) != '\n' && c != EOF)
//				;
//		}
//		if (wybor == 1)
//		{
//			printf("Podaj bok spuszczony na wysokosc: ");
//			while (scanf_s("%lf", &aOdH) != 1 || aOdH <= 0 || getchar() != '\n')
//			{
//				printf("Niepoprawne dane, popraw: ");
//				while ((c = getchar()) != '\n' && c != EOF)
//					;
//			}
//			printf("Podaj wysokosc trojkata: ");
//			while (scanf_s("%lf", &hOdH) != 1 || hOdH <= 0 || getchar() != '\n')
//			{
//				printf("Niepoprawne dane, popraw: ");
//				while ((c = getchar()) != '\n' && c != EOF)
//					;
//			}
//			printf("\na: %lf", aOdH);
//			printf("\nh: %lf", hOdH);
//			printf("\nP: (%lf * %lf)/2 = %lf", aOdH, hOdH, (aOdH * hOdH) / 2);
//		}
//		if (wybor == 2)
//		{
//			printf("Podaj pierwszy bok: ");
//			while (scanf_s("%lf", &pierwszyBok) != 1 || pierwszyBok <= 0 || getchar() != '\n')
//			{
//				printf("Niepoprawne dane, popraw: ");
//				while ((c = getchar()) != '\n' && c != EOF)
//					;
//			}
//			printf("Podaj drugi bok: ");
//			while (scanf_s("%lf", &drugiBok) != 1 || drugiBok <= 0 || getchar() != '\n')
//			{
//				printf("Niepoprawne dane, popraw: ");
//				while ((c = getchar()) != '\n' && c != EOF)
//					;
//			}
//			printf("Podaj kat miedzy podanymi bokami\n");
//			printf("\n1. w stopniach");
//			printf("\n2. w radianach\n");
//			while (scanf_s("%d", &wyborKata) != 1 || wyborKata < 1 || wyborKata > 2 || getchar() != '\n')
//			{
//				while ((c = getchar()) != '\n' && c != EOF)
//					;
//			}
//			if (wyborKata == 1)
//			{
//				printf("Podaj kat miedzy podanymi bokami w stopniach: \n");
//				while (scanf_s("%lf", &katMiedzyBokami) != 1 || getchar() != '\n')
//				{
//					while ((c = getchar()) != '\n' && c != EOF)
//						;
//				}
//				printf("\na: %lf", pierwszyBok);
//				printf("\nb: %lf", drugiBok);
//				katMiedzyBokami = katMiedzyBokami * (3.14 / 180);
//				printf("\nkat: %lf", katMiedzyBokami);
//				double nowyKat = (0.5 * pierwszyBok * drugiBok * sin(katMiedzyBokami));
//				printf("\nP: (1/2) * %.3lf * %.3lf * sin(%.3lf) = %lf\n", pierwszyBok, drugiBok, katMiedzyBokami, nowyKat);
//			}
//			if (wyborKata == 2)
//			{
//				printf("Podaj kat miedzy podanymi bokami w radianach: \n");
//				while (scanf_s("%lf", &katMiedzyBokami) != 1 || getchar() != '\n') {
//					{
//						while ((c = getchar()) != '\n' && c != EOF)
//							;
//					}
//				}
//				printf("\na: %lf", pierwszyBok);
//				printf("\nb: %lf", drugiBok);
//				printf("\nkat: %lf", katMiedzyBokami);
//				double nowyKat = (0.5 * pierwszyBok * drugiBok * sin(katMiedzyBokami));
//				printf("\nP: (1/2) * %.3lf * %.4lf * sin(%.3lf) = %lf\n", pierwszyBok, drugiBok, katMiedzyBokami, nowyKat);
//			}
//		}
//		if (wybor == 3)
//		{
//			printf("Podaj pierwszy bok: ");
//			while (scanf_s("%lf", &bokJeden) != 1 || bokJeden <= 0 || getchar() != '\n')
//			{
//				printf("Niepoprawne dane, popraw: ");
//				while ((c = getchar()) != '\n' && c != EOF)
//					;
//			}
//			printf("Podaj drugi bok: ");
//			while (scanf_s("%lf", &bokDwa) != 1 || bokDwa <= 0 || getchar() != '\n')
//			{
//				printf("Niepoprawne dane, popraw: ");
//				while ((c = getchar()) != '\n' && c != EOF)
//					;
//			}
//			printf("Podaj trzeci bok: ");
//			while (scanf_s("%lf", &bokTrzy) != 1 || bokTrzy <= 0 || getchar() != '\n')
//			{
//				printf("Niepoprawne dane, popraw: ");
//				while ((c = getchar()) != '\n' && c != EOF)
//					;
//			}
//			if (bokJeden + bokDwa <= bokTrzy || bokJeden + bokTrzy <= bokDwa || bokDwa + bokTrzy <= bokJeden) {
//				printf("Nie mozna zbudowac trojkata z podanych bokow\n");
//			}
//			else
//			{
//				printf("a: %.3lf\n", bokJeden);
//				printf("b: %.3lf\n", bokDwa);
//				printf("c: %.3lf\n", bokTrzy);
//				double p = (bokJeden + bokDwa + bokTrzy) / 2;
//				double pole = sqrt(p * (p - bokJeden) * (p - bokDwa) * (p - bokTrzy));
//				printf("p (polowa obwodu trojkata): (%.3lf + %.3lf + %.3lf)/2 = %3.lf\n", bokJeden, bokDwa, bokTrzy, p);
//				printf("sqrt(%.3lf(%.3lf-%.3lf)(%.3lf-%.3lf)(%.3lf-%.3lf)) = %.3lf\n", p, p, bokJeden, p, bokDwa, p, bokTrzy, pole);
//			}
//		}
//	}
//	printf("\nKoniec programu\n");
//	return 0;
//}


/*===========================================================================*/
/*                               ZADANIE 61                                  */
/*===========================================================================*/


//#include <stdio.h>
//#include <ctype.h>
//
//int main()
//{
//	printf("Program wypisuje godzine wprowadzona przez uzytkownika.\nAutor: Jakub Drozd\n");
//	printf("Podaj dowolna godzine w formacie (hh:mm): ");
//	int godz = 0;
//	int min = 0;
//	char znak;
//	znak = getchar();
//	if (znak < '0' || znak > '2')
//	{
//		printf("Pierwszy znak powinien byc cyfra 0, 1, 2.\n");
//		printf("\nKoniec programu.\n\n");
//		return 0;
//	}
//	godz = znak - '0';
//	znak = getchar();
//	if (!isdigit(znak))
//	{
//		printf("Drugi znak powinien byc cyfra.\n");
//		printf("\nKoniec programu.\n\n");
//		return 0;
//	}
//	godz = 10 * godz + (znak - '0');
//	if (godz > 23) { 
//		printf("Godzina powinna byc z zakresu 0-23.\n");
//		printf("\nKoniec programu.\n\n");
//		return 0;
//	}
//	if (getchar() != ':') {
//		printf("Trzeci znak powinien byc dwukropkiem.\n");
//		printf("\nKoniec programu.\n\n");
//		return 0;
//	}
//	znak = getchar();
//	if (znak < '0' || znak > '5')
//	{
//		printf("Czwarty znak powinien byc cyfra od 0 do 5.\n");
//		printf("\nKoniec programu.\n\n");
//		return 0;
//	}
//	min = znak - '0';
//	znak = getchar();
//	if (!isdigit(znak))
//	{
//		printf("Piaty znak powinien byc cyfra.\n");
//		printf("\nKoniec programu.\n\n");
//		return 0;
//	}
//	min = 10 * min + (znak - '0');
//	if (min > 59) {
//		printf("Minuty powinny byc z zakresu 0-59.\n");
//		printf("\nKoniec programu.\n\n");
//		return 0;
//	}
//	znak = getchar();
//	if (znak != '\n')
//	{
//		printf("Szosty znak powinien byc enterem.\n");
//		printf("\nKoniec programu.\n\n");
//		return 0;
//	}
//	else
//	{
//		printf("\n\nOto podana godzina: \n");
//		if (min == 1)
//		{
//			printf("Minuta po %d", godz);
//		}else if (min >=2 && min <=4 || min >=22 && min <=34)
//		{
//			printf("%d minuty po %d", min, godz);
//		}
//		else
//		{
//			printf("%d minut po %d", min, godz);
//		}
//		printf("\nKoniec programu.\n\n");
//	}
//	return 0;
//}


/*===========================================================================*/
/*                               ZADANIE 62                                  */
/*===========================================================================*/


//#include <stdio.h>
//#include <ctype.h>
//
//enum {false, true};
//
//int main()
//{
//	printf("Program prosi uzykownika o podanie swego imienia.\nAutor: Jakub Drozd\n");
//	_Bool udalo_sie = false;
//	while (!udalo_sie)
//	{
//		char znak;
//		udalo_sie = true;
//		printf("\nJak masz na imie?\n");
//		znak = getchar();
//		if (!isupper(znak))
//		{
//			if (!isalpha(znak))
//			{
//				printf("Imie sklada sie tylko z liter.\n");
//			}
//			else
//			{
//				printf("Imie nalezy pisac wielka litera.\n");
//			}
//			udalo_sie = false;
//			while (znak != '\n')
//			{
//				znak = getchar();
//			}
//			continue;
//		}
//		printf("\nMasz na imie %c", znak);
//		while ((znak = getchar())!='\n')
//		{
//			if (isupper(znak))
//			{
//				printf("...?\nPoza pierwsza litera wszystkie powinny byc male.");
//				udalo_sie = false;
//				while (znak != '\n')
//				{
//					znak = getchar();
//				}
//				continue;
//			}
//			else if (isdigit(znak))
//			{
//				printf("...?\nImie sklada sie tylko z liter.");
//				udalo_sie = false;
//				while (znak != '\n')
//				{
//					znak = getchar();
//				}
//				continue;
//			}
//			else
//			{
//				putchar(znak);
//			}
//		}
//	}
//	printf(".");
//	printf("\nKoniec programu\n");
//	return 0;
//}


/*===========================================================================*/
/*                               ZADANIE 63                                  */
/*===========================================================================*/


//#include <stdio.h>
//
//int main()
//{
//
//}


/*===========================================================================*/
/*                               ZADANIE 64                                  */
/*===========================================================================*/


//#include <stdio.h>
//
//int main()
//{
//
//}


/*===========================================================================*/
/*                               ZADANIE 65                                  */
/*===========================================================================*/


//#include <stdio.h>
//
//int main()
//{
//
//}


/*===========================================================================*/
/*                               ZADANIE 66                                  */
/*===========================================================================*/


//#include <stdio.h>
//
//int main()
//{
//
//}


