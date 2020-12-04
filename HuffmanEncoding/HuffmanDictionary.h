#ifndef HUFFMANCODING_HUFFMANDICTIONARY_H
#define HUFFMANCODING_HUFFMANDICTIONARY_H
#include "../DataTypes/DataTypes.h"
#include "InputFile.h"

//C FONCTION
int check_letter(const Element* list,const char letter);
Element* new_letter(const char letter);
Element* occurence(const char* text);



//D FONCTION
Node* occ_min(Element_n* l);
void list_remove_element_n(Element_n** l,const Node* n);
void list_insert_element_n(Element_n** l,const Node* n, const int pos);
Node* return_huffman(const Element* l);

//E FONCTION
void number_of_leaves(const Node* tree, int* leaves);
void dictionary_from_tree(const Node* tree, Dictionary** d, int* code, int* code_index);
void write_dictionary_in_txt(Dictionary* d,const char* input);


#endif //HUFFMANCODING_HUFFMANDICTIONARY_H
