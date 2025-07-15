#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define NN 50

void ecritchar(char *car)
{
	int l; 
	do {
	printf("Entre un chaine de caractere : ");
	scanf("%s",car);
	l = strlen(car);
	if (l > NN) {
		printf("Trop de caractères !!! entrer auplus 20 caratères\n");
		exit (1);
	}
	if (*(car + l - 1) != '.') {
		printf("Veuillez terminer votre text par un point\n");
	}
	} while (*(car + l - 1) != '.');

}


int appa(char *car) 	//fonction determine l'apparition de a
{
	int i,l,ap = 0;
	l = strlen(car);
	for (i = 0; i < l; i ++) {
		if (*(car + i) == 'a') {
			ap = ap + 1;
		}
	}
	printf("Le nombre d'apparition du caractère 'a' est %d\n",ap);
	return (ap);
}	

int appes(char *car) 	//fonction determine l'apparition de es
{
	int i,l,ap = 0;
	l = strlen(car);
	for (i = 0; i < l; i ++) {
		if (*(car + i) == 'e' && *(car + i + 1) == 's') {
			ap = ap + 1;
		}
	}
	printf("Le nombre d'apparition du caractère 'es' est %d\n",ap);
	return (ap);
}

int main () 
{
	int es,a;
	char text[NN];

	ecritchar(text);		//ecrire un chaine de caractère

	appa(text);	//determine l'apparition de a

	appes(text); 	//determine l'apparition de es
			return (0);
}
