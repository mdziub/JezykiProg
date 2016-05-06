#include <stdio.h>
#define MAX_DL_IM 11
#define MAX_DL_NA 17

typedef  struct {
	char imie[MAX_DL_IM];
	char nazwisko[MAX_DL_NA];
	int pensja;
} osoba;

osoba *lista_osob = NULL;

int czytanie(const char *sciezka) {
	int ile_osob = 0;
	FILE *plik_bazy = fopen(sciezka, "r");
	if (plik_bazy != NULL) {
		//
		//	Zliczanie wpisow
		//
		osoba tymczasowa;		
		while (fscanf(plik_bazy, "%s %s %i", 
			&tymczasowa.imie[0], &tymczasowa.nazwisko[0], &tymczasowa.pensja) == 3) {
			++ile_osob;
		}
		//
		//	Alokacja pamieci dla listy osob
		//
		lista_osob = (osoba*) malloc(sizeof(osoba) * ile_osob);
		if (lista_osob == NULL) {
			ile_osob = 0;
		}
		else {
			fseek(plik_bazy, 0, SEEK_SET);	// przewijanie pliku na poczatek
			int i;
			for (i=0; i<ile_osob; i++) {
				fscanf(plik_bazy, "%s %s %i", &lista_osob[i].imie[0], 
						&lista_osob[i].nazwisko[0], &tymczasowa.pensja);
			}
		}
		fclose(plik_bazy);
	}
	return ile_osob;
}
void pisanie(const char *sciezka, int ile) {
	FILE *nowa_baza = fopen(sciezka, "w");
	if (nowa_baza != NULL) {
		int i;
		for (i=0; i<ile; i++) {
			fprintf(nowa_baza, "%s %s %i\n", lista_osob[i].imie, 
					lista_osob[i].nazwisko,  lista_osob[i].pensja);
		}
		fclose(nowa_baza);
	}
}
int porownanie(osoba *pierwsza, osoba *druga) {
	int wynik = strcmp(pierwsza->nazwisko, druga->nazwisko);
	if (wynik == 0) {
		return strcmp(pierwsza->imie, druga->imie);
	}
	else return wynik;
}
void sortowanie(osoba *wskaznik, int dlugosc) {
	if (wskaznik == NULL) {
		sortowanie(lista_osob, dlugosc);
	}
	else if (dlugosc > 1) {
		int n = dlugosc / 2;
		int m = dlugosc - n;
		
		osoba *T = wskaznik;
		osoba *U = wskaznik + n;
		
		sortowanie(T, n);
		sortowanie(U, m);
		
		osoba *tymczasowa = (osoba*) malloc(sizeof(osoba) * dlugosc);
		int p_T=0, p_U=0, licznik=0;
		while (licznik < dlugosc) {
			if (p_T < n && p_U < m) {
				int por = porownanie(U + p_U, T + p_T);
				if (por > 0) {
					tymczasowa[licznik] = T[p_T];					
					++p_T;
				}
				else {
					tymczasowa[licznik] = U[p_U];
					++p_U;
				};
			} 
			else {
				if (p_T == n) {
					tymczasowa[licznik] = U[p_U];
					++p_U;
				}
				else {
					tymczasowa[licznik] = T[p_T];
					++p_T;
				}
			}
			++licznik;
		}
		memcpy(wskaznik, tymczasowa, sizeof(osoba) * dlugosc);
		free(tymczasowa);
	}
}
int main (int arg_num, char* arg[]) {
	if (arg_num == 3) {
		int ile = czytanie(arg[1]);
		if (ile > 0) {
			sortowanie(NULL,ile);
			pisanie(arg[2], ile);
		}
		else puts("nie wczytano zadnych osob");
	}
	else printf("\n Poprawne wywolanie: './porzadkuj dane wynik'\n\n");
	return 0;
}
