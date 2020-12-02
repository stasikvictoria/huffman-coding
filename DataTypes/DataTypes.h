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
    int code[8];
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
void print_node(Node*n);
void print_tree(Node*tree);
Node* create_node(char c, int oc);
void free_tree(Node* tree);

///***********************Element******************

Element* create_element(char c, int oc);
void print_list(Element* list);
void print_list2(Element* l);
Element* create_list(char c, int n);
void free_list(Element* l);

///***********************Element_n******************

Element_n* create_element_n(char c, int oc);
Element_n* element_to_element_n(Element* l);
void print_list_n(Element_n* l);
Element_n* create_list_n(char c, int n);
void free_list_n(Element_n* l);

///**********************Queue*********************
Queue* create_queue();
void enqueue(Queue* q, Node* val);
Node* dequeue(Queue* q);

///*******************Dictionary******************************
Dictionary* create_dictionary_element(void);
Dictionary* create_dictionary(int size);
void print_dictionary(Dictionary* d);
void free_dictionary(Dictionary* d);
#endif //HUFFMANCODING_DATATYPES_H
