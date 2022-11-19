/*===========================================================================*/
/*                               ZADANIE 44                                  */
/*===========================================================================*/

//
//#include <stdio.h>
//
//int main()
//{
//	printf("Program wypisuje kod ASCII dla podanego przez uzytkownika znaku.\nAutor: Jakub Drozd");
//	char znak;
//	printf("\nPodaj dowolny znak: ");
//	while (scanf_s("%c", &znak)!=1 || getchar()!='\n')
//	{
//		printf("Bledne dane.");
//		printf("\nPodaj dowolny znak: ");
//		int c;
//		while ((c = getchar()) != '\n' && c != EOF)
//			;
//	}
//	printf("Kod ASCII dla \"%c\" to %d\n", znak, znak);
//	return 0;
//}


/*===========================================================================*/
/*                               ZADANIE 45                                  */
/*===========================================================================*/


//#include <stdio.h>
//#include <ctype.h>
//
//int main()
//{
//	printf("Program wypisuje znak dla podanego przez uzytkownika kodu ASCII.\nAutor: Jakub Drozd");
//	int znak;
//	printf("\nPodaj dowolny kod ASCII: ");
//	while (scanf_s("%d", &znak) != 1 || getchar() != '\n')
//	{
//		printf("Bledne dane.");
//		printf("\nPodaj dowolny kod ASCII: ");
//		int c;
//		while ((c = getchar()) != '\n' && c != EOF)
//			;
//	}
//	if (isprint(znak))
//	{
//		printf("Podales kod znaku drukowalnego %c", znak);
//	}
//	else if (iscntrl(znak))
//	{
//		printf("Podales kod znaku kontrolnego");
//	}
//	printf("\nKoniec programu\n");
//	return 0;
//}


/*===========================================================================*/
/*                               ZADANIE 46                                  */
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
/*                               ZADANIE 47                                  */
/*===========================================================================*/


//#include <stdio.h>
//#include <ctype.h>
//
//int main()
//{
//	printf("Program wypisuje date z lat 2001-2050 wypisana przez uzytkownika.\nAutor: Jakub Drozd\n");
//	printf("Podaj dowolna date w formacie (dd.mm.rr): ");
//	int dzien = 0;
//	int miesiac = 0;
//	int rok = 0;
//	char znak;
//	znak = getchar();
//	if (znak < '0' || znak > '3')
//	{
//		printf("Pierwszy znak powinien byc cyfra od 0 do 3.\n");
//		printf("\nKoniec programu.\n\n");
//		return 0;
//	}
//	dzien = znak - '0';
//	znak = getchar();
//	if (!isdigit(znak))
//	{
//		printf("Drugi znak powinien byc cyfra.\n");
//		printf("\nKoniec programu.\n\n");
//		return 0;
//	}
//	dzien = 10 * dzien + (znak - '0');
//	if (dzien > 31) {
//		printf("Dzien miesiaca powinien byc z zakresu 1-31.\n");
//		printf("\nKoniec programu.\n\n");
//		return 0;
//	}
//	if (getchar() != '.') {
//		printf("Trzeci znak powinien byc kropka.\n");
//		printf("\nKoniec programu.\n\n");
//		return 0;
//	}
//	znak = getchar();
//	if (znak < '0' || znak > '1')
//	{
//		printf("Czwarty znak powinien byc cyfra od 0 do 1.\n");
//		printf("\nKoniec programu.\n\n");
//		return 0;
//	}
//	miesiac = znak - '0';
//	znak = getchar();
//	if (znak < '0' || znak > '9')
//	{
//		printf("Piaty znak powinien byc cyfra od 0 do 9.\n");
//		printf("\nKoniec programu.\n\n");
//		return 0;
//	}
//	miesiac = 10 * miesiac + (znak - '0');
//	if (miesiac > 12) {
//		printf("Miesiac powinien byc liczba z zakresu od 1 do 12.\n");
//		printf("\nKoniec programu.\n\n");
//		return 0;
//	}
//	znak = getchar();
//	if (znak != '.')
//	{
//		printf("Szosty znak powinien byc kropka.\n");
//		printf("\nKoniec programu.\n\n");
//		return 0;
//	}
//	znak = getchar();
//	if (znak < '0' || znak > '5')
//	{
//		printf("Siodmy znak powinien byc cyfra od 0 do 5.\n");
//		printf("\nKoniec programu.\n\n");
//		return 0;
//	}
//	rok = znak - '0';
//	znak = getchar();
//	if (!isdigit(znak))
//	{
//		printf("Osmy znak powinien byc cyfra.\n");
//		printf("\nKoniec programu.\n\n");
//		return 0;
//	}
//	rok = 10 * rok + (znak - '0');
//	if (rok < 1 || rok > 50) {
//		printf("Rok powinien byc liczba z zakresu od 1 do 50.\n");
//		printf("\nKoniec programu.\n\n");
//		return 0;
//	}
//	int czyPrzestepny = ((rok % 4 == 0 && rok % 100 != 0) || (rok % 400 == 0));
//	znak = getchar();
//		if (znak != '\n')
//		{
//			printf("Dziewiaty znak powinien byc enterem.\n");
//			printf("\nKoniec programu.\n\n");
//			return 0;
//		}
//		else
//		{
//
//			if (miesiac == 2 && czyPrzestepny == 1 && dzien > 29)
//			{
//				printf("Luty w roku 20%d moze miec maksymalnie 29 dni", rok);
//				printf("\nKoniec programu.\n\n");
//				return 0;
//			}
//			else if (miesiac == 2 && czyPrzestepny == 0 && dzien > 28)
//			{
//				printf("Luty w roku 20%d moze miec maksymalnie 28 dni", rok);
//				printf("\nKoniec programu.\n\n");
//				return 0;
//			}
//			else if ((miesiac == 4 || miesiac == 6 || miesiac == 9 || miesiac == 11) && dzien > 30)
//			{
//				printf("Podany miesiac moze miec maksymalnie 30 dni");
//				printf("\nKoniec programu.\n\n");
//				return 0;
//			}
//			else
//			{
//				printf("\nOto podana data\n");
//				switch (miesiac)
//				{
//				case 1:
//					printf("%d stycznia 20%02d", dzien, rok);
//					break;
//				case 2:
//					printf("%d luty 20%02d", dzien, rok);
//					break;
//				case 3:
//					printf("%d marca 20%02d", dzien, rok);
//					break;
//				case 4:
//					printf("%d kwietnia 20%02d", dzien, rok);
//					break;
//				case 5:
//					printf("%d maja 20%02d", dzien, rok);
//					break;
//				case 6:
//					printf("%d czerwca 20%02d", dzien, rok);
//					break;
//				case 7:
//					printf("%d lipca 20%02d", dzien, rok);
//					break;
//				case 8:
//					printf("%d sierpnia 20%02d", dzien, rok);
//					break;
//				case 9:
//					printf("%d wrzesnia 20%02d", dzien, rok);
//					break;
//				case 10:
//					printf("%d pazdziernika 20%02d", dzien, rok);
//					break;
//				case 11:
//					printf("%d listopada 20%02d", dzien, rok);
//					break;
//				case 12:
//					printf("%d grudnia 20%02d", dzien, rok);
//					break;
//				default:
//					break;
//				}
//			}
//			printf("\nKoniec programu\n");
//		}
//		return 0;
//}


/*===========================================================================*/
/*                               ZADANIE 48                                  */
/*===========================================================================*/


//#include <stdio.h>
//#include <math.h>
//
//int main()
//{
//	printf("Program probuje wypisac 50 poczatkowych poteg liczby 2 na ekranie.\nAutor: Jakub Drozd\n");
//	int liczba;
//	int i = 50;
//	int potega = 0;
//	while (i >= 0)
//	{
//		liczba = pow(2, potega);
//		printf("\n2^%d : %d", potega, liczba);
//		i--;
//		potega++;
//	}
//	printf("\nKoniec programu\n");
//	return 0;
//}


/*===========================================================================*/
/*                               ZADANIE 49                                  */
/*===========================================================================*/


//#include <stdio.h>
//
//int main()
//{
//
//}


/*===========================================================================*/
/*                               ZADANIE 50                                  */
/*===========================================================================*/


//#include <stdio.h>
//
//int main()
//{
//
//}


/*===========================================================================*/
/*                               ZADANIE 51                                  */
/*===========================================================================*/


//#include <stdio.h>
//
//int main()
//{
//
//}


