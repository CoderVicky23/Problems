#include<bits/stdc++.h>
using namespace std;
int partition(vector <int>& diff, vector <int>& profit, int left, int right) {
    int pivot = diff[right];
    int i = left - 1;
    for (int j = left; j < right; j++) {
        if (diff[j] < pivot) {
            i++;
            swap(diff[i], diff[j]);
            swap(profit[i], profit[j]);
        }
    }
    swap(diff[i+1], diff[right]);
    return i + 1;
}
void quickSort(vector <int>& diff, vector <int>& profit, int left, int right) {
    if (left < right) {
        int pi = partition(diff, profit, left, right);
        quickSort(diff, profit, left, pi-1);
        quickSort(diff, profit, pi+1, right);
    }
}
int maxProfit(vector <int>& diff, vector <int>& profit, vector <int>& worker) {
    int n = diff.size();
    int m = worker.size();
    int result = 0;
    quickSort(diff, profit, 0, n-1);
    for (int i=0; i<m; i++) {
        int j = 0;
        int res = 0;
        while (diff[j] <= worker[i]) {
            res = max(res, profit[j]);
            j++;
        }
        cout << res << endl;
        result += res;
    }
    return result;
}
int main()
{
    vector <int> difficulty = {5,50,92,21,24,70,17,63,30,53};
    vector <int> profit = {68,100,3,99,56,43,26,93,55,25};
    vector <int> worker = {96,3,55,30,11,58,68,36,26,1};
    cout << maxProfit(difficulty, profit, worker);
    return 0;
}