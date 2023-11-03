cmake_minimum_required(VERSION 3.10)

project(condicionais)

set(CMAKE_PREFIX_PATH /home/rafael/Documentos/UFMG/TCC/TCC-Lista-de-exercicios-auto-corrigiveis/EasyTesting/Archives/doctest)
set(doctest_DIR /home/rafael/Documentos/UFMG/TCC/TCC-Lista-de-exercicios-auto-corrigiveis/EasyTesting/Archives/doctest)

set(CMAKE_CXX_STANDARD 11)

find_package(doctest REQUIRED)

add_executable(main src/main.cc)
target_link_libraries(main doctest)

add_executable(condicionais_test test/condicionais_test.cc)
target_link_libraries(condicionais_test doctest)
