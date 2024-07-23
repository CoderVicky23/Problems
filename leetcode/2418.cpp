#include <bits/stdc++.h>
using namespace std;

int partition(vector <int>& heights, vector <string>& names, int start, int end)
{

    int pivot = heights[start];

    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (heights[i] >= pivot)
            count++;
    }

    int pivotIndex = start + count;
    swap(heights[pivotIndex], heights[start]);
    swap(names[pivotIndex], names[start]);

    int i = start, j = end;

    while (i < pivotIndex && j > pivotIndex) {

        while (heights[i] >= pivot) {
            i++;
        }

        while (heights[j] < pivot) {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex) {
            swap(heights[i], heights[j]);
            swap(names[i], names[j]);
            i++; j--;
        }
    }

    return pivotIndex;
}

void quickSort(vector <int>& heights, vector <string>& names, int start, int end)
{
    if (start >= end)
        return;

    int p = partition(heights, names, start, end);

    quickSort(heights, names, start, p - 1);
    quickSort(heights, names, p + 1, end);
}

vector <string> sortPeople(vector <string>& names, vector <int>& heights) {
    quickSort(heights, names, 0, heights.size()-1);
    return names;
}


int main() {
    vector <string> names = {"Alice"};
    vector <int> heights = {155};
    for (auto i: sortPeople(names, heights)) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}