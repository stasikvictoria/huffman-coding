#include "InputFile.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//A FONCTION 
void binary_translation(char* input,char* output){
    //Open the file to read the file
    FILE* fic_input = fopen(input, "r");
    if (fic_input == NULL){
        printf("\nOPENING ERROR : FILE INPUT \n");
        exit(EXIT_FAILURE);
    }
    //Create the new file if it is not already create
    FILE *fic_output = fopen(output, "w+");
    if (fic_output == NULL){
        printf("\nOPENNIG ERROR : FILE OUTPUT \n");
        exit(EXIT_FAILURE);
    }
    //Read the file that we want to traduct
    int my_char = 0;
    do {
        //Read the character
        my_char = fgetc(fic_input);
        //Display the character
        //printf(" %c", my_char);
        //Traduct in binary MY_CHAR
        int tab[8] = {0,0,0,0,0,0,0,0};
        int i=0;
        int bin = my_char;
        for (i=0; bin>0 ; i++){
            tab[i] = bin%2;
            bin = bin/2;
        }
        //Display the character in binary
        /*
        for (i=i; i>=0; i--){
            printf("%d", tab[i]);
        }
        */
        //Get in the character in binary into the output file
        for (i=i; i>=0; i--){
            fprintf(fic_output, "%d", tab[i]);
        }
    }while (my_char != EOF); //EOF = End Of File
    printf("End of translation ! \n Your new file is output.txt \n");
    //Don't forget to close the file !
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
