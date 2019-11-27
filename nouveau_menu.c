
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "grille.h"
#include "jeu.h"
#define VIDE ' ' // statut continue
#define JOUEUR1 'X'
#define JOUEUR2 'O'
#define MATCH_NUL 'N'


//////////////////////////  MENU PRINCIPALE  //////////////////////////////////
void menu_principale()
{

    int choix=0;
    jeu* j=NULL;


    do
    {
                printf("      �������������������������� Bienvenu dans TIC TAC TOE����������������������������ͻ\n");
                printf("      �   -----------------------------------------------------                        �\n");
                printf("      �  (  | 1 | Commence une nouvelle partie                                       ) �\n");
                printf("      �                                                                                �\n");
                printf("      �  (  | 2 | Charger une partie sauvegardee                                     ) �\n");
                printf("      �                                                                                �\n");
                printf("      �  (  | 3 | Decrire les fonctionnements du jeu                                 ) �\n");
                printf("      �                                                                              ) �\n");
                printf("      �  (  | 4 | Quitter                                                            ) �\n");
                printf("      �                                                                              ) �\n");
                printf("      �   -----------------------------------------------------                        �\n");
                printf("      ��������������������������������������������������������������������������������ͼ\n");
                printf("      *        Entrer Votre Choix                    *\t");

        scanf("%d", &choix);

    }
    while((choix<1) && (choix>4));

    switch(choix)
    {

    case 1:
        menu_du_Nouveau_Partie();
        break;
    case 2 :
          j=charger();


           printf("\n\n\n\t\t la partie est chargee\n") ;
            menu_du_mode_de_jeu(j);


                Sleep(1000);

       break;
        printf("\n\n La partie est chargee \n\n");
       // menu_Nouvelle_Partie();
        break;
    case 3:
        printf("\n...............................................\n");
        printf("Les deux joueurs remplissent alternativement les  \n");
        printf("grilles vides avec de symboles specifiques. Le but \n");
        printf("est de placer n symboles identiques sur une \n");
        printf("colonne, une ligne ou une diagonale. Le jeu prend \n");
        printf("fin si le panneau est entierement rempli et si aucun \n");
        printf("joueur n arrive a atteindre le but. ");
        printf("\n...............................................\n\n\n\n");
        menu_principale();
        break;
    case 4:
        printf ("  \n    ********* Merci pour votre consontration ********* \n\n\n\n");
        exit(0);
        break;
    default:
        system("cls");
        menu_principale();
        break;


    }

}

//////////////////////////////// MENU DU NEAUVEAU PARTIE /////////////////////////////////
void menu_du_Nouveau_Partie()
{
     int  choix1=0;
//     int taille;
     jeu* j=NULL;

     system("cls");
     //*g=creer_grille();

    do
    {
                printf("      ��������������������������MENU DU NEAUVEAU PARTIE����������������������������ͻ\n");
                printf("      �   -----------------------------------------------------                     �\n");
                printf("      �  (  | 1 | Donner la taille                                                ) �\n");
                printf("      �                                                                             �\n");
                printf("      �  (  | 2 | Retour                                                          ) �\n");
                printf("      �                                                                             �\n");
                printf("      �   -----------------------------------------------------                     �\n");
                printf("      �����������������������������������������������������������������������������ͼ\n");
                printf("      *        Entrer Votre Choix                    *\t");

        printf("\n-------------------");
        printf("\n\nVeuillez entrer votre choix : ");
        scanf("%d",&choix1);

    }
    while((choix1<1)&&(choix1>2));

 printf("**");
    switch(choix1)
    {
    case 1:
       // system("cls");
        /*do
        {
            printf("Donner la taille : ");
            scanf("%d",&taille);
            printf("...........");
            settaille(g,taille);
            printf("...........");
        }while(taille<3);*/

        j=creer_grille();

        menu_du_mode_de_jeu(j);

        break;
        menu_du_Nouveau_Partie();


    case 2:
         menu_principale();
        break;
    default:
        system("cls");
        menu_du_Nouveau_Partie();
        break;

    }
}
//////////////////////// MENU DU MODE DE JEU //////////////////////////////////////////////////
void menu_du_mode_de_jeu(jeu* j)
{
     int  choix1=0;
     int difficulte;
     char nom_joueur[10],nom_joueur_1[10],nom_joueur_2[10];

    system("cls");

    do
    {
                printf("      ��������������������������Menu Mode De Jeu ����������������������������ͻ\n");
                printf("      �   -----------------------------------------------------                �\n");
                printf("      �  (  | 1 | Jouer contre un humain                                     ) �\n");
                printf("      �                                                                        �\n");
                printf("      �  (  | 2 | Jouer contre le machine                                    ) �\n");
                printf("      �                                                                        �\n");
                printf("      �  (  | 3 | Retour                                                     ) �\n");
                printf("      �                                                                        �\n");
                printf("      �   -----------------------------------------------------                �\n");
                printf("      ��������������������������������������������������������������������������ͼ\n");
                printf("      *        Entrer Votre Choix                    *\t");

                scanf("%d",&choix1);

    }
    while((choix1<1)&&(choix1>3));

    switch(choix1)
    {
    case 1:
        system("cls");
        printf("Entrer les noms des joueurs : \n");
        printf("Joueur num 1 :\t");
        scanf("%s",nom_joueur_1);
        printf("\nJoueur num 2 :\t");
        scanf("%s",nom_joueur_2);
        fflush(stdin);
        match_joueur_vs_joueur(j);
        menu_retour_joueur();

        break;
    case 2:
        system("cls");
        //printf("\n/////////////////////////////////////////////////////\n");
        printf("\nEntrer le nom du joueur:\t");
        scanf("%s",nom_joueur);
        fflush(stdin);
        printf("\n/////////////////////////////////////////////////////\n");


        system("cls");
        printf("\n/////////////////////////////////////////////////////\n");
        printf("Choisir la difficulte : \n");
        printf("1.Facile\n");
        printf("2.Moyenne\n");
        printf("3.Difficile\n");
        printf("\n/////////////////////////////////////////////////////\n");
        do
        {
            printf("\ndifficulte = ");
            scanf("%d",&difficulte);
            j->difficulte=difficulte;
        }while(difficulte<1&&difficulte>3);
        switch(difficulte)
        {
            case 1 :
              printf("\n**********facile***********\n");
              match_joueur_vs_machine_facile(j);
              Sleep(3000);
              system("cls");
              menu_retour_machine_facile();

              break;
            case 2 :
                printf("\n**********Moyenne***********\n");
                match_joueur_vs_machine_moyenne(j);
                menu_retour_machine_moyenne();

                break;
            case 3 :
                printf("\n**********Difficile***********\n");
                match_joueur_vs_machine_difficile(j);
                menu_retour_machine_difficile();

                break;
            default:
                printf("erreur");
                break;
        }

        break;
    case 3:
         menu_du_Nouveau_Partie();
        break;
    default:
        system("cls");
        menu_du_mode_de_jeu(j);
        break;

    }
}
//////////////////////////////////////////////////////////////////////////////////
void menu_secondaire(jeu* j)
{
    int choix1;

     system("cls");
                do
                    {
                        printf("      ��������������������������MENU_SECONDAIRE����������������������������ͻ\n");
                        printf("      �   -----------------------------------------------------             �\n");
                        printf("      �  (  | 1 | Continuer                               )                 �\n");
                        printf("      �                                                                     �\n");
                        printf("      �  (  | 2 | Sauvgarder la partie                                    ) �\n");
                        printf("      �                                                                     �\n");
                        printf("      �  (  | 3 | Retour au menu principale                               ) �\n");
                        printf("      �                                                                     �\n");
                        printf("      �  (  | 4 | Quitter                                                 ) �\n");
                        printf("      �                                                                     �\n");
                        printf("      �   -----------------------------------------------------             �\n");
                        printf("      ������������������������������������������������������������������ͼ   \n");
                        printf("      *        Entrer Votre Choix                    *\t");
                        // votre choix
                        scanf("%d",&choix1);
                        switch (choix1)
                        {
                        case 1:
                            system("cls");


                            return ;
                            break;

                        case 2 :
                           sauvegarder(j);
                            printf("============================================\n");
                            printf("============================================\n");
                            printf("============================================\n");
                            printf("la partie est sauvgardee");
                            printf("============================================\n");
                            printf("============================================\n");
                            printf("============================================\n");
                            Sleep(2000);
                            menu_principale();
                        case 3 :
                            system("cls");
                            menu_principale();


                        }



                    }while(choix1!=4);


}
