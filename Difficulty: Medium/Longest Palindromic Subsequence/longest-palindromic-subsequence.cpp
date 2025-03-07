//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    int memoi(string &s, int i, int j, vector<vector<int>> &dp){
        if(i > j)
            return 0;
        if(i == j)
            return 1;
        if(dp[i][j] != -1)
            return dp[i][j];
        if(s[i] == s[j])
            return dp[i][j] = 2 + memoi(s,i+1,j-1,dp);
        return dp[i][j] = max(memoi(s,i+1,j,dp),memoi(s,i,j-1,dp));
    }
    int longestPalinSubseq(string &s) {
        int n = s.length();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return memoi(s,0,n-1,dp);
        // code here
    }
};


//{ Driver Code Starts.

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends