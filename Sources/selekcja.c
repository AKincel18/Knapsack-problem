#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include "selekcja.h"
#include "struct.h"

int *best(int n, int ilosc, int rozmiar, bool *tablica, struct przedmioty *tab)
{
	float *the_best;
	float suma = 0;
	float waga = 0;
	the_best = (float*)malloc(n * sizeof(float)); //tablica wartosci przedmiotow
	int p = 0; //licznik
	float wartosc = 0;
	for (int i = 0; i < n; i++)
	{
		for (int i = 0; i < ilosc; i++)
		{
			if (tablica[p] == 1)
			{
				wartosc = wartosc + tab[p%ilosc].wartosc;
				waga = waga + tab[p%ilosc].waga;
			}
			p++;
		}
		if (waga > rozmiar) //przekroczono maksymalna wage
		{
			the_best[i] = 0; //przypisujemy 0 zeby sie 'zly' osobnik nie krzyzowal
		}
		else
		{
			the_best[i] = wartosc;
			suma = suma + wartosc;
		}

		waga = 0;
		wartosc = 0;
	}
	//przypisywanie poszczegolnym osobnikom wartosci 
	for (int i = 0; i < n; i++)
	{

		the_best[i] = (the_best[i] / suma) * RAND_MAX;
		wartosc = the_best[i] + wartosc;
		if (i != 0)
			the_best[i] = wartosc;
	}

	int *selekcja;
	selekcja = (int*)malloc(n * sizeof(int)); //ustawianie w pary
	int q = 0;
	for (int i = 0; i < n; i++)
	{
		float los = (rand() % RAND_MAX);
		for (int i = 0; i < n; i++)
		{
			if (i == 0 && the_best[i]>los) //pierwszy
			{
				selekcja[q] = i;
				q++;
			}
			else if (i == n - 1 && the_best[i] < los) //ostatni 
			{
				selekcja[q] = i;
				q++;
			}
			else if (the_best[i]<los && the_best[i + 1]>los) //srodkowy
			{
				selekcja[q] = i + 1;
				q++;
			}
		}


	}
	free(the_best);
	return selekcja; //-----> ustawione w pary elementy
}