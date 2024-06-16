#include <iostream>
#include <fstream>
#include <unordered_map>
#include <climits>
using namespace std;

int secondLargest(int arr[], int n) {
	    int l = INT_MIN;
        int s = INT_MIN;
	    for (int i=0; i<n; i++) {
	        if (arr[i] > l) {
	            s = l;
	            l = arr[i];
	        } else if (arr[i] != l && arr[i] > s) {
	            s = arr[i];
	        }
	    }
        cout << l;
	    return s;
	}

int main() {
    // reading from input.txt
    ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        cerr << "File not open!" << endl;
        return 1;
    }

    int n;
    inputFile >> n;
    int * arr = new int[n];
    for (int i=0; i<n; i++) {
        inputFile >> arr[i];
    }

    cout << secondLargest(arr, n) << endl;

    // closing inputFile object
    inputFile.close();
    return 0;
}