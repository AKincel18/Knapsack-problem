#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include "final.h"
#include "struct.h"

void final(float *uni, struct przedmioty *tab, int ilosc)
{
	printf("%s\n", "Lista przedmiotow znajdujacych sie w plecaku: ");
	for (int i = 0; i < ilosc; i++)
	{
		if (uni[i] == 1)
		{
			printf("%s\n", tab[i].nazwa);
		}
	}
	printf("\n%s%f\n%s%f\n", "Wartosc plecaka: ", uni[ilosc], "Waga plecaka: ", uni[ilosc + 1]);
}