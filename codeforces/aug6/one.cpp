#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int _sum = 0;
        while (n > 0) {
            int rem = n%10;
            _sum += rem;
            n = n/10;
        }
        cout << _sum << endl;
    }
    return 0;
}