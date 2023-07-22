#include "BagliListe.hpp"
#include <iostream>
#include <iomanip>
using namespace std;

BagliListe::BagliListe()
{
	ilk = 0;
}
BagliListe::~BagliListe()
{
	Dugum* gec = ilk;
	while(gec !=0)
	{
		Dugum* sil = gec;
		gec = gec->sonraki;
		delete sil;
	}
}
void BagliListe::ekle(int veri)
{
	Dugum* yeni = new Dugum(veri);
	if(ilk==0)
	{
		ilk = yeni;
		return;
	}
	Dugum* gec = ilk;
	
	while(gec->sonraki !=0)
	{
		gec = gec->sonraki;		
	}
	gec->sonraki = yeni;
}
void BagliListe::yazdir()
{
	cout << setw(10) <<	"adres" << setw(10) << "veri" << setw(15) << "sonraki" << endl;
	cout << "-----------------------------------------------------------------------" << endl;
	Dugum* gec = ilk;
	
	while(gec !=0)
	{
		cout << setw(10) <<	gec << setw(10) << gec->veri << setw(15) << gec->sonraki << endl;
		gec = gec->sonraki;		
	}
	cout << endl;
}