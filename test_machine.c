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
case_grille test_pres_gain_ligne(jeu* j,int _ligne,char s,int deb_colonne,int fin_colonne)
{
    int i=deb_colonne,nbr_vide=0,test=1,k=deb_colonne-1;
    case_grille c;
    c.ligne=-1;
    c.colonne=-1;
    while(i>=deb_colonne&&i<=fin_colonne)
    {
        if(j->gr.matrice[_ligne][i]!=VIDE)
        {
            i++;
        }
        else
        {
            nbr_vide++;
            c.ligne=_ligne;
            c.colonne=i;
            i++;
        }
        if(nbr_vide>1)
        {
            c.ligne=-1;
            c.colonne=-1;
            return c;
        }
    }
    if(i==fin_colonne+1)
    {
        do
        {
            k++;
            if(k==c.colonne)
                continue;
            if(j->gr.matrice[_ligne][k]!=s)
                test=0;
        }while(test==1&&k<fin_colonne);
    }
    if(test==1)
        return c;
    else
    {
        c.ligne=-1;
        c.colonne=-1;
        return c;
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////
case_grille test_pres_gain_colonne(jeu* j,int _colonne,char s,int deb_ligne,int fin_ligne)
{
    int i=deb_ligne,nbr_vide=0,test=1,k=deb_ligne-1;
    case_grille c;
    c.ligne=-1;
    c.colonne=-1;
    while(i>=deb_ligne&&i<=fin_ligne)
    {
        if(j->gr.matrice[i][_colonne]!=VIDE)
        {
            i++;
        }
        else
        {
            nbr_vide++;
            c.ligne=i;
            c.colonne=_colonne;
            i++;

        }
        if(nbr_vide>1)
        {
            c.ligne=-1;
            c.colonne=-1;
            return c;
        }
    }
    if(i==fin_ligne+1)
    {

        do
        {
            k++;
            if(k==c.ligne)
            {
                continue;
            }
            if(j->gr.matrice[k][_colonne]!=s)
            {
                test=0;
            }
        }while(test==1&&k<fin_ligne);
    }
    if(test==1)
        return c;
    else
    {
        c.ligne=-1;
        c.colonne=-1;
        return c;
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////
case_grille test_pres_gain_diagonale_principale(jeu* j,char s,int deb_diag_p,int fin_diag_p,int pos)
{
    int i=deb_diag_p,nbr_vide=0,test=1,k=deb_diag_p-1;
    case_grille c;
   while(i+pos<0&&i<fin_diag_p)
    {
         i++;
    }
    while(i>=deb_diag_p&&i<=fin_diag_p)
    {

        if(j->gr.matrice[i+pos][i]!=VIDE)
        {

            i++;
        }
        else
        {
            nbr_vide++;
            c.ligne=i+pos;
            c.colonne=i;
            i++;
        }
        if(nbr_vide>1)
        {
            c.ligne=-1;
            c.colonne=-1;
            return c;
        }
    }
    if(i==fin_diag_p)
    {
        do
        {
            k++;
            if(k==c.colonne)
            {

               continue;
            }

            if(j->gr.matrice[k+pos][k]!=s)
            {
                  test=0;
            }


        }while(test==1&&k<fin_diag_p);
    }

    if(test==1)
    {

        return c;
    }

    else
    {
        c.ligne=-1;
        c.colonne=-1;
        return c;
    }
}
///////////////////////////////////////////////////////////////////////////////////////

case_grille test_pres_gain_diagonale_secondaire(jeu* j,char s,int deb_diag_s,int fin_diag_s,int pos_diag)
{
    int i=deb_diag_s,nbr_vide=0,test=1,k=deb_diag_s-1;
    case_grille c;
    c.ligne=-1;
    c.colonne=-1;
    while(i+pos_diag<0&&i<fin_diag_s)
    {
         i++;
    }
    while(i>=deb_diag_s&&i<=fin_diag_s)
    {
        if(j->gr.matrice[i+pos_diag][j->gr.taille-i-1]!=VIDE)
        {
            i++;
        }
        else
        {
            nbr_vide++;
            c.ligne=i+pos_diag;
            c.colonne=j->gr.taille-i-1;
            i++;
        }
        if(nbr_vide>1)
        {

            c.ligne=-1;
            c.colonne=-1;
            return c;
        }
    }
    if(i==fin_diag_s)
    {
        do
        {
            k++;
            if(j->gr.taille-k-1==c.colonne)
            {
                printf("+");
                 continue;
            }

            if(j->gr.matrice[k+pos_diag][j->gr.taille-i-1]!=s)
                test=0;

        }while(test==1&&k<fin_diag_s);
    }
    if(test==1)
        return c;
    else
    {
        c.ligne=-1;
        c.colonne=-1;
        return c;
    }
}
/////////////////////////////////////////////////////////////////////////////////
case_grille test_pres_gain_ligne_pos(jeu* j,int _ligne,char s)
{
    case_grille c;
    c.ligne=-1;
    c.colonne=-1;
    int pos=0;

    do
    {
        c=test_pres_gain_ligne(j,_ligne,s,pos,pos+3);
        pos++;

    }while(pos<=j->gr.taille-4&&c.ligne==-1);
    return c;
}
///////////////////////////////////////////////////////////////////////////////////////
case_grille test_pres_gain_colonne_pos(jeu* j,int _colonne,char s)
{
    case_grille c;
    c.ligne=-1;
    c.colonne=-1;
    int pos=0;
    do
    {
        c=test_pres_gain_colonne(j,_colonne,s,pos,pos+3);
        pos++;

    }while(pos<=j->gr.taille-4&&c.ligne==-1);
    return c;
}
case_grille test_pres_gain_diagonale_principale_pos(jeu* j,char s,int pos_diag)
{
    case_grille c;
    c.ligne=-1;
    c.colonne=-1;
    int pos=0;

    do
    {
        c=test_pres_gain_diagonale_principale(j,s,pos,pos+3,pos_diag);
        pos++;

    }while(pos<=j->gr.taille-4&&c.ligne==-1);
    return c;
}
case_grille test_pres_gain_diagonale_secondaire_pos(jeu* j,char s,int pos_diag)
{
    case_grille c;
    c.ligne=-1;
    c.colonne=-1;
    int pos=0;
    do
    {
        c=test_pres_gain_diagonale_secondaire(j,s,pos,pos+3,pos_diag);
        pos++;
    }while(pos<=j->gr.taille-4&&c.ligne==-1);
    return c;
}
