#include <bits/stdc++.h>
using namespace std;

vector <vector <int>> mergeIntervals1(vector <vector <int>>& arr) {
    vector <vector <int>> result;
    int n = arr.size();
    int hash[10001] {0};
    for (int i=0; i<n; i++) {
        for (int j=arr[i][0]; j<=arr[i][1]; j++) {
            hash[j] = 1;
        }
    }
    int flag = 0;
    for (int i=0; i<10001; i++) {
        if (hash[i] == 1) {
            if (flag) {
                continue;
            }
            else {
                flag = i;
            }
        }
        else if (hash[i] == 0 && flag) {
            vector <int> x = {flag, i-1};
            result.push_back(x);
            flag = 0;
        }
    }
    return result;
}

vector <vector <int>> mergeIntervals2(vector <vector <int>>& arr) {
    if (arr.size() <= 1) return arr;
    vector <vector <int>> result;
    sort(arr.begin(), arr.end());
    int start = arr[0][0];
    int end = arr[0][1];
    for (int i=1; i<arr.size(); i++) {
        if (end >= arr[i][0]) {
            end = max(end, arr[i][1]);
        } else {
            vector <int> x = {start, end};
            result.push_back(x);
            start = arr[i][0];
            end = arr[i][1];
        }
    }
    result.push_back({start, end});
    return result;
}

int main() {
    vector <vector <int>> arr = {{1,4}, {2,3}};
    for (auto i: mergeIntervals2(arr)) {
        cout << i[0] << " " << i[1] << endl;
    }
    return 0;
}