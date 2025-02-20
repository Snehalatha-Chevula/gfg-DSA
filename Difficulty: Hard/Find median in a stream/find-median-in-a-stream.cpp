//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<double> getMedian(vector<int> &arr) {
        int n = arr.size();
        vector<double> ans(n);
        priority_queue<int> maxpq;
        priority_queue<int,vector<int>,greater<int>> minpq;
        maxpq.push(arr[0]);
        ans[0] = (double)arr[0];
        for(int i=1;i<n;i++){
            if(arr[i] >= maxpq.top())
                minpq.push(arr[i]);
            else
                maxpq.push(arr[i]);
            if(abs(maxpq.size()-minpq.size()) > 1){
                if(maxpq.size() > minpq.size()){
                    int x = maxpq.top();
                    maxpq.pop();
                    minpq.push(x);
                }
                else{
                    int x = minpq.top();
                    minpq.pop();
                    maxpq.push(x);
                }
            }
            if(abs(maxpq.size()-minpq.size()) == 1)
                ans[i] = (double)maxpq.top();
            else{
                int a = maxpq.top();
                int b = minpq.top();
                ans[i] = (double)((a+b)/2.0);
            }
        }
        return ans;
        // code here
    }
};




//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<double> ans = ob.getMedian(nums);
        cout << fixed << setprecision(1);
        for (auto &i : ans)
            cout << i << " ";
        cout << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends