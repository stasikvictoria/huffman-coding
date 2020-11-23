#include "DataTypes/DataTypes.h"
#include "HuffmanEncoding/EncodingFile.h"
#include "HuffmanEncoding/HuffmanDictionary.h"
#include "HuffmanEncoding/InputFile.h"
#include "HuffmanEncoding/OutputFile.h"
#include "stdlib.h"
#include <string.h>
#include <stdio.h>


int main(){
    char chaine[81]; // 80 caractères + '\0' terminal
    printf("Enter a text : ");
    fgets(chaine, 81, stdin);
    chaine[strlen(chaine)-1]='\0';
    printf("%s",chaine);

    // POUR WINDOWS
    /*
    char* dico = "dico.txt";
    char* Huffman = "Huffman.txt";
    char* input = "input.txt";
    char* output = "output.txt";
    */
    // POUR MAC

    char* dico ="../dico.txt";
    char* Huffman="../Huffman.txt";
    char* input = "../input.txt";
    char* output = "../output.txt";


    binary_translation(input,output);

    //int size = nb_caracteres_fichier(input);
    // size n'est pas utilisé par la suite

    Element* list = occurence(chaine);
    print_list(list);
    printf("\n\n");

    Node* n =return_huffman(list);
    printf("Arbre de Huffman correspondant : \n");
    print_tree(n);

    //TEST OF THE DICTIONARY
    int code[8];
    int code_index = 0;
    int leaves = 0;
    number_of_leaves(n, &leaves);
    Dictionary* d = create_dictionary(leaves);
    Dictionary* temp = d;
    dictionary_from_tree(n, &temp, code, &code_index);
    print_dictionary(d);
    write_dictionary_in_txt(d);


    encoding(dico,Huffman,input);
    free_dictionary(d);
    free_list(list);
    free_tree(n);


    return 0;
}

