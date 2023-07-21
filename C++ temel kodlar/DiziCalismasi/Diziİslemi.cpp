#include <iostream>
using namespace std;

void DiziElemanDegeriArttir(int *p,int indeks)// Bu fonkisyon atanmış dizinin her elemanını 1 arttırır.
{
	for(int i=0;i<boyut;i++)
	{
		p[i]++;//++ operatorü referans pointerın ya da dizinin döndürülen indeksindeki elemanı eşitlik operatörü kullanımından bağımsız arttırır.
	}
}

void DiziElemanlariVeAdresleriYazdir(int *p, int indeks)// Bu fonksiyon atanmış dizinin her elemanını ve adresini sırayla yazdırır.
{
	for(int i=0;i<indeks;i++)
	{
		cout<<"Adres("<<i+1<<"):"<<p+i << "Eleman ("<<i+1<<")"<< *(p+i)<<endl;	
	}
}

int main()
{
	int sayilar[] = {1,2,3,4,5}; // dizinin indeksi belirtilmese bile dizinin içeriği yerleştirildiyse indeks otomatik belirlenir.
	
	return 0;
}