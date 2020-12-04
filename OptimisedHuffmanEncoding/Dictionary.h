
#ifndef HUFFMANCODING_DICTIONARY_H
#define HUFFMANCODING_DICTIONARY_H
#include "../DataTypes/DataTypes.h"
#include "../HuffmanEncoding/EncodingFile.h"

void add_node_BST(Node_AVL** tree,const char letter,const int* code,int code_index);
int depth(const Node_AVL* tree);
int bf(const Node_AVL* tree);
void right_rotation(Node_AVL** tree);
void left_rotation(Node_AVL** tree);
void balance(Node_AVL** tree);
void add_node_AVL(Node_AVL** tree,const char letter, int* code,const int code_index );

void code_from_tree(const Node* tree, int* code, int* code_index, Node_AVL** AVL);
Node_AVL* AVL_dico(const Node* tree);

void fill_dico(const Node_AVL* tree,const FILE* file);
void write_AVL_in_dico(const Node_AVL* tree,const char* dico);


#endif //HUFFMANCODING_DICTIONARY_H
