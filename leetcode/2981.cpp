#include <bits/stdc++.h>
using namespace std;

int maximumLength(string s) {
    int n = s.length();
    int result = 0;
    unordered_map <string, int> hash;
    for (int i=0; i<n; i++) {
        string sub = "";
        int len = 0;
        for (int j=i; j<n; j++) {
            if (s[j] != s[i]) break;
            sub += s[j];
            hash[sub]++;
            len++;
            if (hash[sub] > 2) result = max(result, len);
        }
    }
    if (result == 0) return -1;
    return result;
}

int main(){
    string s = "abcdef";
    // maximumLength(s);
    cout << maximumLength(s) << endl;
    return 0;
}