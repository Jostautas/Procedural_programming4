#include "func.h"       // 2110617
#include <stdio.h>      // jostautas.sakas@mif.stud.vu.lt
#include <stdlib.h>     // 4 uzduotis
#include <assert.h>     // 9 variantas
#include <string.h>

int main(){
    struct list *start = NULL;

    // Good data:

    int Elem[3] = {1, 5, 8};

    // Check create_list():
    printf("Testing create_list():\n");

    start = (NEW *) create_list(Elem, 3);
    assert(start != NULL);
    printf("input: %d %d %d. output:", Elem[0], Elem[1], Elem[2]);
    print_list(start);

    free_previous(start);

    Elem[0] = 0;
    Elem[1] = -1;
    Elem[2] = 100;

    start = (NEW *) create_list(Elem, 3);
    assert(start != NULL);
    printf("input: %d %d %d. output:", Elem[0], Elem[1], Elem[2]);
    print_list(start);

    free_previous(start);

    Elem[0] = 10000;
    Elem[1] = -1000000;
    Elem[2] = 0;

    start = (NEW *) create_list(Elem, 3);
    assert(start != NULL);
    printf("input: %d %d %d. output:", Elem[0], Elem[1], Elem[2]);
    print_list(start);

    //free_previous(start);

    // Check insert():
    int k = 1, new = 9; // k - where to insert
    int *n = (int *) malloc(sizeof(int));
    *n = 3;
    printf("\nTesting insert():\n");
    printf("input: %d %d %d. new element is %d and will be inserted in %d position. output:", Elem[0], Elem[1], Elem[2], new, k);
    start = (NEW *) insert(n, k-1, new, start);
    assert(start != NULL);
    print_list(start);

}