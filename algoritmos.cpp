#include <vector>
#include "algoritmos.hpp"

void insertion_sort(int v[], int n) {
    for (int i = 1; i < n; i++) {
        int chave = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] > chave) {
            v[j + 1] = v[j];
            j = j - 1;
        }
        v[j + 1] = chave;
    }
}

void selection_sort(int v[], int n) {
    int i, j, min, chave;
    for (i = 0; i < n-1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (v[j] < v[min])
                min = j;              
        }
        chave = v[i]; 
        v[i] = v[min]; 
        v[min] = chave;
    }
}

void bubble_sort(int v[], int n) {
    int i, j, aux;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (v[j] > v[j+1]){
                aux = v[j]; 
                v[j] = v[j+1]; 
                v[j+1] = aux;
            }
        }
    }
}

void shell_sort(int v[], int n) {
    int i, j, aux;

    int h = 1;
    while (h < n) {
        h = h * 3 + 1;
    }

    while (h > 0) {
        for (i = h; i < n; i++) {
            aux = v[i];
            j = i;

            while (j >=h && aux < v[j-h]) {
                v[j] = v[j-h];
                j -= h;
            }
            v[j] = aux;
        }
        h = (h-1) / 3;
    }
}

/*
OBS: Para o merge sort foi necessário separar a funcao recursiva do merge sort para padronizar
com a mesma interface dos outros algoritmos na funcao de ordenacao principal do programa 
que recebe dois parametros (FuncaoOrdenacao)
*/ 

void merge (int v[], int esq, int meio, int dir) {
    std::vector<int> arr((dir - esq) + 1);

    int e = esq, d = meio + 1, k = 0;

    while (e <= meio && d <= dir) {
        if(v[e] <= v[d])
            arr[k++] = v[e++];
        else
            arr[k++] = v[d++];
    }

    //se acabar o vetor da dir primeiro, copiar o restante da esq;
    while (e <= meio) {
        arr[k++] = v[e++];
    }

    //se acabar o vetor da esq primeiro, copiar o restante da dir;
    while (d <= dir) {
        arr[k++] = v[d++];
    }

    for (int i = esq; i <= dir; i++) {
        v[i] = arr[i - esq];
    }
}

void merge_sort_recursivo (int v[], int esq, int dir) {
    if (esq < dir) {
        int meio = esq + (dir - esq) / 2;
        merge_sort_recursivo(v, esq, meio);
        merge_sort_recursivo(v, meio + 1, dir);
        merge(v, esq, meio, dir);
    }
}

void merge_sort (int v[], int n) {
    if (n > 1) {
        merge_sort_recursivo(v, 0, n - 1);
    }
}

// void quickSort(int v[], int n) {
//     // Implementação futura do Quick Sort
// }