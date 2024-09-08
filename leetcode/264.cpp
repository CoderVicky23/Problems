#include<bits/stdc++.h>

using namespace std;

// int uglyNumber(long long n) {
//     long long count=1;
//     long long i=1;
//         while (count < n) {
//         i++;
//         long long a = i;
//         while (a % 2 == 0) a /= 2;
//         while (a % 3 == 0) a /= 3;
//         while (a % 5 == 0) a /= 5;
//         if (a == 1) {
//         count++;
//             }
//     }
//     return i;
// }

int uglyNumber(long long n) {
    priority_queue <int, vector<int>, greater<int>> pq;
    unordered_set <int> visited;
    pq.push(1);
    int num = 1;
    int arr[] = {2,3,5};
    while (num < n) {
        int a = pq.top();
        pq.pop();
        for (int i=0; i<3; i++) {
            if (visited.find(a*arr[i]) == visited.end()) {
                visited.insert(a*arr[i]);
                pq.push(a*arr[i]);
            }
        }
        num++;
    }
    return pq.top();
}

int main()
{
    long long n = 1690;
    cout << "\n" << uglyNumber(n) << endl;
    return 0;
}


    // cout << "set values: " << endl;
    // for (int i: st) {
    //     cout << i << " ";
    // }
    // cout << endl;