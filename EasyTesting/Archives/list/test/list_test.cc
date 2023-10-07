// Copyright 2014 Universidade Federal de Minas Gerais (UFMG)

#include "Archives/doctest/doctest.h"

int main(int argc, char** argv) {
    doctest::Context context(argc, argv);
    context.setOption("no-breaks", true); 

    int result = context.run();

    return result;
}