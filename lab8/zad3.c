#include <stdio.h>
#define CZYT(zmienna, format) \
		printf("Podaj wartosc " #zmienna ":"); \
		scanf("%" #format, &zmienna)

int main() {
	double a;
	int b;
	
	CZYT(a,lf);
	CZYT(b,i);
	
	printf("%lf ", a);
	printf("%i\n", b);
	
	return 0;
}
