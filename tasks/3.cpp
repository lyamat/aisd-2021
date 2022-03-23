#include <algorithm>
#include <iostream>

const long long _mod = 1e9+7;

using namespace std;

long long mod(long long val, long long _mod)
{
    if (val % _mod < 0)
        return val % _mod + _mod;
    else return val % _mod;
}

long long mod_mul(long long val1, long long val2, long long _mod)
{
   return mod(mod(val1,_mod) * mod(val2, _mod), _mod);
}

long long func(long long arr[], int n, int k)
{
    long long ans;
    int l = 0, r = n - 1;
    bool even = false, first = true;

    sort(arr, arr + n);

    if(k % 2 == 0) even = true;

    if (arr[n - 1] == 0 && !even) return 0; // 6 5 || -5 -4 -3 -2 -1 0 // ans = 0

    if (arr[n - 1] <= 0 && !even) // 4 3 || -4 -3 -2 -1 // ans = -6
    {
        for (int i = n - 1; i >= n - k; i--)
        {
            if(first)
            {
                ans = mod(arr[i],_mod);
                first = false;
            }
            else ans = mod_mul(ans, arr[i], _mod);
        }
        return ans;
    }

    if (!even)
    {
        ans = mod(arr[r], _mod);
        first = false;
        r--;
        k--;
    }

    for (int i = 0; i < k / 2; i++)
    {
        long long mul_of_left = arr[l] * arr[l + 1];
        long long mul_of_right = arr[r] * arr[r - 1];

        if (mul_of_left > mul_of_right)
        {
            if(first)
            {
                ans = mod(mul_of_left, _mod);
                first = false;
            }
            else ans = mod_mul(ans, mul_of_left, _mod);
            l += 2;
        }
        else
        {
            if(first)
            {
                ans = mod(mul_of_right, _mod);
                first = false;
            }
            else ans = mod_mul(ans, mul_of_right, _mod);
            r -= 2;
        }
    }
    return ans;
}

int main()
{
    //long long test1 = mod_mul(1000000055, 345678, _mod); //1000000055 345678 876543

    //cout << mod_mul(test1, 876543, _mod);

    int n, k;
    scanf("%d %d", &n, &k);

    long long arr[n];
    for (int i = 0; i < n; ++i)
        scanf("%lld", &arr[i]);

    cout << func(arr, n, k);

    return 0;
}