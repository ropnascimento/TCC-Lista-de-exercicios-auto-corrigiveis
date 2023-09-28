// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#ifndef TRUNK_PRIORITY_QUEUE_SRC_PRIORITY_QUEUE_H_
#define TRUNK_PRIORITY_QUEUE_SRC_PRIORITY_QUEUE_H_

#include <string>

// Define como os elementos da fila de prioridades ser�o organizados na mem�ria.
// � declarado aqui, mas s� � implementado em priority_queue.cc para n�o violar
// o encapsulamento.
struct Node;

// Implementa uma fila de prioridades utilizando �rvores bin�rias de busca.
// NOTA1: Podem haver elementos repetitos.
// NOTA2: O c�lculo da complexidade das fun��es assume que a �rvore est�
// balanceada, ou seja, considera-se que a altura da arvore � O(log n), onde n
// � a cardinalidade da fila (i.e. n = size_). Entretanto, isto n�o � garantido
// nesta implenta��o.
class priority_queue {
 public:
  // Cria uma fila de prioridades vazia em O(1).
  priority_queue();

  // Testa se a fila est� vazia em O(1).
  bool empty();

  // Retorna o n�mero de elementos na fila em O(1).
  int size();

  // Retorna o menor elemento da fila em O(log n).
  // Precondi��o: a fila n�o est� vazia.
  SType top();

  // Insere k na fila de prioridades em O(log n).
  void push(SType k);

  // Remove o menor elemento da fila em O(log n).
  // Precondi��o: a fila n�o est� vazia.
  void pop();

  // Libera a mem�ria alocada para todos os elementos da fila em O(n.log n).
  ~priority_queue();

 private:
  // N�mero de elementos na fila.
  int size_;

  // Ponteiro para a raiz da �rvore.
  // "root_ == NULL" se o conjunto � vazio.
  Node* root_;

  friend class Teste;
};

#endif  // TRUNK_PRIORITY_QUEUE_SRC_PRIORITY_QUEUE_H_
