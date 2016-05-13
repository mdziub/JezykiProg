#include <stdio.h>

double *A, *B;
int n, k;

void wczytaj_liczby(double *M) {
	int x, y;
	for (y=0; y<n; y++) {
		printf("Podaj %i liczb w wierszu %i: ", k, y+1);
		for (x=0; x<k; x++) {
			scanf("%lf", &M[y * k + x]);		
		}
	}
}

void transpozycja(double *X, double *Y) {
	int x, y;
	for (y=0; y<n; y++) {
		for (x=0; x<k; x++) {
			Y[ x * n + y ] = X[ y * k + x ];
		}
	}
}

void wypisz_macierz(double *X, int w, int s) {
	int x, y;
	for (y=0; y<w; y++) {
		printf("\n");
		for (x=0; x<s; x++) {
			printf("%g ", X[ y * s + x ]);
		}
	}
	printf("\n");
}

int main() {
	printf("Podaj rozmiary macierzy (wys x szer): ");
	scanf("%i %i", &n, &k);
	
	if (n <= 0 || k <= 0) 
		puts("Bledne rozmiary");
	else {
		A = (double*) malloc( sizeof(double) * n * k );
		B = (double*) malloc( sizeof(double) * n * k );
		if (A == NULL || B == NULL) {
			puts("Blad alokacji");
			return -1;
		}
		wczytaj_liczby(A);
		transpozycja(A, B);
		wypisz_macierz(B, k, n);
		
		free(A);
		free(B);
	}
	return 0;
}
