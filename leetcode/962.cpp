#include<bits/stdc++.h>

using namespace std;

int maxRamp(vector <int>& nums) {
    int n = nums.size();
    stack <int> s;
    s.push(0);
    int maxi = 0;
    for (int i=1; i<n; i++) {
        if (nums[i] < nums[s.top()]) s.push(i);
    }
    for (int i=n-1; i>=0; i--) {
        if (s.empty()) break;
        while (!s.empty() && nums[s.top()] <= nums[i]) {
            maxi = max(maxi, i-s.top());
            s.pop();
        }
    }
    return maxi;
}

int main()
{
    vector <int> nums = {9,8,1,0,1,9,4,0,4,1};
    cout << maxRamp(nums) << endl;
    return 0;
}