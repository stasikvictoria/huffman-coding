/*****************************************************************//**
 * \file   OutputFile.h
 * \brief  Header of the librairy that compresses a text file in an optimized way.
 * 
 * \author Astryd CASIMIR astryd.casimirgressier@gmail.com
 * \date   December 2020
 *********************************************************************/

#ifndef HUFFMANCODING_OUTPUTFILE_H
#define HUFFMANCODING_OUTPUTFILE_H
#include "HuffmanDictionary.h"
#include "InputFile.h"
#include "EncodingFile.h"

/**
 * \brief Function which takes a text file and stores the characters.
 * \param file_name, the name of the file whose characters we want to recover.
 * \param a pointer to a charcater string.
 * \param size_text, the number of character of the file_name.
 */
void txt_to_text(const char* file_name,const char* text,const int size_text);

/**
 * \brief Function that compresses a texte file.
 * \param input, the file that we want to traduct.
 * \param dico, the file who contains the dictionary of Huffman.
 * \param output, the file with the compresses file.
 */
void writting_output_txt(const char* input,const char* dico,const char* output);

/**
  * \brief Function to do the choice in the menu.
  * \param choix, integer of the choise of the user.
  */
void menue(int* choix);

#endif //HUFFMANCODING_OUTPUTFILE_H
