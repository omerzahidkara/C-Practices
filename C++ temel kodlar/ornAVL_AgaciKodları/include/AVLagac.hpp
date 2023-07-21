#ifndef AVLagac_hpp
#define AVLagac_hpp
#include "dugum.hpp"
class AVLagac
{
	public:
		AVLagac();
		~AVLagac();
		int yukseklik(dugum* aktifDugum);
		int dengesizlikYonu(dugum* aktif);
		dugum* sagaDondur(Dugum* buyukEbeveyn);
		dugum* solaDondur(Dugum* buyukEbeveyn);
		dugum* ekle(int veri, dugum* aktifDugum);
		dugum* sil(int veri, dugum* aktif);
	private:
		dugum* kok;
};
#endif