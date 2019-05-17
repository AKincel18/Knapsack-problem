#pragma once
/*
Funkcja zwracajaca populacje po mutacji
Parametry funkcji:
n- ilosc osobnikow
ilosc- ilosc przedmiotow w plecaku
prawd- prawdopodobienstwo mutacji
*bufor- tablica pomocnicza reprezentujaca populacje
*/
bool *mutacja(int n, int ilosc, float prawd, bool *bufor);
