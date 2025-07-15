#include<stdio.h>
#define NN 50

void remplitab (int *tab, int *taille)
{
	int i;
	do {
		printf("Entre la taille de de tableau : ");
		scanf("%d",taille);
		if ( *taille <= 0 || *taille > NN) {
			printf("Entrer la valeur entre 1 et 50 !!!\n");
		}
	} while  ( *taille <= 0 || *taille > NN); 
	printf("\ntaille=%d\n",*taille);
	for (i = 0; i < *taille; i++) {
		printf("case[%d]=",i);
		scanf("%d",tab + i);
	}
}

int mindet (int *tab, int taille, int *pst)
{
	int i;
	int vmin = *tab;
	for(i = 0; i < taille; i++) {
		if (vmin == *(tab + i)) {
			continue;
		}
		else if(vmin>*(tab + i)){
			vmin =*(tab + i);
			*pst = i;
		}
	}
	return (vmin);
}

int maxdet (int *tab, int taille, int *pst)
{
	int i;
	int vmax = *tab;
	for(i = 0; i < taille; i++) {
		if (vmax == *(tab + i)) {
			continue;
		}
		if ( vmax <*(tab + i)) {
			vmax =*(tab + i);
			*pst = i;
		}
	}
	return (vmax);
}

int main ()
{
	int A[NN];
	int max, posmax = 0, min, posmin = 0, n;

	printf ("Remplie le tableau A :\n ");
	remplitab (A,&n);

	max=maxdet(A,n,&posmax);	//determine la valeur maximal et sa position
	printf("La valeur maximale de A est %d à la position %d\n",max,posmax);

	min=mindet(A,n,&posmin);	//determine la valeur minimal et sa position
	printf("La valeur minimal de tableau A est %d à la position %d\n",min,posmin);
	return (0);
}
