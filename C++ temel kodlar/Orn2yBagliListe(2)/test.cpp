#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <cstdlib>
#include <limits>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif


using namespace std;
void clearLine()
{
#ifdef _WIN32
    COORD cursorPosition;
    CONSOLE_SCREEN_BUFFER_INFO screenBufferInfo;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (GetConsoleScreenBufferInfo(hStdOut, &screenBufferInfo))
    {
        cursorPosition.X = 0; // Satirin baslangic konumu
        cursorPosition.Y = screenBufferInfo.dwCursorPosition.Y; // Mevcut imlec konumu
        SetConsoleCursorPosition(hStdOut, cursorPosition); // Imleci baslangic noktasina tasi
    }
#else
    cout << "\r"; // Carriage return karakteri ile imleci satirin basina tasi
    cout.flush(); // Cikti tamponunu bosalt
#endif
}
class Dugum
{

	public:	
		Dugum* oncekiDugum;
		Dugum* sonrakiDugum;
		int dugumBilgisi;
		Dugum()
		{
			Dugum* oncekiDugum = 0;
			Dugum* sonrakiDugum = 0;
			int dugumBilgisi = 0;
		}
		~Dugum()
		{

		}
		void DugumOku()
		{
			cout << " Dugumdeki sayi: "  << dugumBilgisi << endl;
		}
};
class BagliListe
{
	private:
		Dugum* bas;
		Dugum* son;
		void ListeyiSil()
		{
			if(bas == 0)
			{
				return;
			}
						
			while(dugumSayisi != 0)
			{
				SondanDugumSil();
			}			
		}
	public:
		int dugumSayisi;
		BagliListe()
		{
			dugumSayisi = 0;
			bas = 0;
			son = 0;
		}
		~BagliListe()
		{
			ListeyiSil();
		}
		void SonaDugumEkle(int veri)
		{
			Dugum* yeniDugum = new Dugum();
			if(bas == 0)
			{
				bas = yeniDugum;
				son = yeniDugum;
				bas->dugumBilgisi = veri;
				dugumSayisi++;
				return;
			}
			yeniDugum->dugumBilgisi = veri;
			son->sonrakiDugum = yeniDugum;
			yeniDugum->oncekiDugum = son;
			son = yeniDugum;			
			dugumSayisi++;
		}
		void SondanDugumSil()
		{
			if(bas == 0)
			{
				cout << "--- liste yok ---" << endl;
				for(int i = 3; i>0; i--)
				{
					cout << "Yeniden islem icin " << i << " saniye " << "kaldi";
					Sleep(1000);
					clearLine();
				}				
				return;
			}
			if(dugumSayisi > 1)
			{
				Dugum* silinecekDugum;
				silinecekDugum = son;
				son = son->oncekiDugum;
				delete silinecekDugum;
				dugumSayisi--;
			}
			else if(dugumSayisi == 1)
			{
				Dugum* silinecekDugum;
				silinecekDugum = son;
				son = 0;
				bas = son;
				delete silinecekDugum;
				dugumSayisi--;
			}
			else
			{
				cout << "--- liste yok ---" << endl;
				for(int i = 5; i>0; i--)
				{
					cout << "Yeniden islem icin " << i << " saniye " << "kaldi";
					Sleep(1000);
					clearLine();
				}
			}

		}
		void DugumOku(int sira)
		{
			if(bas == 0)
			{
				cout << "--- liste yok ---" << endl;
				return;
			}
			
			if(sira <= dugumSayisi)
			{
				
				Dugum* tarayici = bas;
				if(sira == 1)
				{
					cout << setw(4) << sira << " numarali dugumun verisi = " << setw(4) << bas->dugumBilgisi << " || " << " Bellek adresi: " <<  bas <<  endl;
					return;
				}
				for(int indeks = 1; indeks<sira; indeks++)
				{
					tarayici = tarayici->sonrakiDugum;				
				}
				cout << setw(4) << sira << " numarali dugumun verisi = " << setw(4) << tarayici->dugumBilgisi << " || " << " Bellek adresi: " << tarayici<<  endl;
			}
			else
			{
				cout << "Belirttiginiz sira listede mevcut degil" << endl;
				for(int i = 5; i>0; i--)
				{
					cout << "Yeniden islem icin " << i << " saniye " << "kaldi";
					Sleep(1000);
					clearLine();
				}
			}		
		}
		void ButunListeyiOku()
		{
			system("cls");
			cout << " Dugum sayisi :" << dugumSayisi << endl << endl ;
			for(int a = 1; a<dugumSayisi+1; a++)
			{
				DugumOku(a);
			}
		}
		void ButunListeyiSil()
		{
			if(bas == 0)
			{
				cout << "--- liste yok ---" << endl;
				for(int i = 3; i>0; i--)
				{
					cout << "Yeniden islem icin " << i << " saniye " << "kaldi";
					Sleep(1000);
					clearLine();
				}			
				return;
			}
			int donguBelirteci = dugumSayisi;
			for(int y = 0; y < donguBelirteci ; y++)
			{
				SondanDugumSil();
			}
		}
		void Guncelle(int veriNumarasi)
		{
			int yeniVeri = 0;
			if(bas == 0)
			{
				cout << "--- liste yok ---" << endl;
				for(int i = 3; i>0; i--)
				{
					cout << "Yeniden islem icin " << i << " saniye " << "kaldi";
					Sleep(1000);
					clearLine();
				}			
				return;
			}			
			if(veriNumarasi == 1)
			{

				if (cin.fail() || cin.peek() != '\n') 
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					for(int i = 5; i>0; i--)
					{
						cout << "Hatali giris! Bir sayi girmelisiniz. Yeniden girmek icin " << i << " saniye " << "kaldi";
						Sleep(1000);
						clearLine();
					}
					yeniVeri = bas->dugumBilgisi; 
					return;
				}
				else
				{
					cout << setw(4) << veriNumarasi << " numarali sayinin yenisi: ";
					cin >> yeniVeri;					
					bas->dugumBilgisi = yeniVeri;						
				}
			}
			else if (veriNumarasi > 1)
			{
				Dugum* gidici = bas;
				if (cin.fail() || cin.peek() != '\n') 
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					for(int i = 5; i>0; i--)
					{
						cout << "Hatali giris! Bir sayi girmelisiniz. Yeniden girmek icin " << i << " saniye " << "kaldi";
						Sleep(1000);
						clearLine();
					}
					yeniVeri = gidici->dugumBilgisi;
					return;
				}
				else
				{
					cout << setw(4) << veriNumarasi << " numarali sayinin yenisi: ";
					for(int u = 0; u < veriNumarasi-1; u++)
					{
						gidici = gidici->sonrakiDugum;
					}
					cin >> yeniVeri;
					gidici->dugumBilgisi = yeniVeri;						
				}
			}
			else
			{
				cout << "Hatali giris! Mevcut numara giriniz."<< endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				for(int i = 3; i>0; i--)
				{
					cout << "Yeniden islem icin " << i << " saniye " << "kaldi";
					Sleep(1000);
					clearLine();
				}	
			}
		}

		void BirdenFazlaGuncelle(int miktar)
		{
			int siralar = 0;
			for(int o = 0; o < miktar; o++)
			{
				cout << " guncellenecek sayinin numarasini giriniz:";
				cin >> siralar;
				if (cin.fail()) 
				{
					cout << "Hatali giris! Sayi girmelisiniz."<< endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					for(int i = 3; i>0; i--)
					{
						cout << "Yeniden islem icin " << i << " saniye " << "kaldi";
						Sleep(1000);
						clearLine();
					}
					break;
				}
				else
				{
					Guncelle(siralar);						
				}				
			}
		}
};

int main()
{
	BagliListe* yeniListe = new BagliListe();
	int a = 0;
	int girilenSayi = 0;
	bool hataVar = false;
	bool hataVarMenu = false;
	while(true)
	{
		system("cls");
		yeniListe->ButunListeyiOku();
		cout << endl;
		cout << " MENU " << endl;
		cout << " Sona Ekle. (1) [1 sayi 1 sayi... seklinde cok sayi ekleyebilirsiniz] " << endl;
		cout << " Sondan Sil (2) " << endl;
		cout << " Hepsini Sil (3) " << endl;
		cout << " Guncelle (4) " << endl;
		cout << " Coklu Guncelle (5) " << endl;
		cout << " Programi Sonlandir (6) " << endl;
		cout << endl;
		cout << "Isleminiz : ";
		cin >> a;
		if (cin.fail()) 
		{
            cout << "Hatali giris! Sayi girmelisiniz." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            hataVarMenu = true;
        }
		else
		{
			hataVarMenu = false;
		}
		cout << endl;
		if(a == 1)
		{
			cout << "Eklenecek sayiyi giriniz: ";
			cin >> girilenSayi;
            if (cin.fail()) 
			{
                cout << "Hatali giris! Sayi girmelisiniz." << endl;
				for(int i = 5; i>0; i--)
				{
					cout << "Yeniden islem icin " << i << " saniye " << "kaldi";
					Sleep(1000);
					clearLine();
				}				
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                hataVar = true;
            } 
			else 
			{
                yeniListe->SonaDugumEkle(girilenSayi);
                hataVar = false;
            }
		}
		else if(a == 2)
		{
			yeniListe->SondanDugumSil();
			a = 0;
		}
		else if(a == 3)
		{
			yeniListe->ButunListeyiSil();
		}
		else if(a == 4)
		{
			int veriSirasi = 0;
			cout << "Guncellemek istediginiz sayinin numarasi: ";
			cin >> veriSirasi;
			if (cin.fail()) 
			{
                cout << "Hatali giris! Sayi girmelisiniz." << endl;
				for(int i = 5; i>0; i--)
				{
					cout << "Yeniden islem icin " << i << " saniye " << "kaldi";
					Sleep(1000);
					clearLine();
				}				
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                hataVar = true;
            }
			else
			{
				hataVar = false;
				yeniListe->Guncelle(veriSirasi);	
			}		
		}
		else if(a == 5)
		{
			int girisBilgisi = 0;
			cout << " Kac adet sayiyi guncelleyeceginizi giriniz: ";
			cin >> girisBilgisi;
			if (cin.fail()) 
			{
				cout << "Hatali giris! Sayi girmelisiniz." << endl;
				for(int i = 5; i>0; i--)
				{
					cout << "Yeniden islem icin " << i << " saniye " << "kaldi";
					Sleep(1000);
					clearLine();
				}				
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				hataVar = true;
			}
			else
			{
				if(girisBilgisi <= yeniListe->dugumSayisi && !(girisBilgisi <= 0) )
				{
					hataVar = false;
					yeniListe->BirdenFazlaGuncelle(girisBilgisi);	
				}
				else
				{
					cout << "Hatali giris! Mevcut sayi miktarindan bir sayi belirtiniz" << endl;
					for(int i = 5; i>0; i--)
					{
						cout << "Yeniden islem icin " << i << " saniye " << "kaldi";
						Sleep(1000);
						clearLine();
					}				
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					hataVar = true;
				}				
	
			}

		}
		else if(a == 6)
		{
			break;
		}
		else
		{
			a = 0; 
			cout << " 1, 2, 3, 4, 5 veya 6 numaralarindan birini seciniz " << endl;			
			for(int i = 5; i>0; i--)
			{
				cout << "Yeniden islem icin " << i << " saniye " << "kaldi";
				Sleep(1000);
				clearLine();
			}
		}
		        // Hata durumunda işlemi baştan başlat
        if (hataVar) 
		{
            a = 0;
            continue;
		}
		if (hataVarMenu) 
		{
            a = 0;
            continue;
		}
	}
	delete yeniListe;
	return 0;
}	


