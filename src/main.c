
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#include "functions.h"
// #define TAILLE_MAX 100 // Tableau de taille 1000

int Nbrcoups = 10;
int LongueurMot = 0;

char *Mot = NULL;
char *MotCache = NULL;
char *ChangeMotCache = NULL ;

char Lettre;

// char lireCaractere();
// int CompterMotFichier();
// int TirageAleatoire(int NbrMots);
// void ChoisirMot(int RandomChooseMot);


int main(int argc, char *argv[])
{

    int NbrMots;
    int RandomChooseMot;

    NbrMots = CompterMotFichier();
    RandomChooseMot = TirageAleatoire(NbrMots);
    ChoisirMot(RandomChooseMot);

    while (Nbrcoups > 0)
    {
        int LengthMot = strlen(Mot);

        printf("Bienvenue dans le Pendu!\n\n");
        printf("il vous reste %d coups à jouer\n", Nbrcoups);

        printf("quel est le mot secret ?%s \n", MotCache);
        printf("Proposez une lettre :");
        Lettre = lireCaractere();
        printf(" %c \n\n", Lettre);
        strcpy(ChangeMotCache, MotCache);

        for (int i = 0; i <= LengthMot; i++)
        {

            if (Lettre == Mot[i])
            {
                MotCache[i] = Lettre;
            }
        }

        if (strcmp(ChangeMotCache, MotCache) == 0)
        {
            Nbrcoups--;
        }

        if (strcmp(Mot, MotCache) == 0)

        {
            printf("Gagne! Le mot secret etait bien : %s", MotCache);
            exit(0);
        }

        else
        {
            if (Nbrcoups == 0)
            {
                printf("Perdu!");
            }
        }
    }
    return 0;
}