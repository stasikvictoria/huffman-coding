#ifndef HUFFMANCODING_ENCODINGFILEOP_H
#define HUFFMANCODING_ENCODINGFILEOP_H

#include "../DataTypes/DataTypes.h"
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


void add_element(char* code, Node** Huffman_tree,const char letter, int pos);

Node* Huffman_tree_from_dico(const char* dico);
void optimised_decoding(const char* Huffman,const char* dico, const char* decoding);

#endif //HUFFMANCODING_ENCODINGFILEOP_H
