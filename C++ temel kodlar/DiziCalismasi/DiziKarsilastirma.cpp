#include <iostream>
using namespace std;

bool DiziKarsilastir(int* d1,int indeks1,int *d2,int indeks2)
{
	if(indeks1 != indeks2)
		return false;
	for(int i=0;i<indeks1;i++)
	{
		if(d1[i] != d2[i])
			return false;
	}
	return true;
}

int main()
{
	int p[] ={10,20,30};
	int r[] ={10,20,30};
	
	if(DiziKarsilastir(p,3,r,3)) cout <<"Diziler esit";
	else cout << "Diziler esit degil";
	
	return 0;	
}