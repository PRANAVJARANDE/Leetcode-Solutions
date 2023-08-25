class Solution {
public:

    bool helper(int i1,int i2,int i3,string s1,string s2,string s3,vector<vector<int>> &dp)
    {
        if(i3==s3.size() && i1==s1.size() && i2==s2.size())
            return 1;

        if(i1>s1.size() || i2>s2.size())
            return 0;

        if(dp[i1][i2]!=-1)
            return dp[i1][i2];
        
        if(s3[i3]==s2[i2] && s1[i1]==s3[i3])
        {
            bool op1=helper(i1,i2+1,i3+1,s1,s2,s3,dp);
            bool op2=helper(i1+1,i2,i3+1,s1,s2,s3,dp);
            return dp[i1][i2]=op1 || op2;
        }
        if(s1[i1]==s3[i3])
        {
            return dp[i1][i2]=helper(i1+1,i2,i3+1,s1,s2,s3,dp);
        }
        if(s2[i2]==s3[i3])
        {
            return dp[i1][i2]=helper(i1,i2+1,i3+1,s1,s2,s3,dp);
        }
        return dp[i1][i2]=0;
    }

    bool isInterleave(string s1, string s2, string s3) 
    {
        vector<vector<int>> dp(s1.size()+1,vector<int>(s2.size()+1,-1));
        return helper(0,0,0,s1,s2,s3,dp);
    }
};
