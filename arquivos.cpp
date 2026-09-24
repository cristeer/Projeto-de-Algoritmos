#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <iomanip>
#include <filesystem>
#include <random>
#include "arquivos.hpp"

using namespace std;

void limpar_tela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void pausar() {
    cout << "\nPressione ENTER para continuar...";
    cin.ignore();
    cin.get();
}

void criar_estrutura_pastas(const string& pasta_algoritmo) {
    string categorias[] = {"Arquivos de Entrada", "Arquivos de Saida", "Arquivos de Tempo"};
    string tipos[] = {"Crescente", "Decrescente", "Random"};

    for (const auto& cat : categorias) {
        for (const auto& tipo : tipos) {
            string caminho = pasta_algoritmo + "/" + cat + "/" + tipo;
            filesystem::create_directories(caminho);
        }
    }
}

void processar_instancia(string nome_algoritmo, string pasta_algoritmo, string tipo_entrada, int tamanho, FuncaoOrdenacao funcao) {
    criar_estrutura_pastas(pasta_algoritmo);

    // Caminhos dos arquivos de acordo com o padrão exigido
    string arq_entrada = pasta_algoritmo + "/Arquivos de Entrada/" + tipo_entrada + "/Entrada" + tipo_entrada + to_string(tamanho) + ".txt";
    string arq_saida   = pasta_algoritmo + "/Arquivos de Saida/"   + tipo_entrada + "/Saida"   + tipo_entrada + to_string(tamanho) + ".txt";
    string arq_tempo   = pasta_algoritmo + "/Arquivos de Tempo/"   + tipo_entrada + "/Tempo"   + tipo_entrada + to_string(tamanho) + ".txt";

    vector<int> v(tamanho);
   
    cout << "> EXECUTANDO " << nome_algoritmo << " | Entrada: " << tipo_entrada << " | Tamanho: " << tamanho << "\n\n";

   
    random_device rd;   // obter semente para o random
    mt19937 gen(rd());  // para gerar o motor com a semente
    uniform_int_distribution<int> dist(1, tamanho * 10);  // para gerar intervalo com <random>
    
    // 1. GERAR/ESCREVER ARQUIVO DE ENTRADA
    ofstream entrada(arq_entrada);
    if (!entrada.is_open()) {
        cout << "ERRO ao criar o arquivo de entrada em: " << arq_entrada << "\n";
        // cout << "Certifique-se de que a estrutura de pastas ja foi criada!\n";
        pausar();
        return;
    }

    // Primeira linha: Tamanho da instancia
    entrada << tamanho << "\n";
    for (int i = 0; i < tamanho; i++) {
        if (tipo_entrada == "Crescente") {
            v[i] = i + 1;
        } else if (tipo_entrada == "Decrescente") {
            v[i] = tamanho - i;
        } else { // Random
            v[i] = dist(gen);
        }
        entrada << v[i] << "\n";
    }
    entrada.close();
    cout << "[1/3] Arquivo de Entrada gerado\n";

    // 2. EXECUTAR A ORDENAÇÃO E MEDIR O TEMPO
    cout << "[2/3] Executando " << nome_algoritmo << "...\n";
    
    auto inicio = chrono::high_resolution_clock::now();
    funcao(v.data(), tamanho);
    auto fim = chrono::high_resolution_clock::now();
    
    chrono::duration<double> tempo_exec = fim - inicio;

    // 3. SALVAR ARQUIVO DE SAÍDA (VETOR ORDENADO)
    ofstream saida(arq_saida);
    if (saida.is_open()) {
        for (int i = 0; i < tamanho; i++) {
            saida << v[i] << "\n";
        }
        saida.close();
        cout << "[3/3] Arquivo de Saida gerado\n";
    }

    // 4. SALVAR ARQUIVO DE TEMPO
    ofstream tempo(arq_tempo);
    if (tempo.is_open()) {
        // Primeira linha: Tamanho da instancia
        tempo << tamanho << "\n";
        tempo << fixed << setprecision(4) << tempo_exec.count() << "\n";
        tempo.close();
        cout << "Arquivo de Tempo salvo\n";
    }

    cout << "\nTempo gasto: " << fixed << setprecision(4) << tempo_exec.count() << " seg\n";  
    pausar();

}