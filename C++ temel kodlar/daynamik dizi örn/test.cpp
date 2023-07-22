#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class hata
{
	public:
	hata(const string& yeni)
	{
		mesaj = yeni;
	}
	string mesaj;
};
class dinamikDizi
{
	public:
		dinamikDizi()
		{
			m_boyut = 5;
			m_adres = new int[m_boyut];
			m_kullanilan = 0;
		}
		~dinamikDizi()
		{
			cout << "siyatut cagrildi" << endl;
			delete[] m_adres;
		}
		int boyut()const
		{
			return m_boyut;
		}
		int kullanilan()const
		{
			return m_kullanilan;
		}
		void sonaEkle(int yeniSayi)
		{
			if(m_kullanilan >= m_boyut)
			{
				genislet(m_boyut);
			}
			m_adres[m_kullanilan] = yeniSayi;
			m_kullanilan++;
		}
		int getir(int sira)const
		{
			if(sira<0 || sira >= m_kullanilan)
			{
				throw hata("getir sinir problemi");
			}
			return m_adres[sira];
		}
		void genislet (int eKboyut)
		{
			int *yeniAdres = new int [m_boyut + eKboyut];
			for(int i = 0; i< m_kullanilan; i++)
			{
				yeniAdres [i] = m_adres[i];
			}
			delete[] m_adres;
			m_adres = yeniAdres;
			m_boyut += eKboyut;
		}		
		friend ostream &operator<<(ostream& os,const dinamikDizi& dizi)
		{
			os << "|";
			for(int i = 0; i < dizi.boyut();i++)
			{
				os << setw(3) << i << setw(1) << "|";
			}
			os << endl << "|";
			for(int i = 0; i < dizi.boyut();i++)
			{
				os << setw(3) << "---" << setw(1) << "|";
			}
			os << endl << "|";
			for(int i = 0; i < dizi.kullanilan();i++)
			{
				os << setw(3) << dizi.getir(i) << setw(1) << "|";
			}
			for(int i = dizi.kullanilan(); i < dizi.boyut();i++)
			{
				os << setw(3) << "bos" << setw(1) << "|";
			}
			os << endl << endl;
			return os;
		}
		void arayaEkle(int sira, int veri)
		{
			if(sira >= 0 && sira <= m_kullanilan)
			{
				if(m_kullanilan >= m_boyut)
				{
					genislet(m_boyut);
					cout << this;
				}
				for(int i = m_kullanilan-1; i >= sira; i--)
				{
					m_adres[i+1] = m_adres[i];
				}
				m_adres[sira] = veri;
				m_kullanilan++;
			}
		}
	private:
		int m_boyut;
		int m_kullanilan;
		int* m_adres;
};
int main()
{
	dinamikDizi dizi;
	while(true)
	{
		system("cls");
		cout << dizi;
		cout << "1) sona ekle" << endl;
		cout << "2) araya ekle" << endl;
		cout << "3) cikis" << endl;
		int secim;
		cin >> secim;
		if(secim == 1)
		{
			dizi.sonaEkle(rand() % 100);
		}
		else if(secim == 2)
		{
			int sira;
			cout << "sira: ";
			cin >> sira;
			dizi.arayaEkle(sira, rand() % 100);
		}
		else if(secim == 3)
		{
			break;
		}
	}
	
}	


