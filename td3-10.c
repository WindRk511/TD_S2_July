#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXCHAINE 100

void recu_text(char* text);
void aff_phrase(char* ph, int status);
int voyel(char v);
void decal(char* ph,int ref);
void crypt(char* ph);

int main()
{
	char phrase[MAXCHAINE];
	recu_text(phrase);
	aff_phrase(phrase,0);
	crypt(phrase);
	aff_phrase(phrase,1);
	return 0;
}

void recu_text(char* text)
{
	printf("Etrer votre phrase:\n");
	fgets(text,MAXCHAINE,stdin);
	if (strlen(text) >= MAXCHAINE) {
		printf("Memoire saturé, saisir caractere inferieur de %ld\n",sizeof(text));
		exit (1);
	}
}

void aff_phrase(char* ph, int status)	// status 0: Non crypté ; 1: crypté 
{

	switch(status) {
		case 0: printf("Votre phrase :\n");
			puts(ph);
			break;
		case 1:printf("Phrase crypté:\n");
		       puts(ph);
		default: break;
	}
}

void crypt(char* ph)
{
	int i;
	int l = strlen(ph);
	printf("\tCryptage:");
	for (i = 0; i < l; i++) {
		if(voyel(ph[i]) != 1 && voyel(ph[i+1]) == 1) {
			decal(ph,i+1);
			decal(ph,i+2);
			ph[i+1] = 'I';
			ph[i+2] = 'T';
			i = i + 2;

		}
	}
	printf(":Fin de cryptage\n");
}

int voyel(char v)
{
	char vo[] = "aeyuio";
	int i;
	for(i = 0; i < strlen(vo); i++) {
		if( v == vo[i]) {
			return 1;
		}
	}
	return 0;

}

void decal(char* ph, int ref)
{
	int i;
	int l=strlen(ph);
	if(l >= MAXCHAINE) {
		printf("Espace alloué est saturé\n");
		exit (1);
	}

	for(i = l; i >= ref; i--) {
		 ph[i+1] = ph[i];
		printf("*");
	}
}
