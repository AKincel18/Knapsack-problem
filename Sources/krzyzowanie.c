#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include "krzyzowanie.h"
bool *krzyzowanie(int n, int ilosc, int *selekcja, bool *tablica)
{

	int l = 2; //indeks w tablicy selekcja
	bool *bufor_tablicy;
	bufor_tablicy = (bool*)malloc(ilosc*n * sizeof(bool));
	int pierwszy = selekcja[0] * ilosc, drugi = selekcja[1] * ilosc;
	int i1 = 0, i2 = ilosc;
	int nieparz_r = 0; //rzeczy
	if (ilosc % 2 == 1) //sprawdzanie czy ilosc przedmiotow jest nieparzysta
		nieparz_r = 1; //jesli tak to ustaw zmienna na 1
	for (int i = 0; i < n / 2; i++)
	{
		for (int i = 0; i < ilosc / 2; i++)
		{

			bufor_tablicy[i1] = tablica[drugi];
			bufor_tablicy[i2] = tablica[pierwszy];
			i1++; drugi++; i2++; pierwszy++;
		}
		for (int i = 0; i < ilosc / 2 + nieparz_r; i++) //jesli jest nieparzysta ilosc przedmiotow to gdy np jest 7 to krzyzuja sie 3 pierwsze, a 4 nie
		{
			bufor_tablicy[i1] = tablica[pierwszy];
			bufor_tablicy[i2] = tablica[drugi];
			i1++; pierwszy++; i2++; drugi++;
		}
		i1 = i1 + ilosc;
		i2 = i2 + ilosc;
		pierwszy = selekcja[l] * ilosc;
		l++;
		drugi = selekcja[l] * ilosc;
		l++;
	}

	if (n % 2 == 1) //jesli ilosc osobnikow nieparzysta to ostatniego osobnika przepisz bez zmian
	{
		for (int i = 0; i < ilosc; i++)
		{
			bufor_tablicy[(n - 1)*ilosc + i] = tablica[(n - 1)*ilosc + i];
		}
	}
	return bufor_tablicy;
}