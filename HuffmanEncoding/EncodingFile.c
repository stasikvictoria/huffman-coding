#include "EncodingFile.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//F FONCTION
// To copy the code in the file

char* copy(char* chaine){
    char* code = malloc(strlen(chaine)*sizeof(char));
    int i=0,j=2;
    for(j=2;j < strlen(chaine) ; j++){
        code[i] = chaine[j];
        i++;
    }
    return code;
}


// to find the code in the file

char* open_file(char* file , char c ) {
    FILE* fich = NULL;
    char chaine[MAX_SIZE] ="";
    char* result = NULL;
    fich = fopen(file,"r");
    if(fich == NULL)
        printf("\nError to open dico");
    else{
        while(fgets(chaine,MAX_SIZE,fich)!=NULL){
            if( (int)chaine[0] == (int)c ){
                if(chaine[strlen(chaine)-1]=='\n'){
                    chaine[strlen(chaine)-1]='\0';
                }
                result = copy(chaine);
            }
        }
        if(result == NULL)
            printf("We don't find the letter in the dico");
    }
    fclose(fich);
    return result;
}

void encoding(char* dico, char* Huffman, char* input){
    FILE* fich = NULL,*fich2 = NULL;
    fich = fopen(input,"r");
    int current_letter = 0;
    fich2 = fopen(Huffman, "w");
    if (fich2 == NULL) {
        printf("Error to open Huffman");
    }
    if(fich==NULL)
        printf("Error to open input");
    else{
        do{
            current_letter = fgetc(fich);
            if(current_letter >=0) {
                char *code = open_file(dico, (char) current_letter);
                fputs(code,fich2);
            }
        }while(current_letter!=EOF);
        fclose(fich2);
    }
    fclose(fich);
}
