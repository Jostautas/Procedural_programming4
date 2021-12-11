#ifndef FUNC_H
#define FUNC_H 

struct list;

typedef struct list NEW;

void free_previous(NEW *start);
int read_n();
int *entered(int n);
NEW *create_list(int Elem[], int n);
void file_name(char *File_name);
NEW *read_file(char File_name[], NEW *start, int *n);
int new_position(int n);
int get_input(char Text1[], char Text2[], char Text3[]);
NEW *insert(int *n, int k, int new, NEW *start);
void print_list(NEW *start);
void fprint_list(NEW *start, char File_name[]);

#endif