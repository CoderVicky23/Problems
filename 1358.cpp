#include <iostream>
#include <fstream>
#include <unordered_map>
using namespace std;

// brute force
// time complexity - O(N);
// space complexity - O(1);
// int numberOfStrings(string s) {
//     int n = s.size();
//     int count = 0;
//     for (int i=0; i<n; i++) {
//         int hash[3] = {0};
//         for (int j=i; j<n; j++) {
//             hash[s[j]-'a'] = 1;
//             if (hash[0]+hash[1]+hash[2] == 3) {
//                 count += (n-j);
//                 break;
//             }
//         }
//     }
//     return count;
// }

int numberOfStrings(string s) {
    int n = s.size();
    int left = 0, right = 0;
    int subs = 0;
    unordered_map <char, int> count;
    while (right < n) {
        count[s[right]]++;
        while (count.size() == 3) {
            subs += n - right;
            count[s[left]]--;
            if (count[s[left]] == 0) count.erase(s[left]);
            left++;
        }
        right++;
    }
    return subs;
}

int main() {
    // reading from input.txt
    ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        cerr << "File not open!" << endl;
        return 1;
    }

    string s;
    inputFile >> s;

    cout << numberOfStrings(s) << endl;

    // closing inputFile object
    inputFile.close();
    return 0;
}