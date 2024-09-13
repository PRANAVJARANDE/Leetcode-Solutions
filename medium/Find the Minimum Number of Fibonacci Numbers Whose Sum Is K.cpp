class Solution {
public:

    int findMinFibonacciNumbers(int k) 
    {
        vector<int>dp;
        dp.push_back(0);
        dp.push_back(1);
        for(int i=2;i<1000000001;i++)
        {
            dp.push_back(dp[i-1]+dp[i-2]);
            if(dp[i]==k)
                return 1;
            if(dp[i]>k)
            {
                dp.pop_back();
                break;
            }  
        }
        int ans=0;
        for(int i=dp.size()-1;i>=0;i--)
        {
            if(k==0)
                return ans;

            if(k>=dp[i])
            {
                k=k-dp[i];
                ans++;
            }
        }
        return ans;
    }
};
