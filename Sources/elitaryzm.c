#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include "elitaryzm.h"
#include "struct.h"

float *elitaryzm(int rozmiar, int n, int ilosc, bool *tablica, struct przedmioty *tab, float best, float waga2, float *uni)
{
	float wartosc = 0;
	bool wszedl = false;
	int p = 0;
	float waga = 0;
	int osobnik = 0;
	float *t1 = (float*)malloc((ilosc + 2) * sizeof(float));
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

		if (waga <= rozmiar && wartosc>best) //dopuszczalna waga i nowa wartosc wieksza od starej
		{
			best = wartosc;
			osobnik = i;
			waga2 = waga;
			wszedl = true;

			for (int i = 0; i < ilosc; i++)
			{
				t1[i] = tablica[ilosc*osobnik + i]; //kopiowanie najlepszego osobnika do tablicy t1
			}
			t1[ilosc] = best;
			t1[ilosc + 1] = waga2;
		}

		waga = 0;
		wartosc = 0;
	}

	if (wszedl == true) //jak jest lepszy osobnik w tej populacji to zwroc go, w przeciwnym wypadku zwroc 'starego' najlepszego
	{
		free(uni);
		return t1;
	}
	else
	{
		free(t1);
		return uni;
	}
}