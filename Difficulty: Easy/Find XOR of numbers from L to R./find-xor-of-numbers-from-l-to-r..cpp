// User function Template for C++

class Solution {
  public:
    int findSetBit(int pos, int n){
        int partitions = n/(1<<(pos+1));
        int cnt = 0;
        cnt += (partitions*(1<<pos));
        int rem = n-(partitions*(1<<(pos+1)));
        if(rem > (1<<pos))
            cnt += (rem-(1<<pos));
        return cnt;
    }
    int findXOR(int l, int r) {
        // complete the function here
        int ans = 0;
        for(int i=0;i<31;i++){
            int x = findSetBit(i, r+1);
            int y = findSetBit(i, l);
            if((x-y)&1)
                ans += (1 << i);
        }
        return ans;
    }
};