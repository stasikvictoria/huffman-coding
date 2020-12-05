#ifndef HUFFMANCODING_ENCODINGFILEOP_H
#define HUFFMANCODING_ENCODINGFILEOP_H
#include "../HuffmanEncoding/EncodingFile.h"

char* copy2(const char* chaine);

char* find_code(const Node_AVL* tree ,const  char c );
void encoding_v2(const Node_AVL* tree,const char* Huffman,const char* input);

void add_element(char* code, Node** Huffman_tree,const char letter, int pos);
Node* Huffman_tree_from_dico(const char* dico);
void optimised_decoding(const char* Huffman,const char* dico, const char* decoding);

#endif //HUFFMANCODING_ENCODINGFILEOP_H
