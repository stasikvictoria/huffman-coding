#include "CreateHuffmanTree.h"
#include "../DataTypes/DataTypes.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int MAX_TAB =255;

Node* add_by_dichtomie_v2(char* my_fic){
    //Open the text file 
    FILE* fic = fopen(my_fic, "r");
    if (fic== NULL){
        printf("\nOPENING ERROR : FILE MY_FIC \n");
        exit(EXIT_FAILURE);
    }
    // Create and initialize the tab
    Node* tab = malloc(MAX_TAB*sizeof(Node));
    int indexe = 0;
    for(indexe=0; indexe<MAX_TAB; indexe++){
        tab[indexe].letter = indexe;
        tab[indexe].occ = 0;
        tab[indexe].left = NULL;
        tab[indexe].right = NULL;
    }
    int cpt = 0;
    int my_char = fgetc(fic);
    int INF =0;
    int SUP = MAX_TAB-1;
    int POS = -1;
    int MIL;
    // Add occurences to my tab by dichotomy
    while (my_char != EOF){
        INF =0;
        SUP = MAX_TAB -1;
        POS =-1;
        while ((INF<=SUP)&& (POS == -1)){
            MIL = (SUP+INF)/2;
            if (my_char < tab[MIL].letter){
                SUP = MIL-1;
            }
            else if ( my_char > tab[MIL].letter){
                INF = MIL+1;
            }
            else {
                POS = MIL ;
            }
        }
        if (tab[POS].occ == 0){
            cpt += 1;
        }
        tab[POS].occ += 1;
        my_char = fgetc(fic);
    }
    //Create the end tab (to return) 
    Node* end_tab = malloc(cpt*sizeof(Node));
    int j=0;
    for (indexe = 0; indexe< cpt ; indexe++){
        while (tab[j].occ == 0){
            j = j+1;
        }
        end_tab[indexe] = tab[j];
        j+=1;
    }
    // Close the file
    free(tab);
    fclose(fic);
    return end_tab;
}

// To test
void print_Tab_of_DoubleNode(Node* tab, int n){
    int indexe = 0;
    for (indexe = 0; indexe<n ; indexe++){
        printf("\n%c : %d", tab[indexe].letter, tab[indexe].occ);
    }
}

void swap(DoubleNode** a, DoubleNode** b) {
    DoubleNode* tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

// fast sorting technique

void quick_sorting (DoubleNode* tab, int first, int last) {
    int pivot, i, j;
    if(first < last) {
        pivot = first;          //We define the pivot at the beginning
        i = first;
        j = last;
        while (i < j) {
            while(tab[i].occ <= tab[pivot].occ && i < last)   //We are looking for an element larger than the pivot on the left if it exists.
                i++;
            while(tab[j].occ > tab[pivot].occ)   // We are looking for an element smaller than the pivot on the right if it exists
                j--;
            if(i < j) {                 //If they exist, we exchange them
                swap(&tab[i], &tab[j]);
            }
        }
        swap(&tab[pivot], &tab[j]);
        quick_sorting(tab, first, j - 1);  // This is repeated until the 2 sub-tables are sorted.
        quick_sorting(tab, j + 1, last);
    }
}
