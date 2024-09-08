#include<bits/stdc++.h>

using namespace std;

// brute force
long long maxPoints(vector <vector <int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector <int> arr(n);
    for (int i=0; i<n; i++) {
        arr[i] = matrix[0][i];
    }
    for (int i=1; i<m; i++) {
        for (int j=0; j<n; j++) {
            for (int k=0; k<n; k++) {
                arr[j] = max(arr[j], arr[j]+matrix[i][k]-abs(j-k));
                cout << arr[j] << " - ";
            }
            cout << arr[0] << " " << arr[1] << " " << arr[2] << endl;
            break;
        }
        break;
    }
    int a = arr[0];
    for (int i=1; i<n; i++) {
        a = max(a, arr[i]);
    }
    return a;
}

int main()
{
    vector <vector <int>> matrix = {{1,2,3},{1,5,1},{3,1,1}};
    cout << maxPoints(matrix);
    return 0;
}