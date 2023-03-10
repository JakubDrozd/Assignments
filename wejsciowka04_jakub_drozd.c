#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
//C:\\Users\\PATOX\\Desktop\\uczniowie.txt

typedef struct 
{
	int indeks;
	char napis[80];
	int ocena;
}para;

void wiersz( FILE *plik,  para tab[]) {
	char sciezka[80];
	printf("Podaj sciezke pliku zrodlowego: ");
	scanf_s("%s", sciezka, 80);
	plik = fopen(sciezka, "r");

	if (plik == NULL)
	{
		printf("Nie udalo sie otworzyc pliku\n");
	}
	else
	{
		int indeks;
		char napis[80];
		int ocena;
		fscanf(plik, "%d %80s %d", &indeks, napis, &ocena);
		strcpy(tab[0].napis, napis);
	}
	if (plik !=NULL)
	{
		fclose(plik);
	}
}


int main() {
	FILE* plik;
	para tab[5];
	wiersz(&plik, tab);
	printf("%s", tab[0].napis);
	return 0;
}