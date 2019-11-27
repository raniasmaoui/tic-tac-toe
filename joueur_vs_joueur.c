#include <stdlib.h>
#include <string.h>
#include<stdio.h>
#include "grille.h"
#define VIDE ' ' // statut continue
#define JOUEUR1 'X'
#define JOUEUR2 'O'
#define MATCH_NUL 'N'
#include<windows.h>
#include "jeu.h"
#include "menu.h"
#include "Grille.h"


void match_joueur_vs_joueur(jeu* j)
{

     system("cls");
    //affichage_de_grille(g);
    case_grille _case;
    while(j->statut==VIDE)
    {
       // printf("\n\n-------------------");
        affichage_de_grille(j);
        printf("Joueur %c , a vous jouer ! \n",j->jr.symbole);
       // affichage_de_grille(g);

        _case=grille_obtenir_position(j);

        j->gr.matrice[_case.ligne][_case.colonne]=j->jr.symbole;
        j->nbr_des_cases_vides--;
      //  affichage_de_grille(g);
        system("cls");
        //affichage_de_grille(g);
        j->statut=grille_mettre_a_jour_statut(j);
        if(j->jr.symbole==JOUEUR2)
            j->jr.symbole=JOUEUR1;
        else
            j->jr.symbole=JOUEUR2;



    }
    //printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t0-sort");

    if(j->statut==MATCH_NUL)
        printf("Match nul !\n");
    else
        printf("Le joueur %c a gagne !\n",j->statut);


}
void menu_retour_joueur()
{
        int choix;
        jeu* j=NULL;
        //g=creer_grille();

        printf("  \n     ***********************************************************  \n             ");

        do
        {

            printf("\n1- Rejouer");
            printf("\n2- Retour ");
            printf("\n Votre choix ? \n");
            scanf("%d", &choix);
        }while((choix<1) && (choix>2));
        switch(choix)
        {
        case 1:
            j=creer_grille();
            match_joueur_vs_joueur(j);
            break;
        case 2:
            menu_du_mode_de_jeu(j);
            break;





        }


}




