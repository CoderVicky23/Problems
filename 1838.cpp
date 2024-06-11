#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

using namespace std;

int maxFrequency(vector <int>& nums, int k) {

}

int main() {
    ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        cerr << "File not open!" << endl;
        return 1;
    }
    vector<int> nums;
    int number;
    while (inputFile >> number) {
        nums.push_back(number);
    }
    inputFile >> number;
    inputFile.close();
    cout << maxFrequency(nums, number) << endl;
    return 0;
}