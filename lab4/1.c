#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>

/****************************************************************/
// DEFINICJA TYPU LICZB ZESPOLONYCH:

typedef struct {
  double rea, ima;
}  zespol;

/****************************************************************/
// POMOCNICZE:

void  err(char s[]) {  // -- sygnalizacja bledu wejscia
  printf("\n !!! FUNKCJA zesp_get: %s !!!\n\n", s);
  exit(1);
}

/****************************************************************/
// INICJALIZACJE oraz WEJSCIE-WYJSCIE:

zespol  zesp_zestawic (double r, double i) {
    // zestawienie liczby zespolonej z dwoch rzeczywistych
  zespol z;
  z.rea = r;  z.ima = i;
  return z;
}

zespol  zesp_get (void) {
    /* wczytanie liczby zespolonej; powinna skladac sie z dwoch
       rzeczywistych, oraz plusa lub minusa miedzy nimi, zaczynac sie od
       nawiasu otwierajacego, konczyc sie litera i oraz nawiasem
       zamykajacym;
       np.  (123.45 + 67.89i)
    */
  char ch;  zespol z;  int znak_im;
  do { ch = getchar(); } while (isspace(ch));
  if (ch == '(') {
    if (scanf("%lf", &(z.rea)) == 1) {
      do { ch = getchar(); } while (isspace(ch));
      if (ch == '+' || ch == '-') {
	if (ch == '+')  znak_im = 1;
	else  znak_im = -1;
	if (scanf("%lf", &(z.ima)) == 1) {
	  do { ch = getchar(); } while (isspace(ch));
	  if (ch == 'i') {
	    do { ch = getchar(); } while (isspace(ch));
	    if (ch == ')') {
	      if (znak_im == -1)  z.ima = -z.ima;
	    } else err("brak koncowego nawiasu");
	  } else err("brak 'i' na koncu czesci urojonej");
	} else err("niepoprawna czesc urojona");
      } else err("po czesci rzeczywistej brak znaku '+' lub '-'");
    } else err("niepoprawna czesc rzeczywista");
  } else err("brak rozpoczynajacego nawiasu");
  return z;
}

void  zesp_print (zespol z) { // drukowanie liczby zespolonej
  if (z.ima >= 0)
    printf("(%.2lf+%.2lfi)", z.rea, z.ima);
  else
    printf("(%.2lf-%.2lfi)", z.rea, -z.ima);
}

/****************************************************************/
// DZIALANIA:

zespol  zesp_dodac (zespol z1, zespol z2){
	zespol z;
  z.rea=(z1.rea+z2.rea);
  z.ima=(z1.ima+z2.ima);
return z;
}
zespol  zesp_odjac (zespol z1, zespol z2){
	zespol z;
    z.rea=(z1.rea-z2.rea);
	z.ima=(z1.ima-z2.ima);
return z;
}
zespol  zesp_razy (zespol z1, zespol z2){
  zespol z;
  z.rea=(z1.rea*z2.rea+z1.ima*z2.ima);
  z.ima=(z1.rea*z2.ima+z2.rea*z1.ima);
  return z;
}


float zesp_euler(zespol z1, zespol z2){

	zespol z;
	float te;
	z.ima=(z1.ima+z2.ima);
	te = cos(M_PI) + (sin(M_PI)*z.ima) +1 ;
		return te;
	}



double  zesp_abs (zespol z){
	z.rea=sqrt(pow(z.rea,2)+pow(z.rea,2));
return z.rea;
}


zespol silnia (zespol z3)
{
int i, t, wynik;
i=z3.ima;
wynik = 1;
if(i==1 || i==0) z3.ima=1;
else{
  for(t=2;t<=i;t++)
  wynik=wynik*t;
}
z3.ima = wynik;
z3.rea = 0;
  return z3;
}

zespol dzielenie(zespol k, zespol z3){
    zespol z;
z.rea= (k.rea*z3.rea+k.ima*z3.ima)/(z3.rea*z3.rea + z3.ima*z3.ima);
z.ima= (k.ima*z3.rea-k.rea*z3.ima)/(z3.rea*z3.rea + z3.ima*z3.ima);
return z;

}

zespol suminfinity(zespol z1, zespol z2, zespol z3)
{
    int i, j;
    zespol z, k, w, u;
    u.ima = i;
    u.rea = 0;
    z = zesp_dodac(z1, z2);

    for (i=0; i<=10; i++)
    {
        for (j=0; j<=i; j++)
        {
            if (j == 0)  {k.rea = 1; k.ima = 0;}
            else k = zesp_razy(k, z);
        }
        w = zesp_razy(k,dzielenie(k,silnia(z3)));
    }
    return w;
}
/****************************************************************/


int main () {
  zespol  z1, z2, z3;

  printf("\n z1 == "); z1 = zesp_get();
  printf(" z2 == "); z2 = zesp_get();

  printf("\n z1+z2 == "); zesp_print(zesp_dodac(z1, z2));
  printf("\n z1-z2 == "); zesp_print(zesp_odjac(z1, z2));
  printf("\n z1*z2 == "); zesp_print(zesp_razy(z1, z2));
  printf("\n |z1+z2| == %.4lf", zesp_abs(zesp_dodac(z1, z2)));
  printf("\n Tozsamosc Eulera ze wzoru na sume f. trygonometrycznych == %.4f\n\n", zesp_euler(z1, z2));
  printf("\n Wzor na sume n wyrazow == ");  zesp_print(suminfinity(z1, z2, z3));
  printf("\n");
  return 0;
}
