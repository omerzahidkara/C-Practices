#include <iostream>
using namespace std;

int *DiziKopyala(int *kaynak,int uzunluk)
{
	int *hedef = new int[uzunluk];
	for (int i=0;i<uzunluk;i++){
		hedef[i]=kaynak[i];
	}
	return hedef;
}

int main() 
{
	int p[]={10,20,30};
	int *r;
	r=DiziKopyala(p,3);
	r[0]=100;
	
	cout<<p[0];
	delete [] r;
	return 0; 
}