#include <iostream>
using namespace std;

void degistirSayilar(int &x, int &y) {
	int z = x;
	x=y;
	y=z;
}

int main() {
	int firstNum = 10;
	int secondNum = 20;        

cout << "Before swap: " << endl;
cout << firstNum <<" "<< secondNum << endl;

degistirSayilar(firstNum,secondNum);

cout << "After swap: " << endl;
cout << firstNum <<" "<<  secondNum << endl;
system("pause"); 
}	