class Solution {
public:
    const int MOD=1e9+7;
    int countPartitions(vector<int>& a, int k) 
    {
        int n=a.size();
        multiset<int>s1;
        vector<long long>dp(n+1,0),psum(n+1,0);
        dp[0]=1;
        psum[0]=1;
        int l=0;
        for(int i=0;i<n;i++)
        {
            s1.insert(a[i]);
            while((*s1.rbegin() - *s1.begin()) > k)
            {
                s1.erase(s1.find(a[l]));
                l++;
            } 

            dp[i+1]=((psum[i]%MOD)-(l>0 ? (psum[l-1]%MOD) :0) + MOD)%MOD;
            psum[i+1]=((psum[i]%MOD)+(dp[i+1]%MOD))%MOD;
        }
        return dp[n];
    }
};
