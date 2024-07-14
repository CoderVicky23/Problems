#include <bits/stdc++.h>
using namespace std;

vector <vector <int>> three_sum(vector <int> arr) {
    sort(arr.begin(), arr.end());
    int a = 0;
    int sum = 0;
    vector <vector <int>> result;
    while (a <= arr.size() - 3) {
        sum += arr[a];
        int b = a + 1;
        int c = arr.size() - 1;
        while (b < c) {
            sum = arr[a] + arr[b] + arr[c];
            if (sum == 0) {
                result.push_back({arr[a], arr[b], arr[c]});
                b++;
                while (b < c && arr[b] == arr[b-1]) b++;
                c--;
                while (b < c && arr[c] == arr[c+1]) c--;
            }
            else if (sum < 0) {
                b++;
                while (b < c && arr[b] == arr[b-1]) b++;
            }
            else {
                c--;
                while (b < c && arr[c] == arr[c+1]) c--;
            }
        }
        a++;
        while (a <= arr.size() - 3 && arr[a] == arr[a-1]) a++;
    }
    return result;
}

int main() {
    vector <int> arr = { -1, 0, 1, 2, -1, -4, 2, 3};
    for (auto i:three_sum(arr)) {
        for (int a: i) {
            cout << a << " ";
        }
        cout << endl;
    }
    return 0;
}