#ifndef _FUNCTION
#define _FUNCTION
                                /*§§§§§§§§§§§§§§§§§§§§§§§§ - LES INCLUDES - §§§§§§§§§§§§§§§§§§§§§§§§§§§§*/
#include <stdio.h>                  /* pour les fonction d'enter sortie printf , scanf ... */
#include<stdlib.h>                  /*pour les fonctions 'system' et fonction atoi() */
#include<string.h>                  /*pour fonction strlen */
#include<ctype.h>                   /* pour les deux fonctions isalpha et ispunct */
#include<regex.h>                   /* regexe pour vérifiecation de l'email */
#define max 100
#define max_emprunts 3
                                /*§§§§§§§§§§§§§§§§§§§§§§§§ - LES COLERS - §§§§§§§§§§§§§§§§§§§§§§§§§§§§*/
#define RED   "\x1b[91m"
#define JAN   "\x1b[93m"
#define GRN   "\x1b[92m"
#define NOI   "\x1b[30m"
#define VIO   "\x1b[95m"
#define SAM   "\x1b[96m"
#define BLE   "\x1b[34m"
#define MAR   "\x1b[31m"
#define MIT   "\x1b[32m"
#define MAMA  "\x1b[38m"
#define VIOM  "\x1b[35m"
#define BLEM  "\x1b[34m"
#define BLEN  "\x1b[36m"
                                /*§§§§§§§§§§§§§§§§§§§§§§§§ - STRUCT - §§§§§§§§§§§§§§§§§§§§§§§§§§§§*/


typedef struct  /* structure d'information de chaque adhérent  */
{
    int num_adh;
    char nom_adh[max];
    char prenom_adh[max];
    char email_adh[max];
    char adress_adh[max];
    int nbre_emprunts_adh;
} adherent;

typedef struct  /* structure d'information de chaque auteur de livre  */
{
    char nom_aut[max];
    char prenom_aut[max];
} auteur;

typedef struct  /* structure d'information de chaque livre  */
{
    int num_liv;
    char titre_liv[max];
    char categ_liv[max];
    auteur auteur_liv;
    int emprunteur_liv;
} livre;

static FILE *fichier = NULL;   /* notre pointeur vers le fichier */

static adherent Information_adherent[max];
static adherent Un_Adherent;
static livre Information_livre[max];
static livre Un_Livre;

                                /*§§§§§§§§§§§§§§§§§§§§§§§§ - LES PRPTOTYPES - §§§§§§§§§§§§§§§§§§§§§§§§§§§§*/

void Ajouter_adherent();
int Libre_place_Adherent(int num);
void affichage_all_Adherent();
void nv_menu_supprime();
void Supprimer_code_Adherent();
void Supprimer_nom_Adherent();
void nv_menu_recherche();
void Affichage_Adherent_Numero();
void Affichage_Adherent_Nom();
void Nv_Menu_Modification();
void Modification_Numero();
void Modification_Nom();


void style_ajoute();
void style_menu();
void style_supprime();
void style_supprime_poubelle();
void style_recherche_loupe();
void style_recherche();
void style_modification();
void style_changement();


#endif
