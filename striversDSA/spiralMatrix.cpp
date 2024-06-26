#include <iostream>
#include <vector>

using namespace std;

vector <int> spiralMatrix(vector <vector <int>> matrix) {
    vector <int> arr;
    int top = 0, bottom = matrix.size()-1;
    int left = 0, right = matrix[0].size()-1;
    while (top <= bottom && left <= right) {

        for (int i=left; i<=right; i++) {
            arr.push_back(matrix[top][i]);
        }
        top++;
        for (int i=top; i<=bottom; i++) {
            arr.push_back(matrix[i][right]);
        }
        right--;
        if (top <= bottom) {
            for (int i=right; i>=left; i--) {
                arr.push_back(matrix[bottom][i]);
            }
            bottom--;
        }
        if (left <= right) {
            for (int i=bottom; i>=top; i--) {
                arr.push_back(matrix[i][left]);
            }
            left++;
        }
    }
    return arr;
}

int main() {
    vector <vector <int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector <int> result = spiralMatrix(matrix);
    for (int i: result) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}