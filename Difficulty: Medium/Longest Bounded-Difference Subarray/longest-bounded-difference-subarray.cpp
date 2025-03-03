//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        // code here
        int n = arr.size();
        deque<pair<int,int>> maxdq;
        deque<pair<int,int>> mindq;
        maxdq.push_front({arr[0],0});
        mindq.push_front({arr[0],0});
        int curl = 0, curr = 1, ansl = 0, ansr = 0;
        while(curr < n){
            while(!maxdq.empty() && maxdq.back().first < arr[curr])
                maxdq.pop_back();
            maxdq.push_back({arr[curr],curr});
            while(!mindq.empty() && mindq.back().first > arr[curr])
                mindq.pop_back();
            mindq.push_back({arr[curr],curr});
            if(maxdq.front().first - mindq.front().first > x){
                if(maxdq.front().first == arr[curr]){
                    while(maxdq.front().first-mindq.front().first > x){
                        curl = mindq.front().second+1;
                        mindq.pop_front();
                    }
                }
                else{
                    while(maxdq.front().first-mindq.front().first > x){
                        curl = maxdq.front().second+1;
                        maxdq.pop_front();
                    }
                }
            }
            if(curr-curl+1 > ansr-ansl+1){
                ansr = curr;
                ansl = curl;
            }
            curr++;
        }
        vector<int> ans;
        while(ansl <= ansr){
            ans.push_back(arr[ansl]);
            ansl++;
        }
        return ans;
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
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        vector<int> ans = ob.longestSubarray(arr, k);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends