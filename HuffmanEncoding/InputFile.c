#include "InputFile.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//A FONCTION
void binary_translation(char* input,char* output){
    FILE* fic_input = fopen(input, "r");
    if (fic_input == NULL){
        //fprintf(stderr, "ERREUR OUVERTURE FICHIER \n");

        printf("\nEREEUR OUVERTURE FICHIER \n");
        exit(EXIT_FAILURE);
    }
    //printf("\n \nOUVERT input !");

    // CREER LE NOUVEAU FICHIER SI IL N'EST PAS DEJA CREER POUR METTRE LE TEXTE BINAIRE

    FILE *fic_output = fopen(output, "w+");
    if (fic_output == NULL){
        printf("\nERREUR OUVERTURE FICHIER OUTPUT \n");
        exit(EXIT_FAILURE);
    }
    //printf("\nOUVERT output ! \n");

    //LIRE LE FICHIER A TRADUIRE

    int my_char = 0;
    do {
        // LIRE LES CARACTERES

        my_char = fgetc(fic_input);
        // AFFICHER LES CARACTERES
        //printf(" %c", my_char);

        // TRADUIRE EN BINAIRE MY_CHAR

        int tab[8] = {0,0,0,0,0,0,0,0};
        int i=0;
        int bin = my_char;
        for (i=0; bin>0 ; i++){
            tab[i] = bin%2;
            bin = bin/2;
        }
        // AFICHER LE CARACTERE EN BINAIRE
        /*
        for (i=i; i>=0; i--){
            printf("%d", tab[i]);
        }
        */

        // ENTRER LE CARACTERE BINAIRE DANS LE FICHIER
        for (i=i; i>=0; i--){
            fprintf(fic_output, "%d", tab[i]);
        }
    }while (my_char != EOF); //EOF = End Of File
    printf("End of translation ! \n Your new file is output.txt \n");

    // PENSER A FERMER LES FICHIERS
    fclose(fic_input);
    fclose(fic_output);
}

//B FONCTION
int nb_caracteres_fichier(char* nomFichier)
{
    FILE* fichier ;
    fichier = fopen(nomFichier, "r" );    //ouvrir le fichier en lecture seule

    if (fichier==NULL)
    {
        printf("Nombre de caracteres = 0");
        exit(EXIT_FAILURE);
        return 0 ;
    }
    else
    {
        int compteur = 0 ;
        char char_actuel ;
        do
        {
            char_actuel = fgetc(fichier) ;
            //printf("%c \n",char_actuel);
            compteur ++ ;
        }while (char_actuel!=EOF);
        fclose(fichier) ;
        compteur --;
        printf("\n\nNombre de caracteres = %d", compteur);
        return compteur ;
    }
}
