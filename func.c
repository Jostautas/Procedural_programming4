#include "func.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>

struct list{
    int x;
    struct list *next;
    struct list *pre;
};

void free_previous(NEW *start){
    if(start != NULL){
        NEW *elem = start;
        NEW *new_elem;
        while(elem != NULL){
            new_elem = elem -> next;
            free(elem);
            elem = new_elem;
        }
    }
}

int read_n(){
    int n = 0, bool = 1;
    while(bool == 1){
        n = get_input("!    Enter the wanted number of elements in the list", "!    Entered number of elements is", "!    Please enter a valid number of elements in the array");
        if(n < 1){
            printf("!    Please enter a valid number of elements in the array\n");
            }
        else bool = 0;
    }
    return n;
}

int *entered(int n){
    int *Elem = (int *) malloc(n * sizeof(int));
    printf("Enter %d elements\n", n);
    for(int i = 0; i < n; i++){
        if((scanf("%d", (Elem + i)) != 1)){
            printf("Please enter a correct element - integer\n");
            --i;
            while(getchar() != '\n');
        }
    }
    return Elem;
}

NEW *create_list(int Elem[], int n){
    NEW *start = (NEW *) malloc(sizeof(NEW));
    start -> x = Elem[0];
    start -> next = NULL;
    start -> pre = NULL;
    NEW *elem = start;
    NEW *end;
    for(int i = 1; i < n; i++){
        end = (NEW *) malloc(sizeof(NEW));
        end -> x = Elem[i];
        end -> pre = elem;
        end -> next = NULL;
        elem -> next = end;
        elem = end;
    }
    return start;
}

void file_name(char *File_name){
    printf("!    Enter the name of the file\n");
    if(scanf("%s", File_name) == 1){
        printf("!    Entered file name: %s\n", File_name);
    }
    else{
        printf("!    Enter a correct file name\n");
    }
}

NEW *read_file(char File_name[], NEW *start, int *n){

    int *Elem = (int *) malloc(sizeof(int) * 50);
    int size = 50;
    char temp;
    *n = 0;
    FILE *input_f;
    input_f = fopen(File_name, "r");
    if(input_f != NULL){
        while((fscanf(input_f, "%d", (Elem + *n))) == 1){
            ++*n;
            if(size == *n){
                Elem = (int *) realloc(Elem, size * 2);
            }
        }
        if(fscanf(input_f, "%c", &temp) != EOF){
            printf("!   Check if all elements in the file are integers seperated by spaces\n");
            free_previous(start);
        }
        else{
            fclose(input_f);
            return start = create_list(Elem, *n);
        }
        fclose(input_f);
    }
    else{
        printf("!   Enter a correct file name of existing data file (with extension .txt)\n");
    }
    return NULL;
}

int new_position(int n){
    int k, bool = 1;
    while (bool == 1){
        k = get_input("!    Enter in which position you would like to insert a new element", "!    Position of the new element will be", "!    Please enter a valid position of the new element");
        if((k < 1) || (k > n)){
            printf("!    Please enter a valid position of the new element\n");
        }
        else bool = 0;
    }
    return k;
}

int get_input(char Text1[], char Text2[], char Text3[]){
    int x;
    printf("%s\n", Text1);
    if((scanf("%d", &x) == 1) && (getchar() == '\n')){
        printf("%s %d\n", Text2, x);
        return x;
    }
    else{
        printf("%s\n", Text3);
        get_input(Text1, Text2, Text3);
    }
    return 0;
}

NEW *insert(int *n, int k, int new, NEW *start){
    NEW *elem = start;
    if(k == 0){
        start = (NEW *) malloc(sizeof(NEW));
        start -> pre = NULL;
        start -> next = elem;
        start -> x = new;
        elem -> pre = start;
    }
    else{
        for(int i = 0; i < k-1; ++i){
            if(elem != NULL){
                elem = elem -> next;
            }
            else{
                printf("!    Could not find the %d element in the list\n", k);
            }
        }
        NEW *new_elem = (NEW *) malloc(sizeof(NEW));
        new_elem -> x = new;
        new_elem -> pre = elem;
        new_elem -> next = elem -> next;
        elem -> next = new_elem;
    }
    ++*n;
    return start;
}

void print_list(NEW *start){
    NEW *elem = start;
    printf("Your list: ");
    while(elem != NULL){
        printf("%d ", elem -> x);
        elem = elem -> next;
    }
    printf("\n");
}

void fprint_list(NEW *start, char File_name[]){
    FILE *out_file;
    out_file = fopen(File_name, "w");

    if((out_file != NULL) && (start != NULL)){
        NEW *elem = start;
        while(elem != NULL){
            fprintf(out_file, "%d ", elem -> x);
            elem = elem -> next;
        }
        printf("!    List has been printed to an output file in project directory\n");
    }
    else{
        printf("!    Cannot open file or linked list doesn't exist\n");
    }
    
    fclose(out_file);
}
