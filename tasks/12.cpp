#include <iostream>

using namespace std;

int main()
{
    long x;
    scanf("%ld", &x);

    if(!(x % 10))
    	cout << "NO";
	else cout << x % 10;

    return 0;
}
