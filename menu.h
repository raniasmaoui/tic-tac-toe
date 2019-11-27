
#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "Grille.h"
#include "jeu.h"
#include <string.h>
#include <windows.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define VIDE ' ' // statut continue
#define JOUEUR1 'X'
#define JOUEUR2 'O'
#define MATCH_NUL 'N'
void pub();
void menu_principale();
void menu_du_Nouveau_Partie();
void menu_du_mode_de_jeu(jeu* );
jeu* charger();
void sauvegarder(jeu*);
void menu_secondaire(jeu*);
///////////////////////////////////////////////gr
jeu* creer_grille();
case_grille grille_obtenir_position(jeu*);
char grille_mettre_a_jour_statut(jeu*);
void affichage_de_grille(jeu*);
char test_gain_ligne(jeu* j,int _ligne);
char test_gain_ligne_pos(jeu* j,int _ligne,int deb,int fin);
char test_gain_colonne(jeu* j,int _colonne);
char test_gain_colonne_pos(jeu* j,int _colonne,int deb,int fin);
char test_gain_diagonale_principale(jeu* j,int pos);
char test_gain_diagonale_principale_pos(jeu* j,int deb,int fin,int pos);
char test_gain_diagonale_secondaire(jeu* j,int pos);
char test_gain_diagonale_secondaire_pos(jeu* j,int deb,int fin,int pos);
////////////////////////////////////////jeu
void match_joueur_vs_joueur(jeu*);
case_grille grille_obtenir_position_machine_facile(jeu*);
void match_joueur_vs_machine_facile(jeu*);
void match_joueur_vs_machine_moyenne(jeu*);
void match_joueur_vs_machine_difficile(jeu*);
void menu_retour_joueur();
void menu_retour_machine_facile();
void menu_retour_machine_moyenne();
void menu_retour_machine_difficile();

//case_grille defence(case_grille c,grille* g);
case_grille test_pres_gain_diagonale_principale(jeu* j,char s,int deb_diag_p,int fin_diag_p,int pos);
case_grille test_pres_gain_diagonale_secondaire(jeu* j,char s,int deb_diag_s,int fin_diag_s,int pos_diag);
case_grille test_pres_gain_ligne(jeu*,int _ligne,char s,int deb_colonne,int fin_colonne);
case_grille test_pres_gain_colonne(jeu*,int _colonne,char s,int deb_ligne,int fin_ligne);
case_grille defence_attaque(jeu*,char s);
//void match_joueur_vs_machine_defficile(grille* g);

case_grille test_pres_gain_ligne_pos(jeu*,int _ligne,char s);
case_grille test_pres_gain_colonne_pos(jeu*,int _colonne,char s);
case_grille test_pres_gain_diagonale_secondaire_pos(jeu* j,char s,int pos_diag);
case_grille test_pres_gain_diagonale_principale_pos(jeu* j,char s,int pos_diag);

//case_grille defence_attaque(grille* g,char s);

//case_grille attaque(grille* g);

#endif

