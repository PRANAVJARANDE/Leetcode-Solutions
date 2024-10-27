#define ll long long 
class Solution {
public:
    
    vector<vector<ll>> memo;
    const int MOD=1E9 + 7;
     
    long long helper(int ch,int t)
    {
        if(t==0)return 1ll;
        if (memo[ch][t] != -1) return memo[ch][t];
        if(ch==25)
        {
            long long ans= ((helper(0,t-1)%MOD)+(helper(1,t-1)%MOD))%MOD;
            return memo[ch][t]=ans;
        }
        else
        {
            long long ans=helper(ch+1,t-1)%MOD;
            return memo[ch][t]=ans;
        }
    }
    
    int lengthAfterTransformations(string s, int t) {
        int ans=0;
        memo = vector<vector<ll>>(26, vector<ll>(t + 1, -1));
        for(char x: s)
        {
            int tp=x-'a';
            ans=((ans%MOD)+(helper(tp,t)%MOD))%MOD; 
        }
        return ans;
    }
};
