//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int getMaxArea(vector<int> &arr) {
        int n = arr.size();
        vector<int> left(n);
        vector<int> right(n);
        left[0] = -1;
        stack<int> st;
        st.push(0);
        for(int i=1;i<n;i++){
            while(!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            if(st.empty())
                left[i] = -1;
            else
                left[i] = st.top();
            st.push(i);
        }
        right[n-1] = n;
        while(st.size() != 0)
            st.pop();
        st.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            if(st.empty())
                right[i] = n;
            else
                right[i] = st.top();
            st.push(i);
        }
        int ans = INT_MIN;
        for(int i=0;i<n;i++){
            int cur = (right[i]-left[i]-1)*arr[i];
            ans = max(ans,cur);
        }
        return ans;
        // Your code here
    }
};



//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.getMaxArea(arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends