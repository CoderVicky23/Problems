#include <iostream>
using namespace std;

int countNumberswith4(int n) {
    int count = 0;
    int k;
    int rem;
    for (int i=1; i<=n; i++) {
        k = i;
        rem;
        while (k) {
            rem = k%10;
            if (rem == 4) {
                count++;
                break;
            }
            k = k/10;
        }
    }
    return count;
}

int main() {
    int n = 44;
    countNumberswith4(n);
}