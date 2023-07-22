#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <stdbool.h>

int koloniSayisiHesapla(int* nufusDizisi)
{
	int koloniSayisi = 0;
	int* gezici = nufusDizisi; 
	while (*gezici != 0)
	{
		gezici++;
		koloniSayisi++;
	}
	printf("\nKoloni sayisi:%d\n\n",koloniSayisi);
	return koloniSayisi;	
}
wchar_t* koloniSemboluUret(int uzunluk)
{
	const wchar_t baslangic = 0x30;
    const int karakterSayisi = 43;
	int rastgeleSayi;
	wchar_t rastgeleKarakter;
	wchar_t* gonderilecek = malloc(sizeof(wchar_t)*(uzunluk+1));
	for(int c = 0; c < uzunluk; c++)
	{
		rastgeleSayi = rand() % karakterSayisi;
		rastgeleKarakter = (wchar_t)(baslangic + rastgeleSayi);
		gonderilecek[c] = rastgeleKarakter;
	}
	
	gonderilecek[uzunluk] = L'\0'; 
	
	return gonderilecek;
}
wchar_t** sembolDeposuUret(int sayi)
{
	wchar_t** semboller = malloc(sizeof(wchar_t*)*sayi);
	int chMiktari = 1;
	semboller[0] = koloniSemboluUret(chMiktari);
	int kontrolcuSayac = 0;
	for(int o = 1; o< sayi; o++)
	{
		semboller[o] = koloniSemboluUret(chMiktari);
		kontrolcuSayac = 0;				
		while(kontrolcuSayac != o)
		{			
			if (wcscmp(semboller[o], semboller[kontrolcuSayac]) == 0)
			{
				semboller[o] = L'\0';
				semboller[o] = koloniSemboluUret(chMiktari);
				kontrolcuSayac = -1;
			}			
			kontrolcuSayac++;
		}				
		if(o%42 == 0)
		{
			chMiktari++;
		}				
	}
	return semboller;
}
int* girdiAlVeYazdir()
{
	int kapasiteSatir = 10;
    char* satir = malloc(sizeof(char) * kapasiteSatir);  
    int karakterSayisi = 0;
    int karakter;
    while ((karakter = getchar()) != '\n') 
	{
        if (karakterSayisi == kapasiteSatir) 
		{
            kapasiteSatir += 10;
            satir = realloc(satir, sizeof(char) * kapasiteSatir);
        }
        satir[karakterSayisi] = karakter;
        karakterSayisi++;
    }   
    satir = realloc(satir, sizeof(char) * (karakterSayisi + 1));
    satir[karakterSayisi] = '\0';   
	int kapasiteInt = 10;
    int* diziInt = malloc(sizeof(int) * kapasiteInt);
    int sayac = 0;
	char* elArabasi = strtok(satir, " "); 
    while (elArabasi != NULL) 
	{
        diziInt[sayac] = atoi(elArabasi);
        sayac++;        
        if (sayac == kapasiteInt) 
		{
            kapasiteInt += 10;
            diziInt = realloc(diziInt, sizeof(int) * kapasiteInt);
        }        
        elArabasi = strtok(NULL, " ");
    }
	diziInt = realloc(diziInt, sizeof(int) * (sayac + 1));
    diziInt[sayac] = '\0'; 
	wchar_t** sembolDeposu = sembolDeposuUret(sayac);	
    printf("Girilen koloniler: ");
	printf("\n");
	int boslukSayaci = 1;
    for (int i = 0; i < sayac; i++) 
	{
        wprintf( L"Koloni %s :%d  ", sembolDeposu[i], diziInt[i]);
		free(sembolDeposu[i]);
		if(boslukSayaci%10 == 0)
		{
			printf("\n");
		}
		boslukSayaci++;
    }
    return diziInt;   
}
int main() 
{
	srand(time(NULL));
	
	int* sayillarr = girdiAlVeYazdir();
	
	int sayiMiktarri = koloniSayisiHesapla(sayillarr);
	
	free(sayillarr);
	
	getch();
	
    return 0;
	
}

