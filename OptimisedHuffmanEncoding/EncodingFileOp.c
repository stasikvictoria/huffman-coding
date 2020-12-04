#include "EncodingFileOp.h"

//question M and N


// question M


char* copy2(const char* chaine){
    char* code = calloc(1,strlen(chaine)*sizeof(char));
    int i=0,j;
    for(j=1;j < strlen(chaine) ; j++){
        code[i] = chaine[j];
        i++;
    }
    return code;
}

// Function to find the code in the AVL

char* find_code(const Node_AVL* tree ,const char c ){
    if((int)(tree->letter)==(int)c){
        char* final = calloc(1,100*sizeof(char));
        int i = 0;
        while(tree->code[i]!=2){
            if(tree->code[i] ==1)
                final[i] = '1';
            else
                final[i] = '0';
            i++;
        }
        return final ;
    }
    else if((int)(tree->letter) > (int)c){
        return find_code(tree->left, c);
    }
    else {
        return find_code(tree->right, c);
    }
}


void encoding_v2(const Node_AVL* tree,const char* Huffman,const char* input){
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

void add_element(char* code, Node** Huffman_tree,const char letter, int pos){
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
Node* Huffman_tree_from_dico(const char* dico ) {
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
            if(chaine[0]!= '\n'){
                if(chaine[strlen(chaine)-1]=='\n'){
                    chaine[strlen(chaine)-1]='\0';
                }
                code = copy(chaine);            // we save the code
                letter = chaine[0];             // we save the letter
                add_element(code,&Huffman_tree,letter,0);  // we add the letter on the Huffman tree with the help of the code and a position in the code
            }

            else{   // pour le cas ou on a retour à la ligne
                fgets(chaine,MAX_SIZE,fich);
                if(chaine[strlen(chaine)-1]=='\n'){
                    chaine[strlen(chaine)-1]='\0';
                }
                code = copy2(chaine);
                add_element(code,&Huffman_tree,'\n',0);
            }

        }
    }
    fclose(fich);
    return Huffman_tree;
}

void optimised_decoding(const char* Huffman,const char* dico,const char* decoding){
    //Open the Huffman file
    FILE* fic = fopen(Huffman, "r");
    if (fic== NULL){
        printf("\nOPENING FAIL \n");
        exit(EXIT_FAILURE);
    }

    // Create or erase the decoding file to write the text inside
    FILE* dec = fopen(decoding, "w+");
    if (dec== NULL){
        printf("\nOPENING FAIL \n");
        exit(EXIT_FAILURE);
    }

    // my_char to travel the file
    int my_char = fgetc(fic);
    Node* t = Huffman_tree_from_dico(dico);
    //3print_tree(t);
    Node* temp = create_node(NULL, 0);
    temp = t;
    while (my_char!=EOF ){
        if(my_char==48 && temp->left!=NULL){
            temp = temp->left;
        }
        else if(my_char==49 && temp->right!=NULL){
            temp = temp->right;
        }
        if (temp->letter != NULL){
            fprintf(dec, "%c", temp->letter);
            temp = t;
        }
        my_char = fgetc(fic);
    }
    free_tree(t);
    fclose(dec);
    fclose(fic);
}

// use the huffman tree to decode
