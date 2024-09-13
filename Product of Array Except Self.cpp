class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        int n=nums.size(); 
        int ap=1;
        int nap=1;
        for(int i=0;i<n;i++)
        {
            ap=ap*nums[i];
        }

        vector<int> ans(n);
        if(ap!=0)
        {
            for(int i=0;i<nums.size();i++)
            {
                ans[i]=ap/nums[i];
            }
            return ans;
        }
        else
        {
            int z=0;
            for(int i=0;i<n;i++)
            {
                if(nums[i]==0)
                {
                    z++;
                }
                if(nums[i]!=0)
                {
                    nap=nap*nums[i];
                }
            }

            if(z>1)
            {
                nap=0;
            }
        
            for(int i=0;i<n;i++)
            {
                if(nums[i]==0)
                {
                    ans[i]=nap;
                }
            }

            return ans;
        }
    }
};
