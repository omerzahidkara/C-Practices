#include "Liste.hpp"
#include <iomanip>
#include <iostream>

Liste::Liste()
{			
		ilk = 0;
}
Liste::~Liste()
{
	Dugum* gec = ilk;
	while(gec!=0)
	{
		Dugum* silinecek = gec;
		gec = gec->sonraki;
		delete silinecek;
	}
}
	
void Liste::ekle(int veri)
{
	Dugum* yeniDugum = new Dugum(veri);
	if(ilk==0)
	{
		ilk = yeniDugum;
	}
	else
	{
		Dugum* gec = ilk;
		while(gec->sonraki !=0)
		{
			gec = gec->sonraki;
		}
		gec->sonraki = yeniDugum;
		yeniDugum->onceki = gec;
	}
	
}
Dugum* Liste::dugumBul(int sira)
{
			
	Dugum* gec = ilk;
	int sayac = 0;
	while(gec!=0)
	{
		if(sayac==sira)
		{
			return gec;
		}
		gec=gec->sonraki;
		sayac++;
	}
	return 0;
	
}

ostream& operator <<(ostream& os, Liste& liste)
{
	using namespace std;
	
	os<<"-----------------------------------------------------------------"<<endl;
	os<<setw(15)<<"dugum adresi"<<setw(15)<<"veri"<<setw(15)<<"onceki"<<setw(15)<<"sonraki"<<endl<<endl;
	Dugum* gec = liste.ilk;
	while(gec !=0)
	{
		os<<setw(15)<<gec<<setw(15)<<gec->veri<<setw(15)<<gec->onceki<<setw(15)<<gec->sonraki<<endl;	
		gec= gec->sonraki;	
	}
	os<<"-----------------------------------------------------------------"<<endl;
	
	return os;
}

void Liste::cikar(int sira)
{
	Dugum* silinecek = dugumBul(sira);	
	if(silinecek)
	{
		Dugum* silinecekOnceki = silinecek->onceki;
		Dugum* silinecekSonraki = silinecek->sonraki;
		
		if(silinecekSonraki)
		{
			silinecekSonraki->onceki=silinecekOnceki;
		}
		if(silinecekOnceki)
		{
			silinecekOnceki->sonraki=silinecekSonraki;
		}
		else
		{
			ilk = silinecekSonraki;
		}
		delete silinecek;
	}
}
void Liste::onuneEkle(int sira,int veri)
{
	Dugum* ondeki = dugumBul(sira);
	if(ondeki)
	{
		Dugum* ondekiOnceki = ondeki->onceki;
		
		Dugum* yeniDugum = new Dugum(veri);
		
		ondeki->onceki = yeniDugum;
		
		yeniDugum->sonraki = ondeki;
		
		yeniDugum->onceki = ondekiOnceki;
		
		if(ondekiOnceki)
		{
			ondekiOnceki->sonraki= yeniDugum;
		}
		else
		{
			ilk = yeniDugum;
		}
		
	}
}