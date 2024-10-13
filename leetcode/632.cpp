#include <bits/stdc++.h>
using namespace std;

vector <int> smallestRange(vector <vector <int>>& nums) {
    int k = nums.size();
    
    priority_queue <vector <int>, vector <vector <int>>, greater<vector <int>>> pq;

    int maxEl = INT_MIN;
    for (int i = 0; i<k; i++) {
        pq.push({nums[i][0], i, 0});
        maxEl = max(maxEl, nums[i][0]);
    }

    vector <int> resultRange = {-1000000, 1000000};

    while (!pq.empty()) {
        vector <int> cur = pq.top();
        pq.pop();

        int minEl = cur[0];
        int listIdx = cur[1];
        int idx = cur[2];

        if (maxEl - minEl < resultRange[1] - resultRange[0]) {
            resultRange[0] = minEl;
            resultRange[1] = maxEl;
        }

        if (idx+1 < nums[listIdx].size()) {
            int nextElement = nums[listIdx][idx+1];
            pq.push({nextElement, listIdx, idx+1});
            maxEl = max(maxEl, nextElement);
        }
        else {
            break;
        }
    }
    return resultRange;
}

int main() {
    vector <vector <int>> nums = {{4,10,15,24,26},{0,9,12,20},{5,18,22,30}};
    for (int i: smallestRange(nums)) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}