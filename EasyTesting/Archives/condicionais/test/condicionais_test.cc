// copyright 2014 Universidade Federal de Minas Gerais (UFMG)

#include "test/condicionais_test.h"
#include "../doctest/doctest.h"



int main(int argc, char** argv) {
    doctest::Context context;

    // Aplica as opções de linha de comando do Doctest
    context.applyCommandLine(argc, argv);

    // Executa todos os testes
    int result = context.run();

    // Retorna o resultado da execução dos testes
    return result;
}
