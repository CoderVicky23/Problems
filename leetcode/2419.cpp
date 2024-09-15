#include<bits/stdc++.h>
using namespace std;

int longestSubarray(vector <int>& nums) {
    int n = nums.size();
    int largest = nums[0];
    int streak = 1;
    int max_streak = 1;
    for (int i=1; i<n; i++) {
        if (nums[i] == largest) {
            streak++;
        } else if (nums[i] > largest) {
            largest = nums[i];
            streak = 1;
            max_streak = 1;
        } else {
            streak = 0;
        }
        max_streak = max(max_streak, streak);
    }
    return max_streak;
}

int main()
{
    vector <int> nums = {1,2,3,3,2,2};
    // cout << longestSubarray(nums) << endl;
    cout << (1 & 2) << endl;
    cout << (2 & 3) << endl;
    cout << (3 & 4) << endl;
    return 0;
}