#ifndef HUFFMANCODING_DATATYPES_H
#define HUFFMANCODING_DATATYPES_H
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

typedef struct Element{
    int occ;
    char letter;
    struct Element* next;
}Element;

typedef struct Node{
    char letter;
    int occ;
    struct Node* left;
    struct Node* right;
}Node;

typedef struct Element_n{
    Node* data;
    struct Element_n * next;
}Element_n;

typedef struct Dictionary{
    char letter;
    int code[100];
    struct Dictionary* next;
}Dictionary;

typedef struct Queue{
    Element_n* first;
} Queue;


typedef struct Node_AVL{
    char letter;
    char* code;
    struct Node_AVl* left;
    struct Node_AVL* right;
}Node_AVL;


///***********************Node*****************************
void print_node(const Node*n);
void print_tree(const Node*tree);
Node* create_node(const char c,const int oc);
void free_tree(const Node* tree);
void print_Tab_of_DoubleNode(const Node* tab,const int n);

///***********************Element******************

Element* create_element(const char c, const int oc);
void print_list(const Element* list);
void print_list2(const Element* l);
Element* create_list(const char c, const int n);
void free_list(Element* l);

///***********************Element_n******************

Element_n* create_element_n(const char c,const int oc);
Element_n* element_to_element_n(Element* l);
void print_list_n(const Element_n* l);
Element_n* create_list_n(char c, int n);
void free_list_n(Element_n* l);

///**********************Queue*********************
Queue* create_queue();
void enqueue(Queue* q, Node* val);
Node* dequeue(Queue* q);

///*******************Dictionary******************************
Dictionary* create_dictionary_element( void);
Dictionary* create_dictionary(int size);
void print_dictionary(const Dictionary* d);
void free_dictionary(Dictionary* d);

///*******************Node_AVL******************************

void print_tree_AVL(const Node_AVL*tree);
#endif //HUFFMANCODING_DATATYPES_H
