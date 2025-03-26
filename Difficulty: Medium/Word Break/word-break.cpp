//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool wordBreakRec(int ind, string &s, vector<string> &dictionary, vector<int> &dp){
    if (ind >= s.size())
        return true;
    if (dp[ind] != -1)
        return dp[ind];
    bool possible = false;
    for (int i = 0; i < dictionary.size(); i++){
        string temp = dictionary[i];
        if (temp.size() > s.size() - ind)
            continue;
        bool ok = true;
        int k = ind;
        for (int j = 0; j < temp.size(); j++){
            if (temp[j] != s[k]){
                ok = false;
                break;
            }
            else
                k++;
        }
        if (ok)
            possible |= wordBreakRec(ind + temp.size(), s, dictionary, dp);
    }
    return dp[ind] = possible;
}

    bool wordBreak(string &s, vector<string> &dictionary) {
        // code here
        int n = s.size();
        vector<int> dp(n + 1, -1);
        string temp = "";
        return wordBreakRec(0, s, dictionary,dp);
    }
};


//{ Driver Code Starts.

vector<string> inputLine() {
    string str;
    getline(cin, str);
    stringstream ss(str);
    vector<string> res;
    while (ss >> str) {
        res.push_back(str);
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s;
        cin >> s;
        cin.ignore();
        vector<string> dictionary = inputLine();

        Solution ob;
        if (ob.wordBreak(s, dictionary)) {
            cout << "true\n";
        } else
            cout << "false\n";
        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends