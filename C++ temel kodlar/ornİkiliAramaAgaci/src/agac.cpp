#include "agac.hpp"

agac::agac()
{
	kok = 0;
}
bool agac::ara(int veri)
{
	return ara(veri,kok);
}
bool agac::ara(int aranan,dugum* aktif)
{
	if(aktif -> veri < aranan)
	{
		if(aktif -> sag)
		{
			return ara(aranan, aktif -> sag);
			
		}
		return false;
	}
	else if(aktif -> veri > aranan)
	{
		if(aktif -> sol)
		{
			return ara(aranan, aktif -> sol);
			
		}
		return false;
	}
	else return true;
}
void agac::ekle(int veri, dugum* aktifDugum)
{
	if(aktifDugum -> veri > veri)
	{
		if(aktifDugum -> sol)
		{
			return ekle(veri, aktifDugum -> sol);
		}
		else
		{
			aktifDugum -> sol = new dugum(veri);
		}
	}
	else if(aktifDugum -> veri < veri)
	{
		if(aktifDugum -> sag)
		{
			return ekle(veri, aktifDugum -> sag);
		}
		else
		{
			aktifDugum -> sag = new dugum(veri);
		}
	}
	else return;
}
int agac::yukseklikBul(dugum* aktifDugum)
{
	if(aktifDugum)
	{
		return 1+max(yukseklikBul(aktifDugum->sol), yukseklikBul(aktifDugum->sag));
	}
	return -1;
}
void agac::preOrder(dugum* aktif)
{
	if(aktif)
	{
		cout << aktif -> veri << " ";
		
		preOrder(aktif->sol);
		
		preOrder(aktif->sag);		
	}
}
void agac::postOrder(dugum* aktif)
{
	if(aktif)
	{		
		postOrder(aktif->sol);
		
		postOrder(aktif->sag);
		
		cout << aktif -> veri << " ";		
	}
}
void agac::inOrder(dugum* aktif)
{
	if(aktif)
	{		
		inOrder(aktif->sol);
		
		cout << aktif -> veri << " ";	
		
		inOrder(aktif->sag);			
	}
}
int agac::enBuyuk(dugum* aktif)
{
	if(aktif -> sag)
		return enBuyuk(aktif -> sag);
	return aktif -> veri;
}
void agac::sil(int aranan, dugum* &aktif)
{
	if(aktif == 0)
		return;
	if(aktif -> veri > aranan)
		sil(aranan, aktif -> sol);
	if(aktif -> veri < aranan)
		sil(aranan, aktif -> sag);
	else
	{
		if(aktif->sag && aktif->sol)
		{
			aktif -> veri = enBuyuk(aktif ->sol);
			sil(aktif -> veri, aktif->sol);
		}
		else
		{
			Dugum* silinecek = aktif;
			if(aktif -> sol == 0)
				aktif = aktif -> sag;
			
			else if(aktif -> sag == 0)
				aktif = aktif -> sol;
			else
				aktif = 0;
			
			delete silinecek;
		}
	}
}
