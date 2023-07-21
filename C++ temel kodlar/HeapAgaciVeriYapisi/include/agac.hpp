#ifndef agac_hpp
#define agac_hpp
#include "dugum.hpp"
#define MAX 100
class agac
{
	public:
		agac();
		~agac();
		void ekle(int e);
		void cikar();
		void sirala();
	private:
		int getir();
		int solCocukIndeksiGetir(int i);
		int sagCocukIndeksiGetir(int i);
		int ebeveynIndeksiGetir(int i);
		int veriler[MAX];
		int ES;
		void heapIfyUp(int i);
		void heapIfyDown(int i);		
};
#endif