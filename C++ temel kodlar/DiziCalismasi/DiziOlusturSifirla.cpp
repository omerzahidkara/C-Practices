#include <iostream>
using namespace std;
/* Dizi içerisi değerleri 0 yapar*/
int* DiziOlusturSifirla(int uzunluk)
{
	int *dizi = new int[uzunluk];//Bu bir dinamik dizidir. Bu dizi heap bellekte yer tutar. Dışarıdan indeks belirtmeye uygundur.
	for(int i=0;i<uzunluk;i++){
		dizi[i]=0;
	}
	return dizi;
}
int main() {
	int uzunluk;
	cout<<"Dizi Uzunlugu: ";
	cin>> uzunluk;
	int *p = DiziOlusturSifirla(uzunluk);
	for(int i=0;i<uzunluk;i++){
		cout<<p[i]<<" ";
	}
	delete p;
	return 0;
}