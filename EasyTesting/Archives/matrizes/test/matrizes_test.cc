// Copyright 2014 Universidade Federal de Minas Gerais (UFMG)

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "Archives/doctest/doctest.h"

int main(int argc, char** argv) {
    doctest::Context context;
    context.setOption("no-breaks", true);
    context.setOption("no-timeouts", true);
    context.applyCommandLine(argc, argv);
    int res = context.run();
    return res;
}