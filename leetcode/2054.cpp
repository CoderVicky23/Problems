#include <bits/stdc++.h>
using namespace std;

int n;

int binarySearch(vector<vector<int>>& events, int endTime) {
    int l = 0;
    int r = n-1;
    int res = n;
    while (l <= r) {
        int mid = l + (r-l)/2;
        if (events[mid][0] > endTime) {
            res = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return res;
}

int solve(vector<vector<int>>& events, int ind, int count) {
    if (count == 2 || ind >= n) return 0;
    int nxtValidInd = binarySearch(events, events[ind][1]);
    int take = events[ind][2] + solve(events, nxtValidInd, ++count);
    int skip = solve(events, ind+1, count);
    return max(take, skip);
}

int recMaxTwoEvents(vector<vector<int>>& events) {
    n = events.size();
    sort(events.begin(), events.end());
    int count = 0;
    return solve(events, 0, count);
}

int maxTwoEvents(vector <vector<int>>& events) {
    int n = events.size();
    int result = 0;
    sort(events.begin(), events.end());
    for (int i=0; i<n; i++) {
        int val = events[i][2];
        for (int j=i+1; j<n; j++) {
            if (events[i][1] < events[j][0]) {
                val += events[j][2];
                result = max(result, val);
            }
        }
    }
    return result;
}

int main() {
    vector<vector <int>> events = {{1,3,2},{4,5,2},{2,4,3}};
    cout << maxTwoEvents(events) << endl;
    return 0;
}