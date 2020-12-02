#ifndef HUFFMANCODING_ENCODINGFILEOP_H
#define HUFFMANCODING_ENCODINGFILEOP_H
#define MAX_SIZE 1000000

char* find_code(Node_AVL* tree , char c );
void encoding_v2(Node_AVL* tree, char* Huffman, char* input);

void add_element(char* code, Node** Huffman_tree, char letter,int pos);
Node* Huffman_tree_from_dico(char* dico);

#endif //HUFFMANCODING_ENCODINGFILEOP_H
