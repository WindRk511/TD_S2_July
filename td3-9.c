#include<stdio.h>
#include<string.h>
#define NN 20

void ecritchar(char *car)
{
	int l; 
	do {
	printf("Entre un chaine de caractere : ");
	scanf("%s",car);
	l = strlen(car);
	if (l > NN) {
		printf("Trop de caractères !!! entrer auplus 20 caratères\n");
	}
	} while (l > 20);

}

int detcarre(char *car) 
{
	int l,i;
	  l = strlen(car);

    while (l > NN) {
        printf("Votre caractere doit inferieur à 50\n");
        return (0);
    }

    if (l % 2 != 0) {
        printf("%s n'est pas carre\n", car);
        return (0);
    }

    for (i = 0; i < (l / 2); i++) {
        if (car[i] != car[(l / 2) + i]) {
            printf("%s n'est pas carree\n", car);
            return (0);
        }
    }

    printf("%s est carree\n", car);
    return (1);
}

int main ()
{
	char chaine[NN];
	
	ecritchar(chaine);

	detcarre(chaine);
	return (0);
}
