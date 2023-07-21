#include <iostream>
using namespace std;

int main()
{	
	cout <<"Satir numarasi giriniz: ";
	int satir;
	cin >> satir;
    int c = 1; 
	      for(int x = 0; x <=satir ; x++)
        {						
			cout<< c << " ";			
			c = c * (satir - x) / (x + 1);
        }
  cout<< endl;
	system("PAUSE");
         
	return 0;
}