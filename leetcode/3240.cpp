#include<bits/stdc++.h>

using namespace std;

int minFlips(vector <vector <int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    int left = 0;
    int right = n-1;
    int top = 0;
    int bottom = m-1;
    int flips = 0;
    int onesCount = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            onesCount += grid[i][j];
        }
    }
    int newOnesCount = 0;
    int twoParody = 0;
    int oneParody = 0;
    while (top < bottom) {
        left = 0;
        right = n-1;
        while (left < right) {
            int tot = grid[left][top] + grid[left][bottom] + grid[right][top] + grid[right][bottom];
            if (tot == 4) {
                continue;
            }
            else if (tot == 3) {
                flips += 1;
                newOnesCount += 1;
            }
            else if (tot == 2) {
                flips += 2;
                newOnesCount -= 2;
                twoParody++;
            }
            else if (tot == 1) {
                flips += 1;
                newOnesCount -= 1;
            }
            else if (tot == 0) {
                continue;
            }
            left++;
            right--;
        }
        if (left == right) {
            int tot = grid[top][left] + grid[bottom][left];
            if (tot == 1) {
                flips++;
                newOnesCount -= 1;
                oneParody++;
            }
        }
        top++;
        bottom--;
        if (top == bottom) {
            int tot = grid[top][left] + grid[top][right];
            if (tot == 1) {
                flips++;
                newOnesCount -= 1;
                oneParody++;
            }
        }
    }
    int newTotalOnes = onesCount + newOnesCount;
    int rem = newTotalOnes % 4;
    if (rem == 0) return flips;
    else if (rem == 1) {
        if (oneParody > 0) {
            return flips;
        } else {
            return ++flips;
        }
    } else if (rem == 2) {
        if (twoParody > 0) {
            return flips;
        } else if (oneParody > 1) {
            return flips;
        } else if (oneParody == 1) {
            return ++flips;
        }
        else {
            return flips+2;
        }
    } else if (rem == 3) {
        if (oneParody > 0) {
            return flips;
        } else {
            return ++flips;
        }
    }
}

int main()
{
    vector <vector <int>> grid = {{1,0,0}, {0,1,0}, {0,0,1}};
    cout << minFlips(grid) << endl;
    return 0;
}