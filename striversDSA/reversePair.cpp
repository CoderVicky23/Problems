#include <bits/stdc++.h>
using namespace std;

int reversePairBrute(vector <int> arr) {
    int n = arr.size();
    int count = 0;
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            if (arr[i] > 2*arr[j]) count++;
        }
    }
    return count;
}

void merge(vector <int>& arr, int left, int mid, int right) {
    vector <int> temp;
    int i = left, j = mid+1;
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i++]);
        } else {
            temp.push_back(arr[j++]);
        }
    }
    while (i <= mid) {
        temp.push_back(arr[i++]);
    }
    while (j <= right) {
        temp.push_back(arr[j++]);
    }
    for (int k=left, l=0; k<=right; k++, l++) {
        arr[k] = temp[l];
    }
}

long long countPairs(vector <int>& arr, int left, int mid, int right) {
    long long count = 0;
    int k = mid + 1;
    for (int i=left; i<=mid; i++) {
        while (k <= right && arr[i] > 2*arr[k]) k++;
        count += (k - (mid + 1));
    }
    return count;
}

long long mergeSort(vector <int>& arr, int left, int right) {
    long long count = 0;
    if (left >= right) return count;
    int mid = left + (right - left) / 2;
    count += mergeSort(arr, left, mid);
    count += mergeSort(arr, mid+1, right);
    count += countPairs(arr, left, mid, right);
    merge(arr, left, mid, right);
    return count;
}

long long reversePair(vector <int> arr) {
    return mergeSort(arr, 0, arr.size() - 1);
}

int main() {
    vector <int> arr = {2, 4, 3, 5, 1}; // {1, 3, 2, 3, 1};
    cout << reversePair(arr) << endl;
    return 0;
}