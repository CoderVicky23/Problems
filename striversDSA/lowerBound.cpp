#include<bits/stdc++.h>

using namespace std;

int main()
{
    vector <int> a = {1, 5, 8, 10, 11, 12, 19};
    int n = a.size();
    auto lb = lower_bound(a.begin(), a.end(), 6) - a.begin();
    cout << lb << endl;
    return 0;
}