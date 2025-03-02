//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        vector<int> ans;
        map<int,int> mp;
        for(int i=0;i<k;i++){
            mp[arr[i]]++;
        }
        auto lp = prev(mp.end());
        ans.push_back(lp->first);
        for(int i=k;i<n;i++){
            mp[arr[i-k]]--;
            if(mp[arr[i-k]] == 0)
                mp.erase(arr[i-k]);
            mp[arr[i]]++;
            auto lp = prev(mp.end());
            ans.push_back(lp->first);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution obj;
        vector<int> res = obj.maxOfSubarrays(arr, k);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends