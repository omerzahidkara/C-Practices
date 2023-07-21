#include "agac.hpp"
#include <iostream>
using namespace std;

agac::agac()
{
	ES = 0;
}
int agac::solCocukIndeksiGetir(int i)
{
	return 2*i+1;
}
int agac::sagCocukIndeksiGetir(int i)
{
	return 2*i+2;
}
int agac::ebeveynIndeksiGetir(int i)
{
	return (i-1)/2;
}
void agac::ekle(int e)
{
	if(ES == MAX) return;
	veriler[ES] = e;
	ES ++;
	heapIfyUp(ES-1); 
}
void agac::heapIfyUp(int i)
{
	if(i==0) return;
	int eb = ebeveynIndeksiGetir(i);
	if(veriler[eb]>veriler[i])
	{
		int temp = veriler[i];
		veriler[i] = veriler[eb];
		veriler[eb] = temp;
		heapIfyUp(eb);
	}
}
void agac::cikar()
{
	if(ES == 0) return;
	veriler[0] = veriler[ES-1];
	ES--;
	heapIfyDown(0);
}
void agac::heapIfyDown(int i)
{
	int solu = solCocukIndeksiGetir(i);
	int sagi = sagCocukIndeksiGetir(i);
	int min;
	if(sagi >= ES)
	{
		if(solu >= ES) return;
		else min = solu;
	}
	else
	{
		if(veriler[solu]<veriler[sagi])
		{
			min = solu;
		}
		else
		{
			min = sagi;
		}
	}
	if(veriler[min]<veriler[i])
	{
		int temp = veriler[i];
		veriler[i] = veriler[min];
		veriler[min] = temp;
		heapIfyDown(min);
	}
}
int agac::getir()
{
	return veriler[0];
}
void agac::sirala()
{
	int *sira = new int[ES];
	int siraSayisi = ES;
	for(int i=0;i < siraSayisi; i++)
	{
		sira[i] = getir();
		cikar();
	}
	for(int i=0;i < siraSayisi; i++)
	{
		cout << sira[i] << " " ;
	}
	delete [] sira;
}