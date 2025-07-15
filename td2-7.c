/*
Algorithme: produit scalaire
constant NN 50
variable
    U[NN], V[NN], pscal : entier;
    n = 0 : entier;			//dimension du vecteur

 defvect(int *vect, int *dim) :vide
debut
i : entier; 
    afficher("Definisson du vecteur :\n");
    si (*dim == 0) alors		//verifie si la dimention ne soit pas definie
	faire
	    afficher("Donner la dimension de vecteur de chaque vecteur: ");
	    lire(dim);
	    si (*dim == 0 || *dim > NN) alors
		    afficher("Entrer la valeur superieur de zéro et cinquante !!! \n");
	    finsi
	tantque (*dim <= 0 || *dim > NN);
    sinon
	printf("La dimension de ce vecteur est %d\n", *dim);
    finsi

	afficher("Entre la/les coordonne(s) de vecteur(s) : (sous forme (x1;x2;...))\n");
    pour (i <-  0; i < *dim; i++) {
	afficher("x",i + 1,"=");
	lire(vect + i);
    finpour
fin

xscal(int *vect1, int *vect2, int dim) : entier	//fonction qui calcule le produit scalaire
debut
   scal <- 0 : entier;
   i : entier;
    pour (i <- 0; i < dim; i++)
	scal <- scal + (*(vect1 + i)) * (*(vect2 + i));
    finpour
    afficher("La produit scalaire de U et V est ", scal);
    retourne (scal);
fin

debut
    defvect(U, &n);

    defvect(V, &n);

    xscal(U, V, n);

    return (0);
*/

#include<stdio.h>
#define NN 50

void defvect(int *vect, int *dim)
{
    int i;
    printf("Definisson du vecteur :\n");
    if (*dim == 0) {		//verifie si la dimention ne soit pas definie
	do {
	    printf("Donner la dimension de vecteur de chaque vecteur: ");
	    scanf("%d", dim);
	    if (*dim == 0 || *dim > NN) {
		printf
		    ("Entrer la valeur superieur de zéro et cinquante !!! \n");
	    }

	}
	while (*dim <= 0 || *dim > NN);
    } else {
	printf("La dimension de ce vecteur est %d\n", *dim);
    }

    printf
	("Entre la/les coordonne(s) de vecteur(s) : (sous forme (x1;x2;...))\n");
    for (i = 0; i < *dim; i++) {
	printf("x%d=", i + 1);
	scanf("%d", vect + i);
    }
}

int xscal(int *vect1, int *vect2, int dim)	//fonction qui calcule le produit scalaire
{
   int scal = 0;
    int i;
    for (i = 0; i < dim; i++) {
	scal = scal + (*(vect1 + i)) * (*(vect2 + i));
    }
    printf("La produit scalaire de U et V est %d\n", scal);
    return (scal);
}

int main()
{
    int U[NN], V[NN], pscal;
    int n = 0;			//dimension du vecteur

    defvect(U, &n);

    defvect(V, &n);

    xscal(U, V, n);

    return (0);
}
