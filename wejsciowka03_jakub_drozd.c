
#include <stdio.h>
#include <string.h>

#define MAX_ZNAKOW 25								//maks. dl. napisu
#define MAX_ROZMIAR 5								//maks. rozm. tablicy

struct nowy_typ_t
{
	char napis[25];
	int liczba;
};


int funkcja(struct nowy_typ_t tab[], int m) {
	int liczbaSkrocen = 0;
	for (int i = 0; i < m; i++)
	{
		int dl_napisu = strlen(tab[i].napis);
		int liczba = tab[i].liczba;
		if (liczba > 0 &&  liczba < dl_napisu)
		{
			liczbaSkrocen++;
			for (int j = liczba; j < dl_napisu; j++)
			{
				tab[i].napis[j] = NULL;
			}
		}
	}
	return liczbaSkrocen;
}

void wypisz_tab_1W(struct nowy_typ_t tab[], int m, int n) {
	for (int i = 0; i < m; i++)
	{
		printf("%s", tab[i].napis);
		printf("%2d", tab[i].liczba);
	}
}


int main() {
	struct nowy_typ_t tab[MAX_ROZMIAR] = {NULL};
	tab[0].liczba = 3;
	strcpy_s(tab[0].napis, strlen("jakub")+1, "jakub");
	int liczbaSkrocen = funkcja(tab, MAX_ROZMIAR);
	wypisz_tab_1W(tab, MAX_ROZMIAR, MAX_ZNAKOW);
	printf("\n\nLiczba skrocen: %d\n\n", liczbaSkrocen);
	return 0;
}