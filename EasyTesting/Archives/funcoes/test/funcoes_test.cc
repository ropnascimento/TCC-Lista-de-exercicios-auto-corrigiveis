// copyright 2014 Universidade Federal de Minas Gerais (UFMG)

#include "test/funcoes_test.h"
#include "Archives/doctest/doctest.h"

int main() {

    doctest::Context context;
    context.addFilter(".*"); // Inclui todos os testes
    context.run(); // Executa todos os testes.
    return context.shouldExit() ? context.exit() : 0;
}
