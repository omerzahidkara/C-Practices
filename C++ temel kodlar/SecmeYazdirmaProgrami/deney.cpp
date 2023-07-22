#include <iomanip>
#include <iostream>
#include <fstream>
using namespace std;
void cizgiCizdir(int adet)
{
	for(int i = 0;i<adet;i++)
	{ 
		cout<<"---------  ";
				
	}
	cout<<endl;	
}
void degerYazdir(int adet)
{
	for(int i = 0;i<adet;i++)
	{ 
		cout<<setw(9)<<i<<"  ";
				
	}
	cout<<endl;
}
void boslukBirak(int sira)
{
	cout<<setw(11*sira)<<"";
}
int main()
{
	int sira = 0;
	while(true)
	{
		system("cls");
		int dugumSayisi = 8;
		cizgiCizdir(dugumSayisi);
		degerYazdir(dugumSayisi);
		cizgiCizdir(dugumSayisi);
	
		boslukBirak(sira);cout<<"*********"<<endl;
		boslukBirak(sira);cout<<"*********"<<endl;
		boslukBirak(sira);cout<<"*********"<<endl;
		boslukBirak(sira);cout<<"*********"<<endl;
		cin>>sira;
	}
	
	
	return 0;
}