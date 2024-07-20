#include <bits/stdc++.h>
using namespace std;

string getSmallestString(string s) {
    for (int i=1; i<s.size(); i++) {
        if (s[i]%2 == s[i-1]%2 && s[i] < s[i-1]) {
            swap(s[i], s[i-1]);
            return s;
        }
    }
    return s;
}

int main() {
    string s = "45320";
    cout << getSmallestString(s) << endl;
    return 0;
}