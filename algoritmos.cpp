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

// void mergeSort(int v[], int n) {
//     // Implementação futura do Merge Sort
// }

// void quickSort(int v[], int n) {
//     // Implementação futura do Quick Sort
// }