#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        string s,t;
        cin >> s >> t;
        int j = 0;
        bool flag = 0;
        for (int i=0; i<s.size(); i++) {
            if (s[i] == t[j]) {
                j++;
            }
            else if (s[i] == '?') {
                s[i] = t[j++];
            }
            if (j == t.size()) {
                for (int m=i+1; m<s.size(); m++) {
                    if (s[m] == '?') s[m] = 'a';
                }
                cout << "YES" << endl;
                cout << s << endl;
                flag = 1;
                break;
            }
        }
        if (!flag)
        cout << "NO" << endl;
    }
    return 0;
}