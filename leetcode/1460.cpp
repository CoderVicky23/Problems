#include<bits/stdc++.h>

using namespace std;

bool canBeEqual(vector<int>& target, vector<int>& arr) {
    int n = target.size();
    unordered_map <int, int> hash1;
    unordered_map <int, int> hash2;
    for (int i=0; i<n; i++) {
        hash1[target[i]]++;
        hash2[arr[i]]++;
    }
    if (hash1.size() != hash2.size()) return 0;
    for (auto i: hash1) {
        if (hash2[i.first] != i.second) {
            return 0;
        }
    }
    return 1;
}

int main()
{
    vector <int> target = {2,4,1,3};
    vector <int> arr = {1,2,3,4};
    cout << canBeEqual(target, arr) << endl;
    return 0;
}