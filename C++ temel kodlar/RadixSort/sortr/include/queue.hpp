#ifndef queue_hpp
#define queue_hpp
#include "queueNode.hpp"
class queue
{
	
	public:
		queue();
		void temizle();
		int say();
		bool bosMu();
		int getir();
		void ekle(int dugumVeri);
		void eksilt();
		~queue();		
	private:
		queueNode* bas;
		queueNode* son;
		int boyut;
};
#endif
