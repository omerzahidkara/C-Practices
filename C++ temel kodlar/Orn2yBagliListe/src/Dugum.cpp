#include "Dugum.hpp"
#include <iostream>
using namespace std;



Dugum::Dugum(int veri)
{
	this->veri = veri;
	sonraki=onceki=0;
}
Dugum::~Dugum()
{
	cout<<this<<": adresindeki dugum silindi"<<endl;
}	


