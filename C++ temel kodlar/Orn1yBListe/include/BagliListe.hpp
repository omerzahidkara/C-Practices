#ifndef BagliListe_hpp
#define BagliListe_hpp
#include "Dugum.hpp"

class BagliListe
{
	public:
	BagliListe();
	~BagliListe();
	void ekle (int veri);
	void yazdir();
	private:
	Dugum* ilk;
};
#endif