#ifndef JEU_H_INCLUDED
#define JEU_H_INCLUDED
/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>*/
#include "Grille.h"
//#include "jeu.h"
/*#define VIDE ' ' // statut continue
#define JOUEUR1 'X'
#define JOUEUR2 'O'
#define MATCH_NUL 'N'*/
typedef struct
{
  char symbole;
  char nom[10];
}joueur;
typedef struct
{
    grille gr;
    int difficulte;
    joueur jr ;// tour de joueur 1 ou tour de joueur 2
    int nbr_des_cases_vides;
    char statut;// ' ' ou X ou O OU N
    int mode; //(vs joueur ou vs machine)
}jeu;
typedef struct
{
    int ligne;
    int colonne;

}case_grille;

#endif
