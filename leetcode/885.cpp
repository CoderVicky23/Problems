#include<bits/stdc++.h>

using namespace std;

vector <vector <int>> spiralMatrix(int rows, int cols, int rStart, int cStart) {
    vector <vector <int>> matrix;
    int x = cStart;
    int y = rStart;
    bool right = 1, left = 0, up = 0, down = 0;
    int k = 1;
    int i = 0;
    int counter = 0;
    while (matrix.size() != rows*cols) {
        if ((x < cols && x >= 0) && (y < rows && y >= 0)) {
            matrix.push_back({y, x});
        }
        if (i >= k) {
            if (right) {
                right = 0;
                down = 1;
            } else if (down) {
                down = 0;
                left = 1;
            } else if (left) {
                left = 0;
                up = 1;
            } else if (up) {
                up = 0;
                right = 1;
            }
            i = 0;
            counter++;
            if (counter > 1) {
                k++;
                counter = 0;
            }
        }
        if (i < k) {
            if (right) {
                x++;
            } else if (left) {
                x--;
            } else if (down) {
                y++;
            } else if (up) {
                y--;
            }
            i++;
        }
    }
    return matrix;
}

int main()
{
    int rows = 5, cols = 6, rStart = 1, cStart = 4;
    for (auto i: spiralMatrix(rows, cols, rStart, cStart)) {
        for (int j: i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}