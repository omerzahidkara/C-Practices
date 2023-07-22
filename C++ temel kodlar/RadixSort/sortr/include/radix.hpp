#ifndef radix_hpp
#define radix_hpp

#include "queue.hpp"


class radix{
	private:	
		int *sayilar;
		int boyut;
		queue **kuyruklar;
		int maxBasamak;
		
		int maxBasamakSayisi();
		int basamakSay(int);
		int *queueAndakiBoyut();
	public:
		radix(int*sayilar, int boyut);
		int *sort();
		~radix();
};
#endif
