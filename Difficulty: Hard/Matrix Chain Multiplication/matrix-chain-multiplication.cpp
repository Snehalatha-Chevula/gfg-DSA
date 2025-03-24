//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int solve(int i, int j, vector<int>& arr, vector<vector<int>>& dp){
        if(i+1 == j)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        int res = INT_MAX;
        for(int k=i+1;k<j;k++){
            int cur = solve(i,k,arr,dp)+solve(k,j,arr,dp)+(arr[i]*arr[k]*arr[j]);;
            res = min(res,cur);
            dp[i][j] = res;
        }
        return dp[i][j];
    }
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(0,n-1,arr,dp);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input
    while (t--) {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.matrixMultiplication(a) << endl << "~\n";
    }

    return 0;
}

// } Driver Code Ends