#include "OptimisedHuffmanEncoding/EncodingFileOp.h"
#include "HuffmanEncoding/OutputFile.h"
#include "time.h"
#include "OptimisedHuffmanEncoding/CreateHuffmanTree.h"
#include "OptimisedHuffmanEncoding/Dictionary.h"


int main(){

    char* dico ="../dico.txt";
    char* Huffman="../Huffman.txt";
    char* input = "../input.txt";
    char* output = "../output.txt";
    char* decoding = "../decoding.txt";
    clock_t t1,t2;

    int choix;
    menue(&choix);

    if(choix == 1 || choix == 2){
        printf("\n\n---Output--- ");
        binary_translation(input,output);
        nb_caracteres_fichier(output);
        t1 = clock();
        if(choix == 1) {
            printf("\n\n---Input  and   Huffman--- ");
            writting_output_txt(input, dico, Huffman);
            t2 = clock();
        }
        else {
            printf("\n\n---Input  and   Huffman--- ");
            int len;
            Node* tab = add_by_dichtomie_v2(input,&len);
            quick_sorting(tab,0,len-1);
            Node* HuffmanTree = create_Huff_tree_from_tab(tab,len);
            Node_AVL* AVLTree = AVL_dico(HuffmanTree);
            encoding_v2(AVLTree,Huffman,input);
            nb_caracteres_fichier(input);
            nb_caracteres_fichier(Huffman);
            t2 = clock();
            write_AVL_in_dico(AVLTree,dico);
            free_tree_AVL(AVLTree);
        }
        float temps = (float) t2 - t1;
        temps = temps / CLOCKS_PER_SEC;
        printf("\n\nTemps : %f ", temps);
        printf("\nThe text has been compressed go to the Huffman.txt file to see the result !\n");
    }
    else if(choix == 3){
        optimised_decoding(Huffman,dico,decoding);
        printf("\n\nThe text has been decompressed, go to the decoding.txt file to see the results !\n");
    }
    return 0;
}

