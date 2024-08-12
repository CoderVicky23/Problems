#include <bits/stdc++.h>

using namespace std;

// THIS CODE MAY WORK FOR SUBSTRING CASE NOT SUBSEQUENCE
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s, t;
        cin >> s >> t;
        int n = s.size();
        int m = t.size();
        bool found = false;

        for (int left = 0; left <= n - m; left++) {
            string newString = s; // Reset newString in each iteration
            bool flag = true;

            for (int i = 0; i < m; i++) {
                if (s[left + i] == t[i] || s[left + i] == '?') {
                    newString[left + i] = t[i];
                } else {
                    flag = false;
                    break;
                }
            }

            if (flag) {
                for (int i=0; i<n; i++) {
                    if (newString[i] == '?') {
                        newString[i] = 'a';
                    }
                }
                found = true;
                cout << "YES" << endl;
                cout << newString << endl;
                break;
            }
        }

        if (!found) {
            cout << "NO" << endl;
        }
    }
    return 0;
}
