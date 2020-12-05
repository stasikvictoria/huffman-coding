/*****************************************************************//**
 * \file   CreateHuffmanTree.h
 * \brief  Header to create the Huffman tree optimised.
 * 
 * \author Astryd CASIMIR astryd.casimirgressier@gmail.com
 * \date   December 2020
 *********************************************************************/
#ifndef HUFFMANCODING_CREATEHUFFMANTREE_H
#define HUFFMANCODING_CREATEHUFFMANTREE_H
#include "../DataTypes/DataTypes.h"

/*
* \brief Function to add by dictothomie the caracters and the occurrences in a table of Node.
* \param pointer on my_fic, the file that we want to traduct, and with the caracters to add in the table.
* \param pointer on len, a integer, the len of the file.
* \return a pointer on a table of Node, who contains  caracters and occurences.
*/
Node* add_by_dichtomie_v2(const char* my_fic,int* len);

void swap(Node** a, Node** b);
void quick_sorting (Node* tab, int first, int last);

int compare_queue(const Queue* q1,const Queue* q2);
Node* create_Huff_tree_from_tab(const Node* tab,const int taille);

#endif //HUFFMANCODING_CREATEHUFFMANTREE_H
