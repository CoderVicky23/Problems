#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n,s,m;
        cin >> n >> s >> m;
        vector <pair <int, int>> hours;
        for (int i=0; i<n; i++) {
            int a, b;
            cin >> a >> b;
            hours.push_back({a,b});
        }
        int start = 0;
        bool flag = 0;
        for (int i=0; i<n; i++) {
            if (hours[i].first - start >= s) {
                cout << "YES" << endl;
                flag = 1;
                break;
            } else {
                start = hours[i].second;
            }
        }
        if (!flag) {
            if (m - start >= s) {
                cout << "YES" << endl;
            }
            else {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}