#include "radix.hpp"
#include <cmath>
#include <iostream>
using namespace std;

int radix::maxBasamakSayisi()
{
	int max=0;
	for(int i=0;i<boyut;i++)
	{
		if(basamakSay(sayilar[i])>max) 
			max = basamakSay(sayilar[i]);
	}
	return max;
}
int radix::basamakSay(int sayi)
{
	sayi = abs(sayi);
	int basamak=0;
	while(sayi>0)
	{
		basamak++;
		sayi /= 10;
	}
	return basamak;
}
radix::radix(int *sayilar, int boyut)
{
	this->sayilar = new int[boyut];
	this->boyut = boyut;
	for(int i=0;i<boyut;i++)
	{ 
		this->sayilar[i] = sayilar[i]; 
	}
	kuyruklar = new queue *[10];
	for(int j=0;j<10;j++)
	{ 
		kuyruklar[j] = new queue(); 
	}
	maxBasamak = maxBasamakSayisi();
}
int* radix::queueAndakiBoyut()
{
	int *boyutlar = new int[10];
	for(int i=0;i<10;i++)
	{
		boyutlar[i] = kuyruklar[i]->say();
	}
	return boyutlar;
}
int* radix::sort()
{
	int sayiIndex=0;
	
	for(;sayiIndex<boyut;sayiIndex++)
	{
		int basamakDegeri = sayilar[sayiIndex]%10;
		int deger = sayilar[sayiIndex];
		kuyruklar[basamakDegeri]->ekle(deger);
	}			
	for(int i=1;i<maxBasamak;i++)
	{		
		int *kuyrukBoyutlar = queueAndakiBoyut();
		for(int index=0;index<10;index++)
		{
			int len = kuyrukBoyutlar[index];
			for(;len>0;len--)
			{
				int sayi = kuyruklar[index]->getir();
				cout << sayi << " ";
				kuyruklar[index]->eksilt();
				int basamakDegeri = (sayi/(int)pow(10,i))%10;	
				kuyruklar[basamakDegeri]->ekle(sayi);				
			}
			cout << endl;
		}
		cout << "-------------------" << endl;
		delete [] kuyrukBoyutlar;
	}
	int* siralanmis = new int[boyut];
	sayiIndex=0;
	for(int index=0;index<10;index++)
	{
		while(!kuyruklar[index]->bosMu())
		{
			int sayi = kuyruklar[index]->getir();
			cout << sayi << " ";
			siralanmis[sayiIndex++] = sayi;
			kuyruklar[index]->eksilt();
		}
		cout << "----------------------------" << endl;
	}
		
	return siralanmis;
}
radix::~radix()
{	
	delete [] sayilar;
	for(int i=0;i<10;i++) delete kuyruklar[i];
	delete [] kuyruklar;
}
