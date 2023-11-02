// copyright 2014 Universidade Federal de Minas Gerais (UFMG)

#include "test/condicionais_test.h"
#include "../doctest/doctest.h"

// Definição da função doctest::detail::MessageBuilder::MessageBuilder()

doctest::detail::MessageBuilder::MessageBuilder(char const* file, int line, int assertionType) {
    this->m_file = file;
    this->m_line = line;
    this->m_assertType = assertionType;
}

// Definition of the doctest::detail::MessageBuilder::~MessageBuilder() function

doctest::detail::MessageBuilder::~MessageBuilder() {}

int main(int argc, char** argv) {
    doctest::Context context;

    // Aplica as opções de linha de comando do Doctest
    context.applyCommandLine(argc, argv);

    // Executa todos os testes
    int result = context.run();

    // Retorna o resultado da execução dos testes
    return result;
}
