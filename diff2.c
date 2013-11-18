#include <stdio.h>
#include <stdlib.h>
int main(int argc,char* argv[]){
    int y = 1;
    int erreurLigne = 1;
    char ligne_lue[512];
    char ligne_lue2[512];
    char* nom_fic = argv[y];
    char* nom_fic2 = argv[y+1];
    FILE *fic,*fic2;
    // Ouverture du fichier
    fic = fopen(nom_fic, "r"); // ouvrir en lecture
    fic2 = fopen(nom_fic2, "r");
    printf("File name : %s \n",nom_fic);
    printf("File 2 name : %s \n",nom_fic2);
    // Compte et Affiche le Nombre de Lignes
    int nb_lignes_file1 = 0;
    int nb_lignes_file2 = 0;
    int i=0;
    int countFile1 = 0;
    int countFile2 = 0;
    while(fgets(ligne_lue, 512, fic) != NULL){
        countFile1++;
    }
    //Reinitialize pointer on file 1
    fseek(fic, 0L, SEEK_SET);
    //printf("Compteur du fichier 1 = %d \n",countFile1);
    while(fgets(ligne_lue2, 512, fic2) != NULL){
        countFile2++;
    }
    //printf("File 1 - Line N°%d \n Content : %s\n",nb_lignes_file1,ligne_lue);
    fseek(fic2, 0L, SEEK_SET);
    char* R1 =fgets(ligne_lue, 512, fic);
    char* R2 =fgets(ligne_lue2, 512, fic2);
    //printf("Compteur du fichier 2 = %d \n",countFile2);
        while( R1!= NULL && R2 != NULL){
            printf("Line N°%d \n Content : %s\n",nb_lignes_file1,ligne_lue);
            printf("Line N°%d \n Content : %s\n",nb_lignes_file2,ligne_lue2);
            i = 0;
            while(ligne_lue2[i] != '\0' || ligne_lue[i] != '\0'){
                if(ligne_lue[i] == '\0' ){
                    ligne_lue[i] = '\0';
                }
                if(ligne_lue2[i] == '\0' ){
                    ligne_lue2[i] = '\0';
                }
                if(ligne_lue[i] != ligne_lue2[i]){
                    erreurLigne = 0;
                    printf("File 1 --> '%c' | ",ligne_lue[i]);
                    printf("File 2 --> '%c' ->  PAS OK \n",ligne_lue2[i]);
                    }else{
                        printf("File 1 --> %c | ",ligne_lue[i]);
                        printf("File 2 --> %c -> OK \n",ligne_lue2[i]);
                    }
                    i++;
            }
                nb_lignes_file1++;
                nb_lignes_file2++;
                R1 =fgets(ligne_lue, 512, fic);
                R2 =fgets(ligne_lue2, 512, fic2);
        }
    if(R1 == NULL && R2 != NULL){
        do{
        //printf("File 2 - Line N°%d \n Content : %s\n",nb_lignes_file2,ligne_lue2);
        R2 =fgets(ligne_lue2, 512, fic2);
        }while(R2 != NULL);
    }else{
        do{
        //printf("File 1 - Line N°%d \n Content : %s\n",nb_lignes_file1,ligne_lue);
        R1 =fgets(ligne_lue, 512, fic);
        }while(R1 != NULL);
    }
    if(erreurLigne == 0){
        printf("Files differ ! \n");
    }else{
        printf("File Equals ! \n");
    }
}