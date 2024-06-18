#include <iostream>
#include <vector>
using namespace std;

void print(vector <int>& nums) {
    for (int i: nums) {
        cout << i << " ";
    }
    cout << endl;
}

void rotate(vector<int>& nums, int k) {
    vector <int> temp;
    int n = nums.size();
    k = k % n;
    if (k == 0) return;
    int j = n-k;
    int i = j-1;
    while (j < n) {
        temp.push_back(nums[j]);
        j++;
    }
    while (i >= 0) {
        nums[i+k] = nums[i];
        i--;
    }
    i = 0;
    while (i < temp.size()) {
        nums[i] = temp[i];
        i++;
    }
}

void reverse(vector<int>& arr, int start, int end) {
    while (start <= end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void rotateByReverse(vector <int>& nums, int k) {
    int n = nums.size();
    reverse(nums, 0, n-k-1);
    reverse(nums, n-k, n-1);
    reverse(nums, 0, n-1);
}

int main() {
    vector <int> arr = {1,2,3,4,5,6,7};
    int s = arr.size();
    // rotate(arr, 3);
    rotateByReverse(arr, 3);
    print(arr);
    return 0;
}