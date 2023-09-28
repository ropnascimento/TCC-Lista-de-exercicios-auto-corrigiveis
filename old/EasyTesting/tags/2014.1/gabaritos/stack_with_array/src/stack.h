// Copyright 2014 Universidade Federal de Minas Gerais (UFMG)

#ifndef TRUNK_STACK_WITH_ARRAY_SRC_STACK_H_
#define TRUNK_STACK_WITH_ARRAY_SRC_STACK_H_

#include <string>

// Implementa uma pilha de elementos utilizando arrays.
// O tipo dos elementos contidos na pilha � definido por SType.
// O valor de SType deve ser definido em tempo de compila��o.
class stack {
 public:
  // Cria uma pilha vazia em O(1).
  stack();

  // Testa se a pilha est� vazia em O(1).
  bool empty();

  // Retorna o n�mero de elementos na pilha em O(1).
  int size();

  // Retorna o elemento que est� no topo da pilha em O(1).
  // Precondi��o: a pilha n�o pode estar vazia.
  SType top();

  // Insere k no topo da pilha em O(1).
  void push(SType k);

  // Remove o elemento que est� no topo da pilha em O(1).
  // Precondi��o: a pilha n�o pode estar vazia.
  void pop();

  // Faz a pilha corrente ficar igual a p em O(n + m),
  // onde m = p.size() e n = size().
  void operator=(stack& p);

// Libera a mem�ria alocada para a pilha em O(1).
  ~stack();

 private:
  // Fun��o que altera o n�mero m�ximo de elementos na pilha
  // para pelo menos 'm' em O(m).
  void reserve(int m);

  // N�mero de elementos na pilha.
  int size_;

  // N�mero de elementos no vetor array_.
  int capacity_;

  // Vetor com os elementos da pilha.
  SType* array_;

  friend class Teste;
};

#endif  // TRUNK_STACK_WITH_ARRAY_SRC_STACK_H_
