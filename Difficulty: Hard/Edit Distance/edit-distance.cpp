//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int memoi(string s1, string s2, int i, int j, vector<vector<int>> &dp){
        if(i == s1.length())
            return s2.length()-j;
        if(j == s2.length())
            return s1.length()-i;
        if(dp[i][j] != -1)
            return dp[i][j];
        if(s1[i] == s2[j])
            return dp[i][j] = memoi(s1,s2,i+1,j+1,dp);
        else
            return dp[i][j] = min({memoi(s1,s2,i+1,j,dp),memoi(s1,s2,i,j+1,dp),memoi(s1,s2,i+1,j+1,dp)})+1;
    }
    // Function to compute the edit distance between two strings
    int editDistance(string& s1, string& s2) {
        // code here
        int n1 = s1.length();
        int n2 = s2.length();
        vector<vector<int>> dp(n1,vector<int>(n2,-1));
        return memoi(s1,s2,0,0,dp);
    }
};


//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        string s1;
        getline(cin, s1);
        string s2;
        getline(cin, s2);
        Solution ob;
        int ans = ob.editDistance(s1, s2);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends