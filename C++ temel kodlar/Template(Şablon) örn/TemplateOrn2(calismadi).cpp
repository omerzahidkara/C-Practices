#include <iostream>

using namespace std;

template <typename T>
const T& max(const T& x, const T& y)
{
    return (x > y) ? x : y;
	    friend bool operator>(const T& &p1, const T& &p2){
        return (p1.x > p2.y);
}

int main(){
    int i = max(3,7); //7 döndürür
    cout << i << endl;

    double d = max(6.34,18.523); //18.523 döndürür
    cout << d << endl;

    char ch = max('a', '6'); // 'a' döndürür
    cout << ch << endl;

    return 0;
}