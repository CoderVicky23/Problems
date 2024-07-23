#include <bits/stdc++.h>
using namespace std;

string Love(string s, int n, int m, int k) {
    int ind = 0;
    while (ind < s.size()) {
        if (s[ind] == 'L') {
            ind++;
        }
        else if (s[ind] == 'C') {
            int c_len = 0;
            while (ind < s.size() && s[ind] == 'C') {
                c_len++;
                ind++;
            }
            if (c_len > m) return "NO";
        } else if (s[ind] == 'W') {
            int w_len = 0;
            while (ind < s.size() && s[ind] == 'W')
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        string s;
        cin >> s;
        cout << Love(s, n, m, k) << endl;
    }
    return 0;
}