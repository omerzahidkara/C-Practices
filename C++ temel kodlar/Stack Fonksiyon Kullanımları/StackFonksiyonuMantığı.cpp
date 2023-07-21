void degistir (int x,int y)
{
	int tutucu = x;
	x = y;
	y = tutucu;
	cout << x << " " << y;
}

int main()
{
	int x,y;
	cout<< " Yerleri degiscek iki sayiyi giriniz: "<<endl;
	cin>> x;
	cin>> y;
	degistir(x,y);
	return 0;
}
/*Bu örnekte hatırlanacaklar:
--> degistir fonksiyonu stackte oluşur, işlemini yapar ve yok olur.
--> Dolayısıyla fonksiyondaki cout komutu kendi x ve y değerleridir.
O değerler mainden alınmıştır ama maindeki x ve y değişmemiştir.
