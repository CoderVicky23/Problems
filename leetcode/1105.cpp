#include<bits/stdc++.h>

using namespace std;

int minHeightShelves (vector<vector<int>>& books, int shelfWidth) {
    unordered_map <int , long long> cache;
    int i = 0;
    function<long long(int)> dp = [&](int i) -> long long{
        if ( i == books.size() ) {
            return 0;
        }
        else if (cache.find(i) != cache.end()) {
            return cache[i];
        }
        int curWidth = shelfWidth;
        int maxHeight = 0;
        cache[i] = LLONG_MAX;
        for (int j = i; j < books.size(); j++) {
            int width = books[j][0];
            int height = books[j][1];
            if (curWidth < width) {
                break;
            } else {
                curWidth -= width;
                maxHeight = max(maxHeight, height);
                cache[i] = min(cache[i], dp(j + 1) + maxHeight);
            }
        }
        return cache[i];
    };
    return (int) dp(i);
}

int main()
{
    vector <vector <int>> books = {{7,3},{8,7},{2,7},{2,5}}; // {{1,1}, {2,3}, {2,3}, {1,1}, {1,1}, {1,1}, {1,2}};
    int shelfWidth = 10;
    cout << minHeightShelves(books, shelfWidth) << endl;
    return 0;
}