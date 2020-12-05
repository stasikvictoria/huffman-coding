/*****************************************************************//**
 * \file   Dictionary.h
 * \brief  Header of the library used to manage the dictionary of the optimised version.
 *
 * \author Victoria STASIK stasikvictoria@gmail.com
 * \date   December 2020
 *********************************************************************/
#ifndef HUFFMANCODING_DICTIONARY_H
#define HUFFMANCODING_DICTIONARY_H
#include "../DataTypes/DataTypes.h"
#include "../HuffmanEncoding/EncodingFile.h"

/**
 * \brief Function to add a new node to a binary search tree.
 * \param tree, the tree where we want to add the node.
 * \param letter, the letter of the new node.
 * \param code, array with the code of the letter.
 * \param code_index, index of the code array.
 */
void add_node_BST(Node_AVL** tree,const char letter,const int* code,int code_index);

/**
 * \brief Function to know the depth of the binary search tree.
 * \param tree, the tree that we want to know the depth.
 * \return the depth of the tree.
 */
int depth(const Node_AVL* tree);

/**
 * \brief Function to know the balance factor of a tree.
 * \param tree, the tree that we want to know the balance factor.
 * \return the balance factor of the tree.
 */
int bf(const Node_AVL* tree);

/**
 * \brief Function to make a right rotation with the tree.
 * \param tree, the tree we want to make a right rotation with.
 */
void right_rotation(Node_AVL** tree);

/**
 * \brief Function to make a left rotation with the tree.
 * \param tree, the tree we want to make a left rotation with.
 */
void left_rotation(Node_AVL** tree);

/**
 * \brief Function to balance a tree.
 * \param tree, the tree that we want to balance.
 */
void balance(Node_AVL** tree);

/**
 * \brief Function to add a new node to the AVL tree.
 * \param tree, the tree where we want to add the node.
 * \param letter, the letter of the new node.
 * \param code, array with the code of the letter.
 * \param code_index, index of the code array.
 */
void add_node_AVL(Node_AVL** tree,const char letter, int* code,const int code_index );

/**
 * \brief Function to get the code from a tree.
 * \param tree, the tree that gives the code.
 * \param code, array with the code of the letter.
 * \param code_index, index of the code array.
 * \param AVL, the tree were we put the information about the letters and their codes.
 */
void code_from_tree(const Node* tree, int* code, int* code_index, Node_AVL** AVL);

/**
 * \brief Function to get the dictionary from a tree.
 * \param tree, the tree that gives the dictionary.
 * \return the AVL tree which represent the dictionary.
 */
Node_AVL* AVL_dico(const Node* tree);

/**
 * \brief Function to write the dictionary in a txt file.
 * \param tree, the AVL tree that gives the dictionary.
 * \param file, the txt file where we write the dictionary.
 */
void fill_dico(const Node_AVL* tree,const FILE* file);

/**
 * \brief Function which uses the fill_dico function to write the dictionary in a txt file.
 * \param tree, the AVL tree that gives the dictionary.
 * \param dico, the name of the txt file where we want to write the dictionary.
 */
void write_AVL_in_dico(const Node_AVL* tree,const char* dico);


#endif //HUFFMANCODING_DICTIONARY_H

