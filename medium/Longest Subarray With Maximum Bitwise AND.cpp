class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi=0;
        for(int x:nums)
        {
            maxi=max(maxi,x);
        }
        int ans=0,cnt=0;
        for(int x:nums)
        {
            if(x==maxi)cnt++;
            else cnt=0;
            ans=max(ans,cnt);
        }
        return ans;
    }
};
