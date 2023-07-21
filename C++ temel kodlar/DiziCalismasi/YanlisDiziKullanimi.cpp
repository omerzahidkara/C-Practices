#include <iostream>
using namespace std;

int main()//Bu örnek statik dizidir. Dinamik dizi heap bölgesinde olur ve işlemler bitince kullanıcı tarafından silinmesi gerekir.
{
	cout<< 	"Dizi olusturmak icin eleman sayisini belirleiyiniz: "<<endl;
	int elemanSayisi;
	cin>> elemanSayisi;
	int dizi[elemanSayisi];//Bu indeks belirleme kullanımı statik diziler için yanlıştır. Statik dilizerde derleme hatasına sebep olur. MinGw izin verse bile kullanılmamalıdır.
	int eleman;
	for(int i=0;i<elemanSayisi;i++)
	{
		cout <<i+1<<" Numarali elemani belirleyiniz: ";
		cin>>eleman;
		dizi[i]=eleman;	
	} 
	cout << endl;
	cout << "Olusturdugunuz dizi: {";
	for(int r=0;r<elemanSayisi;r++)
	{
		cout<<*(dizi+r) << " "; 
	}
	cout << " }";
	
	return 0;
	
}