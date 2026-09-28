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






// void shell_sort(int v[], int n) {
//     int gap, i, j, temp;

//     // 1. Reduz o gap dividindo por 2 a cada iteração (Sequência de Shell)
//     for (gap = n / 2; gap > 0; gap /= 2) {

//         // 2. Aplica um Insertion Sort modificado para elementos espaçados pelo 'gap'
//         for (i = gap; i < n; i++) {
//             temp = v[i];

//             // 3. Desloca os elementos maiores que 'temp' para a direita (com salto 'gap')
//             for (j = i; j >= gap && v[j - gap] > temp; j -= gap) {
//                 v[j] = v[j - gap];
//             }

//             // 4. Insere o elemento na sua posição correta do subvetor
//             v[j] = temp;
//         }
//     }
// }










// void mergeSort(int v[], int n) {
//     // Implementação futura do Merge Sort
// }

// void quickSort(int v[], int n) {
//     // Implementação futura do Quick Sort
// }