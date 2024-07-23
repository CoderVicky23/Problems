#include <iostream>
using namespace std;

int minJumps(int arr[], int n){
    int jumps = 0;
    int pointer = 0;
    int leaps;
    if (n == 1) return 1;
    while (pointer < n) {
        leaps = arr[pointer];
        if (leaps == 0 && pointer != n-1) {
            return -1;
        }
        if (n-1 <= leaps) {
            jumps++;
            return jumps;
        } else {
            int i = pointer + 1;
            int max_leap = 0;
            while (i <= pointer + leaps) {
                max_leap = max(max_leap, arr[i] + pointer);
            }
            pointer = max_leap;
            if (pointer >= n-1) {
                jumps++;
                return jumps;
            }
        }
    }
    return jumps;
}

int main() {
    int arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    int n = 11;
    cout << minJumps(arr, n) << endl;
    return 0;
}