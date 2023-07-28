#include <iostream>
#include <iomanip>

using namespace std;

//stack : last in first out
class StackWArray
{
	private:
		int top;
		int diziLimiti;
		int* dizi;
	public:
		StackWArray()
		{
			top = 0;
			diziLimiti = 3;
			dizi = new int[diziLimiti];
		}
		~StackWArray()
		{
			if(top > 0)
			{
				while(top != 0)
				{
					Pop();
				}				
			}
			delete[] dizi;
		}
		void Pop()
		{
			if(top == 0)
			{
				cout << "dizi bos" << endl;
				return;
			}
			else
			{
				dizi[top] = 0;
				top--;
			}
		}
		void Push(int eklenecekVeri)
		{
			if(isFull())
			{
				Genislet();
				dizi[top] = eklenecekVeri;
			}
			else
			{
				dizi[top] = eklenecekVeri;
			}
			top++;
		}
		int Peek()
		{
			if(top == 0)
			{
				cout << "dizi bos" << endl;
				return -1;
			}
			else
			{
				return dizi[top];
			}
		}
		void Genislet()
		{
			if(isFull())
			{
				diziLimiti = diziLimiti*2;
				int* sil;
				int* kopya = new int[diziLimiti];
				for(int sayac = 0; sayac<top; sayac++)
				{
					kopya[sayac] = dizi[sayac];
				}
				sil = dizi;
				dizi = kopya;
				delete sil;
			}
		}
		bool isFull()
		{
			if(top >= diziLimiti)
			{
				return true;
			}
			else
				return false;
		}		
};




int main()
{	

	StackWArray* stack = new StackWArray();
	stack->Pop();
	cout << stack->Peek() << endl;
	stack->Push(15);
	cout << stack->Peek() << endl;
	stack->Push(16);
	cout << stack->Peek() << endl;
	stack->Push(17);
	cout << stack->Peek() << endl;
	stack->Push(18);
	cout << stack->Peek() << endl;
	stack->Pop();
	stack->Pop();
	cout << stack->Peek() << endl;
	stack->Pop();
	stack->Pop();
	delete stack;
	system("PAUSE");
	return 0;
}