#include <algorithm>
#include <iostream>

using namespace std;

long long func(long long arr[], int n, int k)
{
    long long ans = 1;
    int l = 0, r = n - 1;
    bool first = true;

    sort(arr, arr + n);

    long long mul_of_left = arr[l] * arr[l + 1];
    long long mul_of_right = arr[r] * arr[r - 1];

    if (mul_of_left >= mul_of_right)
    {
        ans *= mul_of_left;
        l += 2;
    }
    else
    {
        ans *= mul_of_right;
        r -= 2;
    }

    return ans;
}

int main()
{
    int n;
    scanf("%d", &n);

    long long arr[n];
    for (int i = 0; i < n; ++i)
        scanf("%lld", &arr[i]);

    cout << func(arr, n, 2);

    return 0;
}