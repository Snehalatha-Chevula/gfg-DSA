//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string longestPalindrome(string &s) {
        // code here
        int n = s.length();
        string ans = "";
        int len = 0;
        for(int i=0;i<n;i++){
            int p1=i,p2=i;
            while(p1 >= 0 && p2 < n && s[p1]==s[p2]){
                if(p2-p1+1 > len){
                    ans = s.substr(p1,p2-p1+1);
                    len = p2-p1+1;
                }
                p1--;
                p2++;
            }
            p1=i,p2=i+1;
            while(p1 >= 0 && p2 < n && s[p1]==s[p2]){
                if(p2-p1+1 > len){
                    ans = s.substr(p1,p2-p1+1);
                    len = p2-p1+1;
                }
                p1--;
                p2++;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.longestPalindrome(S) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends