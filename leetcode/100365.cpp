#include <bits/stdc++.h>
using namespace std;

// greedy algo (failed)
// vector <int> nums = {1,1,1,1,0,0,0,5,4,3,19,17,16,15,15,15,19,19,19,19};
// int k = 20;
// int minChanges(vector <int> nums, int k) {
//         int n = nums.size();
//         unordered_map <int, int>  hass;
//         int changes = 0;
//         int max_occur = 0;
//         int zero_occur = 0;
//         int non_zero_occur = 0;
//         for (int i=0; i<n/2; i++) {
//             int k = abs(nums[i] - nums[n-i-1]);
//             hass[k]++;
//         }
//         int max_occur_first = INT_MAX;
//         for (auto i: hass) {
//             cout << i.first << " " << i.second << endl;
//             if (i.second >= max_occur) {
//                 if (i.second == max_occur) max_occur_first = min(max_occur_first, i.first);
//                 else max_occur_first = i.first;
//                 max_occur = i.second;
//             }
//             if (i.first == 0) zero_occur += i.second;
//             else non_zero_occur += i.second;
//         }
//         int changing_zero;
//         // cout << "max occur first : " << max_occur_first << endl;
//         if (max_occur_first >= k/2) {
//             changing_zero = 2*zero_occur;
//         } else {
//             changing_zero = zero_occur;
//         }
//         int changing_non_max = non_zero_occur - max_occur;
//         if (changing_zero + changing_non_max > non_zero_occur) {
//             return non_zero_occur;
//         } else {
//             return changing_zero + changing_non_max;
//         }
// }

int minChanges(vector <int>& nums, int k) {
    int n = nums.size();
    unordered_map <int, int> hash;
    vector <int> order;
    for (int i=0; i<n/2; i++) {
        int m = abs(nums[i] - nums[n-i-1]);
        order.push_back(m);
        hash[m]++;
    }
    int result = INT_MAX;
    for (auto z: hash) {
        int changes = 0;
        for (int i=0; i<order.size(); i++) {
            int m = z.first;
            int min_element = min(nums[i], nums[n-i-1]);
            int max_element = max(nums[i], nums[n-i-1]);
            if (m == order[i]) {
            } else if (min_element <= k - m || max_element >= m) {
                changes += 1;
            } else {
                changes += 2;
            }
        }
        result = min(changes, result);
    }
    return result;
}



int main() {
    vector <int> nums = {1,1,1,1,0,0,0,5,4,3,19,17,16,15,15,15,19,19,19,19};
    int k = 20;
    cout << minChanges(nums, k) << endl;
    return 0;
}




int minChanges2(vector <int>& nums, int k) {
    int n = nums.size();
    vector <int> spare = nums;
    sort(spare.begin(), spare.end());
    int z = spare[n/2];
    int changes = 0;
    for (int i=0; i<n/2; i++) {
        if (max(nums[i], nums[n-i-1]) <= z) {
            changes += 1;
        }
    }
    return z;
}