#ifndef HUFFMANCODING_OUTPUTFILE_H
#define HUFFMANCODING_OUTPUTFILE_H
#include "HuffmanDictionary.h"
#include "InputFile.h"
#include "EncodingFile.h"

void txt_to_text(const char* file_name,const char* text,const int size_text);
void writting_output_txt(const char* input,const char* dico,const char* output);

#endif //HUFFMANCODING_OUTPUTFILE_H
