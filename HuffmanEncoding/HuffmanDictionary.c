#include "HuffmanDictionary.h"
#include "../DataTypes/DataTypes.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


//C FONCTION
// check if the letter is already in the list

int check_letter(Element* list, char letter){
    int here = -1,compt = 0;            // if here return the position, else -1
    if(list!=NULL){
        Element* temp = list;
        while(temp!=NULL){
            if(temp->letter == letter)
                here = compt;
            temp = temp->next;
            compt++;
        }
    }
    return here;
}

Element* new_letter(char letter){
    Element* new = malloc(sizeof(Element));
    new->next = NULL;
    new->letter = letter;
    new->occ = 1;
    return new;
}


Element* occurence(char text[80]){     //????????????????????????????????????????????
    if(strlen(text)>0) {                                // if text no void
        Element* list_occ = new_letter(text[0]);        // we start the list with the first letter
        Element* temp = list_occ;
        for(int i=1; i<=strlen(text)-1;i++){                // browse text
            int here = check_letter(list_occ,text[i]);      // check if the letter is already here
            if(here == -1){                                 // no we add
                temp->next = new_letter(text[i]);
                temp = temp->next;
            }
            else{                                           // if we increase the occ
                Element* temp = list_occ;
                while(temp!=NULL && here>0){
                    temp = temp->next;
                    here--;
                }
                temp->occ ++;
            }
        }
        return list_occ;
    }
    return NULL;
}

//D FONCTION
Node* occ_min(Element_n* l){
    if(l==NULL){
        return NULL;
    }
    else{
        Node* node_min = l->data; // NODE MIN TAKES VALUE OF THE FIRST NODE OF THE LIST
        Element_n* buffer = l->next; //BUFFER ON THE NEXT ELEMENT

        while(buffer != NULL){
            if(buffer->data->occ < node_min->occ){ // COMPARE OCCURENCE NODE MIN / EVERY NODE OF THE LIST
                node_min = buffer->data; // MIN TAKE THE SMALLEST VALUE OF THE LIST
            }
            buffer=buffer->next;
        }
        return node_min;

    }
}

void list_remove_element_n(Element_n** l, Node* n){

    if(l == NULL || (*l) == NULL){return;}

    Element_n* buffer = *l;
    Element_n* temp = NULL;

    while(buffer->next != NULL)
    {
        if(buffer->next->data == n)
        {
            temp = buffer->next->next;
            free(buffer->next);
            buffer->next = temp;
        }else{
            buffer = buffer->next;
        }
    }

    if ((*l)->data == n)
    {
        buffer = *l;
        *l = (*l)->next;
        free(buffer);
    }
}


Node* return_huffman(Element* l){
    Element_n* list = element_to_element_n(l); // LIST BECOME A LIST WITH NODE

    if (list==NULL){
        return NULL;
    }

    else if (list->next ==NULL){ // ONE NODE SO HUFFMAN ONLY ONE CHILD

        Node* huffman = create_node(NULL, list->data->occ);
        huffman->right=occ_min(list);
        return huffman;
    }

    else{ // OTHER CASE
        Node* huffman = create_node(NULL, NULL); //CREATE THE TREE
        huffman->right=occ_min(list); // TREE FIRST CHILD
        list_remove_element_n(&list, huffman->right); //REMOVE THE ELEMENT ALREADY IN THE TREE
        huffman->left=occ_min(list); //TREE SECOND CHILD
        list_remove_element_n(&list, huffman->left); //REMOVE THE ELEMENT
        huffman->occ=(huffman->right->occ)+(huffman->left->occ); //HEAD OF TREE TAKE VALUE OF THE SUM OF OCCURENCE OF THE TWO CHILDREN

        Node* node_r=huffman; //RIGHT CHILD IS THE TREE ALDREADY CREATE
        Node* node_l=NULL;

        while (list != NULL){ // BECAUSE VALUES ARE REMOVE EACH TIME
            node_l=occ_min(list); //LEFT CHILD TAKE THE LITELEST VALUE OH THE LIST
            list_remove_element_n(&list, node_l);//REMOVE THE ELEMENT
            Node* base=create_node(NULL,node_l->occ+node_r->occ); //CREATION HEAD OF TREE + TAKE VALUE OF THE SUM OF OCCURENCE OF THE TWO CHILDREN
            base->right=node_r;  // MOVE FOR THE NEXT NODE OF THE LIST
            base->left=node_l;
            node_r=base;
            huffman=base;
        }
        return huffman;
    }

}

//E FONCTION
void dictionary_from_tree(Node* tree, Dictionary** d, int* code, int* code_index){
    if (tree != NULL){

        //VERIFY IF IT'S A LEAF
        //IF THAT'S A LEAF WE ENTER THE DATA TO THE DICTIONARY STRUCTURE
        if (tree->left == NULL && tree->right == NULL){
            (*d)->letter = tree->letter;
            for (int i = 0 ; i<*code_index ; i++){ //or code_index - 1 ???
                (*d)->code[i] = code[i];
            }
            Dictionary* temp = (*d);
            (*d) = (*d)->next;
            (*d)->previous = temp;
        }

        //WE RUN THROUGH THE HUFFMAN TREE TO SEARCH THE LEAVES
        //WHILE RUNING WE REGISTER THE CODE IN A TAB
        code[*code_index] = 0;
        code_index = code_index + 1;
        dictionary_from_tree(tree->left, d, code, code_index);
        code_index = code_index - 1;
        code[*code_index] = 1;
        code_index = code_index + 1;
        dictionary_from_tree(tree->right, d, code, code_index);
    }
}

void write_dictionary_in_txt(Node* tree){

    //FIRST WE CREATE THE DICTIONARY FROM THE HUFFMAN TREE
    Dictionary* d = create_dictionary();
    int code[8];
    int code_index = 0;
    dictionary_from_tree(tree, &d, code, &code_index);
    while (d->previous != NULL){
        d = d->previous;
    }

    //THEN WE WRITE THE DICTIONARY IN THE TXT FILE
    FILE* file = NULL;
    file = fopen("dictionary.txt", "w");
    if (file != NULL)
    {
        while (d != NULL){
            fprintf(file, " %c : ", d->letter);
            for (int i=0 ; i<sizeof(d->code) ; i++){
                fprintf(file,"%d", d->code[i]);
            }
            fprintf(file,"\n");
            d = d->next;
        }
        fclose(file);
    }
}



