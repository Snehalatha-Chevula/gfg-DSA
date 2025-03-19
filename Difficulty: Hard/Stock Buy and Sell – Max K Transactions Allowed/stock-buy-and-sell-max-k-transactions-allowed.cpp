//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int solve(vector<int>& prices, int k, bool isbuy, int idx, vector<vector<vector<int>>>& dp){
        if(k == 0 || idx == prices.size())
            return 0;
        int include = 0, exclude = 0;
        if(dp[idx][k][isbuy] != -1)
            return dp[idx][k][isbuy];
        if(isbuy){
            include = prices[idx] + solve(prices,k-1,false,idx+1,dp);
            exclude = solve(prices,k,isbuy,idx+1,dp);
        }
        else{
            include = -prices[idx] + solve(prices,k,true,idx+1,dp);
            exclude = solve(prices,k,isbuy,idx+1,dp);
        }
        return dp[idx][k][isbuy] = max(include,exclude);
    }
    int maxProfit(vector<int>& prices, int k) {
        // code here
        int n = prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(k+1,vector<int>(2,-1)));
        return solve(prices,k,false,0,dp);
    }
};


//{ Driver Code Starts.

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        istringstream iss(input);
        vector<int> arr;
        int num;

        // Read integers from the input string
        while (iss >> num) {
            arr.push_back(num);
        }
        int k;
        cin >> k;
        cin.ignore();
        Solution ob;
        cout << ob.maxProfit(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends