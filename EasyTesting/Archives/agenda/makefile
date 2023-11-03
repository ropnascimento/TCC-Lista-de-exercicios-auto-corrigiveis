# Compilador utilizado
cc = g++
# PATH raiz para includes
path = .
# Nome da lista de exercicios
program = agenda

# Gera o binário do programa e de testes e mantém dependências
all: clean main.o $(program).o $(program)_test.o
	$(cc) -I $(path) -L/home/rafael/Documentos/UFMG/TCC/TCC-Lista-de-exercicios-auto-corrigiveis/EasyTesting/Archives/doctest/lib -ldoctest main.o $(program).o -o main
	$(cc) -I $(path) -L/home/rafael/Documentos/UFMG/TCC/TCC-Lista-de-exercicios-auto-corrigiveis/EasyTesting/Archives/doctest/lib -ldoctest $(program).o $(program)_test.o -o easy_testing
	@echo "--------------------------------------------------------------"
	@echo "main: executa o programa em main.cc."
	@echo "easy_testing: testa as funções implementadas em $(program).cc."
	@echo "--------------------------------------------------------------"

# Roda o programa e deleta dependências e o binário
run: clean main.o $(program).o
	$(cc) -I $(path) -L/home/rafael/Documentos/UFMG/TCC/TCC-Lista-de-exercicios-auto-corrigiveis/EasyTesting/Archives/doctest/lib -ldoctest main.o $(program).o
	@./main
	@rm -f $(program).o main

# Roda testes e deleta dependências e o binário
test: clean $(program).o $(program)_test.o
	$(cc) -I $(path) -L../EasyTesting/Archives/doctest/ -ldoctest -lstdc++ -WL,--whole-archive   $(program).o $(program)_test.o
	@./a.out
	@rm -f $(program).o $(program)_test.o a.out

main.o:
	$(cc) -I $(path) -c src/main.cc

$(program).o:
	$(cc) -I $(path) -c src/$(program).cc

# Adicionando a flag -std=c++11 para compatibilidade com o Doctest
$(program)_test.o:
	$(cc) -I $(path) -c test/$(program)_test.cc -std=c++11  

clean:
	@rm -f main.o $(program).o $(program)_test.o a.out

zip:
	zip -r $(CURDIR).zip . -x ".*"