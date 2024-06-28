#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <algorithm>

using namespace std;

// brute force approach
// time complexity O(N^3)
// space complexity O(3*answer_sets)
vector <vector <int>> threeSumBrute(vector <int>& nums) {
    set <vector <int>> st;
    int n = nums.size();
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            for (int k=j+1; k<n; k++) {
                if (nums[i]+nums[j]+nums[k] == 0) {
                    vector <int> a = {nums[i], nums[j], nums[k]};
                    sort(a.begin(), a.end());
                    st.insert(a);
                }
            }
        }
    }
    vector <vector <int>> ans(st.begin(), st.end());
    return ans;
}

// better approach
// time complexity O(n^2)
// space complexity O(n) + O(answer_sets*3)
vector <vector <int>> threeSumBetter(vector <int>& nums) {
    unordered_set <int> hash;
    set <vector <int>> st;
    int n = nums.size();
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            int a = -(nums[i]+nums[j]);
            if (hash.find(a) != hash.end()) {
                vector <int> b = {nums[i], nums[j], a};
                sort(b.begin(), b.end());
                st.insert(b);
            }
            hash.insert(nums[j]);
        }
        hash.clear();
    }
    vector <vector <int>> ans(st.begin(), st.end());
    return ans;
}

vector <vector <int>> threeSum(vector <int>& nums) {
    vector <vector <int>> ans;
    int n = nums.size();
    int l = 0, r = n-1;
    int m = 1;
    sort(nums.begin(), nums.end());
    while (l < n) {
        if (l > 0 && nums[l] == nums[l-1]){
            l++;
            continue;
        }
        m = l+1;
        r = n-1;
        while (m < r) {
            if (nums[l]+nums[r]+nums[m] == 0) {
                ans.push_back({nums[l], nums[r], nums[m]});
                m++;
                r--;
                while (m < r && nums[m-1] == nums[m]) m++;
                while (m < r && nums[r+1] == nums[r]) r--;
            }
            else if (nums[l]+nums[r]+nums[m] < 0) {
                m++;
            } else {
                r--;
            }
        }
        l++;
    }
    return ans;
}

int main() {
    vector <int> nums = {-1, 0, 1, 2, 2, -1, -4};
    for (auto i: threeSum(nums)) {
        for (int j=0; j<3; j++) {
            cout << i[j] << " ";
        }
        cout << endl;
    }
    return 0;
}