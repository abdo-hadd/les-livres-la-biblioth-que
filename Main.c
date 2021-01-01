#include "headers.h"
#include "function.c"

int main()
 {
    int  choix;
    char choix1[3];
    fichier = fopen("info_adherent.bin","ab");
    fclose(fichier);
    system("MODE 180,120");
    system("color F9");

do{
           printf("\n\n");
           Ret1://style_menu();
           printf("\n\n");
           printf("\t\t\t\t       %sLe Menu des operations a executee :%s\n\n",NOI,NOI);
           printf("\t\t\t\t         %s====================================================================================== \n",MAR);
           printf("\t\t\t\t         |%s[%s1%s]%s ==>%s Saisir les donnees d'un Adherent%s                                            | \n",BLEM,VIO,BLEM,GRN,NOI,MAR);
           printf("\t\t\t\t         |                                                                                    | \n");
           printf("\t\t\t\t         |%s[%s2%s]%s ==>%s Modifier un Adherent%s                                                        | \n",BLEM,VIO,BLEM,GRN,NOI,MAR);
           printf("\t\t\t\t         |                                                                                    | \n");
           printf("\t\t\t\t         |%s[%s3%s]%s ==>%s Supprimer  un Adherent%s                                                      | \n",BLEM,VIO,BLEM,GRN,NOI,MAR);
           printf("\t\t\t\t         |                                                                                    | \n");
           printf("\t\t\t\t         |%s[%s4%s]%s ==>%s Rechercher un Adherent particulier dans la liste%s                            | \n",BLEM,VIO,BLEM,GRN,NOI,MAR);
           printf("\t\t\t\t         |                                                                                    | \n");
           printf("\t\t\t\t         |%s[%s5%s]%s ==>%s Afficher tous les Adherentes dans la Base de donnees %s                       | \n",BLEM,VIO,BLEM,GRN,NOI,MAR);
           printf("\t\t\t\t         |                                                                                    | \n");
           printf("\t\t\t\t         |%s[%s6%s]%s ==>%s Quitter%s                                                                     |\n",BLEM,VIO,BLEM,GRN,NOI,MAR);
           printf("\t\t\t\t         |====================================================================================|\n\n");
           printf("\t\t\t\t\t\t  Entrez votre choix : ");
           scanf("%s",choix1);
           choix=atoi(choix1);
           while(choix<0 || choix>9 || isalpha(choix1[0]) || ispunct(choix1[0]) || strlen(choix1)>1){
                fflush(stdin);
                system("cls");
                goto Ret1;
           }
           printf("\n\n");
           switch(choix){
                             case 1: fflush(stdin);system("cls");Ajouter_adherent();break;
                             case 2: fflush(stdin);system("cls");Nv_Menu_Modification();break;
                             case 3: fflush(stdin);system("cls");nv_menu_supprime();break;
                             case 4: fflush(stdin);system("cls");nv_menu_recherche();break;
                             case 5: fflush(stdin);system("cls");affichage_all_Adherent();system("cls");break;
                             /*case 6: system("cls");style_porte();style_fin();exit(0);break;*/
                             default : fflush(stdin);system("cls");break;
           }
    }while(choix!=6);
  return 0;
}
