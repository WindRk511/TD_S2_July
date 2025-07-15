/*
Algorithme :
 constant NN 50
variable :
	tab[NN] : entier;
	N,n_paire : entier;

//Exercice 1
fonction remplitab (int *tab, int *taille) : vide		//fonction qui remplie le tableau 
debut
        i : entier;
        faire
                afficher("Entre la taille de de tableau : ");
                lire(taille);
                si ( *taille <= 0 || *taille > NN) alors
                        afficher("Entrer la valeur entre 1 et 50 !!!\n");
                }
        tantque  ( *taille <= 0 || *taille > NN);
        afficher("\ntaille=",*taille);
	afficher("Remplie le tableau:\n");
        pour (i <- 0; i < *taille; i++) 
                afficher("case[%d]=",i);
                lire(tab + i);
        finpour
fin

fonction affichetab(int *tab, int n) : vide                             // fonction qui affiche les elements du tableau
debut
	i : entier;
	afficher("Votre tableau:\n");
    pour (i <- 0; i < n; i++) 
        afficher(*(tab + i));
    finpour
    afficher("\n");
fin

fonction paireavant (int *tab, int taille) : vide		//fonction qui range les paires avant impaire
debut
	i <- 0 : entier;
        temp : entier;
	afficher("Trie tableau\n");
	pour (i <- 0; i < taille - 1; i++)
		si ((*(tab + i) % 2) != 0) alors
			si ((*(tab + i + 1) % 2) == 0) alors
				temp <- *(tab + i + 1);
				*(tab + i + 1) <- *(tab + i);
				*(tab + i) <- temp;
				i <- 0;	//reinitialliser le trie
			finsi
		finsi
	finpour
fin

//Exercice 2
fonction pairenb (int *tab, int taille) :entier 	//fonction qui determine l'effectif de nombre paire
debut
	i,paire : entier;
	paire <- 0 :entier;
	pour (i <- 0; i < taille; i++) 
		si ( (*(tab + i) % 2) == 0) alors
			paire <- paire + 1;
		finsi
	finpour
	retourne (paire);
fin

fonction taillelibre (int t_courant, int t_total) : entier	//fonction qui determine l'espace libre 
debut
	t_libre : entier;
	t_libre <- t_total - t_courant;
	si (t_libre <= 0) alors
		afficher("pas d'espace libre\n");
		retourne (0);
	finsi
	retourne (t_libre);
fin
	
foction instab (int *tab, int *taille, int *nbrpaire) : entier 	//fonction qui insert un valeur dans tableau trie
{
	X,i <- *taille - 1 : entier;
	tlibre : entier;
	
	tlibre<-taillelibre(*taille,NN);
	si (tlibre == 0) alors
		fin (1);
	finsi

	afficher("Entrer la valeur à insere : \n");
	lire(X);

	si ((X%2) != 0) alors
		*(tab + *taille - 1) <- X;
	sinon
		faire	
			*(tab + i + 1) <- *(tab + i);
			i <-  i - 1;
		tantque (i != *nbrpaire);
		*(tab + i) <- X;
	*nbrpaire <- *nbrpaire + 1;
	*taille <- *taille + 1;
	finsi
fin

fonction supxtab (int *tab, int *taille) :vide 
debut
	X,i,j,temp=0,t=0 : entier;
    afficher("\n\nEntrer un element à supprimer: ");
    lire(X);

    //On ecrase l'element à effacer
    pour (i <- 0; i < *taille; i++)
	si ( X == *(tab + i)) {
	    pour (j <- i; j < *taille; j++) 
		temp <- *(tab + j);
		*(tab + i) <- *(tab + j +1);
		*(tab + i + 1) <- temp;
	    finpour
	    t<-1;
	    *taille <- *taille - 1;
	    sortie;
	finsi

    finpour

    si (t == 0) alors		//si a ne change pas apres la dernier initialisation
	printf("\n!!! Aucun element correspondant\n");
    finsi
fi

debut

	remplitab(tab,&N);	//rempie le tableau en donnant la taille N
	affichetab(tab,N);	//affiche la tableau

	paireavant(tab,N);	//Trier le tableau
	affichetab(tab,N);	//affiche la tableau

	n_paire = pairenb(tab,N);	//compter le nombre paire
	instab(tab,&N,&n_paire);
	affichetab(tab,N);

	supxtab(tab,&N);	//suprime un element 
	affichetab(tab,N);

	return (0);
}
#include<stdio.h>
#include<stdlib.h>
#define NN 50


//Exercice 1
void remplitab (int *tab, int *taille)		//fonction qui remplie le tableau 
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
	printf("Remplie le tableau:\n");
        for (i = 0; i < *taille; i++) {
                printf("case[%d]=",i);
                scanf("%d",tab + i);
        }
}

void affichetab(int *tab, int n){                               // fonction qui affiche les elements du tableau
    int i;
	printf("Votre tableau:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", *(tab + i));
    }
    printf("\n");
}

void paireavant (int *tab, int taille)		//fonction qui range les paires avant impaire
{
	int i = 0;
	int temp;
	printf("Trie tableau\n");
	for (i = 0; i < taille - 1; i++) {
		if ((*(tab + i) % 2) != 0) {
			if ((*(tab + i + 1) % 2) == 0) {
				temp = *(tab + i + 1);
				*(tab + i + 1) = *(tab + i);
				*(tab + i) = temp;
				i = 0;	//reinitialliser le trie
			}
		}
	}
}

//Exercice 2
int pairenb (int *tab, int taille) 	//fonction qui determine l'effectif de nombre paire
{
	int i,paire;
	paire=0;
	for (i = 0; i < taille; i++) {
		if ( (*(tab + i) % 2) == 0) {
			paire = paire + 1;
		}
	}
	return (paire);
}

int taillelibre (int t_courant, int t_total)	//fonction qui determine l'espace libre 
{
	int t_libre;
	t_libre = t_total - t_courant;
	if(t_libre <= 0) {
		printf("pas d'espace libre\n");
		return (0);
	}
	return (t_libre);
}
	
void instab (int *tab, int *taille, int *nbrpaire) 	//fonction qui insert un valeur dans tableau trie
{
	int X,i = *taille - 1;
	int tlibre;
	
	tlibre=taillelibre(*taille,NN);
	if(tlibre == 0) {
		exit (1);
	}

	printf("Entrer la valeur à insere : \n");
	scanf("%d",&X);

	if((X%2) != 0) {
		*(tab + *taille - 1) = X;
	} 
	else {
		do {	
			*(tab + i + 1) = *(tab + i);
			i =  i - 1;
		} while (i != *nbrpaire);
		*(tab + i) = X;
	*nbrpaire = *nbrpaire + 1;
	*taille = *taille + 1;
	}
}

void supxtab (int *tab, int *taille) 
{
	int X,i,j,temp=0,t=0;
    printf("\n\nEntrer un element à supprimer: ");
    scanf("%d", &X);

    //On ecrase l'element à effacer
    for (i = 0; i < *taille; i++) {
	if ( X == *(tab + i)) {
	    for (j = i; j < *taille; j++) {
		temp = *(tab + j);
		*(tab + i) = *(tab + j +1);
		*(tab + i + 1) = temp;
	    }
	    t=1;
	    *taille = *taille - 1;
	    break;
	}

    }

    if (t == 0) {		//si a ne change pas apres la dernier initialisation
	printf("\n!!! Aucun element correspondant\n");
    }
}

int main () 
{
	int tab[NN];
	int N,n_paire;

	remplitab(tab,&N);	//rempie le tableau en donnant la taille N
	affichetab(tab,N);	//affiche la tableau

	paireavant(tab,N);	//Trier le tableau
	affichetab(tab,N);	//affiche la tableau

	n_paire = pairenb(tab,N);	//compter le nombre paire
	instab(tab,&N,&n_paire);
	affichetab(tab,N);

	supxtab(tab,&N);	//suprime un element 
	affichetab(tab,N);

	return (0);
}
