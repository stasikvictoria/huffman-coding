/*****************************************************************//**
 * \file   HuffmanDictionary.h
 * \brief  Header of the library to create the Huffman tree using occurrences and create the Huffman dictionary from the tree.
 * 
 * \author Astryd CASIMIR astryd.casimirgressier@gmail.com
 * \date   December 2020
 *********************************************************************/

#ifndef HUFFMANCODING_HUFFMANDICTIONARY_H
#define HUFFMANCODING_HUFFMANDICTIONARY_H
#include "../DataTypes/DataTypes.h"
#include "InputFile.h"

//C FONCTION
/*
* \brief Function to check if the letter is already in the list.
* \param list, chained list which contains letters and occurrences already found in the text.
* \param letter, the letter we are looking for in the list.
* \return an integer which is the position of the letter if it was found in the list.
* \return \c -1, if the letter is not in the list.
*/
int check_letter(const Element* list,const char letter);

/*
* \brief Function to create a new Element.
* \param letter, the information of the letter to add.
* \return an Element with the information of the letter and the occurrence.
*/
Element* new_letter(const char letter);

/*
* \brief Function to create	a list of Element with all the caracters of the texte and the occurrences.
* \param texte, the texte from which we want to recover the letters and occurrences.
* \return a list of Element, with all the letters and the occurrences of the text.
*/
Element* occurence(const char* text);



//D FONCTION

/**
* \brief Function to find the node with the the smallest occurrence in a list of Element_n.
* \param l the first element of the list to search in. 
* \return the Node's pointer, the node with the smallest occurrence.
* \return \c NULL, if the list of Element_n is empty.
*/
Node* occ_min(Element_n* l);

/**
* \brief Function to delate an element of a list of Element_n.
* \param l a pointer on the first element of the list to delate in.
* \param n a pointer on the node to remove. 
*/
void list_remove_element_n(Element_n** l,const Node* n);

/**
* \brief Function to add an element to a list of Element_n.
* \param l a pointer on the first element of the list which we want to delete inside.
* \param n a the node to insert in the list.
* \param pos the position where the node have to be insert. 
*/
void list_insert_element_n(Element_n** l,const Node* n, const int pos);

/**
* \brief Function to cretate an Huffman tree from e list of Element.
* \param l the first element of the list of Element with all the caracteres of the text and their occuurance. 
* \return the Node's pointer, the first node of the Huffman tree. 
*/
Node* return_huffman(const Element* l);

//E FONCTION
/*
* \brief Function to count the number of leaves in a tree of Node.
* \param pointer to a tree, a tree of Node.
* \param pointer to leaves, the number of leaves in the tree.
*/
void number_of_leaves(const Node* tree, int* leaves);

/*
* \brief Function to find the Huffman code of a letter.
* \param tree, a pointer to the Huffman tree.
* \param d, a pointer to the Dictionary list, who contains the letter and the Huffman code of the letter.
* \param code, a pointer to a table of integer who contains the Huffman code.
* \param code_indexe, a pointer to an integer to keep the indexe of the code letter.
*/
void dictionary_from_tree(const Node* tree, Dictionary** d, int* code, int* code_index);

/*
* \brief Function to write the dictionnay list into a file.
* \param d, the Dictionary list.
* \param input, the file in which we write the Huffman dictionary.
*/
void write_dictionary_in_txt(Dictionary* d,const char* input);


#endif //HUFFMANCODING_HUFFMANDICTIONARY_H
