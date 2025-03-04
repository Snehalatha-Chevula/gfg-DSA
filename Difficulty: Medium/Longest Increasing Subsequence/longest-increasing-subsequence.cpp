//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int binarySearch(vector<int> &LIS, int x){
        int ans = LIS.size();
        int lo=0, hi=LIS.size()-1;
        while(lo <= hi){
            int mid = (lo+hi)/2;
            if(LIS[mid] < x)
                lo = mid+1;
            else{
                ans = mid;
                hi = mid-1;
            }
        }
        return ans;
    }
    int lis(vector<int>& arr) {
        // code here
        vector<int> LIS;
        LIS.push_back(INT_MIN);
        for(auto x : arr){
            int idx = binarySearch(LIS,x);
            if(idx == LIS.size())
                LIS.push_back(x);
            else
                LIS[idx] = x;
        }
        return LIS.size()-1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input

    while (t--) {
        int n;
        vector<int> arr;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            arr.push_back(num);

        Solution obj;
        cout << obj.lis(arr) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends