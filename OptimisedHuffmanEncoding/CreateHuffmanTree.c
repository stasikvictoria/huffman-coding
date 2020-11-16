#include "CreateHuffmanTree.h"
#include "../DataTypes/DataTypes.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int MAX_TAB =255;

Node* add_by_dichtomie_v2(char* my_fic){
    FILE* fic = fopen(my_fic, "r");
    if (fic== NULL){
        //fprintf(stderr, "ERREUR OUVERTURE FICHIER \n");

        printf("\nEREEUR OUVERTURE FICHIER \n");
        exit(EXIT_FAILURE);
    }
    Node* tab = malloc(MAX_TAB*sizeof(Node));
    int indexe = 0;
    //INITIALISER MON TAB
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
    // ADD OCCU TO MY TAB
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
    Node* end_tab = malloc(cpt*sizeof(Node));
    int j=0;
    for (indexe = 0; indexe< cpt ; indexe++){
        while (tab[j].occ == 0){
            j = j+1;
        }
        end_tab[indexe] = tab[j];
        j+=1;
    }
    free(tab);
    fclose(fic);
    return end_tab;
}

// POUR TESTER
void print_Tab_of_DoubleNode(Node* tab, int n){
    int indexe = 0;
    for (indexe = 0; indexe<n ; indexe++){
        printf("\n%c : %d", tab[indexe].letter, tab[indexe].occ);
    }
}
