class Solution {
public:

    vector<int>dx;
    vector<int>dy;
    int helper(int in,int p1,int p2,string&s,vector<vector<vector<int>>>&dp)
    {
        int n=s.size();
        if(in>=n)return 0;
        if(dp[in][p1][p2]!=-1)return dp[in][p1][p2];
        //type using 1
        int tadd1=0;
        if(p1!=26)tadd1=abs(dx[p1]-dx[s[in]-'A'])+abs(dy[p1]-dy[s[in]-'A']);
        int op1=tadd1+helper(in+1,s[in]-'A',p2,s,dp);
        //type using 2
        int tadd2=0;
        if(p2!=26)tadd2=abs(dx[p2]-dx[s[in]-'A'])+abs(dy[p2]-dy[s[in]-'A']);
        int op2=tadd2+helper(in+1,p1,s[in]-'A',s,dp);
        return dp[in][p1][p2]=min(op1,op2);
    }

    int minimumDistance(string s) 
    {
        dx=vector<int>(26,0);
        dy=vector<int>(26,0);
        int in=0;
        for(int i=0;i<5;i++)
        {
            for(int j=0;j<6;j++)
            {
                if(in<26)
                {
                    dx[in]=i;
                    dy[in]=j;
                    in++;
                }
            }
        }
        int n=s.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(27,vector<int>(27,-1)));
        int ans=helper(0,26,26,s,dp);
        return ans;
    }
};
