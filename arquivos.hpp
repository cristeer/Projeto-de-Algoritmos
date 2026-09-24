#ifndef ARQUIVOS_HPP
#define ARQUIVOS_HPP

#include <string>
#include "algoritmos.hpp"
using namespace std;


void limpar_tela();

void pausar();


void criar_estrutura_pastas(const string& pasta_algoritmo);

// Função responsável por gerar a entrada, rodar o algoritmo e salvar os arquivos de saída e tempo
void processar_instancia(string nome_algoritmo, string pasta_algoritmo, string tipo_entrada, int tamanho, FuncaoOrdenacao funcao);

#endif