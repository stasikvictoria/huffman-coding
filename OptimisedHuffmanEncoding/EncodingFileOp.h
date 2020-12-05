/*****************************************************************//**
 * \file   EncodingFileOp.h
 * \brief  Headers of the librairy used to encode a file in an optimized way.
 * 
 * \author Astryd CASIMIR astryd.casimirgressier@gmail.com
 * \date   December 2020
 *********************************************************************/
#ifndef HUFFMANCODING_ENCODINGFILEOP_H
#define HUFFMANCODING_ENCODINGFILEOP_H
#include "../HuffmanEncoding/EncodingFile.h"

/**
 * \brief Function to copy the text of a txt file into a char variable.
 * \param chaine, name of the txt file.
 */
char* copy2(const char* chaine);

/**
 * \brief Function to find the code of a letter in the AVL.
 * \param tree, AVL tree.
 * \param c, the letter.
 */
char* find_code(const Node_AVL* tree ,const  char c );

/**
 * \brief Function to compress a txt file.
 * \param tree, AVL tree.
 * \param Huffman, Huffman.txt file.
 * \param input, Input.txt file.
 */
void encoding_v2(const Node_AVL* tree,const char* Huffman,const char* input);

/*
* \brief Function to add element in the Huffman tree.
* \param pointer to a char, the code of a caracter.
* \param pointer to Node, the Huffman_tree.
* \param letter, the caracter, the information.
* \param pos, the position in the Huffman tree.
*/
void add_element(char* code, Node** Huffman_tree,const char letter, int pos);

/*
* \brief Function to recreate the Huffman tree with the dico.
* \param a pointer to the name of the file of the dico.
* \return a pointer to a Node, the Huffman tree.
*/
Node* Huffman_tree_from_dico(const char* dico);

/* 
* \brief Function to decode a file in a way optimised.
* \param pointer to char, the name of the file of the Huffman file, with the encode text.
* \param pointer to char, the name of the file of the Huffman dico.
* \param pointer to char, decoding,  the name of the output file with the decoding text.
*/
void optimised_decoding(const char* Huffman,const char* dico, const char* decoding);

#endif //HUFFMANCODING_ENCODINGFILEOP_H
