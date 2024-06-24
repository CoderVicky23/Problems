#include <iostream>
#include <vector>

using namespace std;

void printMatrix(vector <vector <int>> matrix, int n) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// allocating another 2d matrix space;
// time complexity O(n^2);
vector <vector <int>> rotateMatrix(vector <vector <int>> matrix, int n) {
    vector <vector <int>> mat (n, vector <int> (n));
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            mat[j][n-1-i] = matrix[i][j];
        }
    }
    return mat;
}

// space complexity O(1);
// 

// time complexity -> O(N^2);
void transpose(vector <vector <int>>& matrix, int n) {
    for (int i=0; i<n; i++) {
        for (int j=i; j<n; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}

// time complexity -> O(N^2);
void reverseMatrixRows(vector <vector <int>>& matrix, int n) {
    for (int i=0; i<n; i++) {
        int j=0;
        int k=n-1;
        while (j < k) {
            swap(matrix[i][j], matrix[i][k]);
            j++;
            k--;
        }
    }
}

void rotMatrix(vector <vector <int>>& matrix , int n) {
    transpose(matrix, n);
    reverseMatrixRows(matrix, n);
}

int main() {
    vector <vector <int>> matrix = {{1,2,3,4}, {5,6,7,8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    int n = 4;
    rotMatrix(matrix, n);
    printMatrix(matrix, n);
    return 0;
}