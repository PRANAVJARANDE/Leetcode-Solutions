#define ll long long
class Solution {
public:
    
    ll n;
    ll helper(ll in,vector<ll>&psum,vector<ll>&csum,ll k,vector<ll>&dp)
    {
        if(in>=n)return 0;
        if(dp[in]!=-1)return dp[in];
        ll ans=LLONG_MAX;
        for(ll i=in;i<n;i++)
        {
            ll res=psum[i]*(csum[i]-((in-1>=0)? csum[in-1]:0));
            res+=k*(csum[n-1]-((in-1>=0)? csum[in-1]:0));
            res+=helper(i+1,psum,csum,k,dp);
            ans=min(ans,res);
        }
        return dp[in]=ans;
    }
    
    long long minimumCost(vector<int>& nums, vector<int>& cost, int k) 
    {
        n=nums.size();
        vector<ll>psum(n,0),csum(n,0);
        psum[0]=nums[0];
        csum[0]=cost[0];
        for(int i=1;i<n;i++)
        {
            psum[i]=psum[i-1]+nums[i];
            csum[i]=csum[i-1]+cost[i];
        }
        
        vector<ll>dp(n,-1);
        ll ans=helper(0,psum,csum,k,dp);
        return ans;
    }
};
