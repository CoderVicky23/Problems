#include<bits/stdc++.h>

using namespace std;

int partition(vector <int>& nums, int low, int high) {
    int pivot = nums[low];
    int count = 0;
    for (int i = low+1; i <= high; i++) {
        if (nums[i] <= pivot) {
            count++;
        }
    }
    int pivotIndex = low + count;
    swap(nums[pivotIndex], nums[low]);
    int i = low, j = high;
    while (i < pivotIndex && j > pivotIndex) {
        while (nums[i] <= pivot) {
            i++;
        }
        while (nums[j] > pivot) {
            j--;
        }
        if (i < pivotIndex && j > pivotIndex) {
            swap(nums[i++], nums[j--]);
        }
    }
    return pivotIndex;
}

void quickSort(vector <int>& nums, int low, int high) {
    if (low >= high) {
        return;
    } else {
        int p = partition(nums, low, high);
        quickSort(nums, low, p - 1);
        quickSort(nums, p + 1, high);
    }
}

vector <int> sortArray(vector <int>& nums) {
    int low = 0;
    int high = nums.size() - 1;
    quickSort(nums, low, high);
    return nums;
}

int main()
{
    vector <int> nums = {5,-1,1,-2,0, -10, 5, -1, 8, -55};
    for (int i: sortArray(nums)) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}