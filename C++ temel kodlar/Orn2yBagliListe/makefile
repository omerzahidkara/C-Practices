all: derle bagla calistir
derle:
	g++ -c -I "./include" ./src/main.cpp -o ./lib/main.o
	g++ -c -I "./include" ./src/Dugum.cpp -o ./lib/Dugum.o
	g++ -c -I "./include" ./src/Liste.cpp -o ./lib/Liste.o
bagla:
	g++ ./lib/main.o ./lib/Dugum.o ./lib/Liste.o -o ./bin/program
calistir:
	./bin/program	