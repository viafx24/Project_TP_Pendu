#include "functions.h"

extern int Nbrcoups;
extern int LongueurMot;

extern char *Mot;
extern char *MotCache;
extern char *ChangeMotCache;

extern char Lettre;

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

int TirageAleatoire(int NbrMots)
{
    /* Intializes random number generator */
    time_t t; //for random function
    srand((unsigned)time(&t));
    int RandomChooseMot;
    RandomChooseMot = rand() % NbrMots;
    return RandomChooseMot;
}

void ChoisirMot(int RandomChooseMot)
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

                strncpy(Mot, chaine, LongueurMot - 1);
                Mot[LongueurMot + 1] = '\000';

                for (int i = 0; i < LongueurMot; i++)
                {
                    if (i < LongueurMot - 1)
                    {
                        MotCache[i] = '*';
                        ChangeMotCache[i] = '*';
                    }
                    else
                    {
                        MotCache[i] = '\000';
                        ChangeMotCache[i] = '\000';
                    }
                }
            }
        }

        fclose(fichier);
    }
}