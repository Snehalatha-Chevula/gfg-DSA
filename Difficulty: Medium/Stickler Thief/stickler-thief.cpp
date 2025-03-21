//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;


// } Driver Code Ends

class Solution {
  public:
    int solve(vector<int>& arr, int idx, vector<int>& dp){
        if(idx >= arr.size())
            return 0;
        if(dp[idx] != -1)
            return dp[idx];
        int include = 0, exclude = 0;
        include = arr[idx]+solve(arr,idx+2,dp);
        exclude = solve(arr,idx+1,dp);
        return dp[idx] = max(include,exclude);
    }
    int findMaxSum(vector<int>& arr) {
        // code here
        vector<int> dp(arr.size(),-1);
        return solve(arr,0,dp);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.findMaxSum(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends