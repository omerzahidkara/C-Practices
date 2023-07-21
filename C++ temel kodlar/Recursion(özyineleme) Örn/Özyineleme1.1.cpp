#include <iostream>
using namespace std;

//Faktöriyel hesabı yapmak için 1 tane geriye sararak döngü yapan for döngüsü kullanılarak oluşturulan fonkisyon.

int donguile(int sayi)
{
	int sonuc = 1;
	for(int i = sayi;i>1;i--)
	{
		sonuc=sonuc*i;	
		// return sonuc buraya yazılırsa döngüden maindeki sonuc 6 oalrak hemen çıkıyor.	
	}
	return sonuc;
}

int main()
{ 
	int faktoriyeli_istenen_sayi = 6;
	int sonuc = donguile(faktoriyeli_istenen_sayi);
	cout << sonuc ;
	
	return 0;
}