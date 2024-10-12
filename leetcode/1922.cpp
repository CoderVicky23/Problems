#include<bits/stdc++.h>

using namespace std;

long long M = 1000000007;

long long modd(int base, long long exp, long long ans) {
    if (exp == 0) return ans;
    if (exp & 1) return modd(base, exp-1, (ans * base) % M);
    return modd(base*base%M, exp/2, ans);
}

int countGoodNumbers(long long n) {
    long long ans = modd(20, n/2, 1);
    return (n & 1) ? (ans * 5) % M : ans;
}

int main()
{
    int n = 4;
    cout << countGoodNumbers(n) << endl;
    return 0;
}