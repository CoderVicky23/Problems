#include<bits/stdc++.h>

using namespace std;
// int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
//     int ans = 0;
//     unordered_set <string> hash;
//     for (int i: arr1) {
//         string s = to_string(i);
//         string p = "";
//         p += s[0];
//         hash.insert(p);
//         for (int j=1; j<s.size(); j++) {
//             p += s[j];
//             hash.insert(p);
//         }
//     }
//     for (auto i: hash) {
//         for (int j: arr2) {
//             string s = to_string(j);
//             int r = 0;
//             for (int k=0; k<s.size() && k < i.size(); k++) {
//                 if (i[k] == s[k]) {
//                     r++;
//                 } else {
//                     ans = max(ans, r);
//                     break;
//                 }
//             }
//             ans = max(ans, r);
//         }
//     }
//     return ans;
// }

int longestCommonPrefix(vector <int>& arr1, vector <int>& arr2) {
    int res = 0;
    unordered_set <int> hash;
    for (int i: arr1) {
        while (i && hash.find(i) == hash.end()) {
            hash.insert(i);
            i /= 10;
        }
    }
    for (int i: arr2) {
        while (i && hash.find(i) == hash.end()) {
            i /= 10;
        }
        if (i) {
            res = max(res, (int) log10(i)+1);
        }
    }
    return res;
}

int main()
{
    vector <int> arr1 = {1, 2, 3, 60, 600, 5};
    vector <int> arr2 = {6, 60, 6000};
    cout << longestCommonPrefix(arr1, arr2) << endl;
    return 0;
}