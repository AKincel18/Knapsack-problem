#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include "final.h"
#include "struct.h"
#include "losowanie.h"
#include "selekcja.h"
#include "krzyzowanie.h"
#include "mutacja.h"
#include "elitaryzm.h"
//#include <vld.h> 

int main(int argc, char *argv[])
{	
		srand(time(NULL));
		double prawd; //prawdopodobienstwo mutacji
		int iteracje, n,ilosc; //liczba iteracji, liczba osobnikow na poczatku, ilosc przedmiotow w plecaku
		for (int i = 1; i < argc-1; i++)
		{
			if (strcmp(argv[i], "-i") == 0) 
				iteracje = atoi(argv[i + 1]);
			else if(strcmp(argv[i], "-n") == 0)
				n = atoi(argv[i + 1]);
			else if (strcmp(argv[i], "-p") == 0)
				prawd = atof(argv[i + 1]);
			else if (strcmp(argv[i], "-r") == 0)
				ilosc = atoi(argv[i + 1]);

		}
		if (argc == 10)
		{
			FILE *plik;
			if ((plik = fopen(argv[1], "rb")) == NULL)
			{
				printf("%s\n", "Zla nazwa pliku! ");
				exit(EXIT_FAILURE);
			}
			int rozmiar; //maksymalny rozmiar plecaka
			fscanf(plik, "%i", &rozmiar); //odczytanie z pliku max wagi plecaka
			struct przedmioty *tab = malloc(sizeof(struct przedmioty) * ilosc); 
			int i = 0;
			while (!feof(plik))
			{
				fscanf(plik, "%s%f%f", &tab[i].nazwa, &tab[i].waga, &tab[i].wartosc);
				i++;
			}
			bool *tablica = losowanie_populacji(n,ilosc,rozmiar,tab);
			int *selekcja;
			bool *bufor;
			float *uni=0;
			float naj = 0;
			float naj_waga = 0;

			for (int i = 0; i < iteracje; i++) 
			{
				selekcja = best(n, ilosc, rozmiar, tablica, tab);
				bufor = krzyzowanie(n, ilosc, selekcja, tablica);
				bufor = mutacja(n, ilosc, prawd, bufor);
				memcpy(tablica, bufor, ilosc*n); //przepisanie tablicy o nazwie 'bufor' do tablicy o nazwie 'tablica'
				uni = elitaryzm(rozmiar, n, ilosc, tablica, tab,naj,naj_waga,uni);
				naj = uni[ilosc];
				naj_waga = uni[ilosc + 1];
				free(selekcja);
				free(bufor);
			}
			final(uni, tab, ilosc); //wypisanie najlepszego osobnika
			free(tablica); 
			free(tab);
			free(uni);
			fclose(plik);

		}

		


		else
		{
			printf("%s","Blednie podane argumenty wejsciowe \n");
		}
		return 0;
}