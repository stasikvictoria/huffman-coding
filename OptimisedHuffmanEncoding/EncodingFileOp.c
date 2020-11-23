#include "EncodingFileOp.h"

//question M and N


// question N 

// Function to find the code in the AVL

char* find_code(Node_AVL* tree , char c ){
    if((int)(tree->letter)==(int)c){
        return tree->code;
    }
    else if((int)(tree->letter) > (int)c){
        return find_code(tree->left, c);
    }
    else {
        return find_code(tree->right, c);
    }
}



void encoding_v2(Node_AVL* tree, char* Huffman, char* input){
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
                char *code = find_code(tree,(char)current_letter);
                fputs(code,fich2);
            }
        }while(current_letter!=EOF);
        fclose(fich2);
    }
    fclose(fich);
}
