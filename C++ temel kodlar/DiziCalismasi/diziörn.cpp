#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int boyut;
	cout << "dizi boyutu girin:";
	cin >> boyut ;
	int *dizi = new int[boyut];
	
	for(int i=0;i<boyut;i++)
	{
		dizi[i] = rand()%100;
	}
	
	cout << setw(10) << "adres" <<setw(10)<<"deger"<<endl;
	for(int i = 0;i<boyut;i++)
	{
		cout<<setw(10)<<dizi+i<<setw(10)<<*(dizi+i)<<endl;
	}
	delete[] dizi;
}
