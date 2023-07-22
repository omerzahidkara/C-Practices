all: derle bagla calistir
derle:
	g++ -c -I "./include" ./src/Test.cpp -o ./lib/Test.o
	g++ -c -I "./include" ./src/radix.cpp -o ./lib/radix.o
	g++ -c -I "./include" ./src/queue.cpp -o ./lib/queue.o
	g++ -c -I "./include" ./src/queueNode.cpp -o ./lib/queueNode.o
bagla:
	g++ ./lib/Test.o ./lib/radix.o ./lib/queue.o ./lib/queueNode.o -o ./bin/program
calistir:
	./bin/program	