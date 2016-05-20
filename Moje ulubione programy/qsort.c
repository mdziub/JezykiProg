#include <stdio.h>
#include <time.h>
#include <math.h>

    #define n 100
    int tab[n];


    //#define n 6
    //int tab[n]={23,6,11,12,17,19};



void swap(int *a,int *b) // zamienia miejscami a i b
{
int temp=*a;
*a=*b;
*b=temp;
}

void qsort(int *tab, int left, int right, int c)
{
if (left+c < right){
	    int i;
	int m=left;
	for(i=left+1;i<=right;i++)
		 if (tab[i]<tab[left])
			swap(&tab[++m],&tab[i]);
	swap(&tab[left],&tab[m]);
	qsort(tab,left,m-1,c);
	qsort(tab,m+1,right,c);
	}
}

void insertsort(int *tab){
    int i;
    for(i=1;i<n;i++){
        int j=i;
        int temp=tab[j];
        while((j>0) && tab[j-1]>temp){
            tab[j]=tab[j-1];
            j--;
        }
        tab[j]=temp;
    }
}

main(){
    int i;
    char b;
			for (i=0;i<100;i++){
			tab[n]=rand()%100;
			n+1;
		}
            printf("Przed sortowaniem:\n");
            for(i=0; i<n; i++){
                printf("%i ",tab[i]);
}
            printf("\n");
			clock_t start = clock();
            qsort(tab,0,n-1,2);
            clock_t stop;
			printf("czas:%lu\n", clock()- start);

            printf("Po sortowaniu quicksort:\n");
            for (i=0; i<n; i++){
                printf("%i ",tab[i]);

}
			printf("\n");

			printf("\n");
            insertsort(tab);

        printf("Po sortowaniu insertsort:\n");
            for(i=0; i<n; i++){
                printf("%i ",tab[i]);
}
            printf("\n");

			
}
