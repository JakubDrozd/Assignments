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
//	if (godz > 59) {
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
//
//int main()
//{
//
//}


/*===========================================================================*/
/*                               ZADANIE 48                                  */
/*===========================================================================*/


//#include <stdio.h>
//
//int main()
//{
//
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


