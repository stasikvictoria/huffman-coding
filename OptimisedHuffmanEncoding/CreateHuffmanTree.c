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

void swap(Node** a, Node** b) {
    Node* tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

// fast sorting technique

void quick_sorting (Node* tab, int first, int last) {
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

//K
int compare_queue(Queue* q1, Queue* q2)
{

    if(q2->first==NULL && q1->first==NULL){return 0;}
    else if (q2->first==NULL){return 1;}
    else if (q1->first==NULL){return 2;}
    else if (q1->first->data->occ < q2->first->data->occ){return 1;}
    else{return 2;}
}

Node* create_Huff_tree_from_tab(Node* tab, int taille)
{
    Queue* q1=create_queue();
    Queue* q2=create_queue();
    int val1; //TO CHOSE BETWEEN q1 AND q2
    int val2; //TO CHOSE BETWEEN q1 AND q2


    if (taille==0)
    {
        return NULL;
    }
    if(taille==1)
    {
        return (&(tab[0]));
    }
    else
    {
        for(int i=0;i<taille;i++)
        {
            enqueue(q1,&tab[i]);
        }
        while (q1->first != NULL || (q2->first != NULL && q2->first->next != NULL)) //IF q1 IS NOT EMPTY OR q2 GOT MORE THAN ONE ELEMENT
        {
            Node* huffman = create_node(NULL, NULL); //CREATE THE TREE
            val1= compare_queue(q1,q2);
            if (val1==1)
            {
                huffman->left =dequeue(q1);
            }
            else if (val1==2)
            {
                huffman->left =dequeue(q2);
            }

            val2= compare_queue(q1,q2);
            if (val2==1)
            {
                huffman->right =dequeue(q1);
            }
            else if (val2==2)
            {
                huffman->right =dequeue(q2);
            }
            huffman->occ=(huffman->right->occ)+(huffman->left->occ); //HEAD OF TREE TAKE VALUE OF THE SUM OF OCCURENCE OF THE TWO CHILDREN
            enqueue(q2,huffman);//PUT THE NEW NODE IN q2
        }

        return q2->first->data;
    }

}
