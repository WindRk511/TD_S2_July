#include<stdio.h>

void remplietab(int *tab, int *taille) : vide                       // fonction qui fait rempilie le tableau
{
	int i;
    do {
        printf("Entre la taille du tableau : ");
        scanf("%d",taille);
        if (*taille < 1 || *taille > 50) {
            	prinf("Entrer une valeur compris entre 1 et 50\n");
	}
    } while (*taille < 1 || *taille > 50);
    	for (i <- 0; i < *taille; i++) {
         	printf("case[",i+1,"]=");
         	scanf("%d",tab + i);
    	}
}
                                                                                                                                                             

int sommetab(int *tab, int taille){				// fonction qui calcul la somme des elements du tableau
    int somme = 0, i;
    for (i = 0; i < taille; i++) {
	somme = somme + *(tab + i);
    }
    return (somme);
}


float vmoyen(int *tab, int taille)	//fonction qui  calcul la valeur moyenne
{
	float moyen;
	int somme;
	somme=sommetab(tab,taille);
	moyen=somme/taille;
	printf("La valeur de la moyenne est %f\n",moyen);
	return (moyen);
}
int premoyen(int *tab, int taille) 	//fonction qui determine la valeur plus proche de la moyenne
{
	int pm,i,d1,d2;
	float m;

	  m = vmoyen(tab,taille);			//calcul moyenne

      	  d1 = m - *tab;		//calcul difference entre le moyenne et le contenu du tableau
    if (d1 < 0) {
	d1 = (-d1);
    }
    for (i = 1; i < taille; i++) {
	d2 = m - *(tab + i);		//calcul autre difference entre le moyenne et le contenu du tableau

	if (d2 < 0) {
	    d2 = (-d2);
	}

	if (d2 < d1) {		//comparaison entre les difference des contenus du tableau à la valeur du moyenne
	    pm = *(tab + i);		//ce qui plus petit est plus proche de la moyenne
	}
	d1 = d2;
    }

    printf("L'element le plus proche de la moyenne est %d\n", pm);
	return (pm);
}

int main ()
{
	int tab[50],N;

	remplietab(tab,&N);	//remplie le tableau

	premoyen(tab,N);	//determinaison de la valeur plus proche de la moyenne
				return (0);
}
#include<stdio.h>

void remplietab(int *tab, int *taille){                         // fonction qui fait rempilie le tableau
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

int sommetab(int *tab, int taille){				// fonction qui calcul la somme des elements du tableau
    int somme = 0, i;
    for (i = 0; i < taille; i++) {
	somme = somme + *(tab + i);
    }
    return (somme);
}


float vmoyen(int *tab, int taille)	//fonction qui  calcul la valeur moyenne
{
	float moyen;
	int somme;
	somme=sommetab(tab,taille);
	moyen=somme/taille;
	printf("La valeur de la moyenne est %f\n",moyen);
	return (moyen);
}
int premoyen(int *tab, int taille) 	//fonction qui determine la valeur plus proche de la moyenne
{
	int pm,i,d1,d2;
	float m;

	  m = vmoyen(tab,taille);			//calcul moyenne

      	  d1 = m - *tab;		//calcul difference entre le moyenne et le contenu du tableau
    if (d1 < 0) {
	d1 = (-d1);
    }
    for (i = 1; i < taille; i++) {
	d2 = m - *(tab + i);		//calcul autre difference entre le moyenne et le contenu du tableau

	if (d2 < 0) {
	    d2 = (-d2);
	}

	if (d2 < d1) {		//comparaison entre les difference des contenus du tableau à la valeur du moyenne
	    pm = *(tab + i);		//ce qui plus petit est plus proche de la moyenne
	}
	d1 = d2;
    }

    printf("L'element le plus proche de la moyenne est %d\n", pm);
	return (pm);
}

int main ()
{
	int tab[50],N;

	remplietab(tab,&N);	//remplie le tableau

	premoyen(tab,N);	//determinaison de la valeur plus proche de la moyenne
				return (0);
}
