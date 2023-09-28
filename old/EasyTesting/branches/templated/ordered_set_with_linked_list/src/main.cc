// Copyright 2014 Universidade Federal de Minas Gerais (UFMG)
//
// Lista sobre Conjuntos.
//
// Questão 1.
// Implemente em set.h e set.cc o TAD set, utilizando listas encadeadas.
//
// Questão 2.
// Escreva uma função "void Imprimir(const set& s)" que recebe
// como parâmetro um conjunto s e imprime os elementos de s na tela.
//
// Questão 3.
// Escreva uma função
// "void Intersecao(const set& a, const set& b, set* inter)" que recebe dois
// conjuntos 'a' e 'b' e atribui a 'inter' o resultado da interseção
// de 'a' e 'b'.
//
// Questão 4.
// Escreva uma função
// "void Uniao(const set& a, const set& b, set* uniao)" que recebe dois
// conjuntos 'a' e 'b' e atribui a 'uniao' o resultado da união de 'a' e 'b'.
//
// Questão 5.
// Escreva um programa que gerencia os fornecedores para compra de peças
// em uma montadora de carros. As peças são identificadas por números inteiros
// entre 1 e 100 e os fornecedores são identificados por uma string.
//
// O sistema deve ler de um arquivo o nome dos fornecedores de peças e a lista
// das peças que cada fornecedor vende. Tome como EXEMPLO o
// arquivo "fornecedores.txt". A  primeira linha deste arquivo contém o número n
// de fornecedores. As n linhas seguintes contêm uma string com o nome de um
// fornecedor, seguida de um número 'm' (de peças que o fornecedor vende),
// que por sua vez é seguido de 'm' números naturais, cada um deles referente a
// uma das peças vendidas pelo fornecedor.
//
// O seu programa deve inicialmente exibir o conjunto com todos os
// fornecedores e o conjunto de todas as peças.
// A cada iteração, o usuário deve ser capaz de digitar o número
// de uma peça e o sistema deve eliminar do conjunto de fornecedores candidatos
// aqueles que não vendem a última peça digitada. O programa deve continuar
// pedindo o número de uma nova peça até que o usuário digite zero ou até
// que o conjunto de fornecedores candidatos seja vazio.
//
// DICA: crie um conjunto "set candidatos" que contém
// inicialmente o nome de todos os fornecedores e um vetor
// "set pecas[100]" com o conjunto de fornecedores para cada
// peça. A cada iteração em que uma peça 'p' for digitada, você deve fazer a
// interseção do conjunto 'candidatos' com o conjunto 'pecas[p - 1]'.

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

#include "src/set.h"

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::string;

// Questão 2.
void Imprimir(const set<string>& c) {
  cout << "{ ";
  for (set<string>::iterator i = c.begin(); i != c.end(); i++) {
    cout << *i << " ";
  }
  cout << "} = " << c.size() << endl;
}

// Questão 3.
void Intersecao(const set<string>& a,
                const set<string>& b,
                set<string>* inter) {
  // Percorre todos os elementos do cojunto 'a' e insere em 'inter' todos
  // aqueles que também estão no cojunto 'b'.
  inter->clear();
  for (set<string>::iterator i = a.begin(); i != a.end(); i++) {
    if (b.find(*i) != b.end()) {
      inter->insert(*i);
    }
  }
}

// Questão 4.
void Uniao(const set<string>& a, const set<string>& b, set<string>* uniao) {
  // Inicialmente, faz 'uniao' ficar igual a 'b'.
  *uniao = b;
  // Em seguida, insere em 'uniao' também os elementos em a.
  for (set<string>::iterator i = a.begin(); i != a.end(); i++) {
    uniao->insert(*i);
  }
}

// Questão 5.
int main() {
  set<string> pecas[100];  // pecas[i] contém os fornecedores da peça i + 1.
  set<string> candidatos;  // Conjunto de fornecedores.
  set<string> todas_as_pecas;  // Conjunto com todas as peças vendidas.

  // Inicializa o cojunto de fornecedores candidatos e o vetor de fornecedores
  // de cada peça.
  ifstream fin("fornecedores.txt");
  int n;  // Número de fornecedores.
  fin >> n;
  for (int i = 0; i < n; i++) {
    string nome_fornecedor;
    fin >> nome_fornecedor;
    candidatos.insert(nome_fornecedor);
    int m;  // Número de peças vendidas pelo fornecedor i.
    fin >> m;
    for (int j = 0; j < m; j++) {
      string num_peca;
      fin >> num_peca;
      pecas[atoi(num_peca.c_str()) - 1].insert(nome_fornecedor);
      todas_as_pecas.insert(num_peca);
    }
  }

  // Imprime todos os fonecedores e peças.
  cout << "Fornecedores: ";
  Imprimir(candidatos);
  cout << "Pecas: ";
  Imprimir(todas_as_pecas);
  cout << endl;

  // Filtra iterativamente o cojunto de fornecedores candidatos.
  int num_peca = -1;
  while (!candidatos.empty() && num_peca != 0) {
    cout << "Candidatos: ";
    Imprimir(candidatos);
    cout << "Filtrar por peca [1, 100]: ";
    cin >> num_peca;
    if (num_peca >= 1 && num_peca <= 100) {
      set<string> inter;
      Intersecao(pecas[num_peca - 1], candidatos, &inter);
      candidatos = inter;
    }
  }
  cout << "Resultado: ";
  Imprimir(candidatos);
  return 0;
}
