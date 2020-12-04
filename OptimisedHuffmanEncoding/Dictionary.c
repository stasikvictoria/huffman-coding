#include "Dictionary.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h> 

//typedef Node* Tree;

typedef Node_AVL* Tree; 


Node_AVL* create_node_avl(char letter, char* code)
{
  Node_AVL* new_node = (Node_AVL*)malloc(sizeof(Node_AVL)); 
  new_node -> letter = letter ; 
  new_node -> code = code ; 
  new_node -> left = NULL ; 
  new_node -> right = NULL ; 
  return new_node ; 
}


/*
Node* create_tree_n(int n){
    if(n <= 0){
        return NULL;
    }
    else{
        Node* new_node = create_node(n);   
        new_node->left = create_tree_n((n-1)/2 + (n-1)%2);  
        new_node->right = create_tree_n((n-1)/2); 
        return new_node;
    }
}

*/

int depth(Node_AVL* tree){
    if(tree == NULL){
        return 0;
    }
    else{
        int depth_left = depth(tree->left);
        int depth_right = depth(tree->right);
        if(depth_left > depth_right){
            return 1 + depth_left;
        }
        else{
            return 1 + depth_right;
        }
    }
}


int bf(Node_AVL* tree){    //balance factor 
    if(tree == NULL) {
        return 0;
    }
    else{
        return depth(tree->right) - depth(tree->left);
    }
}

void right_rotation(Node_AVL** tree){
    if (*tree != NULL){
        Node_AVL* temp = (*tree)->left;
        (*tree)->left = temp->right;
        temp->right = *tree;
        *tree = temp;
    }
}

void left_rotation(Node_AVL** tree){
    if (*tree != NULL){
        Node_AVL* temp = (*tree)->right;
        (*tree)->right = temp->left;
        temp->left = *tree;
        *tree = temp;
    }
}


void balance(Node_AVL** tree){
    if (*tree != NULL){
        balance(&((*tree)->left));  // Postfix
        balance(&((*tree)->right));
        
        int balance_factor = bf(*tree);
        if (balance_factor <= -2){// Cas Gauche - ??
            if(bf((*tree)->left) > 0){// Gauche - Droite
                left_rotation(&((*tree)->left));
            }
            right_rotation(tree);// Gauche - Gauche
        }
        else if (balance_factor >= 2){ // Cas Droite - ??
            if(bf((*tree)->right) < 0){// Droite - Gauche
                right_rotation(&((*tree)->right));
            }
            left_rotation(tree);// Droite - Droite
        }
    }
}



void add_node_AVL(Node_AVL** tree, char letter, char* code )
{ 
  if(*tree == NULL)
  {
        *tree = create_node_avl(letter,code); 
  }
  else
  {

    int pos=0 ; 
    int len_code = strlen(code) ;
    printf("Ajout %c. ", letter) ; 
    printf("longueur %d \n", len_code); 

    pos = len_code -1 ; 
     
    if (code[pos] == '0' )
    { 
      add_node_AVL(&((*tree)->left) , letter, code );     
    }
    else if(code[pos] == '1' )
    { 
      add_node_AVL(&((*tree)->right) , letter, code );     
    }
       
  }

  balance(tree) ; 

}



void print_tree_AVL(Node_AVL* tree)
{
    if(tree != NULL)
    {
        printf("(%c|%s) ", tree->letter, tree->code);
        print_tree_AVL(tree->left);
        print_tree_AVL(tree->right);

    }
}


char* copy(char* chaine){
    char* code = malloc(strlen(chaine)*sizeof(char));
    int i=0,j=2;
    for(j=2;j < strlen(chaine) ; j++){
        code[i] = chaine[j];
        i++;
    }
    return code;
}



#define MAX_SIZE 100 

Node_AVL* AVL_from_dico(char* dico ){
    Node_AVL* tree = NULL ; 

    FILE* fich = NULL ; 
    char chaine[MAX_SIZE] = "" ; 
    char* code = NULL ; 
    char letter ; 
    fich = fopen(dico,"r"); 

    if(fich == NULL){
      printf("ERROR TO OPEN DICO\n "); 
    }
    else 
    {
      int counter = 1 ; 
      while(fgets(chaine,MAX_SIZE,fich)!=NULL)
      {
          printf(" COUNTER : %d \n", counter); 
           
          if(chaine[strlen(chaine)-1]=='\n'){
              chaine[strlen(chaine)-1]='\0';
          }
          code = copy(chaine) ; 
          
          letter = chaine[0] ; 
          add_node_AVL(&tree, letter , code );

          counter ++;
      }
    }

    fclose (fich); 

    printf("\n");
    printf("prof : %d\n", depth(tree));
    

    print_tree_AVL(tree) ; 

    return tree ;
} 






int main (void){
  AVL_from_dico("dico.txt") ; 
  return 0 ; 
}

