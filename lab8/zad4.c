#include <stdio.h>
#define PETLA(komenda1, warunek, komenda2)	\
		while (warunek) { \
			komenda1; \
			do { \
				komenda1; komenda2; \
			} while (warunek); \
		}

int main() {
	int a=0, b=0, i=0;
	PETLA(a++, i<5, b++; i++)
	
	printf("a=%i, b=%i, i=%i\n", a,b,i);
	
	

	return 0;
}
