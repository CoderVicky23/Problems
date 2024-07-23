#include <bits/stdc++.h>
using namespace std;

string fun(vector <int> nums) {
    int n = nums.size();
    vector <int> arr;
    if (n <= 2) return "Yes";
    unordered_map <int, int> hash;
    for (int i=0; i<n; i++) {
        hash[nums[i]]++;
        if (hash.size() > 2) return "no";
    }
    if (hash.size() <= 1) return "YES";
    for (auto i: hash) {
        arr.push_back(i.second);
    }
    if (abs(arr[0]-arr[1]) <= 1) return "yes";
    else return "No";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <int> nums(n);
        for (int i=0; i<n; i++) {
            cin >> nums[i];
        }
        cout << fun(nums) << endl;
    }
    return 0;
}



// #include <bits/stdc++.h>
// using namespace std;

// int main() {

//     int t;
//     cin>>t;
//     for(int i=0;i<t;i++)
//     {
//         int n;
//         cin>>n;

//         vector<int> nums(n);
//         for(int i=0;i<n;i++)
//         cin>>nums[i];
//         if(n<=2)
//         {
//             cout<<"Yes"<<endl;
//             continue;
//         }
//         unordered_map<int,int> mpp;
//         for(int i=0;i<n;i++)
//         {
//             mpp[nums[i]]++;
//             if(mpp.size()>2)
//             {
//                 cout<<"No"<<endl;
//                 break;
//             }
//         }
        
//         {
//             if(mpp.size()==1)
//             cout<<"Yes"<<endl;
//             else{
//                 int arr[2];
//                 int index=0;
//                 for(auto i:mpp)
//                 {
//                     arr[index]=i.second;
//                     index++;
//                 }
//                 if(abs(arr[0]-arr[1])<=1)
//                 cout<<"Yes"<<endl;
//                 else
//                 cout<<"No"<<endl;
//             }
//         }
//     }
//     return 0;
// }


