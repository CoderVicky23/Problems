#include <iostream>
#include <fstream>
#include <unordered_map>
using namespace std;

int longestSubstring(string s, int k) {
    int n = s.size();
    int left = 0, right = 0;
    int max_len = 0;
    unordered_map <char, int> count;
    while (right < n) {
        count[s[right]]++;
        if (count.size() > k) {
            count[s[left]]--;
            if (count[s[left]] == 0) count.erase(s[left]);
            left++;
        }
        if (count.size() <= k) {
            max_len = max(max_len, right-left+1);
        }
        right++;
    }
    return max_len;
}

int main() {
    ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        cerr << "File not open!" << endl;
        return 1;
    }
    int k;
    inputFile >> k;
    string s;
    inputFile >> s;
    cout << longestSubstring(s, k) << endl;
}