// copyright 2023 Universidade Federal de Minas Gerais (UFMG)

#include <iostream>
#include <string>
#include "./src/shoppingCart.h"
using std::cin;
using std::cout;
using std::endl;

int main() {

  adicionarProduto("Arroz", 5.0, 10);
  adicionarProduto("Feijão", 4.0, 5);
  adicionarProduto("Macarrão", 2.5, 2);

  cout << "Valor total: " << getValorTotal() << endl;
  cout << "Número de itens: " << getNumeroItens() << endl;

  retirarProduto("Arroz");

  cout << "Valor total: " << getValorTotal() << endl;
  cout << "Número de itens: " << getNumeroItens() << endl;

  return 0;
}