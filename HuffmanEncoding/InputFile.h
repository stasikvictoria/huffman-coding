/*****************************************************************//**
 * \file   InputFile.h
 * \brief  Header of the library used to manage the "Input" file.
 * 
 * \author Astryd CASIMIR astryd.casimirgressier@gmail.com
 * \date   December 2020
 *********************************************************************/

#ifndef HUFFMANCODING_INPUTFILE_H
#define HUFFMANCODING_INPUTFILE_H
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * \brief Function to traduct in binary a file.
 * \param input the name of the file to translate into binary.
 * \param output the name of the file with the traduction of input.
 */
void binary_translation(const char* input,const char* output);

/**
 * \brief Function to know the number of characters in a text file.
 * \param nomFichier the name of the file in which we want to know the number of letters.
 * \return the number of caracters in the texte file.
 */
int nb_caracteres_fichier(const char* nomFichier);

#endif //HUFFMANCODING_INPUTFILE_H
