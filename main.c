#include "OptimisedHuffmanEncoding/EncodingFileOp.h"
#include "HuffmanEncoding/OutputFile.h"
#include "time.h"


int main(){

    clock_t t1,t2;

    char* dico ="../dico.txt";
    char* Huffman="../Huffman.txt";
    char* input = "../input.txt";
    char* output = "../output.txt";
    char* decoding = "../decoding.txt";

    //TESTS
    /*
    char chaine[81]; // 80 caractères + '\0' terminal
    printf("Enter a text : ");
    fgets(chaine, 81, stdin);
    chaine[strlen(chaine)-1]='\0';
    printf("%s",chaine);

    binary_translation(input,output);


    Element* list = occurence(input);
    print_list(list);
    printf("\n\n");

    Node* n =return_huffman(list);
    printf("Arbre de Huffman correspondant : \n");
    print_tree(n);

    int code[8];
    int code_index = 0;
    int leaves = 0;
    number_of_leaves(n, &leaves);
    Dictionary* d = create_dictionary(leaves);
    Dictionary* temp = d;
    dictionary_from_tree(n, &temp, code, &code_index);
    print_dictionary(d);
    write_dictionary_in_txt(d,dico);

    encoding(dico,Huffman,input);
    free_dictionary(d);
    free_list(list);
    free_tree(n);
    */

    printf("\n\n---Output--- ");
    binary_translation(input,output);
    nb_caracteres_fichier(output);
    t1 = clock();
    printf("\n\n---Input  and   Huffman--- ");
    writting_output_txt(input,dico,Huffman);
    printf("\n\n---Decoding--- ");
    optimised_decoding(Huffman,dico,decoding);
    int n2 = nb_caracteres_fichier(decoding);
    char *new_text = malloc(n2 * sizeof(char));
    txt_to_text(decoding, new_text, n2);
    t2 = clock();
    float temps = (float) t2-t1;
    temps = temps/CLOCKS_PER_SEC;
    printf("\n\nTemps : %f ",temps);

    return 0;
}

