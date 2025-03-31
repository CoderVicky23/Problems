#include <bits/stdc++.h>
using namespace std;

int countPalindromicSubsequence(string s) {
    int n = s.size();
    unordered_map <char, int> right;
    unordered_set <char> left;
    unordered_set <string> res;
    for (char c: s) {
        right[c]++;
    }
    for (char c: s) {
        right[c]--;
        for (char i: left) {
            if (right[i] > 0) {
                string str = "";
                str += i;
                str += c;
                res.insert(str);
            }
        }
        left.insert(c);
    }
    return res.size();
}

// int countPalindromicSubsequence(string s) {
//     int count = 0;
//     unordered_set <char> left;
//     unordered_map <char, int> right;
//     unordered_set <string> st;
//     int n = s.length();
//     for (char c: s) {
//         right[c]++;
//     }
//     int m = 0;
//     while (m < n) {
//         right[s[m]]--;
//         for (char i: left) {
//             if (right.find(i) != right.end()) {
//                 string str = "";
//                 str += i + s[m];
//                 if (st.find(str) == st.end()) {
//                     st.insert(str);
//                     count++;
//                 }
//             }
//         }
//         left.insert(s[m]);
//         m++;
//     }
//     return count;
// }

int countPalindromicSubsequence2(string s) {
    int n = s.size();
    unordered_set <string> st;
    int onesPlace[26] = {0};
    for (int i=0; i<n; i++) {
        if (onesPlace[s[i]-'a']) continue;
        onesPlace[s[i]-'a']++;
        int tensPlace[26] = {0};
        for (int j=i+1; j<n; j++) {
            if (tensPlace[s[j]-'a']) continue;
            tensPlace[s[j]-'a']++;
            for (int k=j+1; k<n; k++) {
                if (s[k] == s[i]) {
                    string str = "";
                    str += s[i] + s[j] + s[k];
                    st.insert(str);
                }
            }
        }
    }
    return st.size();
}

int main() {
    string s = "bbcbaba";
    cout << countPalindromicSubsequence(s) << endl;
    return 0;
}