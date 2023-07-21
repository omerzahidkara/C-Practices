#include <iostream>
using namespace std;

template <typename Tur>
Tur topla(Tur deger1, Tur deger2)
{
	return deger1+deger2;
}

int main(){
	int sayi1=23, sayi2 = 42;
	cout<< topla(sayi1, sayi2);
	cout<<endl;
	float sayi3 = 20.4,sayi4 = 71.3;
	cout<< topla(sayi3, sayi4);
	
	return 0;
	
}