class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) 
    {
            int n=nums.size();
            if(n==1)
            {
                if(k==0)
                {
                        return nums[0];
                }
                return 0;
            }
            vector<int> dp(n,0);
            dp[0]=0;
            dp[1]=1;
            
            for(int i=2;i<n;i++)
            {
                    if(i%2==0)
                    {
                            dp[i]=dp[i/2];
                    }
                    else
                    {
                            dp[i]=dp[i-1]+1;
                    }
            }
            int s=0;
            for(int i=0;i<n;i++)
            {
                  if(dp[i]==k)
                  {
                          s+=nums[i];
                  }
            }
            return s;
        
    }
};
