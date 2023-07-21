#include <iostream>
using namespace std;

int main()
{
	int x = 14;
	int *P = &x;
	int **R = &P;
	cout << " &P : " << &P << endl;
	cout << " P : " << P << endl;
	cout << " *P : " << *P << endl;
	cout << " &R : " << &R << endl;
	cout << " R  : " << R << endl;
	cout << " *R  : " << *R << endl;
	cout << " **R  : " << **R << endl;
	cout << " &x : " << &x << endl;
	cout << " x : " << x << endl;
}


