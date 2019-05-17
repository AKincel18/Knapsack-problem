#pragma once
/*
Funkcja zwraca tablice wylosowanych przedmiotow danej ilosci osobnikow.
Parametry funkcji:
n- ilosc osobnikow
ilosc- ilosc przedmiotow w plecaku
rozmiar- max waga plecaka
*tab- wskaznik na tablice struktur
*/
bool *losowanie_populacji(int n, int ilosc, int rozmiar, struct przedmioty *tab);
