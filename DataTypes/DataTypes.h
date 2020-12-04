/*****************************************************************//**
 * \file   DataTypes.h
 * \brief  Header of the library allowing the managment onf all the structures
 * 
 * \author Amélie SENAUX am.senaux@gmail.com
 * \date   December 2020
 *********************************************************************/
#ifndef HUFFMANCODING_DATATYPES_H
#define HUFFMANCODING_DATATYPES_H
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

/**  
 * \typedef struct Element
 * \brief the element list with an int the occurence, a char the letter and pointer next. 
 */
typedef struct Element{
    int occ;
    char letter;
    struct Element* next;
}Element;

/**
 * \typedef struct Node
 * \brief the node of the Huffman tree with a char the letter, an int the occurence, and two pointers : left and right.
 */
typedef struct Node{
    char letter;
    int occ;
    struct Node* left;
    struct Node* right;
}Node;

/**
 * \typedef struct Element_n
 * \brief the element list of node with a Node as data and a pointer next.
 */
typedef struct Element_n{
    Node* data;
    struct Element_n * next;
}Element_n;

/**
 * \typedef struct Dictionary
 * \brief the element list of dictionary with a char the letter, an int the tab of code, and a pointer next.
 */
typedef struct Dictionary{
    char letter;
    int code[100];
    struct Dictionary* next;
}Dictionary;

/**
 * \typedef struct Queue
 * \brief the structure of the queue with a pointer first.
 */
typedef struct Queue{
    Element_n* first;
} Queue;

/**
 * \typedef struct Node_AVL
 * \brief the node of a AVL tree with a char the letter, a tab of char the code, and two pointers : left and right.
 */
typedef struct Node_AVL{
    char letter;
    int code[100];
    struct Node_AVl* left;
    struct Node_AVL* right;
}Node_AVL;


///***********************Node*****************************

/**
* \brief Function to print one node Node.
* \param n a Node to print. 
*/
void print_node(const Node*n);

/**
* \brief Function to print an entire tree, all the different node of the tree.
* \param tree the first node of the tree that need to be printed.
*/
void print_tree(const Node*tree);

/**
 * \brief Function to create a Node filled with the letter and the occurrence. 
 * \param c the letter.
 * \param oc the occurrence.
 * \return the Node's pointer. 
 */
Node* create_node(const char c,const int oc);

/**
 * \brief Function to free an entire tree composed by Node. 
 * \param tree the first node of the tree to free.
 */
void free_tree(Node* tree);

/**
 * \brief Function to print a tab of Node.
 * \param tab the tab of node to print.
 * \param n the tab size.
 */
void print_Tab_of_DoubleNode(const Node* tab,const int n);

///***********************Element******************

/**
 * \brief Function to create an Element with the letter and the occurrence.
 * \param c the letter.
 * \param oc the occurrence.
 * \return the Element's pointer.
 */
Element* create_element(const char c, const int oc);

/**
* \brief Function to print an entire list, all the Element of the list.
* \param list the first element of the list that need to be printed.
*/
void print_list(const Element* list);

/**
* \brief Function to print an entire list, all the Element of the list : with different display.
* \param l the first element of the list that need to be printed.
*/
void print_list2(const Element* l);

/**
 * \brief Function to free an entire list composed by Element.
 * \param l the first element of the list to free.
 */
void free_list(Element* l);

///***********************Element_n******************

/**
 * \brief Function to create an Element_n with the letter and the occurrence to put in the Node.
 * \param c the letter.
 * \param oc the occurrence.
 * \return the Element_n's pointer.
 */
Element_n* create_element_n(const char c,const int oc);

/**
 * \brief Function to transform a list of Element to a list of Element_n.
 * \param l the first element of the list composed by Element
 * \return tne Element_n's pointer, the new list with node as data. 
 */
Element_n* element_to_element_n(Element* l);

/**
* \brief Function to print an entire list, all the Element_n with node inside  of the list.
* \param list the first element of the list that need to be printed.
*/
void print_list_n(const Element_n* l);

/**
 * \brief Function to free an entire list composed by Element_n.
 * \param l the first element of the list to free.
 */
void free_list_n(Element_n* l);

///**********************Queue*********************

/**
 * \brief Function to create an empty queue.
 * \return the Queue's pointer.
 */
Queue* create_queue();

/**
 * \brief Function to add a new node a the end of a list (queue).
 * \param q the queue on which add the new node.
 * \param val the new node to enqueue.
 */
void enqueue(Queue* q, Node* val);

/**
 * \brief Function to delate the first node of the list (queue) and return it. 
 * \param q the queue on which delate the new node a return it.
 * \return the Node's pointer, the node which is dequeue. 
 */
Node* dequeue(Queue* q);

///*******************Dictionary******************************

/**
 * \brief Function to create an element dictionary.
 * \return the element Dictionary's pointer.
 */
Dictionary* create_dictionary_element( void);

/**
 * \brief Function to create a list composed by elements dictionary.
 * \param size the tumer of element in the list. 
 * \return the element Dictionary's pointer, the first of the list whith have been created.
 */
Dictionary* create_dictionary(int size);

/**
* \brief Function to print an entire list, all the element dictionary with a letter and the corresponding code inside of the list.
* \param d the first element of the list dictionary that need to be printed.
*/
void print_dictionary(const Dictionary* d);

/**
 * \brief Function to free an entire list composed by element Dictonary.
 * \param d the first element dictionary of the list to free.
 */
void free_dictionary(Dictionary* d);

///*******************Node_AVL******************************

/**
 * \brief Function to create a Node filled with the letter and the occurrence.
 * \param letter the letter.
 * \param code the tab of int with the binary code reduced.
 * \param code_index the index of the tab.
 * \return the Node_AVL's pointer.
 */
Node_AVL* create_node_avl(const char letter,const int* code, int code_index);

/**
 * \brief Function to print an entire AVL tree composed by Node_AVL.
 * \param tree the first node of the AVL tree to print.
 */
void print_tree_AVL(const Node_AVL*tree);

/**
 * \brief Function to free an entire AVL tree composed by Node_AVL.
 * \param tree the first node of the AVL tree to free.
 */
void free_tree_AVL(const Node_AVL* tree);




#endif //HUFFMANCODING_DATATYPES_H
