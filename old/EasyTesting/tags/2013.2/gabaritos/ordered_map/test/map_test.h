// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#ifndef TRUNK_ORDERED_MAP_WITH_BST_TEST_MAP_TEST_H_
#define TRUNK_ORDERED_MAP_WITH_BST_TEST_MAP_TEST_H_

#include <cstdlib>
#include <sstream>
#include <string>

#include "gtest/gtest.h"
#include "ordered_map/src/map.h"

using std::string;
using std::stringstream;

// Define como os elementos da �rvore ser�o organizados na mem�ria.
struct Node {
  SType key;  // Valor da chave do n�.
  VType value; // Valor do n�
  Node* left;  // Ponteiro para o n� a esquerda.
  Node* right;  // Ponteiro para o n� a direita.
  Node* parent;  // Ponteiro para o n� acima.
};

// Classe base dos testes.
class Teste : public testing::Test {
 protected:
  // Retorna o valor da chave do elemento x;
  SType key(Node* x) {
    return x->key;
  }

  // Retorna o valor do elemento x;
  VType value(Node* x) {
    return x->value;
  }

  // Retorna o n�mero de elementos no conjunto.
  int size(map& s) {
    return s.size_;
  }

  // Insere uma FOLHA z na �rvore cujo n� raiz � 'root' de forma consistente.
  // NOTA: Esta fun��o N�O aloca a mem�ria para z.
  void TreeInsert(Node*& root, Node* z) {
    // Procura qual vai ser o pai y de z na �rvore.
    Node* y = NULL;
    Node* x = root;
    while (x != NULL) {
      y = x;
      if (z->key < x->key) {
        x = x->left;
      } else {
        x = x->right;
      }
    }
    // Insere z em baixo do n� y.
    z->parent = y;
    if (y == NULL) {
      root = z;  // z se torna a raiz da �rvore.
    } else if (z->key < y->key) {
      y->left = z;
    } else  {
      y->right = z;
    }
  }

  Node* insert(SType k, VType v, map* s) {
    Node* z = new Node;
    z->key = k;
    z->value = v;
    z->left = z->right = z->parent = NULL;
    TreeInsert(s->root_, z);
    s->size_++;
    return z;
  }

  // Retorna um ponteiro para o primeiro elemento do conjunto.
  Node* begin(const map& s) {
    Node* x = s.root_;
    if (x != NULL) {
      while (x->left != NULL) {
        x = x->left;
      }
    }
    return x;
  }

  // Retorna um ponteiro para o elemento seguinte ao �ltimo elemento
  // do conjunto.
  Node* end(const map& s) {
    return NULL;
  }

  // Dado o n� x, retorna o sucessor de x, ou seja, o n� cuja chave � o menor
  // elemento maior que a chave de x. Caso x seja o maior elemento da �rvore,
  // retorna o n� sentinela.
  Node* next(Node* x, map& s) {
    if (x->right != NULL) {
      x = x->right;
      while (x->left != NULL) {
        x = x->left;
      }
      return x;
    } else {
      Node* y = x->parent;
      while (y != NULL && x == y->right) {
        x = y;
        y = y->parent;
      }
      return y;
    }
  }

  // Dado o n� x, retorna o antecessor de x, ou seja, o n� cuja chave � o menor
  // elemento maior que a chave de x. Caso x seja o menor elemento da �rvore,
  // retorna o n� sentinela.
  Node* prev(Node* x, map& s) {
    if (x == end(s)) {
      x = s.root_;
      while (x->right != NULL) {
        x = x->right;
      }
      return x;
    } else if (x->left != NULL) {
      x = x->left;
      while (x->right != NULL) {
        x = x->right;
      }
      return x;
    } else {
      Node* y = x->parent;
      while (y != NULL && x == y->left) {
        x = y;
        y = y->parent;
      }
      return y;
    }
  }

  // Retorna um ponteiro para o elemento k de s.
  Node* find(SType k, map& s) {
    Node* x = s.root_;
    while (x != NULL && k != x->key) {
      if (k < x->key) {
        x = x->left;
      } else {
        x = x->right;
      }
    }
    return x;
  }

  // Retorna uma string contendo o par <chave,valor> do n� x.
  string ToString(Node* x) {
    stringstream out;
    if (x == NULL) {
      out << "NULL";
    } else {
      out << "<" << x->key << "," << x->value << ">";
    }
    return out.str();
  }

  // Retorna uma string contendo os elementos do conjunto
  // no formato { <k1,v1> <k2,v2> ... <kn,vn> } e ordenados do menor para o maior.
  string ToString(map& s) {
    stringstream out;
    out << "{ ";
    for (Node* i = begin(s); i != end(s); i = next(i, s)) {
      out << ToString(i) << " ";
    }
    out << "}";
    return out.str();
  }
};

TEST_F(Teste, Testa_construtor_vazio) {
  map atual;
  ASSERT_EQ(0, size(atual))
    << "-------------------------------------------------------------------\n"
    << "Erro no construtor: map::map()\n"
    << "-------------------------------------------------------------------\n"
    << " Em um conjunto vazio, size_ = 0\n"
    << "-------------------------------------------------------------------\n";
  ASSERT_EQ(begin(atual), end(atual))
    << "-------------------------------------------------------------------\n"
    << "Erro no construtor: map::map()\n"
    << "-------------------------------------------------------------------\n"
    << " Em um conjunto vazio, map::begin() == map::end()\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_empty_em_conjunto_vazio) {
  map s;
  ASSERT_TRUE(s.empty())
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: bool map::empty() \n"
      << "------------------------------------------------------------------\n"
      << " o conjunto esta vazio e a funcao retornou FALSE.\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_empty_em_conjunto_nao_vazio) {
  map s;
  insert("B", 2, &s);
  insert("A", 1, &s);
  insert("C", 3, &s);
  ASSERT_FALSE(s.empty())
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: bool map::empty() \n"
      << "------------------------------------------------------------------\n"
      << " o conjunto tem pelo menos um elemento e a funcao retornou TRUE.\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_size_em_conjunto_vazio) {
  map s;
  int esperado = 0;
  int atual = s.size();
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: int map::size()\n"
    << "-------------------------------------------------------------------\n"
    << " s = " << ToString(s) << "\n"
    << " \"s.sise()\" retornou: " << atual << "\n"
    << " Valor esperado: " << esperado << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_size_em_conjunto_nao_vazio) {
  map s;
  insert("B", 2, &s);
  insert("A", 1, &s);
  insert("C", 3, &s);
  int atual = s.size();
  int esperado = 3;
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: int map::size()\n"
    << "-------------------------------------------------------------------\n"
    << " s = " << ToString(s) << "\n"
    << " \"s.sise()\" retornou: " << atual << "\n"
    << " Valor esperado: " << esperado << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_begin_em_conjunto_vazio) {
  map s;
  ASSERT_EQ(begin(s), s.begin())
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: Node* map::begin() \n"
      << "------------------------------------------------------------------\n"
      << " s = " << ToString(s) << "\n"
      << " s.begin() nao retornou s.end().\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_begin_em_conjunto_nao_vazio) {
  map s;
  insert("A", 1, &s);
  Node* atual = s.begin();
  Node* esperado = begin(s);
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: Node* map::begin() \n"
      << "------------------------------------------------------------------\n"
      << " s = " << ToString(s) << "\n"
      << " \"s.begin()\" retornou: ponteiro para " << ToString(atual) << "\n"
      << " Valor esperado: ponteiro para " << ToString(esperado) << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_end_em_conjunto_vazio) {
  map s;
  ASSERT_EQ(end(s), s.end())
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: Node* map::end() \n"
      << "------------------------------------------------------------------\n"
      << " s = " << ToString(s) << "\n"
      << " s.end() nao retornou s.begin().\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_end_em_conjunto_nao_vazio) {
  map s;
  insert("A", 1, &s);
  Node* atual = s.end();
  Node* esperado = end(s);
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: Node* map::end() \n"
      << "------------------------------------------------------------------\n"
      << " s = " << ToString(s) << "\n"
      << " \"s.end()\" retornou: ponteiro para " << ToString(atual) << "\n"
      << " Valor esperado: ponteiro para " << ToString(esperado) << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_next_do_primeiro_elemento) {
  map s;
  insert("A", 1, &s);
  insert("B", 2, &s);
  Node* atual = s.next(begin(s));
  Node* esperado = next(begin(s), s);
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: Node* map::next(Node* x) \n"
      << "------------------------------------------------------------------\n"
      << " s = " << ToString(s) << "\n"
      << " \"s.next(s.begin())\" retornou: ponteiro para "
      << ToString(atual) << "\n"
      << " Valor esperado: ponteiro para " << ToString(esperado) << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_next_do_ultimo_elemento) {
  map s;
  insert("A", 1, &s);
  Node* atual = s.next(begin(s));
  Node* esperado = NULL;
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: Node* map::next(Node* x) \n"
      << "------------------------------------------------------------------\n"
      << " s = " << ToString(s) << "\n"
      << " \"s.next(s.begin())\" retornou: ponteiro para "
      << ToString(atual) << "\n"
      << " Valor esperado: ponteiro para " << ToString(esperado) << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_next_com_o_proximo_abaixo) {
  map s;
  Node* c = insert("C", 3, &s);
  Node* a = insert("A", 1, &s);
  Node* d = insert("D", 4, &s);
  Node* b = insert("B", 2, &s);
  Node* atual = s.next(a);
  Node* esperado = b;
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: Node* map::next(Node* x) \n"
      << "------------------------------------------------------------------\n"
      << " s = " << ToString(s) << "\n"
      << " \"s.next(s.find('A'))\" retornou: ponteiro para "
      << ToString(atual) << "\n"
      << " Valor esperado: ponteiro para " << ToString(esperado) << "\n"
      << " DICA: Verifique o caso onde o proximo esta abaixo de 'x'.\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_next_com_o_proximo_acima) {
  map s;
  Node* c = insert("C", 3, &s);
  Node* a = insert("A", 1, &s);
  Node* d = insert("D", 4, &s);
  Node* b = insert("B", 2, &s);
  Node* atual = s.next(b);
  Node* esperado = c;
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: Node* map::next(Node* x) \n"
      << "------------------------------------------------------------------\n"
      << " s = " << ToString(s) << "\n"
      << " \"s.next(s.find('B'))\" retornou: ponteiro para "
      << ToString(atual) << "\n"
      << " Valor esperado: ponteiro para " << ToString(esperado) << "\n"
      << " DICA: Verifique o caso onde o proximo esta abaixo de 'x'.\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_prev_do_primeiro_elemento) {
  map s;
  insert("A", 1, &s);
  insert("B", 2, &s);
  Node* atual = s.prev(begin(s));
  Node* esperado = end(s);
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: Node* map::prev(Node* x) \n"
      << "------------------------------------------------------------------\n"
      << " s = " << ToString(s) << "\n"
      << " \"s.prev(s.begin())\" retornou: ponteiro para "
      << ToString(atual) << "\n"
      << " Valor esperado: ponteiro para " << ToString(esperado) << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_prev_do_end) {
  map s;
  Node* a = insert("A", 1, &s);
  Node* atual = s.prev(end(s));
  Node* esperado = a;
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: Node* map::prev(Node* x) \n"
      << "------------------------------------------------------------------\n"
      << " s = " << ToString(s) << "\n"
      << " \"s.next(s.end())\" retornou: ponteiro para "
      << ToString(atual) << "\n"
      << " Valor esperado: ponteiro para " << ToString(esperado) << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_prev_com_o_anterior_abaixo) {
  map s;
  Node* c = insert("C", 3, &s);
  Node* a = insert("A", 1, &s);
  Node* d = insert("D", 4, &s);
  Node* b = insert("B", 2, &s);
  Node* atual = s.prev(c);
  Node* esperado = b;
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: Node* map::next(Node* x) \n"
      << "------------------------------------------------------------------\n"
      << " s = " << ToString(s) << "\n"
      << " \"s.next(s.find('C'))\" retornou: ponteiro para "
      << ToString(atual) << "\n"
      << " Valor esperado: ponteiro para " << ToString(esperado) << "\n"
      << " DICA: Verifique o caso onde o proximo esta abaixo de 'x'.\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_prev_com_o_proximo_acima) {
  map s;
  Node* c = insert("C", 3, &s);
  Node* a = insert("A", 1, &s);
  Node* d = insert("D", 4, &s);
  Node* b = insert("B", 2, &s);
  Node* atual = s.prev(b);
  Node* esperado = a;
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: Node* map::next(Node* x) \n"
      << "------------------------------------------------------------------\n"
      << " s = " << ToString(s) << "\n"
      << " \"s.next(s.find('B'))\" retornou: ponteiro para "
      << ToString(atual) << "\n"
      << " Valor esperado: ponteiro para " << ToString(esperado) << "\n"
      << " DICA: Verifique o caso onde o proximo esta abaixo de 'x'.\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_find_de_elemento_no_conjunto) {
  map s;
  Node* c = insert("C", 3, &s);
  Node* a = insert("A", 1, &s);
  Node* d = insert("D", 4, &s);
  Node* b = insert("B", 2, &s);
  Node* atual = s.find("B");
  Node* esperado = b;
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: Node* map::find(SType k) \n"
    << "-------------------------------------------------------------------\n"
    << " s = " << ToString(s) << "\n"
    << " 's.find(\"B\")' retornou: ponteiro para " << ToString(atual) << "\n"
    << " Valor esperado: ponteiro para " << ToString(esperado) << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_find_de_elemento_fora_do_conjunto) {
  map s;
  Node* c = insert("C", 3, &s);
  Node* a = insert("A", 1, &s);
  Node* d = insert("D", 4, &s);
  Node* b = insert("B", 2, &s);
  Node* atual = s.find("X");
  Node* esperado = end(s);
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: Node* map::find(SType k) \n"
    << "-------------------------------------------------------------------\n"
    << " s = " << ToString(s) << "\n"
    << " 's.find(\"E\")' retornou: ponteiro para " << ToString(atual) << "\n"
    << " Valor esperado: ponteiro para " << ToString(esperado) << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_operador_at_para_atribuicao) {
  map atual;
  insert("A", 1, &atual);
  insert("B", 2, &atual);
  insert("C", 3, &atual);
  atual["B"] = -2;
  map esperado;
  insert("A", 1, &esperado);
  insert("B", -2, &esperado);
  insert("C", 3, &esperado);
  ASSERT_EQ(ToString(atual), ToString(esperado))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: SType& map::operator[](Node* x)\n"
    << "-------------------------------------------------------------------\n"
    << " s = " << ToString(atual) << "\n"
    << " \"s[\"B\"] = -2\" resultou em: s = " << ToString(atual) << "\n"
    << " Valor esperado: " << ToString(esperado) << "\n"
    << "-------------------------------------------------------------------\n";
}


TEST_F(Teste, Testa_incremento_do_size_na_funcao_insert) {
  map s;
  s.insert("A", 1);
  int atual = size(s);
  int esperado = 1;
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void map::insert(SType k) *\n"
      << "------------------------------------------------------------------\n"
      << " s = { } \n"
      << " 's.insert(\"A\",1)' resultou em: s.size() == " << atual << "\n"
      << " Resultado esperado: s.size() == " << esperado << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_insert_em_conjunto_vazio) {
  map atual;
  atual.insert("A", 1);
  map esperado;
  insert("A", 1, &esperado);
  ASSERT_EQ(ToString(esperado), ToString(atual))
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void map::insert(SType k) *\n"
      << "------------------------------------------------------------------\n"
      << " s = { } \n"
      << " 's.insert(\"A,1\")' resultou em: s = " << ToString(atual) << "\n"
      << " Resultado esperado: s = " << ToString(esperado) << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_insert_em_conjunto_nao_vazio) {
  map atual;
  insert("D", 4, &atual);
  insert("A", 1, &atual);
  insert("C", 3, &atual);
  map original;
  insert("D", 4, &original);
  insert("A", 1, &original);
  insert("C", 3, &original);
  map esperado;
  insert("D", 4, &esperado);
  insert("A", 1, &esperado);
  insert("C", 3, &esperado);
  insert("B", 2, &esperado);
  atual.insert("B", 2);
  ASSERT_EQ(ToString(esperado), ToString(atual))
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void map::insert(SType k) *\n"
      << "------------------------------------------------------------------\n"
      << " s = " << ToString(original) << "\n"
      << " 's.insert(\"B\",2)' resultou em: s = " << ToString(atual) << "\n"
      << " Resultado esperado: s = " << ToString(esperado) << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_insert_com_atualizacao_de_valor) {
  map atual;
  insert("D", 4, &atual);
  insert("A", 1, &atual);
  insert("C", 3, &atual);
  insert("B", 2, &atual);
  map original;
  insert("D", 4, &original);
  insert("A", 1, &original);
  insert("C", 3, &original);
  insert("B", 2, &original);
  map esperado;
  insert("D", 4, &esperado);
  insert("A", 1, &esperado);
  insert("C", 3, &esperado);
  insert("B", -2, &esperado);
  atual.insert("B", -2);
  ASSERT_EQ(ToString(esperado), ToString(atual))
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void map::insert(SType k) *\n"
      << "------------------------------------------------------------------\n"
      << " s = " << ToString(original) << "\n"
      << " 's.insert(\"B\",-2)' resultou em: s = " << ToString(atual) << "\n"
      << " Resultado esperado: s = " << ToString(esperado) << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_decremento_do_size_na_funcao_erase) {
  map s;
  insert("A", 1, &s);
  s.erase("A");
  int atual = size(s);
  int esperado = 0;
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void map::insert(SType k) *\n"
      << "------------------------------------------------------------------\n"
      << " s = { <A,1> } \n"
      << " \"s.erase(A)\" resultou em: s.size() == " << atual << "\n"
      << " Resultado esperado: s.size() == " << esperado << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_erase_em_conjunto_unitario) {
  map atual;
  insert("A", 1, &atual);
  map original;
  insert("A", 1, &original);
  map esperado;
  atual.erase("A");
  ASSERT_EQ(ToString(esperado), ToString(atual))
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void map::erase(SType k) *\n"
      << "------------------------------------------------------------------\n"
      << " s = " << ToString(original) << " \n"
      << " 's.erase(\"A\")\' resultou em: s = " << ToString(atual) << "\n"
      << " Resultado esperado: s = " << ToString(esperado) << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_erase_de_no_com_dois_filhos) {
  map atual;
  insert("B", 2, &atual);
  insert("A", 1, &atual);
  insert("D", 4, &atual);
  insert("C", 3, &atual);
  map original;
  insert("B", 2, &original);
  insert("A", 1, &original);
  insert("D", 4, &original);
  insert("C", 3, &original);
  map esperado;
  insert("A", 1, &esperado);
  insert("D", 4, &esperado);
  insert("C", 3, &esperado);
  atual.erase("B");
  ASSERT_EQ(ToString(esperado), ToString(atual))
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void map::erase(SType k) *\n"
      << "------------------------------------------------------------------\n"
      << " s = " << ToString(original) << " \n"
      << " 's.erase(\"B\")\' resultou em: s = " << ToString(atual) << "\n"
      << " Resultado esperado: s = " << ToString(esperado) << "\n"
      << "------------------------------------------------------------------\n";
}


TEST_F(Teste, Testa_funcao_erase_de_no_sem_subarvore_direita) {
  map atual;
  insert("B", 2, &atual);
  insert("A", 1, &atual);
  insert("D", 4, &atual);
  insert("C", 3, &atual);
  map original;
  insert("B", 2, &original);
  insert("A", 1, &original);
  insert("D", 4, &original);
  insert("C", 3, &original);
  map esperado;
  insert("B", 2, &esperado);
  insert("A", 1, &esperado);
  insert("C", 3, &esperado);
  atual.erase("D");
  ASSERT_EQ(ToString(esperado), ToString(atual))
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void map::erase(SType k) *\n"
      << "------------------------------------------------------------------\n"
      << " s = " << ToString(original) << " \n"
      << " 's.erase(\"B\")\' resultou em: s = " << ToString(atual) << "\n"
      << " Resultado esperado: s = " << ToString(esperado) << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_erase_em_no_sem_subarvore_esquerda) {
  map atual;
  insert("B", 2, &atual);
  insert("A", 1, &atual);
  insert("D", 4, &atual);
  insert("C", 3, &atual);
  map original;
  insert("B", 2, &original);
  insert("A", 1, &original);
  insert("D", 4, &original);
  insert("C", 3, &original);
  map esperado;
  insert("B", 2, &esperado);
  insert("D", 4, &esperado);
  insert("C", 3, &esperado);
  atual.erase("A");
  ASSERT_EQ(ToString(esperado), ToString(atual))
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void map::erase(SType k) *\n"
      << "------------------------------------------------------------------\n"
      << " s = " << ToString(original) << " \n"
      << " 's.erase(\"A\")\' resultou em: s = " << ToString(atual) << "\n"
      << " Resultado esperado: s = " << ToString(esperado) << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_erase_de_elemento_que_nao_pertence_ao_conjunto) {
  map atual;
  insert("B", 2, &atual);
  insert("A", 1, &atual);
  insert("D", 4, &atual);
  insert("C", 3, &atual);
  map original;
  insert("B", 2, &original);
  insert("A", 1, &original);
  insert("D", 4, &original);
  insert("C", 3, &original);
  map esperado;
  insert("B", 2, &esperado);
  insert("A", 1, &esperado);
  insert("D", 4, &esperado);
  insert("C", 3, &esperado);
  atual.erase("X");
  ASSERT_EQ(ToString(esperado), ToString(atual))
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void map::erase(SType k) *\n"
      << "------------------------------------------------------------------\n"
      << " s = " << ToString(original) << " \n"
      << " 's.erase(\"B\")\' resultou em: s = " << ToString(atual) << "\n"
      << " Resultado esperado: s = " << ToString(esperado) << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Clear) {
  map atual;
  insert("B", 2, &atual);
  insert("A", 1, &atual);
  insert("C", 3, &atual);
  map original;
  insert("B", 2, &original);
  insert("A", 1, &original);
  insert("C", 3, &original);
  map esperado;
  atual.clear();
  ASSERT_EQ(ToString(esperado), ToString(atual))
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void map::clear() \n"
      << "------------------------------------------------------------------\n"
      << " s = " << ToString(original) << " \n"
      << " 's.erase(\"B\")\' resultou em: s = " << ToString(atual) << "\n"
      << " Resultado esperado: s = " << ToString(esperado) << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_operador_de_atribuicao_a_conjunto_vazio) {
  map original;
  insert("B", 2, &original);
  insert("A", 1, &original);
  insert("C", 3, &original);
  map esperado;
  insert("B", 2, &esperado);
  insert("A", 1, &esperado);
  insert("C", 3, &esperado);
  map atual;
  atual = original;
  ASSERT_EQ(ToString(esperado), ToString(atual))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: void map::operator=(map& s)\n"
    << "-------------------------------------------------------------------\n"
    << " u = " << "{ }" << " \n"
    << " s = " << ToString(original) << "\n"
    << " \"u = s\" resultou em: u = " << ToString(atual) << "\n"
    << " Resultado esperado: u = " << ToString(esperado) << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_operador_de_atribuicao_a_conjunto_nao_vazio) {
  map original;
  insert("B", 2, &original);
  insert("A", 1, &original);
  insert("C", 3, &original);
  map esperado;
  insert("B", 2, &esperado);
  insert("A", 1, &esperado);
  insert("C", 3, &esperado);
  map atual;
  insert("D", 4, &atual);
  atual = original;
  ASSERT_EQ(ToString(esperado), ToString(atual))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: void map::operator=(map& s)\n"
    << "-------------------------------------------------------------------\n"
    << " u = " << "{ <D,4> }" << " \n"
    << " s = " << ToString(original) << "\n"
    << " \"u = s\" resultou em: u = " << ToString(atual) << "\n"
    << " Resultado esperado: u = " << ToString(esperado) << "\n"
    << "-------------------------------------------------------------------\n";
}

#endif  // TRUNK_ORDERED_MAP_WITH_BST_TEST_MAP_TEST_H_
