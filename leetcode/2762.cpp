#include <bits/stdc++.h>
using namespace std;

// bool check(int& a, int& b) {
//     int diff = abs(a - b);
//     if (diff >= 0 && diff <= 2) return 1;
//     return 0;
// }

long long fun(vector<int>& nums) {
    int n = nums.size();
    map <int, int> mp;
    int i = 0;
    int j = 0;
    long long count = 0;
    while (j < n) {
        mp[nums[j]]++;
        while (abs(mp.rbegin()->first - mp.begin()->first) > 2) {
            mp[nums[i]]--;
            if (mp[nums[i]] == 0) {
                mp.erase(nums[i]);
            }
            i++;
        }
        count += j - i + 1;
        j++;
    }
    return count;
}

// long long continuousSubarrays(vector<int>& nums) {
//     int n = nums.size();
//     long long result = n;
//     int start = 0;
//     int end = 1;
//     while (end < n) {
//         int max = start;
//         int min = end-1;
//         for (int i=start; i<end; i++) {
//             max = nums[max] > nums[i] ? max : i;
//             min = nums[min] > nums[i] ? i : min;
//         }
//         if (check(nums[max], nums[min])) {
//             end++;
//         } else {
//             long long nm = end - start - 1;
//             long long val = (nm * (nm + 1))/2;
//             result += val;
//             cout << start << " " << end << " " << val << endl;
//             while (!check(nums[max], nums[min])) {
//                 start++;
//                 max = start;
//                 min = end-1;
//                 for (int i=start; i<end; i++) {
//                     max = nums[max] > nums[i] ? max : i;
//                     min = nums[min] > nums[i] ? i : min;
//                 }
//             }
//             end++;
//         }
//     }
//     return result;
// }

int main() {
    vector <int> nums = {5,4,2,4,3,6,7,9,12,11,5,4};
    cout << fun(nums) << endl;
    // cout << continuousSubarrays(nums) << endl;
    return 0;
}