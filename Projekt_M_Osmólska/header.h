/**@file*/
#pragma once
#ifndef header_h
#define header_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct wydatki {
    int budget;
    int child;
    int rent;
    int groceries;
    int bills;
    int education;
    int all;
    struct wydatki * next;
} wydatki;
/**Funkcja "add" dodaje elementy do listy*/
void add(wydatki** lista, wydatki* nowa);
/**Funkcja "addinfo" pobiera dane potrzebne do zapisania do listy, potem w funkcji uzywamy funkcji "add"*/
void addinfo(wydatki** lista);
/**Funckja "show_list" wypisuje dane do pliku(o nazwe pliku pytamy uzytkownika), funkcja pyta rowniez o informacje na temat wydatkow czlonka rodziny,
funkcja oblicza czy budzet zostal przekroczony i czy czlonek rodziny o nazwie "dziecko" przekroczyl swoj limit i zapisuje te informacje do pliku*/
void show_list(wydatki* lista);
/**Funkcja "show_history" wypisuje dane z konkretnego pliku, ktory zawiera informacje na temat wydatkow w danym miesiacu( o nazwe pliku pytamy uzytkownika*/
void show_history();
/**W funkcji "add_year" pytamy uzytkownika, ktory plik miesieczny chcemy dodac do pliku zawierajacego informacje o wydatkach z calego roku(o nazwe pliku i rok pytamy uzytkownika*/
void add_year();
/**Funkcja "show_year" wypisuje informacje na temat wydatkow z calego roku(o nazwe pliku pytamy uzytkownika)*/
void show_year();
#endif // header_h
