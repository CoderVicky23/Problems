#include <bits/stdc++.h>

using namespace std;

vector <int> getPrimes(int n) {
    bool prime[n+1];
    memset(prime, true, sizeof(prime));
    for (int p=2; p*p <= n; p++) {
        if (prime[p]) {
            for (int i=p*p; i<=n; i+=p) {
                prime[p] = false;
            }
        }
    }
    for (int i=2; i<=n; i++) {
        if (prime[i] && prime[n-i]) return {i, n-i};
    }
    return {-1, -1};
}

int main() {
    int n = 10;
    vector<int> result = getPrimes(n);
    return 0;
}