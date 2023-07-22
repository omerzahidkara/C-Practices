#include <iostream>
#include "BagliListe.hpp"
int main()
{
	BagliListe* b = new BagliListe();
	b->ekle(11*1);
	b->ekle(11*2);
	b->ekle(11*3);
	b->ekle(11*4);
	b->ekle(11*5);
	b->ekle(11*6);
	
	b->yazdir();
	system("PAUSE");
}