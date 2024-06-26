#include <iostream>

using namespace std;

int findElement(int row, int col) {
    row = row-1;
    col = col-1;
    int num = 1;
    int den = 1;
    int diff = row-col;
    diff = (diff < col) ? diff : col;
    for (int i=0; i<diff; i++) {
        num *= row-i;
        den *= 1+i;
    }
    return num/den;
}

int main() {
    int row = 6;
    int col = 4;
    int element = findElement(row, col);
    cout << element;
    return 0;
}