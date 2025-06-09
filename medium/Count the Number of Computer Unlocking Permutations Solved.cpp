class Solution {
public:
    int countPermutations(vector<int>& a) 
    {
        int n=a.size();
        int u=a[0];
        for(int i=1;i<n;i++)if(a[i]<=u)return 0;
        int MOD=1e9 + 7;
        long long ans=1;
        for(int i=1;i<=n-1;i++)
        {
            ans=((ans%MOD)*(i%MOD))%MOD;
        }
        return ans;
    }
};
