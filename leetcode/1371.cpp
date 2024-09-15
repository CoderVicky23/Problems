#include<bits/stdc++.h>

using namespace std;
// int lowestSubstring(string& s) {
//     unordered_map <string, int> hash;
//     vector <int> state (5, 0);
//     string curr = "00000";
//     hash[curr] = -1;
//     int result = 0;

//     for (int i=0; i<s.size(); i++) {
//         if (s[i] == 'a') {
//             state[0] = (state[0] + 1) % 2;
//         } else if (s[i] == 'e') {
//             state[1] = (state[1] + 1) % 2;
//         } else if (s[i] == 'i') {
//             state[2] = (state[2] + 1) % 2;
//         } else if (s[i] == 'o') {
//             state[3] = (state[3] + 1) % 2;
//         } else if (s[i] == 'u') {
//             state[4] = (state[4] + 1) % 2;
//         }
//         curr = "";
//         for (int j=0; j<5; j++) {
//             if (state[j] == 1) curr += '1';
//             else curr += '0';
//         }
//         if (hash.find(curr) != hash.end()) {
//             result = max(result, i - hash[curr]);
//         } else {
//             hash[curr] = i;
//         }
//     }
//     return result;
// }

int lowestSubstring(string& s) {
    int result = 0;
    unordered_map <int, int> hash;
    int mask = 0;
    hash[0] = -1;
    for (int i=0; i<s.size(); i++) {
        if (s[i] == 'a') {
            mask = (mask ^ (1 << 0));
        } else if (s[i] == 'e') {
            mask = (mask ^ (1 << 1));
        } else if (s[i] == 'i') {
            mask = (mask ^ (1 << 2));
        } else if (s[i] == 'o') {
            mask = (mask ^ (1 << 3));
        } else if (s[i] == 'u') {
            mask = (mask ^ (1 << 4));
        }
        if (hash.find(mask) != hash.end()) {
            result = max(result, i - hash[mask]);
        }
        else {
            hash[mask] = i;
        }
    }
    return result;
}

int main()
{
    string s = "eleetminicoworoep";
    cout << lowestSubstring(s) << endl;
    return 0;
}