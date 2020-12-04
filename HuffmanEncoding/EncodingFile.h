#ifndef HUFFMANCODING_ENCODINGFILE_H
#define HUFFMANCODING_ENCODINGFILE_H
#define MAX_SIZE 100
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


//F FONCTION
char* copy(const char* chaine);
char* open_file(const char* file ,const char c );
void encoding(const char* dico,const  char* Huffman,const char* input);

#endif //HUFFMANCODING_ENCODINGFILE_H
