#include "Huffman.hpp"

int main(){
	Huffman *huffman = new Huffman("dene.txt");
	huffman->Kodla();
	cout<<*huffman;
	system("PAUSE");
	delete huffman;
	return 0;
}