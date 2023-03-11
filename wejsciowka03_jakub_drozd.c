
//#include <stdio.h>
//#include <string.h>
//
//#define MAX_ZNAKOW 25								//maks. dl. string'a
//#define MAX_ROZMIAR 5								//maks. rozm. tablicy
//
//struct nowy_typ_t
//{
//	char napis[MAX_ZNAKOW];
//	int liczba;
//};
//
//
//int funkcja(struct nowy_typ_t tab[], int m) {
//	int liczbaSkrocen = 0;
//	for (int i = 0; i < m; i++)
//	{
//		int dl_napisu = (int)strlen(tab[i].napis);
//		int liczba = tab[i].liczba;
//		if (liczba > 0 &&  liczba < dl_napisu)
//		{
//			liczbaSkrocen++;
//			for (int j = liczba; j < dl_napisu; j++)
//			{
//				tab[i].napis[j] = '\0';
//			}
//		}
//	}
//	return liczbaSkrocen;
//}
//
//void wypisz_tab_1W(struct nowy_typ_t tab[], int m) {
//	printf("\n");
//	for (int i = 0; i < m; i++)
//	{
//		printf("[%d] %s", i+1, tab[i].napis);
//		printf("%2d\n", tab[i].liczba);
//	}
//}
//
//
//int wczytajLiczbe() {
//	int liczba;
//	while (scanf_s("%d", &liczba)!=1 || getchar()!='\n')
//	{
//		printf("Bledne dane, podaj liczbe: ");
//		int c;
//		while ((c = getchar()) != '\n' && c != EOF)
//			;
//	}
//	return liczba;
//}
//
//
//
//void wczytaj_dane_tab_1W(struct nowy_typ_t tab[], int m) {
//	for (int i = 0; i < m; i++)
//	{
//		printf("Podaj napis dla [%d]:%3s", i+1, "");
//		scanf_s("%s", tab[i].napis, MAX_ZNAKOW + 1);
//		printf("Podaj liczbe dla [%d]:%2s", i+1, "");
//		tab[i].liczba = wczytajLiczbe();
//	}
//}
//
//int main() {
//	struct nowy_typ_t tab[MAX_ROZMIAR];
//	wczytaj_dane_tab_1W(tab, MAX_ROZMIAR);
//	int liczbaSkrocen = funkcja(tab, MAX_ROZMIAR);
//	wypisz_tab_1W(tab, MAX_ROZMIAR);
//	printf("\n\nLiczba skrocen: %d\n\n", liczbaSkrocen);
//	printf("\n\nKoniec programu\n\n");
//	return 0;
//}