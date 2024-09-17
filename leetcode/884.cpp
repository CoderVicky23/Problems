#include<bits/stdc++.h>
using namespace std;

vector <string> uncommon(string s1, string s2) {
    unordered_map <string, int> hash1;
    unordered_map <string, int> hash2;
    vector <string> result;
    int i=0;
    string sample = "";
    while (s1[i] != '\0') {
        if (s1[i] == ' ') {
            if (hash1.find(sample) != hash1.end()) {
                hash1[sample]++;
            } else {
                hash1[sample] = 1;
            }
            sample = "";
        }
        else sample += s1[i];
        i++;
    }
    if (hash1.find(sample) != hash1.end()) {
        hash1[sample]++;
    } else hash1[sample] = 1;

    i = 0;
    sample = "";
    while (s2[i] != '\0') {
        if (s2[i] == ' ') {
            if (hash2.find(sample) != hash2.end()) {
                hash2[sample]++;
            } else {
                hash2[sample] = 1;
            }
            sample = "";
        }
        else sample += s2[i];
        i++;
    }
    if (hash2.find(sample) != hash2.end()) {
        hash2[sample]++;
    } else hash2[sample] = 1;

    for (auto i=hash1.begin(); i!=hash1.end(); i++) {
        if (i->second == 1 && hash2.find(i->first) == hash2.end()) result.push_back(i->first);
    }
    for (auto i=hash2.begin(); i!= hash2.end(); i++) {
        if (i->second == 1 && hash1.find(i->first) == hash1.end()) result.push_back(i->first);
    }
    return result;
}

int main()
{
    string s1 = "apple apple";
    string s2 = "banana";
    for (string s: uncommon(s1, s2)) {
        cout << s << endl;
    }
    return 0;
}