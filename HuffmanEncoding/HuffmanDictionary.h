#ifndef HUFFMANCODING_HUFFMANDICTIONARY_H
#define HUFFMANCODING_HUFFMANDICTIONARY_H
#include "../DataTypes/DataTypes.h"

//C FONCTION
int check_letter(Element* list, char letter);
Element* new_letter(char letter);
Element* occurence(char text[80]);

//D FONCTION
Node* occ_min(Element_n* l);
void list_remove_element_n(Element_n** l, Node* n);
Node* return_huffman(Element* l);

//E FONCTION
void dictionary_from_tree(Node* tree, Dictionary** d, int* code, int* code_index);
void write_dictionary_in_txt(Node* tree);


#endif //HUFFMANCODING_HUFFMANDICTIONARY_H
