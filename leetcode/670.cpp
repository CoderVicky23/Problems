#include <iostream>
#include <cmath>
using namespace std;

int maximumSwap(int n) {
    string s = to_string(n);
    int k = s.size();
    int array[n] = {0};
    array[k-1] = k-1;
    int max_index = k-1;
    for (int i=k-2; i>=0; i--) {
        if (s[i] > s[max_index]) {
            array[i] = i;
            max_index = i;
        } else {
            array[i] = max_index;
        }
    }
    for (int i=0; i<s.size(); i++) {
        if (s[array[i]] > s[i]) {
            char temp = s[i];
            s[i] = s[array[i]];
            s[array[i]] = temp;
            break;
        }
    }
    return stoi(s);
}

int main() {
    int n = 500009;
    cout << maximumSwap(n) << endl;
    return 0;
}