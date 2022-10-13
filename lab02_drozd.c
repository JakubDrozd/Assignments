/*===========================================================================*/
/*                               ZADANIE 10                                  */
/*===========================================================================*/


/*#include <stdio.h>

int main()
{
	putchar('x');
	putchar(':');
	putchar('\t');
	putchar('f');
	putchar('(');
	putchar('x');
	putchar(')');
	putchar(':');
	putchar('\n');
	putchar('3');
	putchar('\t');
	putchar('5');
	getchar();
	return 0;
}*/


/*===========================================================================*/
/*                               ZADANIE 11                                  */
/*===========================================================================*/


//#include <stdio.h>
//
//int main()
//{
//	printf("d: %d\n", -5);  // -5
//	printf("d: %o\n", -5);  // 37777777773
//	printf("d: %u\n", -5);  // 4294967291
//	printf("d: %lf\n", -5);  //specified: 'double', received: 'int'
//	printf("d: %le\n", -5);  //specified: 'double', received: 'int'
//	printf("d: %lg\n", -5);  //specified: 'double', received: 'int'
//	printf("d: %s\n", -5);  //specified: 'char*', received: 'int'
//	getchar();
//	return 0;



/*===========================================================================*/
/*                               ZADANIE 12                                  */
/*===========================================================================*/


//#include <stdio.h>
//
//int main()
//{
//	printf("d: %d\n", -5.0);  //  -random
//	printf("d: %o\n", -5.0);  // 0
//	printf("d: %u\n", -5.0);  // 0
//	printf("d: %lf\n", -5.0); // -5.000000
//	printf("d: %le\n", -5.0);  // -5.000000e+00
//	printf("d: %lg\n", -5.0);  // -5
//	printf("d: %s\n", -5.0);  // (null)
//}


/*===========================================================================*/
/*                               ZADANIE 13                                  */
/*===========================================================================*/


/*#include <stdio.h>

int main()
{
	printf("%d + %d = %lf\t argumenty: 2x zmiennopozycyjne, wynik zmiennopozycyjny\n", 2, 3, 2.0 + 3.0);
	printf("%d - %d = %lf\t argumenty: 2x zmiennopozycyjne, wynik zmiennopozycyjny\n", 2, 3, 2.0 - 3.0);
	printf("%d * %d = %lf\t argumenty: 2x zmiennopozycyjne, wynik zmiennopozycyjny\n", 2, 3, 2.0 * 3.0);
	printf("%d : %d = %lf\t argumenty: 2x zmiennopozycyjne, wynik zmiennopozycyjny\n", 3, 2, 3.0 / 2.0);
	printf("%d : %d = %lf\t argumenty: 2x zmiennopozycyjne, wynik zmiennopozycyjny\n", 2, 3, 2.0 / 3.0);
	printf("-------------------------------------------------------------------------------\n");
	printf("%d + %d = %d\t argumenty: 2x calkowite, wynik calkowity\n", 2, 3, 2 + 3);
	printf("%d - %d = %d\t argumenty: 2x calkowite, wynik calkowity\n", 2, 3, 2 - 3);
	printf("%d * %d = %d\t argumenty: 2x calkowite, wynik calkowity\n", 2, 3, 2 * 3);
	printf("%d / %d = %d\t argumenty: 2x calkowite, wynik calkowity\n", 3, 2, 3 / 2);
	printf("%d / %d = %d\t argumenty: 2x calkowite, wynik calkowity\n", 2, 3, 2 / 3);
	printf("-------------------------------------------------------------------------------\n");
	printf("%d + %d = %lf\t argumenty: 1x zmiennopozycyjne | 1x calkowite, wynik zmiennopozycyjny\n", 2, 3, 2.0 + 3);
	printf("%d - %d = %lf\t argumenty: 1x zmiennopozycyjne | 1x calkowite, wynik zmiennopozycyjny\n", 2, 3, 2.0 - 3);
	printf("%d * %d = %lf\t argumenty: 1x zmiennopozycyjne | 1x calkowite, wynik zmiennopozycyjny\n", 2, 3, 2.0 * 3);
	printf("%d / %d = %lf\t argumenty: 1x zmiennopozycyjne | 1x calkowite, wynik zmiennopozycyjny\n", 3, 2, 3.0 / 2);
	printf("%d / %d = %lf\t argumenty: 1x zmiennopozycyjne | 1x calkowite, wynik zmiennopozycyjny\n", 2, 3, 2.0 / 3);
	printf("-------------------------------------------------------------------------------\n");
	printf("%d + %d = %d\t argumenty: 1x zmiennopozycyjne | 1x calkowite, wynik calkowity\n", 2, 3, 2.0 + 3);
	printf("%d - %d = %d\t argumenty: 1x zmiennopozycyjne | 1x calkowite, wynik calkowity\n", 2, 3, 2.0 - 3);
	printf("%d * %d = %d\t argumenty: 1x zmiennopozycyjne | 1x calkowite, wynik calkowity\n", 2, 3, 2.0 * 3);
	printf("%d / %d = %d\t argumenty: 1x zmiennopozycyjne | 1x calkowite, wynik calkowity\n", 3, 2, 3.0 / 2);
	printf("%d / %d = %d\t argumenty: 1x zmiennopozycyjne | 1x calkowite, wynik calkowity\n", 2, 3, 2.0 / 3);
	getchar();
	return 0;
}*/


/*===========================================================================*/
/*                               ZADANIE 14                                  */
/*===========================================================================*/


//#include <stdio.h>
//
//int main()
//{
//	printf("%s\n", "ala");	//ala
//	printf("%s\n", ’ala’);	//blad kompilacji
//	printf("%s\n", ala);	//blad kompilacji
//	printf("%s\n""ala");	//nieprawidlowy znak
//	printf("%s\n", "5");	// 5	
//	printf("%s\n", ’5’);	//b³¹d kompilacji
//	printf("%s\n", 5);		// 5
//	getchar();
//	return 0;
//}

/*===========================================================================*/
/*                               ZADANIE 15                                  */
/*===========================================================================*/


//#include <stdio.h>
//
//int main()
//{
//	printf("Sekwencja specjalna\ntekst za nia.\n");		//nowy wiersz
//	printf("Sekwencja specjalna\ttekst za nia.\t");		//tabulator
//	printf("Sekwencja specjalna\vtekst za nia.\v");		//pionowy tabulator
//	printf("Sekwencja specjalna\btekst za nia.\b")		//backspace	
//	printf("Sekwencja specjalna\rtekst za nia.\r");		//przesuwa pozycje wypisywania na poczatek linii
//	printf("Sekwencja specjalna\ftekst za nia.\f");		//przesuwa pozycje wypisywania do nastepnej strony
//	printf("Sekwencja specjalna\atekst za nia.\a");		//alert
//	printf("Sekwencja specjalna\\tekst za nia.\\");		//Nic
//	printf("Sekwencja specjalna\?tekst za nia.\?");		//zamienia znak przed i po na '?'
//	printf("Sekwencja specjalna\" tekst za nia.\"");
//	getchar();
//	return 0;
//}


/*===========================================================================*/
/*                               ZADANIE 16                                  */
/*===========================================================================*/


//#include <stdio.h>
//
//int main()
//{
//	printf("Uzywanie sekwencji specjalnych.\n");
//	printf("%s\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\%s", "\n", "\n");
//	printf("Czy %c%c%c oznacza w C to samo co ’a’?\n", '"', 'a', '"');
//	printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\%s", "\n");
//	printf("\nKoniec.");
//	return 0;
//}


/*===========================================================================*/
/*                               ZADANIE 17                                  */
/*===========================================================================*/


//#include <stdio.h>
//int main()
//{
//	int liczba;
//	printf("Podaj liczbe: ");
//	scanf_s("%d", &liczba);
//	printf("Podales liczbe: %d", liczba);
//	printf("\nKoniec.");
//	return 0;
//}


/*===========================================================================*/
/*                               ZADANIE 18                                  */
/*===========================================================================*/


//#include <stdio.h>
//
//#include <stdio.h>
//int main()
//{
//	double liczba;
//	printf("Podaj liczbe zmiennoprzecinkowa: ");
//	scanf_s("%lf", &liczba);
//	printf("Podales liczbe: %lf", liczba);
//	printf("\nKoniec.");
//	return 0;
//}


/*===========================================================================*/
/*                               ZADANIE 19                                  */
/*===========================================================================*/


//#include <stdio.h>
//
//int main()
//{
//	int liczba1;
//	int	liczba2;
//	printf("Podaj pierwsza liczbe: ");
//	scanf_s("%d", &liczba1);
//	printf("Podaj druga liczbe: ");
//	scanf_s("%d", &liczba2);
//	printf("Podales liczby: %d i %d\n", liczba1, liczba2);
//	printf("Koniec.");
//	return 0;
//}

