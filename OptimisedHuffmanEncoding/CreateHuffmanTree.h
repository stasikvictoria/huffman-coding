#ifndef HUFFMANCODING_CREATEHUFFMANTREE_H
#define HUFFMANCODING_CREATEHUFFMANTREE_H
#include "../DataTypes/DataTypes.h"

Node* add_by_dichtomie_v2(const char* my_fic,int* len);

/**
 * \brief Function to exchange two nodes.
 * \param a, the first node.
 * \param b, the second node.
 */
void swap(Node** a, Node** b);

/**
 * \brief Function which sorts the array of nodes.
 * \param first, index of the first node.
 * \param last, index of the last node.
 */
void quick_sorting (Node* tab, int first, int last);

int compare_queue(const Queue* q1,const Queue* q2);
Node* create_Huff_tree_from_tab(const Node* tab,const int taille);

#endif //HUFFMANCODING_CREATEHUFFMANTREE_H
