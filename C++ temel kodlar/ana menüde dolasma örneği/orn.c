#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <wchar.h>


wchar_t karakterUret()//rastgele 100 karakter arasindan bir karakter döndüren fonksiyon
{
	const wchar_t baslangic = 0x26;
	const int karakterSayisi = 100;
	const wchar_t bitis = baslangic + karakterSayisi;
	int rastgeleSayi = rand() % karakterSayisi;
	wchar_t rastgeleKarakter = (wchar_t)(baslangic + rastgeleSayi);
	return rastgeleKarakter;
}
void koloniVerileriAlVeSakla()
{

	char ilkVeriGirisi[100];
	int nufusSayilariStack[100];
	int koloniSayisi = 0;
	printf("Ornek:1235 68 45 68 975 3\n");
	printf("Koloni nufuslari sayilarini  giriniz:");
	fgets(ilkVeriGirisi, sizeof(ilkVeriGirisi), stdin);
	printf("\n");
	char* strokAyraci = strtok(ilkVeriGirisi, " ");

	while (strokAyraci != NULL)
	{
		nufusSayilariStack[koloniSayisi] = atoi(strokAyraci);
		koloniSayisi++;
		strokAyraci = strtok(NULL, " ");
	}
	int* nufusSayilariHeap = (int*)malloc(sizeof(int) * koloniSayisi);
	wchar_t* koloniSembolleri = (wchar_t*)malloc(sizeof(wchar_t) * koloniSayisi);

	printf("Koloni Sayisi:%d\n\n", koloniSayisi);
	for (int donguInd = 0; donguInd < koloniSayisi; donguInd++)
	{
		koloniSembolleri[donguInd] = karakterUret();
		nufusSayilariHeap[donguInd] = nufusSayilariStack[donguInd];
		wchar_t sembolAtayici = koloniSembolleri[donguInd];
		wprintf(L"Koloni %lc: %d \n", sembolAtayici, nufusSayilariHeap[donguInd]);
	}
	free(nufusSayilariHeap);
	free(koloniSembolleri);
	fflush(stdin);
}

int main() {

	char islemKararci = 'e';
	char islemKararci2 = 'e';
	while (islemKararci2 == 'e')
	{
		if (islemKararci == 'e')
		{
			koloniVerileriAlVeSakla();
			islemKararci2 = 'a';
		}
		else if (islemKararci == 'h')
		{
			break;
		}
		else
		{
			printf("Yanlis tus harf girdiniz! Devam etmek icin y, kapatmak icin h karakterini tuslayiniz.\n");
		}
		printf("Bir islem yapacak misiniz?(e/h): ");
		scanf("%c", &islemKararci);
		fflush(stdin);
		if (islemKararci == 'e')
		{
			islemKararci2 = 'e';
		}
		else if (islemKararci == 'h')
		{
			islemKararci2 = 'a';
		}
		else
		{
			islemKararci = 'c';
			islemKararci2 = 'e';
		}
		printf("\n\n\n");
	}

	return 0;
}