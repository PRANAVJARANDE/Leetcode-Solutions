class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) 
    {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int> dp(n,-1),val(n,1);
        for(int i=n-1;i>=0;i--)
        {
            int maxi=0,in=-1;
            for(int j=i+1;j<n;j++)
            {
                if(nums[j]%nums[i]==0 && val[j]>maxi)
                {
                    maxi=val[j];
                    in=j;
                }
            }
            val[i]+=maxi;
            dp[i]=in;
        }

        int maxi=0;
        for(int x: val)
        {
            maxi=max(maxi,x);
        }

        int in=0;
        for(;in<n;in++)
        {
            if(val[in]==maxi)
            {
                break;
            }
        }
        vector<int> ans;
        while(dp[in]!=-1)
        {
            ans.push_back(nums[in]);
            in=dp[in];
        }
        ans.push_back(nums[in]);
        return ans;
    }
};
