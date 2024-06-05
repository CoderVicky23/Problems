#include <bits/stdc++.h>
using namespace std;

void print(int * arr, int n) {
    for (int i=0; i<n; i++) {
        if (arr[i]) {
            cout << char(97+i) << " ";
        }
    }
    cout << endl;
}
vector<string> commonChars(vector<string>& words) {
    int n = words.size();
    vector <string> ans;
    unordered_map <char, int> count;
    int arr[26] = {0};
    for (int i=0; i<words[0].size(); i++) {
        arr[words[0][i]-97]++;
    }
    // print(arr, 26);
    for (int i=1; i<n; i++) {
        int j=0;
        while (words[i][j] != '\0') {
            count[words[i][j]]++;
            j++;
        }
        for (int k=0; k<26; k++) {
            arr[k] = min(arr[k], count['a'+k]);
        }
        count.erase(count.begin(), count.end());
    }
    for (int i=0; i<26; i++) {
        if (arr[i]) {
            while (arr[i]) {
                ans.push_back(string(1, 'a'+i));
                arr[i]--;
            }
        }
    }
    return ans;
}

int main() {
    vector<string> words = {"cool", "lock", "cook"};
    vector<string> result = commonChars(words);
    for (auto c: result) {
        cout << c << endl;
    }
    return 0;
}