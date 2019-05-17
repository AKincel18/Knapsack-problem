#pragma once
/*
Funkcja zwracajaca tablice z najlepszym osobnikiem po wykonaniu 
wszystkich elementow algorytmu genetycznego.
Parametry funkcji:
rozmiar- max waga plecaka
n- ilosc osobnikow
ilosc- ilosc przedmiotow w plecaku
*tablica- populacja
*tab- wskaznik na tablice struktur
best- najlepsza dotychczasowa wartosc
waga- najlepsza dotychczasowa waga
*uni- tablica zawieraja najlepszego osobnika
*/
float *elitaryzm(int rozmiar, int n, int ilosc, bool *tablica, struct przedmioty *tab, float best, float waga2, float *uni);
