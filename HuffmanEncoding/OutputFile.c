#include "OutputFile.h"


void txt_to_text(const char* file_name,const char* text,const int size_text){
    FILE* file = NULL;
    file = fopen(file_name, "r");
    char* chain = calloc(1,size_text * sizeof(char));
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




void writting_output_txt(const char* input,const char* dico,const char* output){
    //CONVERTING THE TXT FILE TO A CHAR*
    int n = nb_caracteres_fichier(input);
    char *text = calloc(1, (n+1) * sizeof(char));   // fill string with NULL characters
    txt_to_text(input, text, n);
    //printf("INPUT : %s\n\n", text);

    //CREATION OF THE OCCURENCE LIST
    Element *e = occurence(text);
   // printf("Occurences :");
   // print_list(e);
    //printf("\n\n");

    //CREATION OF THE HUFFMAN TREE
    Node *tree = return_huffman(e);
    //printf("Tree :\n");
    //print_tree(tree);
   // printf("\n\n");

    //CREATION OF THE DICTIONARY
    int code[100];
    int code_index = 0;
    int leaves = 0;
    number_of_leaves(tree, &leaves);
    Dictionary *d = create_dictionary(leaves);
    Dictionary *temp = d;
    dictionary_from_tree(tree, &temp, code, &code_index);
    //print_dictionary(d);
    write_dictionary_in_txt(d,dico);

    encoding(dico,output, input);
    int n2 = nb_caracteres_fichier(output);
    char *new_text = malloc(n2 * sizeof(char));
    txt_to_text(output, new_text, n2);
    //printf("\nOUTPUT : %s\n\n", new_text);

    free(new_text);
    free_dictionary(d);
    free(text);
    free_list(e);
    free_tree(tree);
}


void menue(int* choix)
{
    int i,n,ch;
    printf(" ");
    for (i=0;i<68;i++){
        printf("-");
    }
    for (i=0;i<9;i++){
        printf("\n⎥");
        if (i==1)
            printf("                           ACCUEIL                                ");
        else if (i==3)
            printf("            1 > Huffman Coding without optimizations              ");
        else if (i==5)
            printf("                 2 > Huffman Coding optimised                     ");
        else if (i==7)
            printf("          3 >  Decoding a Huffman file already encoded            ");
        else
            printf("                                                                  ");
        printf(" ⎥");
    }
    printf("\n");
    printf(" ");
    for (i=0;i<68;i++){
        printf("-");
    }
    printf("\n\nQue souhaitez vous faire : ");

    do{
        n = scanf("%d",choix);
        while((ch = (int)getchar()) != '\n' && ch != EOF);
    }while (n!=1 || (*choix!=1 && *choix!=2 && *choix!=3));
}

