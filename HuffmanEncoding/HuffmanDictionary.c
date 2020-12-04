#include "HuffmanDictionary.h"




//C FONCTION
// check if the letter is already in the list

int check_letter(const Element* list,const char letter){
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

Element* new_letter(const char letter){
    Element* new = malloc(sizeof(Element));
    new->next = NULL;
    new->letter = letter;
    new->occ = 1;
    return new;
}


Element* occurence(const char* text){
    if(strlen(text)>0) {                                // if text no void
        Element* list_occ = new_letter(text[0]);        // we start the list with the first letter
        Element* temp = list_occ;
        for(int i=1; i<=strlen(text)-1;i++){                // browse text
            int here = check_letter(list_occ,text[i]);      // check if the letter is already here
            if(here == -1 ){                                 // no we add
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

void list_remove_element_n(Element_n** l,const Node* n){

    if(l == NULL || (*l) == NULL){return;}

    Element_n* buffer = *l;
    Element_n* temp = NULL;

    while(buffer->next != NULL) //FOR ALL THE LIST
    {
        if(buffer->next->data == n)  //IF VALUE HAVE TO BE REMOVE
        {
            temp = buffer->next->next; //REMOVE IT
            free(buffer->next);
            buffer->next = temp;
        }else{
            buffer = buffer->next;
        }
    }

    if ((*l)->data == n) //IF THE FIRST VALUE HAVE TO BE REMOVE
    {
        buffer = *l; // REMOVE IT
        *l = (*l)->next;
        free(buffer);
    }
}

void list_insert_element_n(Element_n** l,const Node* n,const int pos){

    Element_n* nx_elem = (Element_n*)malloc(sizeof(Element_n));
    nx_elem->data = n;
    nx_elem->next = NULL;

    if((pos <= 1) || (*l == NULL)) {
        nx_elem->next = *l;
        *l = nx_elem;
    }
    else {
        Element_n* temp = *l;
        int size = 2;

        while(temp->next != NULL && size != pos) {
            temp = temp->next;
            size ++;
        }
        nx_elem->next = temp->next ;
        temp->next = nx_elem;
    }

}


/*
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
 */
Node* return_huffman(const Element* l){
    Element_n* list = element_to_element_n(l); // LIST BECOME A LIST WITH NODE

    if (list==NULL){
        return NULL;
    }
    else{ // OTHER CASE
        while (list->next != NULL){ //WHILE ONLY ONE NODE REMAIN IN THE LIST
            Node* huffman = create_node(NULL, NULL); //CREATE THE TREE
            huffman->right=occ_min(list); // TREE FIRST CHILD
            list_remove_element_n(&list, huffman->right); //REMOVE THE ELEMENT ALREADY IN THE TREE
            huffman->left=occ_min(list); //TREE SECOND CHILD
            list_remove_element_n(&list, huffman->left); //REMOVE THE ELEMENT
            huffman->occ=(huffman->right->occ)+(huffman->left->occ); //HEAD OF TREE TAKE VALUE OF THE SUM OF OCCURENCE OF THE TWO CHILDREN
            list_insert_element_n(&list, huffman, 1); //ADD THE NEW NODE HUFFMAN TO THE LIST
        }
        return (list->data);
    }

}

//E FONCTION
void number_of_leaves(const Node* tree, int* leaves){
    if (tree != NULL){
        if (tree->left == NULL && tree->right == NULL){
            *leaves = 1 + *leaves;
        }
        number_of_leaves(tree->left, leaves);
        number_of_leaves(tree->right, leaves);
    }
}


void dictionary_from_tree(const Node* tree, Dictionary** d, int* code, int* code_index){
    if (tree != NULL){
        if (tree->left == NULL && tree->right == NULL){
            code[*code_index] = 2;
            (*d)->letter = tree->letter;
            int i = 0;

            while (code[i] != 2) {
                (*d)->code[i] = code[i];
                i++;
            }
            (*d)->code[i] = 2;
            (*d) = (*d)->next;
        }
        code[*code_index] = 0;
        *code_index = *code_index + 1;
        dictionary_from_tree(tree->left, d, code, code_index);
        *code_index = *code_index - 1;
        code[*code_index] = 1;
        *code_index = *code_index + 1;
        dictionary_from_tree(tree->right, d, code, code_index);
        *code_index = *code_index - 1;
    }
}


void write_dictionary_in_txt(Dictionary* d,const char* input){
    int i;
    FILE* file = NULL;
    file = fopen(input, "w+");
    if (file != NULL)
    {
        while (d->next != NULL){
            fprintf(file, "%c:", d->letter);
            i = 0;
            while (d->code[i] == 1 || d->code[i] == 0){
                fprintf (file,"%d", d->code[i]);
                i++;
            }
            fprintf(file,"\n");
            d = d->next;
        }
        fclose(file);
    }
}








