#include "headers.h"
#include "function.c"

 int main()
 {
    int  choix;
    char a,c[3];
    fichier = fopen("info_adherent.bin","ab");
    fclose(fichier);
    system("MODE 200,150");
    system("color F9");

do{
           printf("\n\n");
           nn://style_menu();
           printf("\n\n");
           printf("\t\t\t\t       %sLe Menu des operations a executee :%s\n\n",NOI,NOI);
           printf("\t\t\t\t         %s====================================================================================== \n",MAR);
           printf("\t\t\t\t         |%s[%s1%s]%s ==>%s Saisir les donnees d'un Adhérent%s                                             | \n",BLEM,VIO,BLEM,GRN,NOI,MAR);
           printf("\t\t\t\t         |                                                                                    | \n");
           printf("\t\t\t\t         |%s[%s2%s]%s ==>%s Acheter un produit%s                                                          | \n",BLEM,VIO,BLEM,GRN,NOI,MAR);
           printf("\t\t\t\t         |                                                                                    | \n");
           printf("\t\t\t\t         |%s[%s3%s]%s ==>%s Livraison d'un produit%s                                                      | \n",BLEM,VIO,BLEM,GRN,NOI,MAR);
           printf("\t\t\t\t         |                                                                                    | \n");
           printf("\t\t\t\t         |%s[%s4%s]%s ==>%s Supprimer  un produit%s                                                       | \n",BLEM,VIO,BLEM,GRN,NOI,MAR);
           printf("\t\t\t\t         |                                                                                    | \n");
           printf("\t\t\t\t         |%s[%s5%s]%s ==>%s Afficher l'etat d'un produit particulier dans le stock%s                      | \n",BLEM,VIO,BLEM,GRN,NOI,MAR);
           printf("\t\t\t\t         |                                                                                    | \n");
           printf("\t\t\t\t         |%s[%s6%s]%s ==>%s Afficher les Produits  qui ont une quantite inferieur a seuil minimum%s       | \n",BLEM,VIO,BLEM,GRN,NOI,MAR);
           printf("\t\t\t\t         |                                                                                    | \n");
           printf("\t\t\t\t         |%s[%s7%s]%s ==>%s Afficher tout les produits dans le Stock%s                                    | \n",BLEM,VIO,BLEM,GRN,NOI,MAR);
           printf("\t\t\t\t         |                                                                                    | \n");
           printf("\t\t\t\t         |%s[%s8%s]%s ==>%s Quitter%s                                                                     |\n",BLEM,VIO,BLEM,GRN,NOI,MAR);
           printf("\t\t\t\t         |====================================================================================|\n\n");
           printf("\t\t\t\t\t\t  Entrez votre choix : ");
           scanf("%s",c);
           choix=atoi(c);
           while(choix<0 || choix>9 || isalpha(c[0]) || ispunct(c[0]) || strlen(c)>1){
                                           fflush(stdin);
                                           system("cls");
                                           goto nn;
                                        }


           printf("\n\n");
           switch(choix){
                             case 1: fflush(stdin);system("cls");Ajouter_adherent();break;
                             /*case 2: fflush(stdin);system("cls");nv_menu_achat();break;
                             case 3: fflush(stdin);system("cls");nv_menu_livraison();break;
                             case 4: fflush(stdin);system("cls");nv_menu_supprime();break;
                             case 5: fflush(stdin);system("cls");nv_menu_recherche();break;
                             case 6: fflush(stdin);system("cls");affichage_info_produit_seuil_minimum();break;
                             case 7: fflush(stdin);system("cls");affichage_all_produit();system("cls");break;
                             case 8: system("cls");style_porte();style_fin();exit(0);break;*/
                             default : fflush(stdin);system("cls");break;
                        }

    }while(choix!=8);

  return 0;
}
