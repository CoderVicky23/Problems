#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    int n = candidates.size();
    
}

int main()
{
    vector <int> candidates = {10,1,2,7,6,1,5};
    int target = 8;
    for (vector <int> i: combinationSum2(candidates, target)) {
        for (int j: i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}