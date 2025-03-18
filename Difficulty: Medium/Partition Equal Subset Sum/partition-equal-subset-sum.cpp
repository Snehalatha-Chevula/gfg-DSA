//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool memoi(vector<int>& arr, int idx, int cursum, int sum, vector<vector<int>>& dp){
        if(cursum == sum)
            return true;
        if(idx < 0 || sum < 0)
            return false;
        if(dp[idx][sum] != -1)
            return dp[idx][sum];
        return dp[idx][sum] = memoi(arr,idx-1,cursum+arr[idx],sum-arr[idx],dp) || memoi(arr,idx-1,cursum,sum,dp);
    } 
    
    bool equalPartition(vector<int>& arr) {
        // code here
        int n = arr.size();
        int sum = accumulate(arr.begin(),arr.end(),0);
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        return memoi(arr,n-1,0,sum,dp);
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
        if (ob.equalPartition(arr))
            cout << "true\n";
        else
            cout << "false\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends