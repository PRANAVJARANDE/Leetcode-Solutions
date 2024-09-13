
class Solution {
public:

    const long long MOD=1e9+7;

    long long helper(int n,int g,int k,vector<vector<int>>&dp)
    {
        if(g==0 && n==0)
        {
            return 1;
        }
        if(g==0)
        {
            return 0;
        }
        if(n==0)
        {
            return 0;
        }
        
        if(dp[n][g]!=-1)
            return dp[n][g];

        long long takenew=(helper(n-1,g-1,k,dp)*n)%MOD;
        long long repeatprev=(helper(n,g-1,k,dp)*max(n-k,0))%MOD;
        return dp[n][g]=(takenew+repeatprev)%MOD;
    }

    int numMusicPlaylists(int n, int goal, int k) 
    {
        vector<vector<int>>dp(n+1,vector<int>(goal+1,-1));
        return helper(n,goal,k,dp)%MOD;
    }
};
