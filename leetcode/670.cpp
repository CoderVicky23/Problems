#include <iostream>
#include <cmath>
using namespace std;

int maximumSwap(int n) {
    int k = n;
    string ns = "";
    int s = log10(n) + 1;
    s--;
    int greatest = 0;
    int index = -1;
    while (k) {
        int rem = k%10;
        if (rem > greatest) {
            greatest = rem;
            index = s;
        }
        ns = (char) rem + ns;
        k /= 10;
    }
    k = n;
    
    for (int i=0; i<ns.size(); i++) {
        int m = ns[i]-48;
        if (m < greatest) {

        }
    }
}

int main() {
    int n = 105989;
    cout << maximumSwap(n) << endl;
    return 0;
}