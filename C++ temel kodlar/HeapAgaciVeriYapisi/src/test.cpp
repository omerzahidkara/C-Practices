#include <iostream>
#include "agac.hpp"
using namespace std;

int main()
{
	agac *agacNesnesi = new agac();
	agacNesnesi->ekle(15);
	agacNesnesi->ekle(9);
	agacNesnesi->ekle(65);
	agacNesnesi->ekle(98);
	agacNesnesi->sirala();
	
	
	return 0;
}