#include <bits/stdc++.h>

using namespace std;

vector <vector <int>> fourSumHash(vector <int>& nums, int target) {
    int n = nums.size();
    set <vector <int>> ans;
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            unordered_set <long long> hash;
            for (int k=j+1; k<n; k++) {
                long long sum = nums[i];
                sum += nums[j];
                sum += nums[k];
                long long diff = target-sum;
                if (hash.find(diff) != hash.end()) {
                    vector <int> a = {nums[i], nums[j], nums[k],(int) diff};
                    sort(a.begin(), a.end());
                    ans.insert(a);
                }
                hash.insert(nums[k]);
            }
        }
    }
    vector <vector <int>> result(ans.begin(), ans.end());
    return result;
}

vector <vector <int>> fourSum(vector <int>& nums, int target) {
    int n = nums.size();
    if (n < 4) return {{}};
    vector <vector<int>> ans;
    sort(nums.begin(), nums.end());
    for (int i=0; i<n; i++) {
        if (i > 0 && nums[i] == nums[i-1]) continue;
        for (int j = i+1; j<n; j++) {
            if (j > i+1 && nums[j] == nums[j-1]) continue;
            int k = j+1, l = n-1;
            while (k < l) {
                long long sum = nums[i];
                sum += nums[j];
                sum += nums[k];
                sum += nums[l];
                if (sum == target) {
                    ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                    k++;
                    l--;
                    while (k < l && nums[k] == nums[k-1]) k++;
                    while (k < l && nums[l] == nums[l+1]) l--;
                } else if (sum < target) {
                    k++;
                } else l--;
            }
        }
    }
    return ans;
}

int main() {
    vector <int> nums = {1, 2, -1, -2, 2, 0, -1, 0};
    int target = 0;
    for (auto i:fourSum(nums, target)) {
        for (int j=0; j<4; j++) {
            cout << i[j] << " ";
        }
        cout << endl;
    }

    return 0;
}