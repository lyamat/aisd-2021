#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;


    if (abs(x1-x2) == abs(y1-y2))
        cout << "NO";
    else
        cout << "YES";

    return 0;
}
