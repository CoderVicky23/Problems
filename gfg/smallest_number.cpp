#include <bits/stdc++.h>
using namespace std;

string smallestNumber(int s, int d) {
    int least = (int) pow(10, d-1) + .5;
    int i = 0;
    bool flag = 0;
    s--;
    while (i < d) {
        if (s < 9) {
            least += s * (int)(pow(10, i) + 0.5);
            flag = 1;
            break;
        } else {
            least += 9 * (int)(pow(10, i) + 0.5);
            s -= 9;
        }
        i++;
    }
    if (flag) return to_string(least);
    else return "-1";
}

int main() {
    int s = 10;
    int d = 2;
    cout << smallestNumber(s, d) << endl;
    return 0;
}