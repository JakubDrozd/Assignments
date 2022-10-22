//#include <stdio.h>
//int main() {
//	int number = 1;
//	int factorialOfNumber = 1;
//	printf("Podaj liczbe calkowita:");
//	scanf_s("%d", &number);
//	printf("Podales liczbe: %d", number);
//	printf("\nLiczenie silni liczby %d...", number);
//	for (size_t i = 1; i <= number; i++)
//	{
//		factorialOfNumber *= i;
//	}
//	printf("\nSilnia liczby %d to %d", number, factorialOfNumber);
//	printf("\nKoniec programu.");
//	return 0;
//}

#include <stdio.h>
int main() {
	int liczba;
	printf("Podaj liczbe calkowita\n");
	if (!scanf_s("%d", &liczba))
	{
		printf("Bledne dane.");
		printf("\nKoniec programu.");
		return 0;
	}
	if (liczba >0)
	{
		printf("Podana liczba %d jest dodatnia", liczba);
		printf("\nKoniec programu.");
		return 0;
	}
	else if (liczba <=0) {
		printf("Podana liczba %d jest niedodatnia", liczba);
		printf("\nKoniec programu.");
		return 0;
	}
}