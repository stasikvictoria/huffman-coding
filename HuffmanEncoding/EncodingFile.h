/*****************************************************************//**
 * \file   EncodingFile.h
 * \brief  Header of the library allowing the encoding of a text file with the Huffman dictionary.
 * 
 * \author Astryd CASIMIR astryd.casimirgressier@gmail.com
 * \date   December 2020
 *********************************************************************/
#ifndef HUFFMANCODING_ENCODINGFILE_H
#define HUFFMANCODING_ENCODINGFILE_H
#define MAX_SIZE 100
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


//F FONCTION
/**
 * \brief Function to copy a character string.
 * \param the character string to duplicate.
 * \return a pointer on a character chain, it is identical to the input.
 */
char* copy(const char* chaine);

/**
 * \brief Function to find the code of a character from the dictionary file.
 * \param file, the name of the file container the dictionary.
 * \param c, the letter to traduct.
 * \return a pointer on a caracter chain, the traduction of the input caracter.
 */
char* open_file(const char* file ,const char c );

/**
 * \brief Function to encode a text with the huffman dictionary.
 * \param dico, the file containing the huffman dictionary.
 * \param input, the file we want to encode.
 * \param Huffman, the encoded file.
 */
void encoding(const char* dico,const  char* Huffman,const char* input);

#endif //HUFFMANCODING_ENCODINGFILE_H
