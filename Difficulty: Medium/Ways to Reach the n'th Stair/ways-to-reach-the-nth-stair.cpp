//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int memoi(int n, vector<int> &dp){
        if(n==0 || n==1)
            return 1;
        if(dp[n] != -1)
            return dp[n];
        return dp[n] = memoi(n-1,dp)+memoi(n-2,dp);
    }
    int countWays(int n) {
        // your code here
        vector<int> dp(n+1,-1);
        return memoi(n,dp);
    }
};



//{ Driver Code Starts.
int main() {
    // taking total testcases
    int t;
    cin >> t;
    while (t--) {
        // taking stair count
        int m;
        cin >> m;
        Solution ob;
        cout << ob.countWays(m) << endl; // Print the output from our pre computed array

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends