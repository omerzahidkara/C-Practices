#ifndef Liste_hpp
#define Liste_hpp
#include <exception>
#include <iostream>
#include "Dugum.hpp"
using namespace std;

class Liste
{
	public:
	Liste();
	~Liste();
	void ekle(int veri);
	void onuneEkle(int sira,int veri);
	void cikar(int sira);		
	friend ostream& operator <<(ostream& os, Liste& liste);
	private:
    Dugum* dugumBul(int sira);	
	Dugum* ilk;
};

#endif