#include <stdlib.h>
#include <string.h>
#include<stdio.h>
#include "grille.h"
#include "jeu.h"
#define VIDE ' ' // statut continue
#define JOUEUR1 'X'
#define JOUEUR2 'O'
#define MATCH_NUL 'N'

jeu* charger()
{
    jeu* j;
    j=(jeu*)malloc(sizeof(jeu));
    FILE * f;
    int i,k,l;
    f=fopen("comptes.txt","r");
    if(f==NULL)
    {
        printf("Impossible d'ouvrir ");
    }
    else
    {


    fscanf(f,"%d/%c/%d/%c/",&j->gr.taille,&j->jr.symbole,&j->nbr_des_cases_vides,&j->statut);
        //fscanf(f,"%d",&g->taille);
        //printf("**");
       // printf("(%d)",g->taille);


        j->gr.matrice=(char**)malloc(j->gr.taille*sizeof(char*));
        for(l=0;l<j->gr.taille;l++)
            j->gr.matrice[l]=(char*)malloc(j->gr.taille*sizeof(char));



       // fseek(f,1,-1);
        for(i=0;i<j->gr.taille;i++)
        {
            for(k=0;k<j->gr.taille;k++)
            {
                fscanf(f,"%c,",&j->gr.matrice[i][k]);
            }
        }

    }
    fclose(f);
    return j;

}
void sauvegarder(jeu* j)
{
    FILE *f;
    int i,k;


    f=fopen("comptes.txt","w+");
    printf("*******");
    fprintf(f,"%d/",j->gr.taille);
  //  fputs("\n",f);
    fprintf(f,"%c/",j->jr.symbole);
   // fputs("\n",f);
    fprintf(f,"%d/",j->nbr_des_cases_vides);
   // fputs("\n",f);
    fprintf(f,"%c/",j->statut);
   // fputs("\n",f);
    for(i=0;i<j->gr.taille;i++)
    {
        for(k=0;k<j->gr.taille;k++)
        {
            fprintf(f,"%c,",j->gr.matrice[i][k]);
        }
    }


    fclose(f);
}

