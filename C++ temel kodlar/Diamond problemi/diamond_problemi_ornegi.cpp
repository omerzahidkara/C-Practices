#include <iostream>
using namespace std;

class At{
	public:
		void yemekye(){
			cout<<"Hayir!At yemek yiyor"<<endl;
		}
};

class Kus{
	public:
		void yemekye(){
			cout<<"Kus yemek yiyor"<<endl;
		}
};

class Pegasus : public At, public Kus{
};

int main() {
	Pegasus *pegasus =new Pegasus();
	pegasus ->::At:: yemekye();
	delete pegasus;
	system("pause");	
}

		