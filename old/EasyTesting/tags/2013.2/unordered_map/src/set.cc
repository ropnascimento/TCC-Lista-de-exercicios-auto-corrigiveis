// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#include "unordered_map_with_set/src/set.h"

// Implementa um nó da lista encadeada.
struct Node {
  KType key;  // Chave do nó.
  SType value; // Valor do nó
  Node* prev;  // Ponteiro para o nó anterior.
  Node* next;  // Ponteiro para o próximo nó.
};

set::set() {
  size_ = 0;
  end_ = new Node;
  end_->next = end_;
  end_->prev = end_;
}

bool set::empty() {
  return size_ == 0;
}

int set::size() {
  return size_;
}

Node* set::begin() {
  return end_->next;
}

Node* set::end() {
  return end_;
}

Node* set::next(Node* x) {
  return x->next;
}

Node* set::prev(Node* x) {
  return x->prev;
}

KType set::operator[](Node* x) {
  return x->key;
}

SType set::value(Node* x) {
  return x->value;
}

Node* set::find(KType k) {
  for (Node* i = begin(); i != end(); i = next(i)) {
    if (i->key == k) {
      return i;
    } else if (i->key > k) {
      return end();
    }
  }
  return end();  // k é maior que todos os elementos contidos no conjunto.
}

void set::insert(KType k, SType v) {
  // Encontra o primeiro elemento que não é menor que k na lista encadeada.
  Node* x = begin();
  while (x != end() && x->key < k) {
    x = next(x);
  }
  // Caso k já não esteja no conjunto, cria um novo nó para armazenar k.
  if (x == end() || x->key != k) {
    // Cria um novo nó e define o valor dos seus campos.
    Node* node = new Node;
    node->key = k;
    node->value = v;
    node->prev = x->prev;
    node->next = x;
    // Ajusta o valor dos ponteiros dos nós adjacentes ao novo nó.
    x->prev->next = node;
    x->prev = node;
    size_++;
  }
}

void set::erase(KType k) {
  Node* x = find(k);
  if (x != end()) {
    x->prev->next = x->next;
    x->next->prev = x->prev;
    delete x;
    size_--;
  }
}

void set::clear() {
  while (!empty()) {
    erase(begin()->key);
  }
}

void set::operator=(set& s) {
  clear();
  for (Node* i = s.begin(); i != s.end(); i = s.next(i)) {
    insert(s[i], s.value(i));
  }
}

set::~set() {
  clear();
  delete end_;
}
