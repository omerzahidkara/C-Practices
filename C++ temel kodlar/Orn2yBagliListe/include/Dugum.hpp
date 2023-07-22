#ifndef Dugum_hpp
#define Dugum_hpp

class Dugum
{
public:	
	Dugum(int veri);
	~Dugum();	
	int veri;
	Dugum* onceki;
	Dugum* sonraki;
};

#endif