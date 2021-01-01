#include "headers.h"

void Ajouter_adherent(){
    int n,choix,Numero_adherent,Nombre_adherent,i;
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
        printf("\n\t\tEmail de la Adherent : ");
        fflush(stdin);
        gets(Information_adherent[i].email_adh);
        printf("\n\t\tAdresse de la Adherent : ");
        fflush(stdin);
        gets(Information_adherent[i].adress_adh);
        printf("\n\n");
        system("cls");
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
