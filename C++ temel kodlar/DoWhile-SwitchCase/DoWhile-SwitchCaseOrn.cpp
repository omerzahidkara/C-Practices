#include <iostream>
using namespace std;

void OPR_yap (int belirtec)
{
	char belirtec_char;
	if (belirtec==1)
	{
		belirtec_char= 'u';
	};
	if (belirtec==0)
	{
		belirtec_char= 'e';
	};
		
	if (belirtec==-1)
	{
		belirtec_char= 'k';
	};
		
	switch(belirtec_char)
	{
		case 'u':
			cout<< "<="<<endl ;
			break;
		case 'e':
			cout <<	"="<<endl;
			break;
		case 'k':
			cout << ">="<<endl;
			break;
		default:
			cout << " !!!"<<endl;
	}
		
		
}

int main()
{
	int tekrar=0;
	int k;
	do{	
		cout << "belirtec sayisi(1,0,-1):" << endl;
		cin >> k;
		cout << "devamlilik sayisi(on=0,off=1):" << endl;
		cin >> tekrar;
		OPR_yap(k);
	}
	while(tekrar==0);
	return 0;
}