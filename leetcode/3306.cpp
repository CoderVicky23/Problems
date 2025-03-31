#include <bits/stdc++.h>
using namespace std;

bool isVowel(char &ch) {
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

long long countOfSubstrings(string word, int k) {
    int n = word.size();
    unordered_map <char, int> mp;

    // array to store the next consonant index
    vector<int> nextConsArray (n);
    int lastIdx = n;
    for (int i=n-1; i>=0; i--){
        nextConsArray[i] = lastIdx;
        if (!isVowel(word[i])) lastIdx = i;
    }

    // code to count the number of substrings
    long long count = 0;
    int left = 0;
    int right = 0;
    int flag = 0;
    
    while (right < n) {
        char ch = word[right];
        if (isVowel(ch)) {
            mp[ch]++;
        } else {
            flag++;
        }
        while (mp.size() > 5 && flag == k) {
            count += nextConsArray[right] - right;
            char c = word[left];
            if (isVowel(c)){
                mp[c]--;
                if (mp[c] == 0) mp.erase(c);
            } else {
                flag--;
            }
            left++;
        }
        right++;
    }
    return count;
}

int main() {
    string word = "ieaouqqieaouqq";
    int k = 1;
    cout << countOfSubstrings(word, k) << endl;
    return 0;
}