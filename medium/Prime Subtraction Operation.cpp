class Solution {
public:
    int n;
    vector<int>primes;
    vector<vector<int>>dp;
    bool helper(int in,int prev,vector<int>&nums)
    {
        if(in>=n)return 1;
        if(dp[in][prev]!=-1)return dp[in][prev];
        if(nums[in]>prev)
        {
            bool b2=helper(in+1,nums[in],nums);
            if(b2)return dp[in][prev]=b2;
        }
        
        for(int x:primes)
        {
            if(nums[in]-x>prev)
            {
                bool b1=helper(in+1,nums[in]-x,nums);
                if(b1)return dp[in][prev]=1;
            }
        }
        return dp[in][prev]=0;
    }

    bool primeSubOperation(vector<int>& nums) {
        n=nums.size();
        vector<int> isprime(1001,1);
        for(int i=2;i<=1000;i++)
        {
            if(isprime[i])
            {
                for(int z=i+i;z<=1000;z+=i)
                {
                    isprime[z]=0;
                }
            }
        }
        for(int i=2;i<=1000;i++)if(isprime[i])primes.push_back(i);
        dp=vector<vector<int>>(n,vector<int>(1001,-1));
        bool ans=helper(0,0,nums);
        return ans;
    }
};
