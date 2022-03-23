#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

int main()
{
    vector<vector<int>> vv = {  {1087388483},
                                {1021, 1065023},
                                {1031, 1054693},
                                {1033, 1052651},
                                {1021, 1031, 1033}};
    vector<int> v;

    int x,N;
    cin >> N;

    for (int i = 0; i < N; i++){
        cin >> x;
        v.push_back(x);
    }

    sort(begin(v), end(v));

    bool is_include = false;

    for (int i = 0; i < vv.size(); i++){
        is_include = includes(begin(v), end(v), begin(vv[i]), end(vv[i]));
        if(is_include) break;
    }

    if(is_include) cout << "YES";
        else cout << "NO";

    return 0;
}
