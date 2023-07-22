#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

int main() 
{
	srand(time(NULL));
	char karakter = 'd';
	int sayi1;
	int sayi2;
	while (karakter == 'd') // Enter tusuna kadar karakter girisi saglanir.
	{
		printf("devam icin d bitirmek icin herhangi bir tusa bas:\n");
		scanf("%c",&karakter);
		if(karakter != 'd')
		{
			break;
		}
		fflush(stdin);		
		sayi1 = rand()%30;
		sayi2 = rand()%40;
		if(sayi1>0 && sayi1<20)
		{
			printf("sayi1: %d sayi2: %d\n\n",sayi1,sayi2);
			printf("Kabile\n\n");
		}
		else
		{
			printf("olmadi\n\n");
			printf("sayi1: %d sayi2: %d\n\n",sayi1,sayi2);
		}
	}
	
	
	getch();
    return 0;
}