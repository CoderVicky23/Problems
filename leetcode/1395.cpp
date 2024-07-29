#include<bits/stdc++.h>

using namespace std;

int numTeamsBrute(vector <int>& rating) {
    int count = 0;
    int n = rating.size();
    for (int i=0; i<n-2; i++) {
        for (int j=i+1; j<n-1; j++) {
            for (int k=j+1; k<n; k++) {
                if (rating[i] < rating[j] && rating[j] < rating[k]) {
                    cout << rating[i] << " " << rating[j] << " " << rating[k] << endl;
                    count++;
                } else if (rating[i] > rating[j] && rating[j] > rating[k]) {
                    count++;
                    cout << rating[i] << " " << rating[j] << " " << rating[k] << endl;
                }
            }
        }
    }
    return count;
}

int main()
{
    vector <int> rating = {2, 5, 3, 4, 1};
    cout << numTeamsBrute(rating) << endl;
    return 0;
}