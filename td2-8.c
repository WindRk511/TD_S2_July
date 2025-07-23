/* algorithme max-min
constant : NN <- 50 : entier 
Variable :
    A[NN] : entier;
    max, posmax = 0, min, posmin = 0, n : entier;

fonction remplitab (pointeur tab : entier , pointeur taille : entier ) : vide
debut
	Variable : i :entier ;
	faire 
		ecrire("Entre la taille de de tableau : ");
		lire(taille);
		si ( *taille <= 0 || *taille > NN) alors
			afficher("Entrer la valeur entre 1 et 50 !!!\n");
		}
	tantque ( *taille <= 0 || *taille > NN); 
	afficher ("\ntaille=",*taille);
	pour (i <- 0; i < *taille; i++) 
		ecrire("case[",i,"]=");
		lire(tab + i);
	finpour
fin

fonction mindet (pointeur tab : entier , taille : entier , pointeur pst : entier ) : entier 
debut
	Variable : i :entier ;
           	pointeur vmin : entier;
               vmin<-*tab
	pour (i <- 0; i < taille; i++) {
		si (vmin <- *(tab + i)) alors
			continue;
		
		sinon si(vmin>*(tab + i)) alors 
			vmin <-*(tab + i);
			*pst <- i;
		finsi
	finpour
	retourne(vmin);
fin

fonction maxdet (pointeur tab : entier , taille : entier , pointeur pst : entier ) : entier 
debut 
	 variable :   i : entier ;
	     vmax : entier ;
        vmax <- *tab;
	pour (i <-0; i < taille; i++) {
		si (vmax = *(tab + i)) {
			continue;
		finsi
		si ( vmax <*(tab + i)) alors
			vmax <- *(tab + i);
			*pst <- i;
		finsi
	finpour
	retourne (vmax);
fin

debut

	afficher ("Remplie le tableau A :\n ");
	remplitab (A,&n);

	max=maxdet(A,n,&posmax);	//determine la valeur maximal et sa position
	afficher ("La valeur maximale de A est ",max,"à la position ",posmax);

	min=mindet(A,n,&posmin);	//determine la valeur minimal et sa position
	afficher ("La valeur minimal de tableau A est ",min ,"à la position ",posmin);
	retourne (0);
fin
 
*/
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
