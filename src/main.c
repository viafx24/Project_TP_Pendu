
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#define TAILLE_MAX 100 // Tableau de taille 1000

int Nbrcoups = 10;
int LongueurMot = 0;

char *Mot = NULL;
char *MotCache = NULL;
char *ChangeMotCache = NULL;

char Lettre;

char lireCaractere();
int CompterMotFichier();
int TirageAleatoire(NbrMots);
void ChoisirMot(RandomChooseMot);


int main(int argc, char *argv[])
{

    int NbrMots = CompterMotFichier();
    int RandomChooseMot = TirageAleatoire(NbrMots);
    void ChoisirMot(RandomChooseMot);

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

char lireCaractere()
{
    char caractere = 0;

    caractere = getchar();          // On lit le premier caractère
    caractere = toupper(caractere); // On met la lettre en majuscule si elle ne l'est pas déjà

    // On lit les autres caractères mémorisés un à un jusqu'au \n (pour les effacer)
    while (getchar() != '\n')
        ;

    return caractere; // On retourne le premier caractère qu'on a lu
}

int CompterMotFichier()
{

    int NbrMots = 0;

    FILE *fichier = NULL;

    char chaine[TAILLE_MAX] = ""; // Chaîne vide de taille TAILLE_MAX

    fichier = fopen("src/Dictionnaire_Pendu.txt", "r");

    if (fichier != NULL)
    {
        while (fgets(chaine, TAILLE_MAX, fichier) != NULL) // On lit le fichier tant qu'on ne reçoit pas d'erreur (NULL)
        {
            NbrMots++;
        }

        fclose(fichier);
    }

    return NbrMots;
}

int TirageAleatoire(NbrMots)
{
    /* Intializes random number generator */
    time_t t; //for random function
    srand((unsigned)time(&t));

    int RandomChooseMot = rand() % NbrMots;
    return RandomChooseMot;
}

void ChoisirMot(RandomChooseMot)
{
    int NbrMots = 0;

    FILE *fichier = NULL;

    char chaine[TAILLE_MAX] = ""; // Chaîne vide de taille TAILLE_MAX
                                  //char chaine;

    fichier = fopen("src/Dictionnaire_Pendu.txt", "r");

    if (fichier != NULL)
    {
        while (fgets(chaine, TAILLE_MAX, fichier) != NULL) // On lit le fichier tant qu'on ne reçoit pas d'erreur (NULL)
        {
            NbrMots++;
            if (NbrMots == RandomChooseMot)
            {
                LongueurMot = strlen(chaine);
                Mot = malloc(LongueurMot * sizeof(char));            // On alloue de la mémoire pour le tableau
                MotCache = malloc(LongueurMot * sizeof(char));       // On alloue de la mémoire pour le tableau
                ChangeMotCache = malloc(LongueurMot * sizeof(char)); // On alloue de la mémoire pour le tableau

                strncpy(Mot, chaine, LongueurMot);
                printf("taille memoire pour le mot: %d", sizeof(Mot));

                for (int i = 0; i < LongueurMot; i++)
                {
                    if (i < LongueurMot - 1)
                    {
                        MotCache[i] = '*';
                        ChangeMotCache[i] = '*';
                    }
                    else
                    {
                        MotCache[i] = '\n';
                        ChangeMotCache[i] = '\n';
                    }
                }
            }
        }

        fclose(fichier);
    }
}