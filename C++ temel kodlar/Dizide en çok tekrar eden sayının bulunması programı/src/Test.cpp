#include "radix.hpp"
#include "queue.hpp"
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int sayilar[] = {10,11,40,89,89,40,10,20,55,31,40,67,20,40,11,40,30,40,21,55};
	int diziBoyutu = sizeof(sayilar) / sizeof(sayilar[0]);
	radix *radixNesnesi = new radix(sayilar,diziBoyutu);
	int *sirali = radixNesnesi->sort();
	int adet1 = 1;
	int adet2 = 1;
	int sayi1 = 0;
	int sayiBulma = 0;
	int sayi2 = 0;
	int enYuksekSayi = 0;
	int enYuksekSayiAdedi = 0;
	while(diziBoyutu != 1)
	{
		sayi1 = sirali[diziBoyutu];
		sayiBulma = sirali[diziBoyutu-1];
		if(sayi1 == sayiBulma)
		{
			adet1++;
			if(adet1 > enYuksekSayiAdedi)
			{
				enYuksekSayiAdedi = adet1;
				enYuksekSayi = sayi1;
				cout<<endl<<"En yuksek adet kaydediliyor:" << enYuksekSayiAdedi << endl;
			}
		}
		else
		{
			sayi2 = sayi1;
			adet2 = adet1;
			adet1 = 1;
		}
		diziBoyutu--;
	}
	cout << "En yuksek sayi ve adedi: " << enYuksekSayi << " | " << enYuksekSayiAdedi << endl;
	delete [] sirali;
	delete radixNesnesi;
	system("PAUSE");
	return 0;
}