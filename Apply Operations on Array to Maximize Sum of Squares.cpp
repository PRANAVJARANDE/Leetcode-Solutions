class Solution {
public:
    int maxSum(vector<int>& nums, int k) 
    {
        long long MOD=1e9+7;
        vector<int> freq(32,0);
        for(int x: nums)
            for(int i=0;i<32;i++)
                if(x & (1<<i))
                    freq[i]++;

    
        long long ans=0;
        for(int i=0;i<k;i++)
        {
            long long a=0;
            for(int j=0;j<32;j++)
            {
                if(freq[j]!=0)
                {
                    a=(a | (1<<j));
                    freq[j]--;
                }
            }
            ans = (ans + (a * a) % MOD) % MOD;
        }
        return ans;
    }
};
