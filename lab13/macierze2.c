#include <stdio.h>

int n, m, k;
double *A, *B, *C;

void wczytaj_macierz(double *X, int w, int h) {
	int x, y;
	for (y=0; y<h; y++) {
		printf("Podaj %i liczb w wierszu %i: ", w, y+1);
		for (x=0; x<w; x++) {
			scanf("%lf", &X[ w * y + x ]);			
		}
	}
	printf("\n");
}

void mnozenie_macierzy(double *X, double *Y, double *Z) {
	int x, y, z;
	for (x=0; x<k; x++)
	for (y=0; y<n; y++) {
		Z[ n * y + x ] = 0;
		for (z=0; z<k; z++) {
			Z[ n * y + x ] += X[ n * x + z ] * Y[ m * z + y ];
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
	printf("Podaj rozmiary n x m x k: ");
	scanf("%i %i %i", &n, &m, &k);
	
	if (n <= 0 || m <= 0 || k <= 0 || n != k) 
		puts("Bledne rozmiary");
	else {
		A = (double*) malloc(sizeof(double) * n * m);
		B = (double*) malloc(sizeof(double) * m * k);
		C = (double*) malloc(sizeof(double) * n * k);
		if (A == NULL || B == NULL || C == NULL) {
			puts("Blad alokacji");
			return -1;
		}
		puts("Wprowadz macierz A:");
		wczytaj_macierz(A, n, m);
		puts("Wprowadz macierz B:");
		wczytaj_macierz(B, m, k);
		puts("A * B = C: ");
		mnozenie_macierzy(A, B, C);
		wypisz_macierz(C, k, n);
		
		
		free(A);
		free(B);
		free(C);
	}
	return 0;
}
