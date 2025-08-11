#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void recu_chaine(char* ch);
int bigr_c(char* chaine);
int main ()
{
	char chaine[100];
	recu_chaine(chaine);
	bigr_c(chaine);
	return 0;
}

void recu_chaine(char* ch) 
{
	printf("Saisir votre chaine:\n");
	fgets(ch,100,stdin);
	if (strlen(ch) >= 100) {
		printf("Votre chaine est trop longue . il faut inferieur de 100.\n");
		exit (1);
	}
}

int bigr_c(char* chaine)
{
	char b[]="bi";
	char* p;
	int i,j;
	printf("Entrer votre bigrame : ");
	scanf("%s",b);

	j = 0;
	for (i = 0; i < strlen(chaine); i ++) {
		p = &chaine[i];
		if(strncmp(b,p,2) == 0) {
			j++;
		}
	}
	printf("Le nombre d'appparution de %s est %d.\n",b,j);

}
