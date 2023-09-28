// Copyright 2010 Universidade Federal de Minas Gerais (UFMG)

#include "agenda/test/agenda_test.h"

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    testing::GTEST_FLAG(print_time) = false;
    return RUN_ALL_TESTS();
}
