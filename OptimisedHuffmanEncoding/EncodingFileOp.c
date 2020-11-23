#include "EncodingFileOp.h"

//question M and N


// question M

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


// question N

// Recreate the Huffman Tree

// add element in the Huffman Tree

void add_element(char* code, Node** Huffman_tree, char letter,int pos){
    if(*Huffman_tree != NULL){                                              // if the node isn't void
        if(code[pos]=='0'){
            add_element(code,&((*Huffman_tree)->left),letter,pos+1);        // go to left if we are on the 0 in the code
        }
        else if(code[pos]=='1'){
            add_element(code,&((*Huffman_tree)->right),letter,pos+1);       // go to right if we are on the 1 in the code
        }
    }
    else{
        if(strlen(code)!=pos){                                      // if we are not at the end of the code we go ahead
            *Huffman_tree = create_node(NULL,pos);
            if(code[pos]=='0'){
                add_element(code,&((*Huffman_tree)->left),letter,pos+1);
            }
            else if(code[pos]=='1'){
                add_element(code,&((*Huffman_tree)->right),letter,pos+1);
            }
        }
        else {                                           // if we are at the end of the code we create a node at the position
            *Huffman_tree = create_node(letter,code[pos]);
        }
    }
}

// create the huffman tree from the dico file
Node* Huffman_tree_from_dico(char* dico ) {
    Node* Huffman_tree = create_node(NULL,NULL);

    FILE* fich = NULL;
    char chaine[MAX_SIZE] ="";
    char* code = NULL;
    char letter;
    fich = fopen(dico,"r");

    if(fich == NULL)
        printf("\nError to open dico");
    else{
        while(fgets(chaine,MAX_SIZE,fich)!=NULL){
            if(chaine[strlen(chaine)-1]=='\n'){
                chaine[strlen(chaine)-1]='\0';
            }
            code = copy(chaine);            // we save the code
            letter = chaine[0];             // we save the letter
            add_element(code,&Huffman_tree,letter,0);       // we add the letter on the Huffman tree with the help of the code and a position in the code
        }
    }
    fclose(fich);
    return Huffman_tree;
}


// use the huffman tree to decode
