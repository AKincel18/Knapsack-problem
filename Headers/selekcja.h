#pragma once
/* 
Funkcja zwracajaca tablice z ustawionymi w pary osobnikami do krzyzowania
Parametry funkcji:
n- ilosc osobnikow
ilosc- ilosc przedmiotow
rozmiar- max waga
*tablica- populacja
*tab- wskaznik na tablice struktur
*/
int *best(int n, int ilosc, int rozmiar, bool *tablica, struct przedmioty *tab);
