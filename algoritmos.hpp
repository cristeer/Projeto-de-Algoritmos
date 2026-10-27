#ifndef ALGORITMOS_HPP
#define ALGORITMOS_HPP

// definindo tipo de ponteiro para função de ordenação
typedef void (*FuncaoOrdenacao)(int[], int);

void insertion_sort(int v[], int n);
void selection_sort(int v[], int n);
void bubble_sort(int v[], int n);
void shell_sort(int v[], int n);

void merge (int v[], int esq, int meio, int dir);
void merge_sort_recursivo(int v[], int esq, int dir);
void merge_sort (int v[], int n);

// void quick_sort(int v[], int n);

#endif