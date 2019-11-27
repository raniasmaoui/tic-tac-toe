#include <stdlib.h>
#include <string.h>
#include<stdio.h>
#include "grille.h"
#include "jeu.h"
#include "menu.h"
#define VIDE ' ' // statut continue
#define JOUEUR1 'X'
#define JOUEUR2 'O'
#define MATCH_NUL 'N'
#include<windows.h>
#include<time.h>
case_grille grille_obtenir_position_machine_facile(jeu* j)
{
    case_grille _case;
    do
    {
       _case.ligne=rand();
    }while(_case.ligne<1||_case.ligne>j->gr.taille);
    _case.ligne--;
    do
    {
        _case.colonne=rand();
    }while(_case.colonne<1||_case.colonne>j->gr.taille);
    _case.colonne--;
    if(j->gr.matrice[_case.ligne][_case.colonne]!=VIDE)
    {
       return grille_obtenir_position_machine_facile(j);
    }
    return _case;
}
/////////////////////////////////////////////////////////////////////////////

void match_joueur_vs_machine_facile(jeu* j)
{
    system("cls");
     affichage_de_grille(j);
    case_grille _case;
    srand(time(NULL));
    while(j->statut==VIDE)
    {
        printf("\n\n-------------------");
        j->jr.symbole=JOUEUR1;
        printf("Joueur %c , a vous jouer ! \n",j->jr.symbole);
        _case=grille_obtenir_position(j);
        j->gr.matrice[_case.ligne][_case.colonne]=j->jr.symbole;
        j->nbr_des_cases_vides--;
       // affichage_de_grille(g);
         system("cls");
        affichage_de_grille(j);
        j->statut=grille_mettre_a_jour_statut(j);

        if(j->jr.symbole==JOUEUR2)
        {

                j->jr.symbole=JOUEUR1;

        }
        else
        {
             j->jr.symbole=JOUEUR2;
            _case=grille_obtenir_position_machine_facile(j);
            j->gr.matrice[_case.ligne][_case.colonne]=j->jr.symbole;
            j->nbr_des_cases_vides--;
            affichage_de_grille(j);
            system("cls");
            affichage_de_grille(j);

        }
        j->statut=grille_mettre_a_jour_statut(j);
          printf("\n%c\n",j->statut);

    }

    if(j->statut==JOUEUR1)
        printf("Le joueur %c a gagne !\n",j->statut);

    else
         printf("Match nul !\n");
}
///////////////////////
void menu_retour_machine_facile()
{

        int choix;
        jeu* j=NULL;

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
            match_joueur_vs_machine_facile(j);
            break;
        case 2:
            menu_du_mode_de_jeu(j);
            break;


        }

}
///////////////////////////////////////////////
void menu_retour_machine_difficile()
{

        int choix;
        jeu* j=NULL;

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
            match_joueur_vs_machine_difficile(j);
            break;
        case 2:
            menu_du_mode_de_jeu(j);
            break;


        }

}
////////////////////////////////////////////////
void menu_retour_machine_moyenne()
{
        int choix;
        jeu* j=NULL;

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
            match_joueur_vs_machine_moyenne(j);
            break;
        case 2:
            menu_du_mode_de_jeu(j);
            break;


        }

}
////////////////////////////////////////////
void match_joueur_vs_machine_moyenne(jeu* j)
{
    system("cls");
    affichage_de_grille(j);
    case_grille _case;
    srand(time(NULL));
    while(j->statut==VIDE)
    {
        j->jr.symbole=JOUEUR1;
        printf("Joueur %c , a vous jouer ! \n",j->jr.symbole);
        _case=grille_obtenir_position(j);
        j->gr.matrice[_case.ligne][_case.colonne]=j->jr.symbole;
        j->nbr_des_cases_vides--;
        system("cls");
        affichage_de_grille(j);
        j->statut=grille_mettre_a_jour_statut(j);
        if(j->nbr_des_cases_vides!=0)
        {
             j->jr.symbole=JOUEUR2;
            if(defence_attaque(j,JOUEUR1).ligne!=-1)
                _case=defence_attaque(j,JOUEUR1);
            else
                _case=grille_obtenir_position_machine_facile(j);
            j->gr.matrice[_case.ligne][_case.colonne]=j->jr.symbole;
            j->nbr_des_cases_vides--;
            system("cls");
            affichage_de_grille(j);
            j->statut=grille_mettre_a_jour_statut(j);
        }
    }
    if(j->statut==MATCH_NUL)
    {
         printf("Match nul !\n");
    }
    else
    {
        printf("Le joueur %c a gagne !\n",j->statut);
    }
}

void match_joueur_vs_machine_difficile(jeu* j)
{
    system("cls");
    affichage_de_grille(j);
    case_grille _case;
    srand(time(NULL));
    while(j->statut==VIDE)
    {
        j->jr.symbole=JOUEUR1;
        printf("Joueur %c , a vous jouer ! \n",j->jr.symbole);
        _case=grille_obtenir_position(j);
        j->gr.matrice[_case.ligne][_case.colonne]=j->jr.symbole;
        j->nbr_des_cases_vides--;
        system("cls");
        affichage_de_grille(j);
        j->statut=grille_mettre_a_jour_statut(j);
        if(j->nbr_des_cases_vides!=0)
        {
             j->jr.symbole=JOUEUR2;
            if(defence_attaque(j,JOUEUR2).ligne!=-1)
                _case=defence_attaque(j,JOUEUR2);
            else
            {
                if(defence_attaque(j,JOUEUR1).ligne!=-1)
                    _case=defence_attaque(j,JOUEUR1);
                else
                    _case=grille_obtenir_position_machine_facile(j);
            }
            j->gr.matrice[_case.ligne][_case.colonne]=j->jr.symbole;
            j->nbr_des_cases_vides--;
            system("cls");
            affichage_de_grille(j);
            j->statut=grille_mettre_a_jour_statut(j);
        }
    }
    if(j->statut==MATCH_NUL)
    {
         printf("Match nul !\n");
    }
    else
    {
        printf("Le joueur %c a gagne !\n",j->statut);
    }
}
/////////////////////////////////////////////////////////////////////////////////////////
case_grille defence_attaque(jeu* j,char s)
{//case_grille test_pres_gain_diagonale_principale_pos(jeu* j,char s,int pos_diag)

    int k=j->gr.taille-4,m=-k;;
    case_grille c;

    c.ligne=-1;
    c.colonne=-1;

   do
    {
        if(test_pres_gain_diagonale_principale_pos(j,s,m).ligne!=-1)
        {
            return test_pres_gain_diagonale_principale_pos(j,s,m);
        }
        if(test_pres_gain_diagonale_secondaire_pos(j,s,m).ligne!=-1)
        {

            return test_pres_gain_diagonale_secondaire_pos(j,s,m);
        }
        m++;
    }while(m!=k);
    k=0;
    while(k<=j->gr.taille-1)
    {
        if(test_pres_gain_ligne_pos(j,k,s).ligne!=-1)
        {
            return test_pres_gain_ligne_pos(j,k,s);
        }

        if(test_pres_gain_colonne_pos(j,k,s).ligne!=-1)
        {
            return test_pres_gain_colonne_pos(j,k,s);
        }
        k++;
    }

    return c;
}
