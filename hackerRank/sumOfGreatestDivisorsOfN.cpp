#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        if (k%2 == 0){
            cout << 2*k << endl;
        } else {
            int m = 2*k + 3*k;
            cout << m << endl;
        }
    }
    return 0;
}