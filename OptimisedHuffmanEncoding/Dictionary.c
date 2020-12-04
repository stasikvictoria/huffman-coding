#include "Dictionary.h"

void add_node_BST(Node_AVL** tree,const char letter,const int* code,int code_index){
    if(*tree == NULL){
        *tree = create_node_avl(letter,code,code_index);
    }
    else{
        if ((int)(*tree)->letter > (int)letter){
            add_node_BST(&((*tree)->left) ,letter, code,code_index);
        }
        else if((int)(*tree)->letter < (int)letter){
            add_node_BST(&((*tree)->right) ,letter,code,code_index);
        }
    }
}

int depth(const Node_AVL* tree){
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


int bf(const Node_AVL* tree){    //balance factor
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



void add_node_AVL(Node_AVL** tree,const char letter, int* code, const int code_index){
    add_node_BST(tree,letter,code,code_index);
    balance(tree) ;
}




void code_from_tree(const Node* tree, int* code, int* code_index, Node_AVL** AVL){
    if (tree != NULL){
        if (tree->left == NULL && tree->right == NULL){
            code[*code_index] = 2;
            add_node_AVL(AVL,tree->letter,code,*code_index);
        }
        code[*code_index] = 0;
        *code_index = *code_index + 1;
        code_from_tree(tree->left, code, code_index,AVL);
        *code_index = *code_index - 1;
        code[*code_index] = 1;
        *code_index = *code_index + 1;
        code_from_tree(tree->right, code, code_index,AVL);
        *code_index = *code_index - 1;
    }
}

Node_AVL* AVL_dico(const Node* tree){
    Node_AVL* new_tree = NULL;

    if (tree!=NULL){
        int* code = calloc(1,100*sizeof(int));
        int code_index = 0;
        code_from_tree(tree,code,&code_index,&new_tree);
    }
    return new_tree;
}

void fill_dico(const Node_AVL* tree,const FILE* file){
    if(tree!=NULL){
        fprintf(file, "%c:", tree->letter);
        int i = 0;
        while (tree->code[i] == 1 || tree->code[i] == 0){
            fprintf (file,"%d", tree->code[i]);
            i++;
        }
        fprintf(file,"\n");
        fill_dico(tree->left, file);
        fill_dico(tree->right,file);
    }
}

void write_AVL_in_dico(const Node_AVL* tree,const char* dico){
    FILE* file = NULL;
    file = fopen(dico, "w+");
    if (file != NULL)
    {
        fill_dico(tree,file);
        fclose(file);
    }
}

