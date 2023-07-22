#include "radix.hpp"
#include "queue.hpp"
#include <iostream>
using namespace std;

int main()
{
	int sayilar[] = {10,11,20,31,40,30,21};
	radix *radixNesnesi = new radix(sayilar,7);
	int *sirali = radixNesnesi->sort();
		cout << endl;
	cout<<"Siralanmadan Onceki Hali:"<<endl;
	for(int i=0;i<7;i++)
	{
		cout<<sayilar[i]<<" ";
	}
	cout<<endl<<endl<<"Siralandiktan Sonraki Hali:"<<endl;
	for(int i=0;i<7;i++)
	{
		cout<<sirali[i]<<" ";
	}
	
	delete [] sirali;
	delete radixNesnesi;
	system("PAUSE");
	return 0;
}