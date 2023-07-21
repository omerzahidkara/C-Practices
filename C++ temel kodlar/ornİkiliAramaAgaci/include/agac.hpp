#ifndef agac_hpp
#define agac_hpp
#include "dugum.hpp"
class agac
{
	public:
		agac();
		~agac();
		bool ara(int veri);
		void ekle(int veri, dugum* aktifDugum);		
		int yukseklikBul(dugum* aktifDugum);
		void preOrder(dugum* aktif);
		void postOrder(dugum* aktif);
		void inOrder(dugum* aktif);
		int enBuyuk(dugum* aktif);
		void sil(int aranan, dugum* &aktif);
	private:
		bool ara(int veri, dugum* aktif);
		dugum* kok;
};
#endif