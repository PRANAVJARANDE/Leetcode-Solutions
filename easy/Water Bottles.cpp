class Solution {
public:
    int numWaterBottles(int n, int x) {
        int ans=n;
        int rem=n;
        while(rem>=x)
        {
            int ta=rem/x;
            ans+=ta;
            rem=rem%x + ta;
        }
        
        return ans;
    }
};
