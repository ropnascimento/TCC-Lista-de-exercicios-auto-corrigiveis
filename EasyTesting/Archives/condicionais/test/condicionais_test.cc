// copyright 2014 Universidade Federal de Minas Gerais (UFMG)

#include "test/condicionais_test.h"
#include "doctest.h"

int main() {
    doctest::Context context;
    context.addFilter(".*"); // Inclui todos os testes, você pode personalizar isso se desejar.
    context.run(); // Executa todos os testes.

    return context.shouldExit() ? context.exit() : 0;
}