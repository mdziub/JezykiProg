#include <stdio.h>

#define WYSOKOSC		8
#define SZEROKOSC		8

int szachownica[WYSOKOSC][SZEROKOSC];
int ilosc_hetmanow;

void zeruj_szachownice(void) {
	int x, y;
	for (y=0; y<WYSOKOSC; y++)
		for (x=0; x<SZEROKOSC; x++) szachownica[y][x] = 0;
}

int main() {
	zeruj_szachownice();
	
	printf("Podaj liczbe hetmanow: ");
	scanf("%i", &ilosc_hetmanow);
	
	char c;
	int n, x, y;
	for (n=1; n<=ilosc_hetmanow; n++) {
		printf("Podaj pozycje hetmana %i", n);
		scanf("%c%i", &c, &y);
		
	}
	
	return 0;
}
