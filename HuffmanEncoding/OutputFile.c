#include "OutputFile.h"
#include "InputFile.h"
#include "HuffmanDictionary.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void txt_to_text(char* file_name, char* text, int size_text){
    FILE* file = NULL;
    file = fopen(file_name, "r");
    char* chain = malloc(size_text * sizeof(char));
    int i = 0;
    if (file != NULL) {
        //WE READ THE FILE UNTIL WE REACH THE END
        while (fgets(chain, size_text, file) != NULL){
            //WE COPY THE CHAINS INTO THE TEXT VARIABLE
            strcat(text, chain);

        }
        fclose(file);
        free (chain);
    }
}


void compress_text(char* text, Dictionary* d, char* file_name) {
    Dictionary *temp = d;
    int i, j;
    FILE *file = NULL;
    file = fopen(file_name, "w");
    if (file != NULL) {
        while (text[i] != '\0') {
            temp = d;
            while (text[i] != temp->letter) {
                temp = temp->next;
            }
            j = 0;
            while (temp->code[j] != 2) {
                if (temp->code[j] == 1) {
                    fputc('1', file);
                } else if (temp->code[j] == 0) {
                    fputc('0', file);
                }
                j++;
            }
            i++;
        }
        fclose(file);
    }
}

void writting_output_txt(char* input, char* output){
    //CONVERTING THE TXT FILE TO A CHAR*
    int n = nb_caracteres_fichier(input);
    char *text = malloc(n * sizeof(char));
    txt_to_text(input, text, n);
    printf("INPUT : %s\n\n", text);

    //CREATION OF THE OCCURENCE LIST
    Element *e = occurence(text);
    printf("Occurences :");
    print_list(e);
    printf("\n\n");

    //CREATION OF THE HUFFMAN TREE
    Node *tree = return_huffman(e);
    printf("Tree :\n");
    print_tree(tree);
    printf("\n\n");

    //CREATION OF THE DICTIONARY
    int code[8];
    int code_index = 0;
    int leaves = 0;
    number_of_leaves(tree, &leaves);
    Dictionary *d = create_dictionary(leaves);
    Dictionary *temp = d;
    dictionary_from_tree(tree, &temp, code, &code_index);
    print_dictionary(d);
    write_dictionary_in_txt(d);

    compress_text(text, d, output);
    int n2 = nb_caracteres_fichier(output);
    char *new_text = malloc(n2 * sizeof(char));
    txt_to_text(output, new_text, n2);
    printf("\nOUTPUT : %s\n\n", new_text);

    free(new_text);
    free_dictionary(d);
    free(text);
    free_list(e);
    free_tree(tree);
}

