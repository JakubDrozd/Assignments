//#include <stdio.h>
//#define DLUGOSC 5
//
//void info() {
//	printf("Program szyfruje tekst wprowadzony przez uzytkownika.\nAutor: Jakub Drozd\n");
//}
//
//void odnajdywanie(char napis[], int m, char A[][5], char* B[], int* p) {																								 
//	for (int i = 0; i < m; i++)
//	{											// Uzupelnia tablice B adresami znakow z napisu z tablicy
//		for (int j = 0; j < m; j++)				// alfabetu
//		{
//			for (int k = 0; k < m; k++)
//			{
//				if (napis[i] == A[j][k])
//				{
//					B[*p] = &A[j][k];
//					(*p)++;
//				}
//			}
//		}
//	}
//}
//
//void wypiszNapis(char *B[], int p) {			// Pozwala wyswietlic napis za pomoca adresowania posredniego
//	for (int i = 0; i < p; i++)
//	{
//		if (B[i] != NULL)
//		{
//			printf("%c", *B[i]);
//		}
//	}
//}
//
//void przestaw(char A[][5], int m) {				// Zamiana kolejnosci wierszy tablicy 2D
//	for (int i = 0; i < m; i++)
//	{
//		char temp;
//		temp = A[0][i];
//		A[0][i] = A[1][i];	
//		A[1][i] = temp;
//		temp = A[2][i];
//		A[2][i] = A[3][i];
//		A[3][i] = temp;
//		temp = A[1][i];
//		A[1][i] = A[2][i];
//		A[2][i] = temp;
//		temp = A[3][i];
//		A[3][i] = A[4][i];
//		A[4][i] = temp;
//	}
//}
//
//void powrot(char A[][5], int m) {				// Odszyfrowuje tablice alfabetu
//	for (int i = 0; i < m; i++)
//	{
//		char temp;
//		temp = A[0][i];
//		A[0][i] = A[2][i];
//		A[2][i] = temp;
//		temp = A[2][i];
//		A[2][i] = A[1][i];
//		A[1][i] = temp;
//		temp = A[2][i];
//		A[2][i] = A[4][i];
//		A[4][i] = temp;
//		temp = A[3][i];
//		A[3][i] = A[4][i];
//		A[4][i] = temp;
//	}
//}
//
//int main() {
//	info();
//	printf("\nMaksymalna ilosc znakow slowa: %d\n", DLUGOSC);
//	int p = 0;									// Licznik do tablicy B
//	char A[5][5] = {{'a', 'f', 'k', 'p', 'v'},	// Tablica z z literami alfabetu
//					{'b', 'g', 'l', 'r', 'w'},
//					{'c', 'h', 'm', 's', 'x'},
//					{'d', 'i', 'n', 't', 'y'},
//					{'e', 'j', 'o', 'u', 'z'}
//	};
//	char* B[DLUGOSC] = {NULL};					// Tablica z adresami liter z napisu podanego przez uzytkownika
//	char napis[DLUGOSC+1];						// Aby moc wpisac 5 literowe slowo, potrzebuje tablice z 6 miejscami, bo string ma jeszcze znak	
//	printf("Podaj slowo: ");					// konca napisu '\0' np. " jakub " to " jakub + '\0' "
//	scanf_s("%s", napis, DLUGOSC + 1);
//	odnajdywanie(napis, DLUGOSC, A, B, &p);
//	printf("\nPodales slowo: ");
//	wypiszNapis(B, p);
//	przestaw(A, DLUGOSC);						// Szyfruje napis, zamieniajac kolejnosc wierszy alfabetu
//	printf("\nZaszyfrowane slowo: ");
//	wypiszNapis(B, p);
//	powrot(A, DLUGOSC);							// Odszyfrowuje napis, przywracajac poczatkowa kolejnosc wierszy alfabetu
//	printf("\nOdszyfrowane slowo: ");
//	wypiszNapis(B, p);
//	printf("\n\nKoniec programu.\n\n");
//	return 0;
//}
//
////#include <stdio.h>
////#include <string.h>
////
////int main() {
////	struct student_t
////	{
////		char imie[25];
////		int wiek;
////		double srednia;
////	};
////	struct student_t uczniowie[17];
////	struct student_t j_drozd;
////	strcpy_s(j_drozd.imie, strlen("Jakub Drozd") + 1, "Jakub Drozd");
////	j_drozd.wiek = 20;
////	j_drozd.srednia = 4.1;
////	struct student_t m_jastrzebski;
////	strcpy_s(m_jastrzebski.imie, strlen("Michal Jastrzebski") + 1, "Michal Jastrzebski");
////	m_jastrzebski.wiek = 21;
////	m_jastrzebski.srednia = 0;
////	uczniowie[0] = j_drozd;
////	uczniowie[1] = m_jastrzebski;
////	for (int i = 0; i < 2; i++)
////	{
////		printf("Imie: %15s\n", uczniowie[i].imie);
////		printf("Wiek: %9d\n", uczniowie[i].wiek);
////		printf("Srednia: %8.2lf\n", uczniowie[i].srednia);
////		printf("\n\n");
////	}
////}