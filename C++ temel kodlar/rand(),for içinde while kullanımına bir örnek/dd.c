#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <time.h>

int main()
{
	srand(time(NULL));
	int* sayilar = malloc(sizeof(int)*10);
	int tasiyiciSayi = 0;
	bool donguKarari = true;
	int donguSayaci = 0;
	for(int sira = 0; sira<10; sira++)
	{
		donguKarari = true;
		while(donguKarari)
		{
			tasiyiciSayi = 0;
			if(tasiyiciSayi != 5)
			{
				tasiyiciSayi = rand()%10;
			}
			if(tasiyiciSayi == 5)
			{
				sayilar[sira] = tasiyiciSayi;
				donguKarari = false;
			}
			printf(" %d ",tasiyiciSayi);
			donguSayaci++;
		}
	}
	printf("Islem sayisi:%d\n\n",donguSayaci);
	printf("Sayilar dizini:");
	for(int sira2 = 0; sira2<10; sira2++)
	{
		printf("%d ",sayilar[sira2]);
	}

	
	free(sayilar);
	getch();
	return 0;
}