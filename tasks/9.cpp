#include <iostream>

using namespace std;

int main()
{
    string str;
    getline(cin, str);

    int change[str.length() + 1];

    fill(change, change + str.length() + 1, 0);

    int l, r, q;

    scanf("%d", &q);

    for (int i = 0; i < q; i++)
    {
        scanf("%d %d", &l, &r);
        if (l > r) swap(l, r);
        change[r]--; change[l-1]++;
    }

    int len_change = sizeof(change) / sizeof(change[0]);

    for (int j = 1; j < len_change; j++)
        change[j] += change[j-1];

    for (int i = 0; i < str.length(); i++)
    {
        if(change[i] % 2)
            if(islower(str[i]))
                str[i] = toupper(str[i]);
            else str[i] = tolower(str[i]);
    }

    cout << str;

    return 0;
}