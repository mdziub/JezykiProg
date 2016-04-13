#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define IMIE_MAX 10
#define NAZW_MAX 15
#define IL_OSOB 10000

typedef struct {
  char imie[IMIE_MAX+1];
  char nazwisko[NAZW_MAX+1];
  int pensja;
} osoba;

osoba spis[IL_OSOB];

//=======================================================

void  utworz_spis(void) {
  FILE* baza = fopen("/home/pracinf/stefan/public_html/Dydaktyka/JezProg/Slajdy/Labs05/baza_danych", "r");
  if (baza == NULL) printf("\n ZLE\n\n");
  int i;
  for (i=0; i<IL_OSOB; i++) {
    fscanf(baza, "%s", spis[i].imie);
    fscanf(baza, "%s", spis[i].nazwisko);
    fscanf(baza, "%i", &spis[i].pensja);
  }
  fclose(baza);
}

//=======================================================

void  sortuj_spis(void) {
  osoba tymczasowa;
  /* sortuje  spis  alfabetycznie wg nazwisk,
     a w przypadku rownych nazwisk wg imion
  */
  int n;
  for (n=0; n<IL_OSOB; n++){
    int i;
	for (i=1; i<IL_OSOB; i++) {
		int wynik = strcmp(spis[i].nazwisko, spis[i-1].nazwisko);
		if (wynik < 0) {
			tymczasowa = spis[i];
			spis[i] = spis[i-1];
			spis[i-1] = tymczasowa;
		} else if (wynik == 0) {
			int wynik_2 = strcmp(spis[i].imie, spis[i-1].imie);
			if (wynik_2 < 0) {
				tymczasowa = spis[i];
				spis[i] = spis[i-1];
				spis[i-1] = tymczasowa;
			}
		}
	}
}
}

//=======================================================

int  znajdz_nazwisko (
  char na[NAZW_MAX+1],
  char im[IMIE_MAX+1], int *p
) {
  /* do danego nazwiska  na  znajduje w spisie
     imie  im  oraz pensje  p
     jesli znajdzie, to zwraca 1, jesli nie, to 0
  */
  int i_start = 0;
  int dlugosc = IL_OSOB;

  do {
	  osoba srodkowa = spis[i_start + (dlugosc / 2)];
	  int porownanie = strcmp(srodkowa.nazwisko, na);
	  if (porownanie > 0) {
		  dlugosc /= 2;
	  } else if (porownanie < 0) {
		  i_start += (dlugosc / 2);
		  dlugosc /= 2;
	  } else {
		  strcpy(im, srodkowa.imie);
		  *p = srodkowa.pensja;
		  return 1;
	  }
  } while (dlugosc > 0);
  return 0;
}

//=======================================================

int  znajdz_imie (
  char im[NAZW_MAX+1],
  char na[IMIE_MAX+1], int *p
) {
  /* do danego imienia  im  znajduje w spisie
     nazwisko  na  oraz pensje  p
     jesli znajdzie, to zwraca 1, jesli nie, to 0
  */
  int i;
  for (i=0; i<IL_OSOB; i++) {
	  if (!strcmp(im, spis[i].imie)) {
		strcpy(na, spis[i].nazwisko);
		*p = spis[i].pensja;
		return 1;
	  }
  }
  return 0;
}

//=======================================================

int main () {
  char odpowiedz, im[NAZW_MAX+1], na[IMIE_MAX+1];
  int p;

  utworz_spis(); sortuj_spis();

  do {
    printf(
     "\n Znalezc wg imienia (I), nazwiska (N), czy zakonczyc (Q)? "
    );
    do { odpowiedz = getchar(); }
    while (isspace(odpowiedz));
    odpowiedz = tolower(odpowiedz);
    switch (odpowiedz) {
    case 'i' :
      printf("\n szukane imie: ");
      scanf("%s", im);
      if (znajdz_imie(im, na, &p))
	printf(" IMIE: %s, NAZWISKO: %s, PENSJA: %i\n", im, na, p);
      else  printf(" nie ma imienia %s\n", im);
      break;
    case 'n' :
      printf("\n szukane nazwisko: ");
      scanf("%s", na);
      if (znajdz_nazwisko(na, im, &p))
	printf(" IMIE: %s, NAZWISKO: %s, PENSJA: %i\n", im, na, p);
      else  printf(" nie ma nazwiska %s\n", na);
      break;
    case 'q' : break;
    default :
      printf(" Poprawne odpowiedzi: N, I, Q.\n");
    }
  }  while (tolower(odpowiedz) != 'q');

  printf("\n DZIEKUJE.\n\n");
  return 0;
}

