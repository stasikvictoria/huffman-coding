#ifndef HUFFMANCODING_HUFFMANDICTIONARY_H
#define HUFFMANCODING_HUFFMANDICTIONARY_H
#include "../DataTypes/DataTypes.h"

//C FONCTION
int check_letter(Element* list, char letter);
Element* new_letter(char letter);
Element* occurence(char* input);

//D FONCTION
Node* occ_min(Element_n* l);
void list_remove_element_n(Element_n** l, Node* n);
void list_insert_element_n(Element_n** l, Node* n, int pos);
Node* return_huffman(Element* l);

//E FONCTION
void number_of_leaves(Node* tree, int* leaves);
void dictionary_from_tree(Node* tree, Dictionary** d, int* code, int* code_index);
void write_dictionary_in_txt(Dictionary* d);


#endif //HUFFMANCODING_HUFFMANDICTIONARY_H
