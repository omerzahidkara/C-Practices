#include <iostream>
#include <iomanip>

using namespace std;
class dugum
{
	public:
		dugum* onceki;
		dugum* sonraki;
		int veri;
	dugum(int gelenDeger)
	{
		onceki = 0;
		sonraki = 0;
		veri = gelenDeger;
	}
	~dugum()
	{

	}
};
class ikiYonluDaireselListe
{
	private:
		dugum* basDugum;
		int dugumSayisi;
	public:
		ikiYonluDaireselListe()
		{
			basDugum = 0;
			dugumSayisi = 0;
		}
		~ikiYonluDaireselListe()
		{
			int sayi = dugumSayisi;
			for(int b = 0; b <sayi; b++)
			{
				SondanDugumCikar();
			}
		}
		void SonaDugumEkle(int veri)
		{
			dugum* yeni = new dugum(veri);
			if(basDugum == 0)
			{
				basDugum = yeni;
				basDugum->sonraki = basDugum;
				basDugum->onceki = basDugum;	
			}

			else
			{
				dugum* gec = DugumuGetir(dugumSayisi-1);
				gec->sonraki = yeni;
				yeni->onceki = gec;
				yeni->sonraki = basDugum;
				basDugum->onceki = yeni;
			}
			dugumSayisi++;
		}
		void SondanDugumCikar()
		{
			if(basDugum == 0)
				return;
			if(basDugum->sonraki == basDugum)
			{
				delete basDugum;
				basDugum = 0;
			}
			else
			{
				dugum* gec = basDugum;
				while(gec->sonraki->sonraki != basDugum)
				{
					gec = gec->sonraki;
				}
				delete gec->sonraki;
				gec->sonraki = basDugum;
				basDugum->onceki = gec;
			}
			dugumSayisi--;
		}
		void BelirliYerdenCikar(int sira)
		{
			dugum* cikarilacak = DugumuGetir(sira);
			if(cikarilacak)
			{
				if(cikarilacak == basDugum)
				{
					basDugum->sonraki->onceki = basDugum->onceki;
					basDugum->onceki->sonraki = basDugum->sonraki;
					basDugum = basDugum->sonraki;
					delete cikarilacak;
				}
				if(sira == dugumSayisi-1&& dugumSayisi != 1)					
				{
					basDugum->onceki->onceki->sonraki = basDugum;
					basDugum->onceki = basDugum->onceki->onceki;
					delete cikarilacak;
				}
				else
				{
					cikarilacak->onceki->sonraki = cikarilacak->sonraki;
					cikarilacak->sonraki->onceki = cikarilacak->onceki;
					delete cikarilacak;	
				}
				dugumSayisi--;
			}
		}
		dugum* DugumuGetir(int sira)
		{
			if(sira<0 || sira >= dugumSayisi)
			{
				return 0;
			}
			dugum* gec = basDugum;
			for(int i = 0; i<sira; i++)
			{
				gec = gec->sonraki;
			}
			return gec;
		}
		void DugumuGuncelle(int yeniVeri,int sira)
		{
			dugum* guncellenecek = DugumuGetir(sira);
			if(guncellenecek != 0)
			{
				guncellenecek->veri = yeniVeri;
			}
			else
			{
				cout << " dugum mevcut degil! " << endl;
			}
		}
		void ArayaDugumEkle(int sira,int veri)
		{			
			if(sira<0 || sira >= dugumSayisi)
			{
				return;
			}

			if(sira == 0)
			{
				dugum* yeniDugum = new dugum(veri);				
				basDugum->onceki->sonraki = yeniDugum;
				yeniDugum->sonraki = basDugum;
				yeniDugum->onceki = basDugum->onceki;
				basDugum->onceki = yeniDugum;
				basDugum = yeniDugum;
			}
			if(sira == dugumSayisi-1)
			{
				SonaDugumEkle(veri);
				dugumSayisi--;
			}
			else
			{
				dugum* yeniDugum = new dugum(veri);
				dugum* eklenecekOnceki = DugumuGetir(sira);
				yeniDugum->onceki = eklenecekOnceki->onceki;
				eklenecekOnceki->onceki->sonraki = yeniDugum;
				yeniDugum->sonraki = eklenecekOnceki;
				eklenecekOnceki->onceki = yeniDugum;
			}
			dugumSayisi++;
		}
		friend ostream& operator<<(ostream& os,ikiYonluDaireselListe& liste)
		{
			dugum* gec = liste.basDugum;
			cout << "dugum sayisi: " << liste.dugumSayisi << endl;
			cout << setw(15) << "adres" << setw(15) << "veri" << setw(15) << "onceki" << setw(15) << "sonraki" << endl;
			for(int y = 0; y<liste.dugumSayisi;y++)
			{
				cout << setw(15) << gec << setw(15) << gec->veri << setw(15) << gec->onceki << setw(15) << gec->sonraki << endl;
				gec = gec->sonraki;
			}
			cout << "--------------------------------------------------------------------------------------------------------" << endl;
			return os;
		}
		int getDugumSayisi()
		{
			return dugumSayisi;
		}
};
int main()
{	
	ikiYonluDaireselListe* nesne = new ikiYonluDaireselListe();
	for(int t = 0; t < 5; t++)
	{
		nesne->SonaDugumEkle((t+1)*10);
	}
	cout << *nesne;
	nesne->ArayaDugumEkle(2,9999);
	cout << *nesne;
	nesne->BelirliYerdenCikar(5);
	cout << *nesne;
	cout << endl;
	system("PAUSE");
	delete nesne;
	return 0;
}