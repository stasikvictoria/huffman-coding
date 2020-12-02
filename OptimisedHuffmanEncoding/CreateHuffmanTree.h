#ifndef HUFFMANCODING_CREATEHUFFMANTREE_H
#define HUFFMANCODING_CREATEHUFFMANTREE_H
#include "../DataTypes/DataTypes.h"

Node* add_by_dichtomie_v2(char* my_fic);

int compare_queue(Queue* q1, Queue* q2);
Node* create_Huff_tree_from_tab(Node* tab, int taille);

#endif //HUFFMANCODING_CREATEHUFFMANTREE_H
