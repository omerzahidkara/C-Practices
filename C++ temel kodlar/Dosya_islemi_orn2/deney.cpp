#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

class Dortgen
{
public:
	Dortgen(string isim)
	{
		mGenislik = rand() % 100;
		mYukseklik = rand() % 100;
		mIsim = isim;
	}
	void kaydet()
	{
		fstream dosya;
		dosya.open("sekiller.txt",ios::in|ios::out|ios::ate|ios::app);
		if(dosya.is_open())
		{
			dosya << mIsim << " "<<mGenislik<<" "<<mYukseklik<< endl;
		}
		dosya.close();
	}
private:
	string mIsim;
	int mGenislik;
	int mYukseklik;
};
class Sekiller
{
public:
	void okuVeEkranaCikar()
	{
		fstream dosya;
		dosya.open("sekiller.txt",ios::in);
		if(dosya.is_open())
		{
			string isim;
			int en, boy;
			
			while(dosya >> isim >> en >> boy)
			{				
				cout <<setw(10)<< isim << setw(4)<<  en<<setw(4) << boy << endl;
			}
		}
		dosya.close();
	}
private:
};

int main()
{
	Sekiller sekiller;
	sekiller.okuVeEkranaCikar();
}