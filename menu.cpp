#include <iostream>
#include "menu.hpp"
#include "arquivos.hpp"

using namespace std;

// Submenu 2: Escolha do Tamanho da Instância
void menu_tamanhos(string nome_algoritmo, string pasta_algoritmo, string tipo_entrada, FuncaoOrdenacao funcao) {
    int op;
    do {
        limpar_tela();
        cout << "> " << nome_algoritmo << " | " << tipo_entrada << "\n\n";
        cout << "Escolha o tamanho da instancia:\n";
        cout << "1. 10\n";
        cout << "2. 100\n";
        cout << "3. 1.000\n";
        cout << "4. 10.000\n";
        cout << "5. 100.000\n";
        cout << "6. 1.000.000\n";
        cout << "0. Voltar ao menu de tipo de entrada\n";
        cout << "\nEscolha uma opcao: ";
        cin >> op;

        int tamanho = 0;
        switch (op) {
            case 1:
                tamanho = 10;
                 break;
            case 2:
                tamanho = 100; 
                break;
            case 3:
                tamanho = 1000; 
                break;
            case 4:
                tamanho = 10000; 
                break;
            case 5:
                tamanho = 100000;
                break;
            case 6:
                tamanho = 1000000;
                break;
            case 0:
                break;
            default:
                cout << "Opcao invalida!\n";
                pausar();
                continue;
        }

        if (tamanho > 0) {
            limpar_tela();
            processar_instancia(nome_algoritmo, pasta_algoritmo, tipo_entrada, tamanho, funcao);
        }

    } while (op != 0);
}

// Submenu 1: Escolha do Tipo de Entrada
void menu_entrada(string nome_algoritmo, string pasta_algoritmo, FuncaoOrdenacao funcao) {
    int op;
    do {
        limpar_tela();
        cout << "> " << nome_algoritmo << "\n\n";
        cout << "1. Crescente\n";
        cout << "2. Decrescente\n";
        cout << "3. Randomica\n";
        cout << "0. Voltar\n";
        cout << "\nEscolha um opcao: ";
        cin >> op;

        limpar_tela();
        switch (op) {
            case 1:
                menu_tamanhos(nome_algoritmo, pasta_algoritmo, "Crescente", funcao);
                break;
            case 2:
                menu_tamanhos(nome_algoritmo, pasta_algoritmo, "Decrescente", funcao);
                break;
            case 3:
                menu_tamanhos(nome_algoritmo, pasta_algoritmo, "Random", funcao);
                break;
            case 0:
                break;
            default:
                cout << "Opcao invalida!\n";
                pausar();
                break;
        }
    } while (op != 0);
}



// Menu Principal
void exibir_menu() {
    int op;
    do {
        limpar_tela();
        cout << "==== ALGORITMOS DE ORDENACAO ====\n\n";
        cout << "1. Insertion Sort\n";
        cout << "0. Sair\n";
        cout << "\nEscolha uma opcao: ";
        cin >> op;

        limpar_tela();
        switch (op) {
            case 1:
                menu_entrada("INSERTION SORT", "Insertion Sort", insertion_sort);
                break;
            // case 2:
            //     menu_entrada("MERGE SORT", "Merge Sort", mergeSort);
            //     break;
            // case 3:
            //     menu_entrada("QUICK SORT", "Quick Sort", quickSort);
            //     break;
            case 0:
                cout << "Encerrando o programa...\n";
                break;
            default:
                cout << "Opcao invalida!\n";
                pausar();
                break;
        }
    } while (op != 0);
}


















// void menu_algoritmo(string nome_algoritmo, string nome_pasta, FuncaoOrdenacao funcao) {
//     int opcao;
//     do {
//         limpar_tela();
//         cout << "==== " << nome_algoritmo << "====\n\n";
//         cout << "1. Gerar instancias (10 a 1.000.000)\n";
//         cout << "2. Executar ordenacao em uma instancia especifica\n";
//         cout << "3. Executar bateria completa de testes (18 arquivos)\n";
//         cout << "0. Voltar ao Menu Principal\n";
//         cout << "----------------------------------------\n";
//         cout << "Escolha uma opcao: ";
//         cin >> opcao;

//         limpar_tela();
//         switch (opcao) {
//             case 1:
//                 cout << "Gerando arquivos na pasta: " << nomePasta << "...\n";
//                 pausar();
//                 break;
//             case 2:
//                 cout << "Executando " << nomeAlgoritmo << " em uma instancia...\n";
//                 pausar();
//                 break;
//             case 3:
//                 cout << "Executando bateria completa para " << nomeAlgoritmo << "...\n";
//                 pausar();
//                 break;
//             case 0:
//                 cout << "Retornando ao menu principal...\n";
//                 break;
//             default:
//                 cout << "Opcao invalida!\n";
//                 pausar();
//                 break;
//         }
//     } while (opcao != 0);
// }

// void exibirMenuPrincipal() {
//     int opcao;
//     do {
//         limpar_tela();
//         cout << "========================================\n";
//         cout << "   ANALISE DE ALGORITMOS DE ORDENACAO   \n";
//         cout << "========================================\n";
//         cout << "1. Insertion Sort\n";
//         cout << "2. Merge Sort\n";
//         cout << "3. Quick Sort\n";
//         cout << "0. Sair do Programa\n";
//         cout << "----------------------------------------\n";
//         cout << "Escolha uma opcao: ";
//         cin >> opcao;

//         limpar_tela();
//         switch (opcao) {
//             case 1:
//                 menuAlgoritmoGenerico("INSERTION SORT", "Insertion Sort", insertionSort);
//                 break;
//             case 2:
//                 menuAlgoritmoGenerico("MERGE SORT", "Merge Sort", mergeSort);
//                 break;
//             case 3:
//                 menuAlgoritmoGenerico("QUICK SORT", "Quick Sort", quickSort);
//                 break;
//             case 0:
//                 cout << "Encerrando o programa...\n";
//                 break;
//             default:
//                 cout << "Opcao invalida!\n";
//                 pausar();
//                 break;
//         }
//     } while (opcao != 0);
// }