#include "headers.h"
                                 /*§§§§§§§§§§§§§§§§§§§§§§§§ -LES FONCTIONS ET PROCEDURES- §§§§§§§§§§§§§§§§§§§§§§§§§§§§*/




        ///***********************************************    saisie les information :  ***********************************************\\\

void Ajouter_adherent(){
    int n,choix,Numero_adherent,Nombre_adherent,i,erreur,match;
    char mail[30];
    regex_t preg ;
    const char *str_regex = "^[a-z0-9][-a-z0-9._]+@([-a-z0-9]+.)+[a-z]{2,4}$";
    ret1:printf("\n\n\t\t\t\t\tDonnez le nombre des adherents que vous voulez ajouter : ");
    while(!(scanf("%d",&Nombre_adherent ))){
    fflush(stdin);
    system("cls");
    goto ret1;
    }
    fflush(stdin);
    printf("\n\n");
    for(i=0; i<Nombre_adherent; i++){
        system("cls");
        style_ajoute();
        printf("\n\n\t\t\t%sSaisie les information de Adherent N*%d  %s:\n\n",MIT,i+1,NOI);
        ret2:printf("\n\t\tCode de l'adherent : ");
        while (!(scanf("%d",&Numero_adherent))){
            fflush(stdin);
            goto ret2;
        }
        while(Libre_place_Adherent(Numero_adherent)==1){
            fflush(stdin);
            printf("\n\t\t\t\t%s   ce code deja existe dans note base de donnees %s\n ",RED,NOI);
            goto ret2;
        }
        fichier = fopen("info_adherent.bin","ab");
        if(fichier == NULL){
            system("cls");
            printf("\n\t%s on peut pas acces au fichier%s \n\n",RED,NOI);
            getchar();
            exit(0);
        }
        Information_adherent[i].num_adh=Numero_adherent;
        printf("\n\t\tNom de la Adherent : ");
        fflush(stdin);
        gets(Information_adherent[i].nom_adh);
        printf("\n\t\tPrenom de la Adherent : ");
        fflush(stdin);
        gets(Information_adherent[i].prenom_adh);


        Ret3:printf("\n\t\tEmail de la Adherent : ");
        fflush(stdin);
        gets(mail);
        // mohim hna khoa sami mafhmtche lache regex mabrache ikhdm 3ndi
        /*
        const char *str_request = mail;
        while(1){
            erreur = regcomp(&preg, str_regex, REG_NOSUB | REG_EXTENDED);
            if (erreur == 0){
                match = regexec (&preg, str_request, 0, NULL, 0);
                regfree (&preg);
                if (match == 0 || mail[0]== 00)
                goto Ret4;
                else if (match == REG_NOMATCH){
                    printf("\n\t\t%s[!] Email n'est pas valide! Essayez une autre fois \n\n",RED);
                    goto Ret3;
                }
            }
        }
        Ret4:*/
        strcpy(Information_adherent[i].email_adh,mail);
        printf("\n\t\tAdresse de la Adherent : ");
        fflush(stdin);
        gets(Information_adherent[i].adress_adh);
        printf("\n\n");
        system("cls");
        Information_adherent[i].nbre_emprunts_adh = 0;
        fwrite(&Information_adherent[i] , sizeof(adherent) , 1 , fichier);
        fclose(fichier);
        fflush(stdin);
        system("cls");
    }
}

        ///**********************************************    test si place est disponible pour adhérent :  ***********************************************\\\

int Libre_place_Adherent(int num){
   FILE *fichier;
   int trouver=0;
   fichier = fopen("info_adherent.bin","rb");
   fread(&Un_Adherent , sizeof(adherent), 1, fichier);
   while(!feof(fichier)){
     if(Un_Adherent.num_adh==num){
            trouver=1;
     }
     fread(&Un_Adherent , sizeof(adherent), 1, fichier);
   }
   fclose(fichier);
   return trouver;
}

                ///***********************************************    affichages du tous les adhérents saisies :  ***********************************************\\\



void affichage_all_Adherent(){
    char c;
    int i=1;
    fichier = fopen("info_adherent.bin","rb");
    if(fichier == NULL){
        printf("on peut pas acces au fichier! \n");
        exit(0);
    }
    fread(&Un_Adherent , sizeof(adherent), 1, fichier);
    printf("\n\n----%s\\%sNumero Adherent%s/-------------\\%sNom%s/------------------\\%sPrenom%s/--------------\\%sEmail%s/-------------------------\\%sAdresse%s/-----------------------\\%sNombre de Empruntes%s/\n",NOI,GRN,NOI,GRN,NOI,GRN,NOI,GRN,NOI,GRN,NOI,GRN,NOI,NOI);
    printf("=====================================================================================================================================================================\n");
    while(!feof(fichier)){
    printf("            %s%-22d %-22s %-18s   %-30s %-40s %d %s\n",
            RED,Un_Adherent.num_adh,Un_Adherent.nom_adh,Un_Adherent.prenom_adh,
            Un_Adherent.email_adh,Un_Adherent.adress_adh,Un_Adherent.nbre_emprunts_adh,NOI);
    printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    i++;
    fread(&Un_Adherent , sizeof(adherent), 1, fichier);
    }
    printf("\n\n\t\t\t%s Tape Entre pour retourn aux menu principale !!",BLEN);
    c= getchar();
    fflush(stdin);
fclose(fichier);
}

                ///***********************************************    Menu de supprime :  ***********************************************\\\


void nv_menu_supprime(){
    int choix1;
    char choix[3];
    do{
        ret3: style_supprime();
        printf("\n\n\n\t\t\t\t\t%svous voulez rechercher avec:\n ",RED);
        printf("\n\t\t\t\t%s[%s1%s]%s ==>%s Numero Adherent  \n",BLEM,VIO,BLEM,GRN,NOI);
        printf("\n\t\t\t\t%s[%s2%s]%s ==>%s Nom de L Adhrent \n",BLEM,VIO,BLEM,GRN,NOI);
        printf("\n\t\t\t\t%s[%s3%s]%s ==>%s Revenir aux menu\n",BLEM,VIO,BLEM,GRN,NOI);
        printf("\n\n\t\t\t\t\t %sEntrer votre choix :",MIT);
        scanf("%s",choix);
        choix1=atoi(choix);
        while (choix1<0 || choix1>4 || isalpha(choix[0]) || ispunct(choix[0]) || strlen(choix)>1){
            fflush(stdin);
            system("cls");
            goto ret3;
        }
        printf("\n\n");
        switch(choix1){
            case 1: fflush(stdin);system("cls");Supprimer_code_Adherent();break;
            case 2: fflush(stdin);system("cls");Supprimer_nom_Adherent();break;
            default : fflush(stdin);system("cls");break;
        }
    }while(choix1!=3);
}

       ///***********************************************    Supprimer un Adherent a l aide Numero identifient  :  ***********************************************\\\


void Supprimer_code_Adherent(){
    int numero_adherent, choix, flag,ch;
    char c[3];
    FILE *fichier1,*fichier_temporaire;
    Ret5: fichier = fopen("info_adherent.bin","rb");
    fichier1 = fopen("Info_code_supprimer.bin","wb");
    flag=0;
    fflush(stdin);
    system("cls");
    Ret6:style_supprime_poubelle();
    printf("\n\n\t\t\t\t\t Saisir le code de Adherent que vous voulez supprimer : ");
    while(!(scanf("%d",&numero_adherent))){
        fflush(stdin);
        system("cls");
        goto Ret6;
    }
    fflush(stdin);
    fread(&Un_Adherent, sizeof(adherent), 1, fichier);
    while(!feof(fichier)){
        if(Un_Adherent.num_adh == numero_adherent){
            flag=1;
            printf("\n\n\t\t\t\t%s ADHERENT EST BIEN SUPPRIMER :) ",GRN);
        }
        else
            fwrite(&Un_Adherent, sizeof(adherent), 1, fichier1);
        fread(&Un_Adherent, sizeof(adherent), 1, fichier);
    }
    if(flag == 0){
            printf("\n\n\t\t\t\t%s LE CODE QUE VOUS ETES CHOISIS N'EXISTE PAR SUR LA LISTE .\n\n",RED);
    }
    Ret7: printf("\n\n\n\t\t\t\t\t%s Voulez vous supprimer un autre Adherent ?\n\t\t\t\t\t ('1-Oui/0-Non' tu doit ecrire que l'entier )  : ",NOI);
    scanf("%s",c);
    ch=atoi(c);
    while(ch<0 || ch>1 || isalpha(c[0]) || ispunct(c[0]) || strlen(c)>1){
        system("cls");
        fflush(stdin);
        goto Ret7;
    }
    system("cls");
    fclose(fichier);
    fclose(fichier1);
    remove("info_adherent.bin");
    rename("Info_code_supprimer.bin","info_adherent.bin");
    if(ch==1){
        system("cls");
        goto Ret5;
    }
}

        ///***********************************************    Supprimer un Adherent par Nom :  ***********************************************\\\


void Supprimer_nom_Adherent(){
    int choix, flag,ch;
    char Nom_Adherent[50];
    char c[3];
    FILE *fichier1,*fichier_temporaire;
    Ret5: fichier = fopen("info_adherent.bin","rb");
    fichier1 = fopen("Info_nom_supprimer.bin","wb");
    flag=0;
    fflush(stdin);
    system("cls");
    style_supprime_poubelle();
    printf("\n\n\t\t\t\t\t Saisir le Nom de Adherent que vous voulez supprimer : ");
    scanf("%s",&Nom_Adherent);
    fflush(stdin);
    fread(&Un_Adherent, sizeof(adherent), 1, fichier);
    while(!feof(fichier)){
        if(strcmp(Nom_Adherent,Un_Adherent.nom_adh)==0){
            flag=1;
            printf("\n\n\t\t\t\t%s ADHERENT EST BIEN SUPPRIMER :) ",GRN);
        }
        else
            fwrite(&Un_Adherent, sizeof(adherent), 1, fichier1);
        fread(&Un_Adherent, sizeof(adherent), 1, fichier);
    }
    if(flag == 0){
            printf("\n\n\t\t\t\t%s LE NOM QUE VOUS ETES CHOISIS N'EXISTE PAR SUR LA LISTE .\n\n",RED);
    }
    Ret7: printf("\n\n\n\t\t\t\t\t%s Voulez vous supprimer un autre Adherent ?\n\t\t\t\t\t ('1-Oui/0-Non' tu doit ecrire que l'entier )  : ",NOI);
    scanf("%s",c);
    ch=atoi(c);
    while(ch<0 || ch>1 || isalpha(c[0]) || ispunct(c[0]) || strlen(c)>1){
        system("cls");
        fflush(stdin);
        goto Ret7;
    }
    system("cls");
    fclose(fichier);
    fclose(fichier1);
    remove("info_adherent.bin");
    rename("Info_nom_supprimer.bin","info_adherent.bin");
    if(ch==1){
        system("cls");
        goto Ret5;
    }
}
            ///***********************************************    Menu de Recherche :  ***********************************************\\\


void nv_menu_recherche(){
        int choix1;
        char choix[3];
        do{
        ret9:style_recherche();
        printf("\n\n\n\t\t\t\t\t%svous voulez rechrcher avec:\n ",RED);
        printf("\n\t\t\t\t%s[%s1%s]%s ==>%s Numero Adherent  \n",BLEM,VIO,BLEM,GRN,NOI);
        printf("\n\t\t\t\t%s[%s2%s]%s ==>%s Nom de Adherent\n",BLEM,VIO,BLEM,GRN,NOI);
        printf("\n\t\t\t\t%s[%s3%s]%s ==>%s Revenir aux menu\n",BLEM,VIO,BLEM,GRN,NOI);
        printf("\n\n\t\t\t\t\t %sEntrer votre choix :",MIT);
        scanf("%s",choix);
        choix1=atoi(choix);
        while (choix1<0 || choix1>4 || isalpha(choix[0]) || ispunct(choix[0]) || strlen(choix)>1){
            fflush(stdin);
            system("cls");
            goto ret9;
        }
        printf("\n");
        switch(choix1){
              case 1: fflush(stdin);system("cls");Affichage_Adherent_Numero();break;
              case 2: fflush(stdin);system("cls");Affichage_Adherent_Nom();break;
              default : fflush(stdin);system("cls");break;
        }
        }while(choix1!=3);
}


    ///***********************************************    affichage  produit par code fournisseur :  ***********************************************\\\



void Affichage_Adherent_Numero(){
    int Numero_Adherent, flag,ch;
    char c[3];
    flag=0;
    Ret11: fichier = fopen("info_adherent.bin","rb");
    fflush(stdin);
    if(fichier == NULL){
        printf("Erreur : fichier introuvable !!!! \n");
        exit(0);
    }
    fflush(stdin);
    style_recherche();
    Ret10:printf("\n\n\n\n\t\t\t\t Saisie le numero de produit que vous voulez afficher : ");
    while(!(scanf("%d",&Numero_Adherent))){
        fflush(stdin);
        system("cls");
        goto Ret10;
    }
    fflush(stdin);
    system("cls");
    style_recherche_loupe();
    printf("\n\n");
    fread(&Un_Adherent , sizeof(adherent), 1, fichier);
    while(!feof(fichier))
    {
       if(Numero_Adherent == Un_Adherent.num_adh){
          flag=1;
          printf("\t\t\t\t\t%s===================================================================================\n",VIO);
          printf("\t\t\t\t\t|\t\t%sLes informations de ADHERENT  N*%-20d%s              |\n",BLE,Numero_Adherent,VIO);
          printf("\t\t\t\t\t|                                                                                 |\n");
          printf("\t\t\t\t\t|    %sNumero de Adherent : %s%-20d%s                                    |\n",MIT,NOI,Un_Adherent.num_adh,VIO);
          printf("\t\t\t\t\t|                                                                                 |\n");
          printf("\t\t\t\t\t|    %sLe Nom de L'adherent : %s%-20s%s                                  |\n",MIT,NOI,Un_Adherent.nom_adh,VIO);
          printf("\t\t\t\t\t|                                                                                 |\n");
          printf("\t\t\t\t\t|    %sLe Prenom de L'adherent : %s%-20s%s                               |\n",MIT,NOI,Un_Adherent.prenom_adh,VIO);
          printf("\t\t\t\t\t|                                                                                 |\n");
          printf("\t\t\t\t\t|    %sEmail de L'adherent : %s%-20s%s                                  |\n",MIT,NOI,Un_Adherent.email_adh,VIO);
          printf("\t\t\t\t\t|                                                                                 |\n");
          printf("\t\t\t\t\t|    %sAdresse : %s%-20s%s                                               |\n",MIT,NOI,Un_Adherent.adress_adh,VIO);
          printf("\t\t\t\t\t|                                                                                 |\n");
          printf("\t\t\t\t\t|    %sNombre de L'empruntes : %s%-20d%s                                 |\n",MIT,NOI,Un_Adherent.nbre_emprunts_adh,VIO);
          printf("\t\t\t\t\t|                                                                                 |\n");
          printf("\t\t\t\t\t===================================================================================\n");
          printf("\n\n");
       }
       fread(&Un_Adherent , sizeof(adherent), 1, fichier);
    }
    if(flag == 0){
      fflush(stdin);
      printf("\n\n\t\t %sAucun Adherent trouver avec le numero que vous avez saisie :( %s\n\n",RED,NOI);
    }
    fclose(fichier);
    fflush(stdin);
    Ret13:printf("\n\n\t\t\t\t\t %sVoulez vous afficher un autre Adherent ? \n\t\t\t\t\t('1-Oui/0-Non' tu doit ecrire que l'entier )  : ",NOI);
    scanf("%s",c);
    ch=atoi(c);
    while(ch<0 || ch>1 || isalpha(c[0]) || ispunct(c[0]) || strlen(c)>1){
        system("cls");
        fflush(stdin);
        goto Ret13;
    }
    if(ch==1){
        system("cls");
        goto Ret11;
    }
    system("cls");
}



            ///***********************************************    affichage  produit par nom :  ***********************************************\\\


void Affichage_Adherent_Nom(){
    char Nom_Adherent[50];
    int flag,ch;
    char c[3];
    flag=0;
    Ret11: fichier = fopen("info_adherent.bin","rb");
    fflush(stdin);
    if(fichier == NULL){
        printf("Erreur : fichier introuvable !!!! \n");
        exit(0);
    }
    fflush(stdin);
    style_recherche();
    printf("\n\n\n\n\t\t\t\t Saisie le Nom de L'adherent que vous voulez afficher : ");
    scanf("%s",&Nom_Adherent);
    fflush(stdin);
    system("cls");
    style_recherche_loupe();
    printf("\n\n");
    fread(&Un_Adherent , sizeof(adherent), 1, fichier);
    while(!feof(fichier))
    {
       if(strcmp(Un_Adherent.nom_adh,Nom_Adherent)==0){
          flag=1;
          printf("\t\t\t\t\t%s===================================================================================\n",VIO);
          printf("\t\t\t\t\t|\t\t%sLes informations de ADHERENT  N*%-20d%s              |\n",BLE,Un_Adherent.num_adh,VIO);
          printf("\t\t\t\t\t|                                                                                 |\n");
          printf("\t\t\t\t\t|    %sNumero de Adherent : %s%-20d%s                                    |\n",MIT,NOI,Un_Adherent.num_adh,VIO);
          printf("\t\t\t\t\t|                                                                                 |\n");
          printf("\t\t\t\t\t|    %sLe Nom de L'adherent : %s%-20s%s                                  |\n",MIT,NOI,Un_Adherent.nom_adh,VIO);
          printf("\t\t\t\t\t|                                                                                 |\n");
          printf("\t\t\t\t\t|    %sLe Prenom de L'adherent : %s%-20s%s                               |\n",MIT,NOI,Un_Adherent.prenom_adh,VIO);
          printf("\t\t\t\t\t|                                                                                 |\n");
          printf("\t\t\t\t\t|    %sEmail de L'adherent : %s%-20s%s                                  |\n",MIT,NOI,Un_Adherent.email_adh,VIO);
          printf("\t\t\t\t\t|                                                                                 |\n");
          printf("\t\t\t\t\t|    %sAdresse : %s%-20s%s                                               |\n",MIT,NOI,Un_Adherent.adress_adh,VIO);
          printf("\t\t\t\t\t|                                                                                 |\n");
          printf("\t\t\t\t\t|    %sNombre de L'empruntes : %s%-20d%s                                 |\n",MIT,NOI,Un_Adherent.nbre_emprunts_adh,VIO);
          printf("\t\t\t\t\t|                                                                                 |\n");
          printf("\t\t\t\t\t===================================================================================\n");
          printf("\n\n");
       }
       fread(&Un_Adherent , sizeof(adherent), 1, fichier);
    }
    if(flag == 0){
      fflush(stdin);
      printf("\n\n\t\t %sAucun Adherent trouver avec le Nom que vous avez saisie :( %s\n\n",RED,NOI);
    }
    fclose(fichier);
    fflush(stdin);
    Ret13:printf("\n\n\t\t\t\t\t %sVoulez vous afficher un autre Adherent ? \n\t\t\t\t\t('1-Oui/0-Non' tu doit ecrire que l'entier )  : ",NOI);
    scanf("%s",c);
    ch=atoi(c);
    while(ch<0 || ch>1 || isalpha(c[0]) || ispunct(c[0]) || strlen(c)>1){
        system("cls");
        fflush(stdin);
        goto Ret13;
    }
    if(ch==1){
        system("cls");
        goto Ret11;
    }
    system("cls");
}

        ///***********************************************    Menu de Recherche Pour Modification :  **********************************************\\\


void Nv_Menu_Modification()
{
    int choix1;
        char co[3];
        do{
        Ret1:style_modification() ;
        printf("\n\t\t\t\t\t%sPour Modifier :vous voulez rechrcher avec:\n ",RED);
        printf("\n\t\t\t\t%s[%s1%s]%s ==>%s Numero Adherent  \n",BLEM,VIO,BLEM,GRN,NOI);
        printf("\n\t\t\t\t%s[%s2%s]%s ==>%s Nom Adherent\n",BLEM,VIO,BLEM,GRN,NOI);
        printf("\n\t\t\t\t%s[%s3%s]%s ==>%s Revenir aux menu\n",BLEM,VIO,BLEM,GRN,NOI);
        printf("\n\n\t\t\t\t\t %sEntrer votre choix :",MIT);
        scanf("%s",co);
        choix1=atoi(co);
        while (choix1<0 || choix1>4 || isalpha(co[0]) || ispunct(co[0]) || strlen(co)>1){
            fflush(stdin);
            system("cls");
            goto Ret1;
        }
        printf("\n");
        switch(choix1){
            case 1: fflush(stdin);system("cls");Modification_Numero();break;
            case 2: fflush(stdin);system("cls");Modification_Nom();break;
            default : fflush(stdin);system("cls");break;
        }
        }while(choix1!=3);
}

                    ///***********************************************    Modification par numero :  **********************************************\\\

void Modification_Numero(){
    int Numero_Adherent, choix, flag,ch1,ch, Choix_champs,NV_Numero_Adherent;
    char d[3],repeter[3],c[3];
    FILE *fichier1 ;
    flag=0;
    Ret1: fichier = fopen("info_adherent.bin","rb");
    fichier1 = fopen("Info_modifier.bin","wb");
    fflush(stdin);
    Ret4:
    printf("\n\n\n\t\t\t\t\t Saisir Numero de L'Adherent que vous voulez modifier : ");
    while(!(scanf("%d",&Numero_Adherent))){
        fflush(stdin);
        system("cls");
        goto Ret4;
    }
    system("cls");
    fread(&Un_Adherent, sizeof(adherent), 1, fichier);
    while(!feof(fichier)){
        if(Un_Adherent.num_adh == Numero_Adherent){
            flag=1;
            Ret6:
            do{
                style_changement();
                printf("\t\t\t\t\t%s===================================================================================\n",VIO);
                printf("\t\t\t\t\t|\t\t%sLes informations de ADHERENT  N*%-20d%s              |\n",BLE,Un_Adherent.num_adh,VIO);
                printf("\t\t\t\t\t|                                                                                 |\n");
                printf("\t\t\t\t\t|    %s[%s1%s]%s%sNumero de Adherent : %s%-20d%s                                 |\n",BLEM,VIO,BLEM,GRN,MIT,NOI,Un_Adherent.num_adh,VIO);
                printf("\t\t\t\t\t|                                                                                 |\n");
                printf("\t\t\t\t\t|    %s[%s2%s]%s%sLe Nom de L'adherent : %s%-20s%s                               |\n",BLEM,VIO,BLEM,GRN,MIT,NOI,Un_Adherent.nom_adh,VIO);
                printf("\t\t\t\t\t|                                                                                 |\n");
                printf("\t\t\t\t\t|    %s[%s3%s]%s%sLe Prenom de L'adherent : %s%-20s%s                            |\n",BLEM,VIO,BLEM,GRN,MIT,NOI,Un_Adherent.prenom_adh,VIO);
                printf("\t\t\t\t\t|                                                                                 |\n");
                printf("\t\t\t\t\t|    %s[%s4%s]%s%sEmail de L'adherent : %s%-20s%s                                |\n",BLEM,VIO,BLEM,GRN,MIT,NOI,Un_Adherent.email_adh,VIO);
                printf("\t\t\t\t\t|                                                                                 |\n");
                printf("\t\t\t\t\t|    %s[%s5%s]%s%sAdresse : %s%-20s%s                                            |\n",BLEM,VIO,BLEM,GRN,MIT,NOI,Un_Adherent.adress_adh,VIO);
                printf("\t\t\t\t\t|                                                                                 |\n");
                printf("\t\t\t\t\t|    %s[%s-%s]%s%sNombre de L'empruntes : %s%-20d%s                              |\n",BLEM,VIO,BLEM,GRN,MIT,NOI,Un_Adherent.nbre_emprunts_adh,VIO);
                printf("\t\t\t\t\t|                                                                                 |\n");
                printf("\t\t\t\t\t===================================================================================\n");
                printf("\n\t\t\t\t\t\t\t\t Vous voulez modifier qu il champes('6-Quitter' tu doit ecrire que l'entier ) :");
                while (!(scanf("%d",&Choix_champs))){
                    fflush(stdin);
                    system("cls");
                    goto Ret6;
                }
                fflush(stdin);
                switch(Choix_champs){

                    case 1:
                        ret12:printf("\n\n\t\t\t\t\t\tNouveau Code de l'adherent : ");
                        while (!(scanf("%d",&NV_Numero_Adherent))){
                            fflush(stdin);
                            goto ret12;
                        }
                        while(Libre_place_Adherent(NV_Numero_Adherent)==1){
                            fflush(stdin);
                            printf("\n\t\t\t\t%s   ce code deja existe dans notre base de donnees %s\n ",RED,NOI);
                            goto ret12;
                        }
                        Un_Adherent.num_adh=NV_Numero_Adherent;
                        system("cls");
                        break;
                    case 2:
                        printf("\n\n\t\t\t\t\t\tNouveau Nom de l'adherent : ");
                        gets(Un_Adherent.nom_adh);
                        system("cls");
                        break;
                    case 3:
                        printf("\n\n\t\t\t\t\t\tNouveau Prenom de l'adherent : ");
                        gets(Un_Adherent.prenom_adh);
                        system("cls");
                        break;
                    case 4:
                        printf("\n\n\t\t\t\t\t\tNouveau Email de l'adherent : ");
                        gets(Un_Adherent.email_adh);
                        system("cls");
                        break;
                    case 5:
                        printf("\n\n\t\t\t\t\t\tNouveau Adresse de l'adherent : ");
                        gets(Un_Adherent.adress_adh);
                        system("cls");
                        break;
                    default : fflush(stdin);system("cls");break;
                }
            }while(Choix_champs!=6);

        }
        fwrite(&Un_Adherent, sizeof(adherent), 1, fichier1);
        fread(&Un_Adherent, sizeof(adherent), 1, fichier);
    }
    if(flag == 0){
        printf("\n\n\t\t\t\t LE NUMERO QUE VOUS ETES CHOISIS N'EXISTE PAS DANS LA LISTE :( \n\n");
    }
    fclose(fichier);
    fclose(fichier1);
    remove("info_adherent.bin");
    rename("Info_modifier.bin","info_adherent.bin");
    fflush(stdin);
    system("cls");
}
                    ///***********************************************    Modification par Nom :  **********************************************\\\

void Modification_Nom(){
    int choix, flag,ch1,ch, Choix_champs,NV_Numero_Adherent;
    char d[3],repeter[3],c[3],Nom_Adherent[50];
    FILE *fichier1 ;
    flag=0;
    Ret1: fichier = fopen("info_adherent.bin","rb");
    fichier1 = fopen("Info_modifier.bin","wb");
    fflush(stdin);
    Ret4:
    printf("\n\n\n\n\t\t\t\t Saisie le Nom de L'adherent que vous voulez afficher : ");
    scanf("%s",&Nom_Adherent);
    system("cls");
    fread(&Un_Adherent, sizeof(adherent), 1, fichier);
    while(!feof(fichier)){
        if(strcmp(Un_Adherent.nom_adh,Nom_Adherent)==0){
            flag=1;
            Ret6:
            do{
                style_changement();
                printf("\t\t\t\t\t%s===================================================================================\n",VIO);
                printf("\t\t\t\t\t|\t\t%sLes informations de ADHERENT  N*%-20d%s              |\n",BLE,Un_Adherent.num_adh,VIO);
                printf("\t\t\t\t\t|                                                                                 |\n");
                printf("\t\t\t\t\t|    %s[%s1%s]%s%sNumero de Adherent : %s%-20d%s                                 |\n",BLEM,VIO,BLEM,GRN,MIT,NOI,Un_Adherent.num_adh,VIO);
                printf("\t\t\t\t\t|                                                                                 |\n");
                printf("\t\t\t\t\t|    %s[%s2%s]%s%sLe Nom de L'adherent : %s%-20s%s                               |\n",BLEM,VIO,BLEM,GRN,MIT,NOI,Un_Adherent.nom_adh,VIO);
                printf("\t\t\t\t\t|                                                                                 |\n");
                printf("\t\t\t\t\t|    %s[%s3%s]%s%sLe Prenom de L'adherent : %s%-20s%s                            |\n",BLEM,VIO,BLEM,GRN,MIT,NOI,Un_Adherent.prenom_adh,VIO);
                printf("\t\t\t\t\t|                                                                                 |\n");
                printf("\t\t\t\t\t|    %s[%s4%s]%s%sEmail de L'adherent : %s%-20s%s                                |\n",BLEM,VIO,BLEM,GRN,MIT,NOI,Un_Adherent.email_adh,VIO);
                printf("\t\t\t\t\t|                                                                                 |\n");
                printf("\t\t\t\t\t|    %s[%s5%s]%s%sAdresse : %s%-20s%s                                            |\n",BLEM,VIO,BLEM,GRN,MIT,NOI,Un_Adherent.adress_adh,VIO);
                printf("\t\t\t\t\t|                                                                                 |\n");
                printf("\t\t\t\t\t|    %s[%s-%s]%s%sNombre de L'empruntes : %s%-20d%s                              |\n",BLEM,VIO,BLEM,GRN,MIT,NOI,Un_Adherent.nbre_emprunts_adh,VIO);
                printf("\t\t\t\t\t|                                                                                 |\n");
                printf("\t\t\t\t\t===================================================================================\n");
                printf("\n\t\t\t\t\t\t\t\t Vous voulez modifier qu il champes('6-Quitter' tu doit ecrire que l'entier ) :");
                while (!(scanf("%d",&Choix_champs))){
                    fflush(stdin);
                    system("cls");
                    goto Ret6;
                }
                fflush(stdin);
                switch(Choix_champs){

                    case 1:
                        ret12:printf("\n\n\t\t\t\t\t\tNouveau Code de l'adherent : ");
                        while (!(scanf("%d",&NV_Numero_Adherent))){
                            fflush(stdin);
                            goto ret12;
                        }
                        while(Libre_place_Adherent(NV_Numero_Adherent)==1){
                            fflush(stdin);
                            printf("\n\t\t\t\t%s   ce code deja existe dans notre base de donnees %s\n ",RED,NOI);
                            goto ret12;
                        }
                        Un_Adherent.num_adh=NV_Numero_Adherent;
                        system("cls");
                        break;
                    case 2:
                        printf("\n\n\t\t\t\t\t\tNouveau Nom de l'adherent : ");
                        gets(Un_Adherent.nom_adh);
                        system("cls");
                        break;
                    case 3:
                        printf("\n\n\t\t\t\t\t\tNouveau Prenom de l'adherent : ");
                        gets(Un_Adherent.prenom_adh);
                        system("cls");
                        break;
                    case 4:
                        printf("\n\n\t\t\t\t\t\tNouveau Email de l'adherent : ");
                        gets(Un_Adherent.email_adh);
                        system("cls");
                        break;
                    case 5:
                        printf("\n\n\t\t\t\t\t\tNouveau Adresse de l'adherent : ");
                        gets(Un_Adherent.adress_adh);
                        system("cls");
                        break;
                    default : fflush(stdin);system("cls");break;
                }
            }while(Choix_champs!=6);

        }
        fwrite(&Un_Adherent, sizeof(adherent), 1, fichier1);
        fread(&Un_Adherent, sizeof(adherent), 1, fichier);
    }
    if(flag == 0){
        printf("\n\n\t\t\t\t LE NOM QUE VOUS ETES CHOISIS N'EXISTE PAS DANS LA LISTE :( \n\n");
    }
    fclose(fichier);
    fclose(fichier1);
    remove("info_adherent.bin");
    rename("Info_modifier.bin","info_adherent.bin");
    fflush(stdin);
    system("cls");
}


                    ///***********************************************   Procédure  de style :  ***********************************************\\\

void style_ajoute(){
printf("\t\t\t%s                         .///:          ///.                                                              \n",BLEM);
printf("\t\t\t                        :NMMMM-        /MMM-                                   :sh                             \n");
printf("\t\t\t                       /MMNNMMo                                               .MM.                                  \n");
printf("\t\t\t                      oMMN  MMm       -mmm:   -odNNMNmy/      ommm`   ommd  :mNMMMmm.   /ymNMNmy:      ommy-yNMh         \n");
printf("\t\t\t                     sMMN   MMM.      yMMN  `hMMMyo/omMMh`    mMMy   `NMMs   oMMMd    :mMMy   mMMs    NMMNMhsy`               \n");
printf("\t\t\t                   `hMMm    NMMo     `NMMs  dMMN.    .MMMo   /MMM-   oMMM.   /MMM-   -MMMo    :MMM   /MMMh.                        \n");
printf("\t\t\t                  `dMMMdhhhhNMMd     oMMM. -MMMo     -MMMo   dMMh    NMMy    dMMd    sMMMMMMMMMMMN   dMMm`                            \n");
printf("\t\t\t                 .mMMmddddddmMMM.    mMMh  .MMMo    `dMMm`  -MMM:   sMMM-   -MMM/    oMMm           -MMM/                             \n");
printf("\t\t\t                -NMMy       `MMMo   :MMM:   oMMMyoosNMMh.   /MMMy/omMMMh    oMMMyo-  `hMMdo/odMMd`  yMMN                              \n");
printf("\t\t\t               .ddds         ydds   dMMd     .ohmNNmho-      odNNds-ddd:    `ymNNm.    :ydNNmds:    hddo                              \n");
printf("\t\t\t                                   sMMM:                                                                                           \n");
printf("\t\t\t                                  sMMMo                                                                                            %s\n",NOI);
}



void style_menu()
{
printf("\t%s                                                          -yho`     -.                           ``                  `/--/\n",BLEM);
printf("\t%s               odmdmmdhy/`       NMd`     oMM/           yyhMMh         -mMm-                      mN/        MM-         `/hNd/`\n");
printf("\t%s               oMMybbodMMy                oMM/`-::.        :MMh          :-`        .-::-`    .--yMMo----     MM-`-::-       `:-/:.        .:::-.-.  `--.    --.      .:::.\n");
printf("\t%s               oMM     MMh   odmmNNm      oMMymmmNNd-      :MMh      -dmmNNN.     ` dNNmmNNh-  hmmNMMmdmmd`   MMymmmNNd.   .smNdhmNd:   `omNNmmNNN   -NNy   `NNd   `omNdhdNm\n");
printf("\t%s               oMMdsshNMy.      -NMm      oMMm/``:NMm`     :MMh       ```mMM.     sMMy.``:mMN- ```sMM+````    MMm `` MMs  `dMd.```hMN- `dMMo.`` MM  :MMy   `NMm   yMN:```oMM\n");
printf("\t%s               oMMhooshMNy`     .NMm      oMM     hMM:     :MMh          mMM.    `NMN`    oMMo    sMM/        MMo   -MMy   MMNmmmmNMM- :MMh     MM  :MMy   `NMm  -MMNmmmmmMMh\n");
printf("\t%s               oMM     dMM      .NMm      oMM/   `dMM-     :MMh          mMM.    `NMN`    sMMo    sMM         MMo   -MMy   MMy         /MMh     MM  :MMy   .NMm  -MMm\n");
printf("\t%s               oMMs:::oNMN-  ...:NMN...`  oMMo..:yMMy   .../MMd...`  `...mMM:..`  sMMh:.--NMd.    oMMy-..-    MMo   -MMy  .mMNo        `mMN/.-sNMM  .NMm-./dMMm   hMMs\n");
printf("\t%s                NNmmmmdho.   hddmNNmddd/   mNNNNNmh/`  `dddmNNmddd-  odddmNNmddo  ` hmNNNNdo`     `smNNNmm`   NN/   -mNs   .sdNNNNmmy   -ymNNmhsMM    dNNmdoyNd   `dmNNNmmd`\n");
printf("\t%s               `......``     `.........`  ``.....``     ..........   `.........`    `.....`         `.....   `..`    ..`     `......`     ....`/MM    `.-.` `.`     `......`\n");
printf("\t%s                                                                                                                                                MM\n");
printf("\t%s                                                                                                                                               -oo-%s\n",NOI);
}

void style_supprime_poubelle()
{
printf("\t\t\t\t\t%s                      `os/-.:::::::::::::::///:::////////////::::    \n",GRN);
printf("\t\t\t\t\t                    `:ossooyyyyyyyyyyyyyyyyyyyyyyyyyyhhhhhhyysssy/    \n");
printf("\t\t\t\t\t                   -oyhydyoshyyyyyyyyyyyyhyyysssyyssyhhdddddhho-.`    \n");
printf("\t\t\t\t\t                 `/ohmdmNd..sssssssssssssyssssssssssyyyyyyyyh-        \n");
printf("\t\t\t\t\t                .osdmNmmd:  /sssssssssyyyyyyyyyyyhyyyyyyyyyhh.        \n");
printf("\t\t\t\t\t               -osdmhdyp-`  :sssssssyysssyyssssyyyyyyyyyyyyhh`        \n");
printf("\t\t\t\t\t             `/sydmhhhyso/::/ssssssyyssssssssyyyyyyyyyyyyyyhy         \n");
printf("\t\t\t\t\t            `osymdddhyssssssyssssssyysssssyyyyyyyyyyyyyyyyyhs         \n");
printf("\t\t\t\t\t           .oshmdddhyssssssyhssssssysssssyyyyyyyyyyyyyyyyyyho         \n");
printf("\t\t\t\t\t          :sydmmddyyssssssyyossssssssssyyyyyyyyyyyyyyyyyyyyho         \n");
printf("\t\t\t\t\t        `/sydmmdhyyssssssso- ossssssysyyyyyyyyyyyyyyyyyyyyyho         \n");
printf("\t\t\t\t\t       `oshmmmdhyysssssss-`  osssssyyyyyyyyyyyyyyyyyyyyyyyhh/         \n");
printf("\t\t\t\t\t      .oyhmmmhyyssssssys.    osssssyyyyyyyyyyyyyyyyyyyyyyyhh:         \n");
printf("\t\t\t\t\t     -sydmmdhyyssssssyy:     /sssssyyyyyyyyyyyyyyyyyyyyyyyhd-         \n");
printf("\t\t\t\t\t    :sydmyyyyysssssyys:      -sssssyyssyyyyyyyyyyyyyyyyyyyhh.         \n");
printf("\t\t\t\t\t   :yo/so.`.:oosssys-.       .sssssyysyyyyyyyyyyyyyyyyyyyyhh.         \n");
printf("\t\t\t\t\t   `.`        `.:o/`         `sssssyyyyyyyyyyyyyyyyyyyyyyyhh.         \n");
printf("\t\t\t\t\t                              ssssyyyyyyyyyyyyyyyyyyyyyyyyhh`         \n");
printf("\t\t\t\t\t                            -osyyyyyyyyyyyyyyyyyyyyyyyyyyhho          \n");
printf("\t\t\t\t\t                           :ydmmmmmdhhhyyyyyyyyyyyyyyyyyyhho          \n");
printf("\t\t\t\t\t                           ydmddhddddddhyyyyyyyyyyyyyyyyyhho          \n");
printf("\t\t\t\t\t                           odmdmmmmdddmdyyyyyysyyyyyyyyyyhh:          \n");
printf("\t\t\t\t\t                           `ohddddhdddmhhyyyyyhhhhhhhhhhhhs.          \n");
printf("\t\t\t\t\t                             -/syyyo/-..-.----------------.%s           \n",NOI);
}

void style_supprime()
{
printf("\n\n");
printf("\t\t%s                                                                                           `...`                      \n",BLEM);
printf("\t\t                                                                                           yNNN/                            \n");
printf("\t\t                                                                                          `hhhh`                                  \n");
printf("\t\t          .-::::-.       ----     ----`   `---. .::::.      `---. .::::.      `---` .:::` .---`   .--- `-:::-`  `.:::-`       `.::::-`  \n");
printf("\t\t       `/dmNMMMMNNd/    :NNNd    .NNNm`   oNNNhhNNMMNmy.    oNNNhdNNMMNmy.    yNNN/ymMMd``mNNN.  `mNNNodNMMMNd:odNMMMNd-    -sdNNMMMNmy-      \n");
printf("\t\t       sMMMo    dmmd-   hMMM     sMMMo   `NMMMmo:-:yMMMm`  `NMMMmo:-:yMMMd   .NMMMNmyos. /MMMh   /MMMMh/-:dMMMNd.--hMMMy   oNMMd/--/mMMN.           \n");
printf("\t\t       hMMMho/         .MMMN`   `NMMN.   /MMMm.     dMMM:  /MMMm.     dMMM-  oMMMNo`     dMMM/   dMMMs`   dMMMy`   hMMM.  .MMMh.    :MMMo              \n");
printf("\t\t       .ymNMMMMmds-    sMMMo    oMMMy    dMMM       dMMM:  dMMMo      dMMM-  mMMMo      -MMMm   -MMMN`   -MMMN`   .MMMN`  NMMMNmmmmmmMMMs              \n");
printf("\t\t       ```-/ohmMMMN-  `NMMN.   .NMMM-   -MMMM:     :MMMm` -MMMM-     :MMMm` :MMMd       yMMMo   sMMMo    sMMMs    sMMMs   MMMN                  \n");
printf("\t\t     shd/    `-NMMM:  /MMMm`  `mMMMh    sMMMMh.``./NMMN:  sMMMMh.``./NMMN-  hMMMo      `NMMM.  `NMMM.   `NMMM.   `NMMM.   yMMM.`  `/hso-               \n");
printf("\t\t     -dNMMmhhdNMMm.   -NMMMdhdmNMMM:   `NMMMdMNddmMMNy.  `NMMMdMNddmMMNy.  .MMMN`      .MMMy   .MMMh    .MMMh    /MMMh    `sNMMmhhmMMNs.               \n");
printf("\t\t       -oshhdhys/.     -shdhs:`osss    .MMMh`:shdhyp-    oMMMh`:shdhyo-    :sss.       .sss-   .sss-    .sss-    .sss-      ./shdhhs/.                 \n");
printf("\t\t                                       dMMM:             mMMM:                                                                                         \n");
printf("\t\t                                      -MMMm             :MMMm                                                                                          %s\n",NOI);
printf("\t\t                                      :sss:             :sss:  \n");
}



void style_recherche_loupe()
{
printf("\n%s",NOI);
printf("\t\t\t\t\t\t\t\t                             `.:/ooooo/:.         \n");
printf("\t\t\t\t\t\t\t\t                          :oyhhyyyyyyyhhddyo.     \n");
printf("\t\t\t\t\t\t\t\t                        /hhyo-.`       ``-/sdy:   \n");
printf("\t\t\t\t\t\t\t\t                      `sy/.                 .oys. \n");
printf("\t\t\t\t\t\t\t\t                      oo`                     -ss`\n");
printf("\t\t\t\t\t\t\t\t                     `o                        `//\n");
printf("\t\t\t\t\t\t\t\t                      o                         -/\n");
printf("\t\t\t\t\t\t\t\t                      o/                        o`\n");
printf("\t\t\t\t\t\t\t\t                      oyo.                    .o- \n");
printf("\t\t\t\t\t\t\t\t                  ``-osmhms:`              `:oo:  \n");
printf("\t\t\t\t\t\t\t\t               ./osymhooosdhhyo/:--...-:/osyso-   \n");
printf("\t\t\t\t\t\t\t\t           `-/sssyyyo`    `:oyhhhhhhhhhyyyo/.     \n");
printf("\t\t\t\t\t\t\t\t        .:ossyyyyo:`          `.-:/_/::-`         \n");
printf("\t\t\t\t\t\t\t\t     ./ossyyyso:`                                 \n");
printf("\t\t\t\t\t\t\t\t `-osssyyyso-                                     \n");
printf("\t\t\t\t\t\t\t\t`hysysyso-                                        \n");
printf("\t\t\t\t\t\t\t\t -hyo/.                                           \n");
}

void style_recherche()
{
printf("\t\t\t\t%s                                     .mm                                        .mm                   \n",BLEM);
printf("\t\t\t\t    sNNNNNNNmy.                      oNN.                                       /No                  \n");
printf("\t\t\t\t  `NM     :MMh   `-::.      `-:-`    mMd -:-`      -::.     `.. .:.    `-::.    oMM..::`     .-:-`      \n");
printf("\t\t\t\t  oMM    :sMMo -hMdyhMm-  omMdhNMy` :MMmhymMN.  .yNmyhMm:   hMmdmm-:  hMmhmMm-  NMNdyhMM.  oNNyyNMs     \n");
printf("\t\t\t\t  mMNmmMMMho- .NMy___hMh yMN-  .o/` hMN-  oMM. `NMd___yMm  .MMd.    :MMo   .o- /MM.  .MM. yMN:___MM-    \n");
printf("\t\t\t\t :MM    dMd`  oMMysssss. MMs       .MMo   NMy  :MMysssss.  sMN`     yMN        dMd   sMN` NMdsssss.    \n");
printf("\t\t\t\t hMN`   `mMd` `mMy     ` hMmo/hMm- sMN`  /MM-  `dMh        NMs      /MMo/sMM. -MM/  `NMs  oMh          \n");
printf("\t\t\t\t oo/     -oo:   :oyyo:!   :oyyo:   oo/   /oo     :oyyo/`  .oo.       .osys/`  :oo   -oo.   .osyso/`      %s\n",NOI);
}


void style_modification(){

printf("\t\t\t\t\t\t%s          ..-.`                                              .--:::-.`\n",BLEM);
printf("\t\t\t\t\t\t      -sssssssss-                                        .:ossssssso:`\n");
printf("\t\t\t\t\t\t    .ossssssssssss:`                                  .ssssssssso:`\n");
printf("\t\t\t\t\t\t   `ssssssssssssssss:`                               /sssssssso:`\n");
printf("\t\t\t\t\t\t   :ssssssssssssssssss:`                            /ssssssss:`       \n");
printf("\t\t\t\t\t\t   -ssssssssssssssssssss:`                         .ssssssso`             .so\n");
printf("\t\t\t\t\t\t    osssssssssssssssssssss:`                       /sssssss-            .ssss`\n");
printf("\t\t\t\t\t\t     :ssssssssssssssssssssss:`                     /sssssss:          .ssssss`\n");
printf("\t\t\t\t\t\t      `/ssssssssssssssssssssss:`                   -ssssssss:`      .ssssssso\n");
printf("\t\t\t\t\t\t        `/sssssssssssssssssssss                  `/ssssssssssss/://ossssssss.\n");
printf("\t\t\t\t\t\t          `/sssssssssssssssssss               `/ssssssssssssssssssssssssso.\n");
printf("\t\t\t\t\t\t            `/sssssssssssssssss  `          `/ssssssssssssssssssssssssss:`\n");
printf("\t\t\t\t\t\t              `/ssssssssssssssss             `ossssssssssssssssssssssso/-\n");
printf("\t\t\t\t\t\t                  `/osssssssssssssss        -sssssssssso:\n");
printf("\t\t\t\t\t\t                         `/sssssssssssss/`  .ossssssso:\n");
printf("\t\t\t\t\t\t                           :ssssssssss/`   -ssssssso:\n");
printf("\t\t\t\t\t\t                             sssssss/`  .-  `:ssso:\n");
printf("\t\t\t\t\t\t                            /sssss/`   :sso-  `::\n");
printf("\t\t\t\t\t\t                            `/oo/`  .`  .osso-\n");
printf("\t\t\t\t\t\t                         `:.      -oss/`  .osso-\n");
printf("\t\t\t\t\t\t                       `/sssos//ssssssss/`  .osso-\n");
printf("\t\t\t\t\t\t            `.----../sssssssssssssssso:         .osso-\n");
printf("\t\t\t\t\t\t        `:osssssssssssssssssssssssso:             .osso-\n");
printf("\t\t\t\t\t\t      .ossssssssssssssssssssssssso:                 .osso-\n");
printf("\t\t\t\t\t\t     /ssssssssssssssssssssssssso:                     .osso-\n");
printf("\t\t\t\t\t\t    osssssssso///sssssssssssso:                         .osso-\n");
printf("\t\t\t\t\t\t   :sssssss:`      -ossssssso                             .osso/oooss-\n");
printf("\t\t\t\t\t\t   osssss:`         `ssssssss                               :sssssssss/\n");
printf("\t\t\t\t\t\t   osss:`            ssssssss                               :sssssssssso`\n");
printf("\t\t\t\t\t\t   :s:`             :ssssssso                               ossssssssssso.\n");
printf("\t\t\t\t\t\t    `             .ossssssss`                               :ossssssssssss:\n");
printf("\t\t\t\t\t\t               .sossssssso.                                  `-osssssssssso`\n");
printf("\t\t\t\t\t\t            .osssssssss:                                       `-osssssso-\n");
printf("\t\t\t\t\t\t           .osssssssso-`                                            -/so-\n");
}
void style_changement(){
printf("\t\t\t%s                                                              -` \n",MAR);
printf("\t\t\t                                                             os/.\n");
printf("\t\t\t                                                            `osss/.\n");
printf("\t\t\t                                                            `osssss/.\n");
printf("\t\t\t                                                            `ooooooos/.\n");
printf("\t\t\t                                               `.............oooooooooo/.\n");
printf("\t\t\t                                          .-/oooooo//////////ooooooooooos/.\n");
printf("\t\t\t                                       `-oooooo////:::::::::////ooooooooosso.                 ./.\n");
printf("\t\t\t                                      -oooooo/////ooooooooooooooooooooooooosss-`               `/ys:`\n");
printf("\t\t\t                                     /ooooo/oossssssssssssssssssssssssssssso/.`                `osys:\n");
printf("\t\t\t                                    :oooooosssssssssssssssssssssssssssssso/.`                   :soyyo`\n");
printf("\t\t\t                                   .ooooossssssoo////////////sssssssssso/.` `/                  .oooyyo`\n");
printf("\t\t\t                                   :oooosssyo/-``           `ossssssso/.` `oss.`                .o/ohhh:`\n");
printf("\t\t\t                                   /ooosssyo-`              `oossooo/.` `ossss-`                :/:/hhhs.\n");
printf("\t\t\t                                   :ssossso-`               `ooooo/.` .ossssss-`               .:-:ohhhy-\n");
printf("\t\t\t                                   .ssssss/.                `ooo/.` .ossssssss-`             `-:-:/hhhhs-\n");
printf("\t\t\t                                    :sssss/`                 :-.` .osssssssooo/:------....-----::oyhhyho.\n");
printf("\t\t\t                                    `:sssoo.                    `ossssssssooooooo///:::----:::/osyyyyhs:`\n");
printf("\t\t\t                                     `-oyoo-`                 `ossssssssoooooooo////////////oosyyyyyhs:.\n");
printf("\t\t\t                                       `:oso.                `osssooooooooooooooooooosssssyyyyyyyyyyo:`\n");
printf("\t\t\t                                         `.::`                ./sssssssssssssyyyyyyyyyyyyyyyyyyssso/-`\n");
printf("\t\t\t                                                               `./ssssssssssssssssssssssssssssoo/:.`\n");
printf("\t\t\t                                                                 `./sssssssssso/////////////:--.`\n");
printf("\t\t\t                                                                   `./ssssssss:`\n");
printf("\t\t\t                                                                     `./osssso-`\n");
printf("\t\t\t                                                                       `./oooo-`\n");
printf("\t\t\t                                                                         `./oo-`\n");
printf("\t\t\t                                                                            `.:.`\n");
}
