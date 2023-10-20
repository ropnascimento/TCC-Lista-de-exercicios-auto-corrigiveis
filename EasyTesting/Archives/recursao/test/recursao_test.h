// Copyright 2014 Universidade Federal de Minas Gerais (UFMG)

#define TRUNK_RECURSAO_TEST_RECURSAO_TEST_H_


#include "Archives/doctest/doctest.h"
#include "src/recursao.h"

using std::string;
using std::stringstream;

TEST_CASE("Teste_Fatorial") {
    int esperado[] = {1, 1, 720};
    int entrada[] = {1, 0, 6};
    int num_testes = 3;

    for (int i = 0; i < num_testes; i++) {
        CHECK(esperado[i] == fat(entrada[i));
        if (esperado[i] != fat(entrada[i])) {
            WARN("---------------------------------------------------");
            WARN("Erro na função: int fat(int)");
            WARN("---------------------------------------------------");
            WARN("Valor de entrada : " << entrada[i]);
            WARN("Resultado esperado : " << esperado[i]);
            WARN("Resultado retornado : " << fat(entrada[i]));
            WARN("---------------------------------------------------");
        }
    }
}

TEST_CASE("Teste_Potenciacao") {
    int esperado[] = {1, 16, -1, 9};
    int entrada1[] = {5, -2, -1, 3};
    int entrada2[] = {0, 4, 3, 2};
    int num_testes = 4;
    for (int i = 0; i < num_testes; i++) {
        CHECK(esperado[i] == pow(entrada1[i], entrada2[i]);
        if (esperado[i] != pow(entrada1[i], entrada2[i])) {
            WARN("---------------------------------------------------");
            WARN("Erro na função: int pow(int, int)");
            WARN("---------------------------------------------------");
            WARN("Valores de entrada : " << entrada1[i] << " elevado a " << entrada2[i]);
            WARN("Resultado esperado : " << esperado[i]);
            WARN("Resultado retornado : " << pow(entrada1[i], entrada2[i]));
            WARN("---------------------------------------------------");
        }
    }
}

TEST_CASE("Teste_MDC_entre_dois_numeros") {
    int esperado[] = {11, 9, 1, 4};
    int entrada1[] = {11, 9, 11, 28};
    int entrada2[] = {11, 27, 13, 20};
    int num_testes = 4;
    for (int i = 0; i < num_testes; i++) {
        CHECK(esperado[i] == mdc(entrada1[i], entrada2[i]));
        if (esperado[i] != mdc(entrada1[i], entrada2[i])) {
            WARN("---------------------------------------------------");
            WARN("Erro na função: int mdc(int, int)");
            WARN("---------------------------------------------------");
            WARN("Valores de entrada : " << entrada1[i] << " e " << entrada2[i]);
            WARN("Resultado esperado : " << esperado[i]);
            WARN("Resultado retornado : " << mdc(entrada1[i], entrada2[i]));
            WARN("---------------------------------------------------");
        }
    }
}

TEST_CASE("Teste_MDC_entre_tres_numeros") {
    int esperado[] = {10, 10, 1, 1, 3};
    int entrada1[] = {10, 10, 17, 23, 9};
    int entrada2[] = {10, 10, 41, 27, 6};
    int entrada3[] = {10, 50, 13, 45, 12};
    int num_testes = 5;
    for (int i = 0; i < num_testes; i++) {
        CHECK(esperado[i] == mdc3(entrada1[i], entrada2[i], entrada3[i]));
        if (esperado[i] != mdc3(entrada1[i], entrada2[i], entrada3[i])) {
            WARN("---------------------------------------------------");
            WARN("Erro na função: int mdc3(int, int, int)");
            WARN("---------------------------------------------------");
            WARN("Valores de entrada : " << entrada1[i] << ", " << entrada2[i] << " e " << entrada3[i]);
            WARN("Resultado esperado : " << esperado[i]);
            WARN("Resultado retornado : " << mdc3(entrada1[i], entrada2[i], entrada3[i]));
            WARN("---------------------------------------------------");
        }
    }
}

TEST_CASE("Teste_MMC") {
    int esperado[] = {10, 27, 21, 30};
    int entrada1[] = {10, 3, 1, 6};
    int entrada2[] = {10, 27, 21, 10};
    int num_testes = 4;
    for (int i = 0; i < num_testes; i++) {
        CHECK(esperado[i] == mmc(entrada1[i], entrada2[i]));
        if (esperado[i] != mmc(entrada1[i], entrada2[i])) {
            WARN("---------------------------------------------------");
            WARN("Erro na função: int mmc(int, int)");
            WARN("---------------------------------------------------");
            WARN("Valores de entrada : " << entrada1[i] << " e " << entrada2[i]);
            WARN("Resultado esperado : " << esperado[i]);
            WARN("Resultado retornado : " << mmc(entrada1[i], entrada2[i]);
            WARN("---------------------------------------------------");
        }
    }
}

TEST_CASE("Teste_sequencia_de_Fibonacci") {
    int esperado[] = {0, 1, 3};
    int entrada[] = {0, 1, 4};
    int num_testes = 3;
    for (int i = 0; i < num_testes; i++) {
        CHECK(esperado[i] == fib(entrada[i]);
        if (esperado[i] != fib(entrada[i])) {
            WARN("---------------------------------------------------");
            WARN("Erro na função: int fib(int)");
            WARN("---------------------------------------------------");
            WARN("Valores de entrada : " << entrada[i]);
            WARN("Resultado esperado : " << esperado[i]);
            WARN("Resultado retornado : " << fib(entrada[i]));
            WARN("---------------------------------------------------");
        }
    }
}

TEST_CASE("Teste_da_Resto") {
    int esperado[] = {3, 0, 0, 5};
    int entrada1[] = {3, 4, 9, 15};
    int entrada2[] = {4, 4, 3, 10};
    int num_testes = 4;
    for (int i = 0; i < num_testes; i++) {
        CHECK(esperado[i] == resto(entrada1[i], entrada2[i]);
        if (esperado[i] != resto(entrada1[i], entrada2[i])) {
            WARN("---------------------------------------------------");
            WARN("Erro na função: int resto(int, int)");
            WARN("---------------------------------------------------");
            WARN("Valores de entrada : " << entrada1[i] << " dividido por " << entrada2[i]);
            WARN("Resultado esperado : " << esperado[i]);
            WARN("Resultado retornado : " << resto(entrada1[i], entrada2[i]);
            WARN("---------------------------------------------------");
        }
    }
}

TEST_CASE("Teste_da_Divisao_inteira") {
    int esperado[] = {0, 1, 3, 1};
    int entrada1[] = {3, 4, 9, 15};
    int entrada2[] = {4, 4, 3, 10};
    int num_testes = 4;
    for (int i = 0; i < num_testes; i++) {
        CHECK(esperado[i] == div_(entrada1[i], entrada2[i]);
        if (esperado[i] != div_(entrada1[i], entrada2[i])) {
            WARN("---------------------------------------------------");
            WARN("Erro na função: int div_(int, int)");
            WARN("---------------------------------------------------");
            WARN("Valores de entrada : " << entrada1[i] << " dividido por " << entrada2[i]);
            WARN("Resultado esperado : " << esperado[i]);
            WARN("Resultado retornado : " << div_(entrada1[i], entrada2[i]);
            WARN("---------------------------------------------------");
        }
    }
}

