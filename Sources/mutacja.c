#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include "mutacja.h"

bool *mutacja(int n, int ilosc, float prawd, bool *bufor)
{
	prawd = prawd * 100; //zamiana na procenty
	for (int i = 0; i < ilosc*n; i++)
	{
		int los = rand() % 100;
		if (los >= 0 && los <= prawd - 1) // nastepuje mutacja
		{
			if (bufor[i] == 0)

				bufor[i] = 1;
			else
				bufor[i] = 0;
		}
	}
	return bufor;
}