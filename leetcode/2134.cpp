#include<bits/stdc++.h>

using namespace std;

int minSwaps(vector<int>& nums) {
    int totalOnes = 0;
    for (int i=0; i<nums.size(); i++) {
        if (nums[i] == 1) totalOnes++;
    }
    int left = 0;
    int right = 0;
    int oneCountWindow = 0;
    int maxOnesHit = 0;
    while (right < 2*nums.size()) {
        oneCountWindow += nums[right % nums.size()];
        if (right - left + 1 > totalOnes) {
            oneCountWindow -= nums[left % nums.size()];
            left++;
        }
        maxOnesHit = max(maxOnesHit, oneCountWindow);
        right++;
    }
    return totalOnes - maxOnesHit;
}

int main()
{
    vector <int> nums = {0,1,1,1,0,0,1,1,0};
    cout << minSwaps(nums) << endl;
    return 0;
}