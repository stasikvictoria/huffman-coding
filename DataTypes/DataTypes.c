#include "DataTypes.h"

///***********************Node*****************************
void print_node(const Node*n)
{
    if (n==NULL){
        printf("NULL ");
    }
    else{
        printf("%c|%d ", n->letter, n->occ);
    }
}

void print_tree(const Node*tree)
{
    if(tree != NULL)
    {
        if(tree->letter==NULL){
            printf("(%d) ", tree->occ);
        }
        else{
            printf("(%c|%d) ", tree->letter, tree->occ);
        }
        print_tree(tree->left);
        print_tree(tree->right);
    }

}

Node* create_node(const char c,const int oc)
{
    Node* new_tree = (Node*)malloc (sizeof(Node));
    new_tree->letter = c;
    new_tree->occ = oc;
    new_tree-> left = NULL;
    new_tree-> right = NULL;
    return new_tree;

}

void free_tree(Node* tree){
    if(tree != NULL)
    {
        free_tree(tree->left);
        free_tree(tree->right);
        free(tree);
    }
}

void print_Tab_of_DoubleNode(const Node* tab,const int n){
    int indexe = 0;
    for (indexe = 0; indexe<n ; indexe++){
        printf("\n%c : %d", tab[indexe].letter, tab[indexe].occ);
    }
}

///***********************Element******************

Element* create_element(const char c,const int oc){
    Element* new_e = malloc(sizeof(Element));
    new_e->letter = c;
    new_e->occ = oc;
    new_e->next = NULL;
    return new_e;
}

void print_list(const Element* list){
    if(list!=0){
        Element* temp = list;
        while(temp!=NULL){
            printf("\nletter : %c ",temp->letter);
            printf("occurence : %d",temp->occ);
            temp = temp->next;
        }
    }
}

void print_list2(const Element* l){
    Element* buffer = NULL;
    buffer = l;

    while(buffer != NULL)
    {
        printf("%c|%d -> ", buffer->letter, buffer->occ);
        buffer = buffer->next;
    }
    printf("NULL\n");
}

void free_list(Element* l)
{
    if(l != NULL) {
        free_list(l->next);
        free(l);
    }
}

///***********************Element_n******************

Element_n* create_element_n(const char c,const int oc){
    Element_n* new_e = (Element_n*)malloc(sizeof(Element_n));
    new_e->data = create_node(c,oc);
    new_e->next = NULL;
    return new_e;
}

void print_list_n(const Element_n* l){
    Element_n* buffer = l;

    while(buffer != NULL)
    {
        print_node(buffer->data);
        buffer = buffer->next;
    }
    printf("NULL\n");
}

Element_n* element_to_element_n(Element* l){

    if (l==NULL){
        return NULL;
    }
    else {
        Element_n* list_node = create_element_n(l->letter,l->occ); //CREATE FIRST ELEMENT_N (WITH A NODE) I)  WITH THE FIRST VALUE OF l

        Element* buffer1 =l->next; // FIRST ELEMENT ALREADY IN THE NEW LIST
        Element_n* buffer2 =list_node;

        while(buffer1 != NULL){ //WHILE l ISN'T EMPTY
            buffer2->next = create_element_n(buffer1->letter,buffer1->occ); //CREATE A NEW ELEMENT_N WITH VALUES OF l
            buffer1=buffer1->next; //MOVE BUFFEERS
            buffer2=buffer2->next;

        }
        return list_node;
    }

}

void free_list_n(Element_n* l)
{
    if(l != NULL) {
        free_list_n(l->next);
        free(l);
    }
}
///******************Queue*****************

Queue* create_queue(){
    Queue* q =malloc(sizeof(Queue*));
    q->first=NULL;
    return q;
}

void enqueue(Queue* q, Node* val){
    Element_n* nouveau = malloc(sizeof(Element_n*));
    if (q != NULL && nouveau != NULL){
        nouveau->data = val;
        nouveau->next = NULL;
        if(q->first != NULL){
            Element_n* tmp =q->first;
            while(tmp->next != NULL){
                tmp=tmp->next;
            }
            tmp->next = nouveau;
        }
        else{
            q->first = nouveau;
        }
    }
}

Node* dequeue(Queue* q){
    if ( q->first == NULL){
        return -1;
    }
    else{
        Node* val=NULL;
        Element_n* supp = q->first;
        val= supp->data;
        q->first = supp->next;
        free(supp);
        return val;
    }
}
///***********************Dictionary*****************************

Dictionary* create_dictionary_element(void){
    Dictionary* d = (Dictionary*) malloc(sizeof(Dictionary));
    d->letter = 'a';
    for (int i = 1; i<8 ; i++){
        d->code[i] = 0;
    }
    d->code[8] = 2;
    d->next = NULL;
    return d;
}


Dictionary* create_dictionary(int size){
    if (size<0){
        return NULL;
    }
    Dictionary* d = create_dictionary_element();
    d->next = create_dictionary(size - 1);
    return d;
}


void print_dictionary(const Dictionary* d){
    int i;
    if (d != NULL) {
        printf("\nDictionary : \n");
        while (d->next != NULL) {
            printf("%c : ", d->letter);
            i = 0;
            while (d->code[i] == 1 || d->code[i] == 0){
                printf ("%d", d->code[i]);
                i++;
            }
            printf("\n");
            d = d->next;
        }
    }
}

void free_dictionary(Dictionary* d){
    if(d != NULL) {
        free_dictionary(d->next);
        free(d);
    }
}

///***********************Node_AVL*****************************


Node_AVL* create_node_avl(const char letter,const int* code, int code_index)
{
    Node_AVL* new_node = (Node_AVL*)malloc(sizeof(Node_AVL));
    new_node -> letter = letter ;
    int i = 0;
    while (code[i] != 2) {
        new_node->code[i] = code[i];
        i++;
        code_index--;
    }
    new_node->code[i] = 2;
    new_node -> left = NULL ;
    new_node -> right = NULL ;
    return new_node ;
}

void print_tree_AVL(const Node_AVL*tree)
{
    if(tree != NULL)
    {
        printf("\n");
        printf("(%c| ", tree->letter);
        int i = 0;
        while (tree->code[i] == 1 || tree->code[i] == 0){
            printf ("%d", tree->code[i]);
            i++;
        }
        printf(")");

        print_tree_AVL(tree->left);
        print_tree_AVL(tree->right);
    }

}

void free_tree_AVL(const Node_AVL* tree)
{
    if(tree != NULL)
    {
        free_tree_AVL(tree->left);
        free_tree_AVL(tree->right);
        free(tree);
    }
}



