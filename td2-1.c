/*

// Exercice 1
fonction remplietab(int *tab, int *taille) : vide				// fonction qui fait rempilie le tableau
debut
	i : entier
    afficher("Remplire le tableau:\n");
    faire 
	ecrire("Entre la taille du tableau : ");
	lire(taille);
	si (*taille < 1 || *taille > 50) alors
	    afficher("Entrer une valeur compris entre 1 et 50\n");
	finsi
     tantque (*taille < 1 || *taille > 50);
    pour (i <- 0; i < *taille; i++) {
	ecrire("case[,i+1,]=");
	lire(tab + i);
    finpour
fin

fonction  affichetab(int *tab, int n) : vide				// fonction qui affiche les elements du tableau
debut
	i : entier;
    pour (i = 0; i < n; i++)
	printf("%d ", *(tab + i));
    finpour
    afficher("\n");
fin

fonction  sommetab(int *tab, int n) : entier				// fonction qui calcul la somme des elements du tableau
debut
     somme <- 0, i : entier;
    pour (i <- 0; i < n; i++) 
	somme <- somme + *(tab + i);
    finpour
    afficher("Les somme du contenu du tableau est %d\n", somme);
    retourne (somme);
fin

// Exercice 2
fonction valmax(int *tab, int n) : entier				// fonction qui determine la valeur maximal dans une tableau
debut
    i, max <- *tab : entier;
    pour (i = 1; i < n; i++) 
	si (*(tab + i) > max) alors
	    max = *(tab + i);
	finsi
    finpour
    printf("La valeur maximal du tableau est %d\n", max);
    retourne (max);
fin

// Exercice 3
fonction effaceoccu(int *tab, int *n) : entier				// fonction qui efface l'occurrence de zero dans le tableau 
debut
    i <- 0, j : entier;
    tantque (i < *n) faire
	si (*(tab + i) = 0) alors
	    pour (j = i; j < *n; j++) 
		*(tab + j) <- *(tab + j + 1);
	    finpour
	    *n <- *n - 1;
	    continue;
	finsi
	i++;
    fintantque
fin


// Exercice 4
tabpos(int *tabc, int *nc, int *tab, int n) : vide				// fonction qui copie les valeurs positives d'un tableau à l'autre
debut
    i : entier;
    *nc <- 0;			// taille occupé
    pour (i <- 0; i < n; i++) 
	si (*(tab + i) > 0) alors
	    *(tabc + *nc) <- *(tab + i);
	    *nc <- *nc + 1;
	finsi
    finpour
    printf("\n\nTableau TPOS :\n");
fin

tabneg(int *tabc, int *nc, int *tab, int n) : void				// fonction qui copie les valeurs negatives d'un tableau à l'autre
debut
    i : entier;
    *nc <- 0;			// taille occupé
  pour (i <- 0; i < n; i++) 
	si ( *(tab + i) < 0 ) alors
	    *(tabc + *nc) <- *(tab + i);
	    *nc <- *nc + 1;
	finsi
    finpour
 fin

triinv(int *tab, int n) : vide				// fonction qui inverse l'orde de contenu  du tableau
debut
    i <- 0 : entier;
    temp <- 0 : entier;
    tantque (i < (n / 2)) faire
	temp <- *(tab + i);
	*(tab + i) <- *(tab + n - i - 1);
	*(tab + n - i - 1) <- temp;
	i <- i + 1;
    fintantque
fin

debut
    n, T[N] : entier;
    TPOS[N], ntpos : entier;		// tableau des valeurs positives et taille occupé
    TNEG[N], ntneg : entier;		// tableau des valeurs négatives et la taille occupé


    remplietab(T, &n);

    sommetab(T, n);		// Calcul somme

    valmax(T, n);		// Determinaison de la valeur maximal

    effaceoccu(T, (&n));	// Effement des occurrents de zero
    printf("Tableau sans valeur 0:\n");
    affichetab(T, n);		// Affichage de tableau 

    tabpos(TPOS, &ntpos, T, n);		// copie des valeurs positifs à TPOS
    affichetab(TPOS, ntpos);

    tabneg(TNEG, &ntneg, T, n);		// copie des valeurs positifs à TNEG
    affichetab(TNEG, ntneg);

    triinv(T, n);		// Inversement de la valeur
    affichetab(T, n);
	
    retourne (0);
fin
	*/

#include<stdio.h>
#define N 50

// Exercice 1
void remplietab(int *tab, int *taille){				// fonction qui fait rempilie le tableau
    int i;
    do {
	printf("Entre la taille du tableau : ");
	scanf("%d", taille);
	if (*taille < 1 || *taille > 50) {
	    printf("Entrer une valeur compris entre 1 et 50\n");
	}
    } while (*taille < 1 || *taille > 50);
    for (i = 0; i < *taille; i++) {
	printf("case[%d]=", i + 1);
	scanf("%d", tab + i);
    }
}

void affichetab(int *tab, int n){				// fonction qui affiche les elements du tableau
    int i;
    for (i = 0; i < n; i++) {
	printf("%d ", *(tab + i));
    }
    printf("\n");
}

int sommetab(int *tab, int n){				// fonction qui calcul la somme des elements du tableau
    int somme = 0, i;
    for (i = 0; i < n; i++) {
	somme = somme + *(tab + i);
    }
    return (somme);
}

// Exercice 2
int valmax(int *tab, int n){				// fonction qui determine la valeur maximal dans une tableau
    int i, max = *tab;
    for (i = 1; i < n; i++) {
	if (*(tab + i) > max) {
	    max = *(tab + i);
	}
    }
    return (max);
}

// Exercice 3
void effaceoccu(int *tab, int *n){				// fonction qui efface l'occurrence de zero dans le tableau 
    int i = 0, j;
    while (i < *n) {
	if (*(tab + i) == 0) {
	    for (j = i; j < *n; j++) {
		*(tab + j) = *(tab + j + 1);
	    }
	    *n = *n - 1;
	    continue;
	}
	i++;
    }
}


// Exercice 4
void tabpos(int *tabc, int *nc, int *tab, int n){				// fonction qui copie les valeurs positives d'un tableau à l'autre
    int i;
    *nc = 0;			// taille occupé
    for (i = 0; i < n; i++) {
	if (*(tab + i) > 0) {
	    *(tabc + *nc) = *(tab + i);
	    *nc = *nc + 1;
	}
    }
}

 void tabneg(int *tabc, int *nc, int *tab, int n){				// fonction qui copie les valeurs negatives d'un tableau à l'autre
    int i;
    *nc = 0;			// taille occupé
  for (i = 0; i < n; i++) {
	if ( *(tab + i) < 0 ) {
	    *(tabc + *nc) = *(tab + i);
	    *nc = *nc + 1;
	}
    }
 }

void triinv(int *tab, int n){				// fonction qui inverse l'orde de contenu  du tableau
    int i = 0;
    int temp = 0;
    while (i < (n / 2)) {
	temp = *(tab + i);
	*(tab + i) = *(tab + n - i - 1);
	*(tab + n - i - 1) = temp;
	i = i + 1;
    }
}

int main()
{
    int n, T[N];
    int s, Max;
    int TPOS[N], ntpos;		// tableau des valeurs positives et taille occupé
    int TNEG[N], ntneg;		// tableau des valeurs négatives et la taille occupé


    printf("Remplire le tableau:\n");
    remplietab(T, &n);

    sommetab(T, n);		// Calcul somme
    printf("Les somme du contenu du tableau est %d\n", s);

	 valmax(T, n);		// Determinaison de la valeur maximal

    effaceoccu(T, (&n));	// Effement des occurrents de zero
    affichetab(T, n);		// Affichage de tableau 

    tabpos(TPOS, &ntpos, T, n);		// copie des valeurs positifs à TPOS
    affichetab(TPOS, ntpos);

    tabneg(TNEG, &ntneg, T, n);		// copie des valeurs positifs à TNEG
    affichetab(TNEG, ntneg);

    triinv(T, n);		// Inversement de la valeur
    affichetab(T, n);
	
    return (0);
}
