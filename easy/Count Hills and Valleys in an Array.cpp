class Solution {
public:
    int countHillValley(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int>psum(n,-1);
        int pv=-1;
        for(int i=0;i<n;)
        {
            int val=nums[i];
            while(i<n && nums[i]==val)
            {
                psum[i]=pv;
                i++;
            }
            pv=val;
        }

        vector<int>ssum(n,-1);
        int nx=-1;
        for(int i=n-1;i>=0;)
        {
            int val=nums[i];
            while(i>=0 && nums[i]==val)
            {
                ssum[i]=nx;
                i--;
            }
            nx=val;
        }

        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(psum[i]==-1 || ssum[i]==-1)continue;
            if(i>0 && nums[i]==nums[i-1])continue;
            if(psum[i]<nums[i] && nums[i]>ssum[i])ans++;
            else if(psum[i]>nums[i] && nums[i]<ssum[i])ans++;
        }
        return ans;
    }
};
