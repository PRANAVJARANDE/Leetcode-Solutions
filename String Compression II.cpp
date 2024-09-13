int dp[101][27][101][101];
class Solution {
public:

    int n;
    int helper(int k,string &s,int in,int prev,int c)
    {
        if(k<0)
            return INT_MAX;
        
        if(in>=n)
            return 0;

        if(dp[in][prev][k][c]!=-1)
            return dp[in][prev][k][c];

        int op1=helper(k-1,s,in+1,prev,c);
        int op2=INT_MAX;
        if(prev+'a'==s[in])
        {
            if(c==9 || c==99 || c==1)
            {
                op2=1+helper(k,s,in+1,prev,c+1);
            }
            else
            {
                op2=helper(k,s,in+1,prev,c+1);
            }
        }
        else
        {
            op2=1+helper(k,s,in+1,s[in]-'a',1);
        }
        return dp[in][prev][k][c]=min(op1,op2);
    }

    int getLengthOfOptimalCompression(string s, int k) 
    {
        n=s.size();
        memset(dp,-1,sizeof(dp));
        return helper(k,s,0,26,0);
    }
};
