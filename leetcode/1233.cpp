#include <bits/stdc++.h>
using namespace std;

int lenCount(string& a) {
    int siz = 0;
    for (int i=0; i<a.size(); i++) {
        if (a[i] == '/') siz++;
    }
    return siz;
}

static bool compare(string& a, string& b) {
    if (lenCount(a) < lenCount(b)) return 1;
    return 0;
}

vector <string> removeFolders (vector <string>& folder) {
    int n = folder.size();
    sort(folder.begin(), folder.end(), compare);
    unordered_set <string> hash;
    for (string s: folder) {
        string sub = "/";
        for (int i=1; i<=s.size(); i++) {
            if (s[i] == '\0') {
                if (hash.find(sub) != hash.end()) {
                    break;
                } else {
                    hash.insert(sub);
                }
            }else if (s[i] == '/') {
                if (hash.find(sub) != hash.end()) {
                    break;
                } else {
                    sub += s[i];
                }
            } else {
                sub += s[i];
            }
        }
    }
    vector <string> result = {hash.begin(), hash.end()};
    return result;
}

int main() {
    vector <string> folder = {"/ah/al/am","/ah/al"};
    vector <string> result = removeFolders(folder);
    for (auto i: result) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}