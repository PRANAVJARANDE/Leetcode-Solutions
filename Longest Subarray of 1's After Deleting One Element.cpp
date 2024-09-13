class Solution {
public:
    int longestSubarray(vector<int>& nums) 
    {
        int zc=0;
        int ans=0;
        int l=0;
        bool b=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                b=1;
                zc++;
            }
            while(zc>1)
            {
                if(nums[l]==0)
                {
                    zc--;
                }
                l++;
            }
            ans=max(ans,i-l+1-zc);
        }
        if(b==0)
        {
            return nums.size()-1;
        }
        return ans;
    }
};
