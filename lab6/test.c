#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_DL_SLOWA 30

typedef struct sl {
  char slowo[MAX_DL_SLOWA];
  struct sl* dalej;
}*  lista;

//=======================================================

int pusta(lista lis) {
  // jesli  lis  jest lista pusta (wskaznik  NULL)
  // to wartoscia jest liczba rozna od 0, w przeciwnym razie 0
  if (lis == NULL) return 1;
  else return 0;
}

//=======================================================

char* pierwsze(lista lis) {
  // zwraca wskaznik na pierwsze slowo z listy  lis
  // jesli jest pusta, to dzialanie nieokreslone
  return lis->slowo;
}

//=======================================================

lista reszta(lista lis) {
  // zwraca liste  lis  z usunietym pierwszym slowem
  // jesli jest pusta, to dzialanie nieokreslone
  return lis->dalej;
}

//=======================================================

lista dolacz(char slow[MAX_DL_SLOWA], lista lis) {
  // dolacza  slowo  do poczatku listy  lis
  lista nowy_wpis = (lista) malloc(sizeof(struct sl));
  strcpy(nowy_wpis->slowo, slow);
  nowy_wpis->dalej = lis;
  return nowy_wpis;
}

//=======================================================

void druk(lista lis) {
  // drukuje po kolei wszystkie slowa z  lis
  lista element = lis;
  while (element != NULL) {
	puts(element->slowo);
	element = element->dalej;
  }
}

//=======================================================

lista odwroc(lista lis) {
  // odwraca liste  lis  od konca
  lista pom = NULL;
  char slowo[MAX_DL_SLOWA];
  while (! pusta(lis)) {
    strcpy(slowo, pierwsze(lis)); lis = reszta(lis);
    pom = dolacz(slowo, pom);
  }
  return pom;
}

//=======================================================

int main () {
  lista lis = NULL;
  lis = dolacz("abc", dolacz("def", dolacz("ghi", lis)));
  druk(odwroc(lis));
  return 0;
}
