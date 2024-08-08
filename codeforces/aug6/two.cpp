#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a1, a2, b1, b2;
        cin >> a1 >> a2 >> b1 >> b2;
        pair<int, int> Suneet[] = { {a1, a2}, {a2, a1} };
        pair<int, int> Slavic[] = { {b1, b2}, {b2, b1} };
        
        int SuneetWins = 0;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                int suneetRoundWins = 0;
                int slavicRoundWins = 0;
                if (Suneet[i].first > Slavic[j].first) suneetRoundWins++;
                else if (Suneet[i].first < Slavic[j].first) slavicRoundWins++;
                if (Suneet[i].second > Slavic[j].second) suneetRoundWins++;
                else if (Suneet[i].second < Slavic[j].second) slavicRoundWins++;
                if (suneetRoundWins > slavicRoundWins) SuneetWins++;
            }
        }
        cout << SuneetWins << endl;
    }
    return 0;
}


// if (a1 > b1 && a2 >= b2) {
//             wins++;
//             cout << "yo1" <<" ";
//         }
//         if (a1 > b2 && a2 >= b1) {
//             wins++;
//             cout << "yo2" <<" ";
//         }
//         if (a2 > b1 && a1 >= b2) {
//             wins++;
//             cout << "yo3" <<" ";
//         }
//         if (a2 > b2 && a1 >= b1) {
//             wins++;
//             cout << "y4" <<" ";
//         }
//         cout << wins << endl;