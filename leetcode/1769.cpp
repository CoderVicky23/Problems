#include <bits/stdc++.h>
using namespace std;

vector<int> minOperations(string boxes) {
    
}

vector<int> minOperations2(string boxes) {
    int n = boxes.length();
    vector<int> result (n, 0);

    for (int i=0; i<n; i++) {
        int _sum = 0;
        for (int j=0; j<n; j++) {
            if (boxes[j] == '1') {
                _sum += abs(j-i);
            }
        }
        result[i] = _sum;
    }

    return result;
}

int main() {
    string boxes = "001011";
    vector<int> result = minOperations(boxes);
    for (int i: result) {
        cout << i << "  ";
    }
    cout << endl;
    return 0;
}