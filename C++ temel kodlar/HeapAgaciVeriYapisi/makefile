all: derle bagla calistir
derle:
	g++ -c -I "./include" ./src/test.cpp -o ./lib/test.o
	g++ -c -I "./include" ./src/dugum.cpp -o ./lib/dugum.o
	g++ -c -I "./include" ./src/agac.cpp -o ./lib/agac.o
bagla:
	g++ ./lib/test.o ./lib/dugum.o ./lib/agac.o -o ./bin/program
calistir:
	./bin/program