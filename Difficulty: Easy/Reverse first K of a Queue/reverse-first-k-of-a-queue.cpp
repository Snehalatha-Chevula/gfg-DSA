class Solution {
  public:
    queue<int> reverseFirstK(queue<int> q, int k) {
        if(k > q.size())
            return q;
        // code here
        queue<int> ans;
        stack<int> st;
        while(k--){
            st.push(q.front());
            q.pop();
        }
        while(!st.empty()){
            ans.push(st.top());
            st.pop();
        }
        while(q.size()){
            ans.push(q.front());
            q.pop();
        }
        return ans;
    }
};