#include <bits/stdc++.h>
using namespace std;

bool closeStrings(string word1, string word2) {
    if (word1.size() != word2.size()) return false;
    int n = word1.size();
    int hash1[26] = {};
    int hash2[26] = {};
    unordered_map <int, int> count;
    for (int i=0; i<n; i++) {
        hash1[word1[i]-'a']++;
    }
    for (int i=0; i<n; i++) {
        if (hash1[word2[i]-'a']) {
            hash2[word2[i]-'a']++;
        } else {
            return false;
        }
    }
    for (int i=0; i<26; i++) {
        if (hash1[i]) {
            count[hash1[i]]++;
        }
    }
    for (int i=0; i<26; i++) {
        if (hash2[i]) {
            count[hash2[i]]--;
        }
    }
    for (auto i = count.begin(); i != count.end(); i++) {
        if (i->second) {
            return false;
        }
    }
    return true;
}