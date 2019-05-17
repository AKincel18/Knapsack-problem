#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include"losowanie.h"
#include "struct.h"

bool *losowanie_populacji(int n, int ilosc, int rozmiar, struct przedmioty *tab)
{
	bool *tablica;
	tablica = (bool*)malloc(ilosc*n * sizeof(bool));
	int skonczone = 0;
	float wartosc = 0;
	float max_waga = 0;
	for (int i = 0; i < n; i++)
	{


		do
		{
			int los = (rand() % ilosc) + i*ilosc; //losowanie liczb dla danego osobnika
			bool los_bin = (rand() % 2); //losowanie 1 lub 0-> czy dany przedmiot jest w plecaku(1) czy nie(0)
			if (los_bin == 1 && tab[los%ilosc].waga + max_waga <= rozmiar && tablica[los] != 1 && tablica[los] != 0) //jesli wylosowano 1, nie przekracza wagi plecaka, nie wylosowano wczesniej liczby na tej pozycji
			{
				tablica[los] = 1;
				max_waga = max_waga + tab[los%ilosc].waga;
				wartosc = wartosc + tab[los%ilosc].wartosc;
				skonczone++;
			}
			else
			{
				if (tablica[los] != 0 && tablica[los] != 1) //jesli nie wylosowano wczesniej liczby na pozycji 'los'
				{
					tablica[los] = 0;
					skonczone++;
				}

			}
		} while (skonczone != ilosc);
		skonczone = 0;
		wartosc = 0;
		max_waga = 0;


	}
	return tablica;

}
