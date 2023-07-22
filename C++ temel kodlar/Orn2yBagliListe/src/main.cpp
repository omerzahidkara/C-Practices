#include <iostream>
#include <iomanip>
#include "Liste.hpp"
using namespace std;

int main()
{
	Liste* liste = new Liste();
	liste ->ekle(11);
	liste ->ekle(17);
	liste ->ekle(87);
	liste ->ekle(101);
	cout<<*liste;
	liste ->onuneEkle(0,69);
	cout<<*liste;
	liste ->cikar(2);
	cout<<*liste;
	
	delete liste;
	system("PAUSE");
}