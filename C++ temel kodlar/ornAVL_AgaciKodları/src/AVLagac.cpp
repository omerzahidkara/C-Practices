#include "AVLagac.hpp"

AVLagac::AVLagac()
{
	kok = 0;
}
int AVLagac::yukseklik(dugum* aktifDugum)
{
	if(aktifDugum)
	{
		return 1+max(yukseklik(aktifDugum->sol), yukseklik(aktifDugum->sag));
	}
	return -1;
}
int AVLagac::dengesizlikYonu(dugum* aktif)
{
	if(aktif == 0)
		return 0;
	return yukseklik(aktif -> sol) - yukseklik(aktif -> sag);
}
dugum* AVLagac::sagaDondur(Dugum* buyukEbeveyn)
{
	dugum* solCocuk = buyukEbeveyn->sol;
	buyukEbeveyn->sol = solCocuk->sag;
	solCocuk->sag = buyukEbeveyn;
	return solCocuk;
}
dugum* AVLagac::solaDondur(Dugum* buyukEbeveyn)
{
	dugum* sagCocuk = buyukEbeveyn->sag;
	buyukEbeveyn->sag = solCocuk->sol;
	solCocuk->sol = buyukEbeveyn;
	return sagCocuk;
}
dugum* AVLagac::ekle(int veri, dugum* aktifDugum)
{
	if(aktifDugum == 0)
	{
		return new dugum(veri);
	}
	
	if(aktifDugum -> veri > veri)
	{
		aktifDugum -> sol = ekle(veri, aktifDugum -> sol);
		if(yukseklik(aktifDugum->sol)-yukseklik(aktifDugum->sag)>1)
		{
			if(veri<aktifDugum->sol->veri)
			{
				aktifDugum = sagaDondur(aktifDugum);
			}
			else
			{
				aktifDugum -> sol = solaDondur(aktifDugum->sol);
				aktifDugum = sagaDondur(aktifDugum);
			}
		}
	}
	
	else(aktifDugum -> veri < veri)
	{
		aktifDugum -> sag = ekle(veri, aktifDugum -> sag);
		if(yukseklik(aktifDugum->sag)-yukseklik(aktifDugum->sol)>1)
		{
			if(veri>aktifDugum->sag->veri)
			{
				aktifDugum = solaDondur(aktifDugum);
			}
			else
			{
				aktifDugum -> sag = sagaDondur(aktifDugum->sag);
				aktifDugum = solaDondur(aktifDugum);
			}
		}
	}
}
dugum* AVLagac::sil(int veri, dugum* aktif)
{
	if(aktif == 0)
		return 0;
	if(veri < aktif -> veri)
	{
		aktif ->sol = sil(veri,aktif->sol);
	}
	else if(veri < aktif -> veri)
	{
		aktif ->sol = sil(veri,aktif->sol);
	}
	else
	{
		if(aktif ->sol == 0 && aktif ->sag == 0)
		{
			delete aktif;
			aktif = 0;
		}
		else if(aktif ->sol == 0)
		{
			dugum* sil = aktif -> sag;
			*aktif = *aktif -> sag ;
			delete sil;
		}
		else if(aktif ->sag == 0)
		{
			dugum* sil = aktif -> sol;
			*aktif = *aktif -> sol ;
			delete sil;
		}
		else
		{
			aktif -> veri = minDeger(aktif -> sag);
			sil(aktif -> veri, aktif -> sag);
		}
	}
	int denge = dengesizlikYonu(aktif);
	if(denge > 1)
	{
		if(dengesizlikYonu(aktif -> sol) >= 0)
		{
			return sagaDondur(aktif);
		}
		if(dengesizlikYonu(aktif ->sol) < 0)
		{
			aktif -> sol = solaDondur(aktif->sol);
			return sagaDondur(aktif);
		}
	}
	else if(denge < -1)
	{
		if(dengesizlikYonu(aktif -> sag) <= 0)
		{
			return solaDondur(aktif);
		}
		if(dengesizlikYonu(aktif -> sag) > 0)
		{
			aktif -> sag = sagaDondur(aktif->sag);
			return solaDondur(aktif);
		}
	}
	return aktif;
}