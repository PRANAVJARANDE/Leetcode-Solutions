class Solution {
public:
    int minOperations(vector<int>& nums) 
    {
        int c=0;
        int n=nums.size();
        int h=nums[0];
        for(int i=0;i<n;i++)
        {
            h=__gcd(h,nums[i]);
            if(nums[i]==1)
                c++;
        }

        if(c>0) return n-c;
        if(h!=1)
        {
            return -1;
        }

        int ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
            int g=nums[i];
            for(int j=i+1;j<n;j++)
            {
                g=__gcd(nums[j],g);
                if(g==1)
                    ans=min(j-i,ans);

            }
        }
        return ans==INT_MAX? -1: ans+n-1;
    }
};
