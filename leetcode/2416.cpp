#include<bits/stdc++.h>
using namespace std;

vector <int> sumPrefixScore(vector <string>& words) {
    unordered_map <string, int> hash;
    for (auto s: words) {
        string st = "";
        for (char c: s) {
            st += c;
            hash[st] += 1;
        }
    }

    vector <int> result;
    for (auto s: words) {
        string st = "";
        int count = 0;
        for (char c: s) {
            st += c;
            count += hash[st];
        }
        result.push_back(count);
    }
    return result;
}

// vector <int> sumPrefixScore(vector <string> words) {
//     unordered_map <string, vector <int>> hash;
//     for (int i=0; i<words.size(); i++) {
//         string s = words[i];
//         string st = "";
//         for (char c: s) {
//             st += c;
//             if (hash.find(st) == hash.end()) {
//                 hash[st] = {i};
//             } else {
//                 hash[st].push_back(i);
//             }
//         }
//     }
//     vector <int> result (words.size(), 0);
//     for (auto i: hash) {
//         for (int j: i.second) {
//             result[j] += i.second.size();
//         }
//     }
//     return result;
// }

int main()
{
    vector <string> words = {"abc","ab","bc","b"};
    for (int i:sumPrefixScore(words)) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}