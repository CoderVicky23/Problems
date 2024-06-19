// sorting 0, 1 and 2.

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void print(vector <int>& nums) {
    for (int i: nums) {
        cout << i << " ";
    }
    cout << endl;
}

// using hashing approach
void sortColorsHash(vector <int>& nums) {
    unordered_map <int, int> count;
    for (int i=0; i<nums.size(); i++) {
        count[ nums[i] ]++;
    }
    int i = 0;
    while (count[0]--) {
        nums[i++] = 0;
    }
    while (count[1]--) {
        nums[i++] = 1;
    }
    while (count[2]--) {
        nums[i++] = 2;
    }
}

// using 2pointers
void sortColor(vector <int>& nums) {
    int i = 0;
    int j = 0;
    int k = nums.size() - 1;
    while (i < k) {
        while (nums[k] == 2) {
            k--;
        }
        while (nums[j] == 0) {
            j++;
            i = j;
        }
        if (nums[i] == 2) {
            swap(nums[i], nums[k]);
        } else if (nums[i] == 0) {
            swap(nums[i], nums[j]);
        } else {
            i++;
        }
    }
}

int main() {
    vector <int> nums = {2, 2, 2, 0, 0, 1, 1, 1, 1, 0 , 0, 0 , 2, 2};
    sortColor(nums);
    print(nums);
    return 0;
}