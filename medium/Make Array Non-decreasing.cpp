class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) 
    {
        int ans=0;
        int mini=0;
        for(auto x:nums)
        {
            if(x>=mini)
            {
                ans++;
                mini=x;
            }
        }
        return ans;
    }
};
