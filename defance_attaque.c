#include <stdlib.h>
#include <string.h>
#include<stdio.h>
#include "menu.h"
#include "Grille.h"
#include "jeu.h"
#define VIDE ' ' // statut continue
#define JOUEUR1 'X'
#define JOUEUR2 'O'
#define MATCH_NUL 'N'
#include<windows.h>
#include<time.h>
//////////////////////////////////////////////////
/////////////////////////////////////////////

/*case_grille defence_aleatoire(case_grille c,grille* g)
{
    int i=-1,n=-1;
    case_grille *case_tab=NULL;
    case_grille ca;
    //case_tab=(case_grille*)malloc(sizeof(case_grille));
    if(c.colonne<g->taille-1&&g->matrice[c.ligne][c.colonne+1]==VIDE)
    {
        i++;
        case_tab[i].ligne=c.ligne;
        case_tab[i].colonne=c.colonne+1;

    }
    if(c.colonne>0&&g->matrice[c.ligne][c.colonne-1]==VIDE)
    {
        i++;
        case_tab[i].ligne=c.ligne;
        case_tab[i].colonne=c.colonne-1;

    }

    if(c.ligne<g->taille-1&&g->matrice[c.ligne+1][c.colonne]==VIDE)
    {
        i++;
        case_tab[i].ligne=c.ligne+1;
        case_tab[i].colonne=c.colonne;

    }
    if(c.ligne>0&&g->matrice[c.ligne-1][c.colonne]==VIDE)
    {
        i++;
        case_tab[i].ligne=c.ligne-1;
        case_tab[i].colonne=c.colonne;
    }
    if(i==-1&&g->nbr_des_cases_vides!=0)
    {
        return grille_obtenir_position_machine_facile(g);
    }
    do
    {
       n=rand();
    }while(n<0||n>i);
    ca.ligne=case_tab[n].ligne;
    ca.colonne=case_tab[n].colonne;
    free(case_tab);

    return ca;

}*/
//////////////////////////////////////////////////////////////////////////////////
/*case_grille defence(case_grille c,grille* g)
{

}*/
//////////////////////////////////////////////////////////////////////////////////
/*int test_existe_case_vide_proche(case_grille c,grille* g)
{
   int test=0,i=0;
   case_grille ca;
   ca.ligne=c.ligne;
   ca.colonne=c.colonne;
   //if(c.ligne<c)



}*/
///////////////////////////////////////////////////////////////////////////////////////////////////
case_grille defence_aleatoire(case_grille c,grille* g)
{
    case_grille ca;
    ca.ligne=c.ligne;
    ca.colonne=c.colonne;
    int test_existe_case_vide_proche=1;

    if(test_existe_case_vide_proche/*(c,g)*/==1)
    {
        while(ca.ligne==c.ligne&&ca.colonne==c.colonne&&g->matrice[ca.ligne][ca.colonne]!=VIDE)
        {

           if(c.ligne==g->taille-1)
            {
                    do
                    {
                        ca.ligne=rand();
                    }while(ca.ligne<(c.ligne-1)||ca.ligne>c.ligne);

            }
            if(c.ligne==0)
            {
                do
                {
                    ca.ligne=rand();
                }while(ca.ligne<c.ligne||ca.ligne>(c.ligne+1));

            }
            else
            {
                do
                {
                    ca.ligne=rand();
                }while(ca.ligne<(c.ligne-1)||ca.ligne>(c.ligne+1));
            }

            if(c.colonne==g->taille-1)
            {
                    do
                    {
                        ca.colonne=rand();
                    }while(ca.colonne<(c.colonne-1)||ca.colonne>c.colonne);
            }
             if(c.colonne==0)
            {
                    do
                    {
                        ca.colonne=rand();
                    }while(ca.colonne<c.colonne||ca.colonne>(c.colonne+1));
            }
            else
            {
                do
                    {
                        ca.colonne=rand();
                    }while(ca.colonne<(c.colonne-1)||ca.colonne>(c.colonne+1));
            }
        }


    }
    else

        return grille_obtenir_position_machine_facile(g);


   return ca;

}
////////////////////////////////////////
//////////////////////////////////////
////////////////////////////////////
///////////////////////////////
///////////////////////////////////////////////////////////////////

/*case_grille grille_mettre_a_jour_statut(grille* g)
{
    int k=0;

    while(k<g->taille)
    {
        if(test_pres_gain_ligne(g,k)==g->joueur)
        {
            g->statut=g->joueur;
            return g->statut;
        }
        if(test_pres_gain_colonne(g,k)==g->joueur)
        {
            g->statut=g->joueur;
            return g->statut;
        }
        k++;
    }

    if(test_pres_gain_diagonale_principale(g)==g->joueur)
    {
            g->statut=g->joueur;
            return g->statut;

    }

    if(test_pres_gain_diagonale_secondaire(g)==g->joueur)
    {
            g->statut=g->joueur;

            return g->statut;

    }

    if(g->nbr_des_cases_vides==0)
    {
         g->statut=MATCH_NUL;

         return g->statut;
    }
    return g->statut;


}
case_grille test_pres_gain(grille* g,case_grille* tab_case,int position)
{

    int j=0;


    while(g->matrice[_ligne][j]==g->matrice[_ligne][j+1]&&g->matrice[_ligne][j]!=VIDE)
    {
        j++;
        if(j==g->taille-2)
        {
            if(g->matrice[_ligne][0]==JOUEUR1)
                return JOUEUR1;
            else
                return JOUEUR2;
        }


    }
    return VIDE;
}
int nbre_de_cases_vides_vecteur(int position,grille* g)
{
    int m=0;
    do
    {
        if(g->matrice[position][m]==VIDE)
            m++;
    }while(m<g->);
}*/


case_grille test_pres_gain_diagonale_secondaire(grille* g,char s)
{
    int i=0,nbr_vide=0,test=1,j=-1;
    case_grille c;
    while(i<g->taille)
    {
        if(g->matrice[i][g->taille-i-1]!=VIDE)
        {
            i++;
        }
        else
        {
            nbr_vide++;
            c.ligne=i;
            c.colonne=g->taille-i-1;
            i++;
        }
        if(nbr_vide>1)
        {
            c.ligne=-1;
            c.colonne=-1;
            return c;
        }
    }
    if(i==g->taille)
    {
        do
        {
            j++;
            if(j==c.ligne)
                continue;
            if(g->matrice[j][g->taille-j-1]!=s)
                test=0;

        }while(test==1&&j<g->taille-1);
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
case_grille test_pres_gain_ligne(grille* g,int _ligne,char s)
{
    int i=0,nbr_vide=0,test=1,j=-1;
    case_grille c;
    c.ligne=-1;
    c.colonne=-1;
    while(i<g->taille)
    {
        if(g->matrice[_ligne][i]!=VIDE)
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
    if(i==g->taille)
    {
        do
        {
            j++;
            if(j==c.colonne)
                continue;
            if(g->matrice[_ligne][j]!=s)
                test=0;
        }while(test==1&&j<g->taille-1);
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
case_grille test_pres_gain_diagonale_principale(grille* g,char s)
{
    int i=0,nbr_vide=0,test=1,j=-1;
    case_grille c;
    while(i<g->taille)
    {
        if(g->matrice[i][i]!=VIDE)
        {
            i++;
        }
        else
        {
            nbr_vide++;
            c.ligne=i;
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
    if(i==g->taille)
    {
        do
        {
            j++;
            if(j==c.ligne)
                continue;
            if(g->matrice[j][j]!=s)
                test=0;

        }while(test==1&&j<g->taille-1);
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
case_grille test_pres_gain_colonne(grille* g,int _colonne,char s)
{
    int i=0,nbr_vide=0,test=1,j=-1;
    case_grille c;
    c.ligne=-1;
    c.colonne=-1;
    while(i<g->taille)
    {
        if(g->matrice[i][_colonne]!=VIDE)
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
    if(i==g->taille)
    {
        do
        {
            j++;
            if(j==c.ligne)
            {
                continue;
            }
            if(g->matrice[j][_colonne]!=s)
            {
                test=0;
            }
        }while(test==1&&j<g->taille-1);
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
case_grille defence_attaque(grille* g,char s)
{
    int k=0;
    if(test_pres_gain_diagonale_principale(g,s).ligne!=-1)
        return test_pres_gain_diagonale_principale(g,s);
    if(test_pres_gain_diagonale_secondaire(g,s).ligne!=-1)
        return test_pres_gain_diagonale_secondaire(g,s);
    while(k<=g->taille-1)
    {
        if(test_pres_gain_ligne(g,k,s).ligne!=-1)
        {
            return test_pres_gain_ligne(g,k,s);
        }

        if(test_pres_gain_colonne(g,k,s).ligne!=-1)
        {
            return test_pres_gain_colonne(g,k,s);
        }
        k++;
    }
    return grille_obtenir_position_machine_facile(g);
}
