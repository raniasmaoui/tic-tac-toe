#include <stdlib.h>
#include <string.h>
#include<stdio.h>
#include<string.h>
#include "grille.h"
#include "menu.h"
#include "jeu.h"
#define VIDE ' ' // statut continue
#define JOUEUR1 'X'
#define JOUEUR2 'O'
#define MATCH_NUL 'N'

////////////////////////////////////////////////////////////
jeu* creer_grille()
{
    int i,k;
    jeu* j=NULL;

     j=(jeu*)malloc(sizeof(jeu));
    do
    {
        printf("Saisir la taille du grille (entre 4 et 8) :\n");
        scanf("%d",&(j->gr.taille));

    }while(j->gr.taille<4||j->gr.taille>10);

    j->gr.matrice=(char**)malloc(sizeof(char*));

    for(i=0;i<j->gr.taille;i++)
    {

        j->gr.matrice[i]=(char*)malloc(sizeof(char));

        for(k=0;k<j->gr.taille;k++)
        {

           j->gr.matrice[i][k]=VIDE;
        }

    }
    j->nbr_des_cases_vides=j->gr.taille*j->gr.taille;
    j->jr.symbole=JOUEUR1;
    j->difficulte=-1;
   // j->jr.nom="";
    j->statut=VIDE;
    return j;
}
/////////////////////////////////////////////////////////////////////////////////////
char test_gain_ligne_pos(jeu* j,int _ligne,int deb,int fin)
{
    while(j->gr.matrice[_ligne][deb]==j->gr.matrice[_ligne][deb+1]&&j->gr.matrice[_ligne][deb]!=VIDE)
    {
        deb++;
        if(deb==fin)
        {
            if(j->gr.matrice[_ligne][deb]==JOUEUR1)
            {
                return JOUEUR1;
            }

            else
            {
                if(j->gr.matrice[_ligne][deb]==JOUEUR2)
                {
                    return JOUEUR2;
                }
            }

        }


    }
    return VIDE;
}
char test_gain_ligne(jeu* j,int _ligne)
{
    int i=0;
    char c=VIDE;
   do
   {

       c=test_gain_ligne_pos(j,_ligne,i,i+3);
       i++;
       if(c!=VIDE)
        return c;
   }while(i<j->gr.taille-3);
   return c;
}
char test_gain_colonne_pos(jeu* j,int _colonne,int deb,int fin)
{
    while(j->gr.matrice[deb][_colonne]==j->gr.matrice[deb+1][_colonne]&&j->gr.matrice[deb][_colonne]!=VIDE)
    {
        deb++;
        if(deb==fin)
        {
            if(j->gr.matrice[deb][_colonne]==JOUEUR1)
                return JOUEUR1;
            else
                {
                    if(j->gr.matrice[deb][_colonne]==JOUEUR2)
                    return JOUEUR2;
                }
        }


    }
    return VIDE;
}
char test_gain_colonne(jeu* j,int _colonne)
{
    int i=0;
    char c=VIDE;
   do
   {

       c=test_gain_colonne_pos(j,_colonne,i,i+3);
       i++;
       if(c!=VIDE)
        return c;
   }while(i<j->gr.taille-3);
   return c;
}
char test_gain_diagonale_principale_pos(jeu* j,int deb,int fin,int pos)
{
    while(deb+pos<0&&deb<fin)
    {
         deb++;
         fin++;
    }
    while(j->gr.matrice[deb+pos][deb]==j->gr.matrice[deb+pos+1][deb+1]&&j->gr.matrice[deb+pos][deb]!=VIDE)
    {
        deb++;
        if(deb==fin)
        {
            if(j->gr.matrice[deb+pos][deb]==JOUEUR1)
            {
                return JOUEUR1;
            }

            else
            {
                if(j->gr.matrice[deb+pos][deb]==JOUEUR2)
                return JOUEUR2;
            }

        }
    }
    return VIDE;
}
char test_gain_diagonale_principale(jeu* j,int pos)
{
    int i=0;
    char c=VIDE;

   do
   {

       c=test_gain_diagonale_principale_pos(j,i,i+3,pos);
       i++;

       if(c!=VIDE)
        return c;
   }while(i<j->gr.taille-3);
   return c;
}/////////////////////////////////////////////////////////////////////////////////////
char test_gain_diagonale_secondaire_pos(jeu* j,int deb,int fin,int pos)
{
    while(deb+pos<0&&deb<fin)
    {
         deb++;
         fin++;
    }
    while(j->gr.matrice[deb+pos][j->gr.taille-deb-1]==j->gr.matrice[deb+pos+1][j->gr.taille-deb-2]&&j->gr.matrice[deb+pos][j->gr.taille-deb-1]!=VIDE)
    {
        deb++;
        if(deb==fin)
        {
            if(j->gr.matrice[deb+pos][j->gr.taille-deb-1]==JOUEUR1)
            {
                 return JOUEUR1;
            }

            else
            {
                 if(j->gr.matrice[deb+pos][j->gr.taille-deb-1]==JOUEUR2)
                 {
                     return JOUEUR2;
                 }

            }

        }
    }
    return VIDE;
}
char test_gain_diagonale_secondaire(jeu* j,int pos)
{
    int i=0;
    char c=VIDE;

   do
   {

       c=test_gain_diagonale_secondaire_pos(j,i,i+3,pos);
       i++;

       if(c!=VIDE)
        return c;
   }while(i<j->gr.taille-3);
   return c;
}
char grille_mettre_a_jour_statut(jeu* j)
{
    int k=0,m=0;

    while(k<j->gr.taille)
    {
        if(test_gain_ligne(j,k)==j->jr.symbole)
        {
            j->statut=j->jr.symbole;
            return j->statut;
        }
        if(test_gain_colonne(j,k)==j->jr.symbole)
        {
            j->statut=j->jr.symbole;
            return j->statut;
        }
        k++;
    }
    k=j->gr.taille-4;
    m=-k;
    do
    {
       if(test_gain_diagonale_principale(j,m)==j->jr.symbole)
        {
            j->statut=j->jr.symbole;
            return j->statut;

        }

        if(test_gain_diagonale_secondaire(j,m)==j->jr.symbole)
        {
            j->statut=j->jr.symbole;

            return j->statut;

        }

        if(j->nbr_des_cases_vides==0)
        {
            j->statut=MATCH_NUL;

            return j->statut;
        }
        m++;
    }while(m!=k);

    return j->statut;


}
////////////////////////////////////////////////////////////////////////
case_grille grille_obtenir_position(jeu* j)
{
case_grille _case;

    do
    {
        printf("Entrer le nombre de ligne de la grille (entre 1 et %d) :",j->gr.taille);
        scanf("%d",&_case.ligne);
        if(_case.ligne==0)
       {
           menu_secondaire(j);
       }


    }while(_case.ligne<1||_case.ligne>j->gr.taille);
    _case.ligne--;
    do
    {
        printf("Entrer le nombre de colone de la grille (entre 1 et %d) :",j->gr.taille);
        scanf("%d",&_case.colonne);
         if(_case.colonne==0)
       {
           menu_secondaire(j);
       }
    }while(_case.colonne<1||_case.colonne>j->gr.taille);
    _case.colonne--;
    if(j->gr.matrice[_case.ligne][_case.colonne]!=VIDE)
    {
       printf("\nLa case est deja occupee.\n");
       return grille_obtenir_position(j);
    }
    return _case;
}
////////////////////////////////////////////////////////////////////
void affichage_de_grille(jeu* j)
{
    int i,k;
    //system("cls");
    printf("\t\t\t\t\t\t\n0=sort");
    for(i=0;i<j->gr.taille;i++)
     {
       printf("\t\t\t\t\t\t\t");
       //printf("…Õ");
       for(k=0;k<2*j->gr.taille;k++)
        printf("…Õ");
        printf("ª");
        //printf("Õ…");
       printf("\n");

       printf("\t\t\t\t\t\t\t");
       for(k=0;k<j->gr.taille;k++)
        printf("∫ %c ",j->gr.matrice[i][k]);
       printf("∫");
       printf("\n");
     }
     printf("\t\t\t\t\t\t\t");
     for(k=0;k<2*j->gr.taille;k++)
     printf("Õº");
     printf("º");
     //printf("…");
     printf("\n");
}

