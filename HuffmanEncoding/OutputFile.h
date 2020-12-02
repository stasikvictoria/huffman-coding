#ifndef HUFFMANCODING_OUTPUTFILE_H
#define HUFFMANCODING_OUTPUTFILE_H

#include "HuffmanDictionary.h"

void txt_to_text(char* file_name, char* text, int size_text);
void compress_text(char* text, Dictionary* d, char* file_name);
void writting_output_txt(char* input,char* dico,char* output);

#endif //HUFFMANCODING_OUTPUTFILE_H
