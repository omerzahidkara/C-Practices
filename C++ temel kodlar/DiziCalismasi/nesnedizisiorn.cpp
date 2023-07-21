#include <iostream>
using namespace std;

class Sayi
{
	public:
		Sayi()
		{
			s1 = rand ()%100;
			s2 = rand ()%100;
			cout << this << " adresindeki nesne olusturuldu" << endl;
		}
		~Sayi()
		{
			cout << this << " adresindeki nesne yok edildi" << endl;
		}
		void yazdir()
		{
			cout << "s1,s2:" << s1 << "," << s2 << endl;
		}
	private:
	int s1;
	int s2;
	
};

int main()
{
	Sayi *p[10];
	p[0] = new Sayi;
	cout << "------------------------------------------------"<< endl;
	p[1] = new Sayi[10];
	cout << "------------------------------------------------"<< endl;
	p[2] = new Sayi[10];
	p[0]->yazdir();
	for(int i=0;i<10;i++)
	{
		p[1][i].yazdir();
	}
	delete p[0];
	delete[] p[1];
	delete[] p[2];
	return 0;
}