#include <iostream>
using namespace std;

int ozyinelemeile(int sayi)
{
	if(sayi == 2) return 2;
	return sayi*ozyinelemeile(sayi-1);
}

int main()
{
	int sayi = ozyinelemeile(4);
	cout << sayi;
	return 0;
}