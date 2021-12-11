#include "func.h"       // 2110617
#include <stdio.h>      // jostautas.sakas@mif.stud.vu.lt
#include <stdlib.h>     // 4 uzduotis
#include <assert.h>     // 9 variantas
#include <string.h>

int main(){
    int menu, loop = 1, n = 0, k = 0, new, *Elem; // n - elements in the array, k - where to insert
    struct list *start = NULL;
    char File_name[256];

    printf("Selection Menu:\n");
    while(loop == 1){
        printf("\nPress 0 to exit program\nPress 1 to create a new doubly linked list\nPress 2 to import a list from a file");
        printf("\nPress 3 to insert an element\nPress 4 to print out the linked list\nPress 5 to print list to a file \nPress 6 for help\n");

        if((scanf("%d", &menu) == 1) && (menu >= 0) && (menu <= 6)){
            switch(menu){
                
                case 0:
                    loop = 0;
                    break;

                case 1:
                    free_previous(start);
                    n = read_n();
                    assert(n > 0);
                    Elem = entered(n);
                    assert(Elem != NULL);
                    
                    for(int i = 0; i < n; i++){
                        printf("%d ", Elem[i]);
                    }
                    printf("\n");

                    start = create_list(Elem, n);
                    assert(start != NULL);
                    free(Elem);

                    break;

                case 2:
                    file_name(File_name);
                    assert(File_name != NULL);
                    start = (struct list *) read_file(File_name, start, &n);
                    assert(start != NULL);
                    break;

                case 3:
                    k = new_position(n);
                    --k;
                    assert(k >= 0 && k < n);

                    new = get_input("!    Enter what element you would like to insert (1 integer wihtout spaces)", "!    new element will be", "!    Please enter a valid element");
                    start = insert(&n, k, new, start);
                    assert(start != NULL);

                    break;

                case 4:
                    print_list(start);
                    break;

                case 5:
                    file_name(File_name);
                    assert(File_name != NULL);
                    fprint_list(start, File_name);
                    break;

                case 6:
                    printf("Generates a doubly linked list, which you can modify by adding new element(s) in your prefered position\n");
                    break;

                default:
                    printf("ERROR1");
            }
        }
        else{
            printf("!    Please enter a valid menu element - a number from 0 to 6\n");
        }
        while(getchar() != '\n');
    }

}