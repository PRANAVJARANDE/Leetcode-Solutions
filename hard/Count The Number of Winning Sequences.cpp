class Solution {
public:
    int n;
    long long MOD=1e9 +7;
    int check(char a,char b)
    {
        if(a==b)return 0;
        if(a=='F' && b=='E')return 1;
        if(a=='W' && b=='F')return 1;
        if(a=='E' && b=='W')return 1;
        return -1;    
    }
    
    int helper(int in,int sc,int prev,string &s,vector<vector<vector<int>>>&dp)
    {
        if(in>=n)
        {
            if(sc<=0)return 0;
            return 1;
        }
        if(sc+n<0 || sc+n>2*n)return 0;
        if(dp[in][sc+n][prev]!=-1)return dp[in][sc+n][prev];
        int op1=0,op2=0,op3=0;
        if(prev!=1)op1=helper(in+1,sc+check('F',s[in]),1,s,dp)%MOD;
        if(prev!=2)op2=helper(in+1,sc+check('W',s[in]),2,s,dp)%MOD;
        if(prev!=3)op3=helper(in+1,sc+check('E',s[in]),3,s,dp)%MOD;
        return dp[in][sc+n][prev]=((op1%MOD)+(op2%MOD)+(op3%MOD))%MOD;
    }
    
    int countWinningSequences(string s) {
        n=s.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>((2*n +1),vector<int>(4,-1)));
        int ans=helper(0,0,0,s,dp)%MOD;
        return ans;
    }
};
