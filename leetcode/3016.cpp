#include<bits/stdc++.h>
using namespace std;

bool compare(const pair<char, int>& a, const pair<char, int>& b) {
    return a.second > b.second;
}
int minimumPushes(string word) {
    unordered_map <char, int> hash;
    for (char c: word) {
        hash[c]++;
    }
    vector <pair <char, int>> arr;
    for (const auto& i: hash) {
        arr.push_back(i);
    }
    sort(arr.begin(), arr.end(), compare);
    for (auto i: arr) {
        cout << i.first << " " << i.second << endl;
    }
    int count = 0;
    int result = 0;
    for (pair i: arr) {
        if (count < 8) {
            result += i.second;
        } else if (count < 16) {
            result += 2*(i.second);
        } else if (count < 24) {
            result += 3*(i.second);
        } else {
            result += 4*(i.second);
        }
        count++;
    }
    return result;
}

int main()
{
    string word = "aabbccddeeffgghhiiiiii";
    cout << minimumPushes(word) << endl;
    return 0;
}