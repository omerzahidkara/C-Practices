#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>

int main() 
{
	srand(time(NULL));
	int* ilkDizi = (int*)malloc(sizeof(int)*10);
	for(int i = 0 ; i < 10; i++)
	{
		ilkDizi[i] = rand()%100;
	}
	printf("ilk dizi sayilari:");
	for(int b = 0 ; b < 10; b++)
	{
		printf(" %d",ilkDizi[b]);
	}
	ilkDizi[5] = '\0';
	printf("\n\n");
	printf("ortadaki silindikten sonra dizi sayilari:");
	for(int n = 0 ; n < 10; n++)
	{
		printf(" %d",ilkDizi[n]);
	}
	
	realloc(ilkDizi,sizeof(int)*9);
	/*
	for(int z = 0 ; z < 9; z++)
	{
		ilkDizi[z] = rand()%100;
	}
	*/
	printf("\n\n");
	printf("dizi yenilendikten sonra dizi sayilari:");
	for(int a = 0 ; a < 9; a++)
	{
		printf(" %d",ilkDizi[a]);
	}
	printf("\n\n");
	printf("realloc ile 10 elemandan 9 a inen dizide son eleman diziden atildi.( sifir olan cikar diye beklemistim :*) )");
	free(ilkDizi);
	getch();
    return 0;
}