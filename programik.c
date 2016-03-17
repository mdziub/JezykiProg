int programik(char *tab){

int n = 0;
int i;

for(i=0;i<255;i++){
	scanf("%c", &tab[i]);
	if(tab[i] == 10) break;
	n++;	
	};

int k = 0;
int m = n;

for(i=0;i<n;i++){
	printf("%c", tab[i]);
	m--;
	if(m%3==0) printf("_");
	};
	
printf("\n\n");
	
int x = 0;
	
	for(i=0;i<n;i++){
		x=(x*10)+tab[i]-'0';
	};
	
return x;

}
