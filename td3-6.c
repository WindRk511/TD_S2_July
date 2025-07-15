#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define NN 20
void ecritchar(char *car)
{
	int l; 

	printf("Entre un chaine de caractere : ");
	scanf("%s",car);

	l = strlen(car);
	if (l > NN) {
		printf("Trop de caractères !!! entrer auplus 20 caratères\n");
		exit (1);
	}
}

int palin(char *car)
{
	int i;
	int l=strlen(car);
	for(i=0; i < (l/2) - 1; i ++) {
		if(*(car + i) != *(car + l - i)) {
			printf("%s n'est pas palindrome.\n",car);
			return (0);
		}
	}
	printf("%s est palindrome.\n",car);
	return (1);
}

int main ()
{
	char chaine[NN];

	ecritchar(chaine);

	palin(chaine);
}
