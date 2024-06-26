#include <iostream>
#include <vector>

using namespace std;

void printTriangle(vector <vector <int>> triangle) {
    for (int i=0; i<triangle.size(); i++) {
        for (int j=0; j<triangle[i].size(); j++) {
            cout << triangle[i][j] << " ";
        }
        cout << endl;
    }
}

vector <vector <int>> generate(int n) {
    vector <vector <int>> result;
    vector <int> a;
    a.push_back(1);
    result.push_back(a);
    for (int i=1; i<n; i++) {
        vector <int> a;
        a.push_back(1);
        if (i > 1) {
            for (int j=0; j<result[i-1].size()-1; j++) {
                a.push_back(result[i-1][j] + result[i-1][j+1]);
            }
        }
        a.push_back(1);
        result.push_back(a);
    }
    return result;
}

int main() {
    int n = 10;
    vector <vector <int>> result = generate(n);
    printTriangle(result);
    return 0;
}