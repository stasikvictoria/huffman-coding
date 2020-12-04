#ifndef HUFFMANCODING_CREATEHUFFMANTREE_H
#define HUFFMANCODING_CREATEHUFFMANTREE_H
#include "../DataTypes/DataTypes.h"

Node* add_by_dichtomie_v2(const char* my_fic,int* len);

void swap(Node** a, Node** b);
void quick_sorting (Node* tab, int first, int last);

int compare_queue(const Queue* q1,const Queue* q2);
Node* create_Huff_tree_from_tab(const Node* tab,const int taille);

#endif //HUFFMANCODING_CREATEHUFFMANTREE_H
