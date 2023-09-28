// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#include "list/src/list.h"

// Implementa um nó da lista encadeada.
struct Node {
  LType key;  // Valor da chave do nó.
  Node* prev;  // Ponteiro para o nó anterior.
  Node* next;  // Ponteiro para o próximo nó.
};

list::list() {
  // TODO.
}

list::list(list& l) {
  // TODO.
}

list::~list() {
  // TODO.
}

int list::size() {
  return 0;  // TODO.
}

bool list::empty() {
  return false;  // TODO.
}

Node* list::begin() {
  return end_;  // TODO.
}

Node* list::end() {
  return end_;  // TODO.
}

Node* list::next(Node* i) {
  return end_;  // TODO.
}

Node* list::prev(Node* i) {
  return end_;  // TODO.
}

LType& list::operator[](Node* i) {
  return end_->key;  // TODO.
}

void list::operator=(list& l) {
  // TODO.
}

void list::insert(Node* i, LType k) {
  // TODO.
}

void list::erase(Node* i) {
  // TODO.
}

void list::clear() {
  // TODO.
}

void list::merge(list& l) {
  // TODO.
}
