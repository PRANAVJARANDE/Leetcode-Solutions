class Solution {
public:

    long long helper(string &s1,string &s2,int i1,int i2,vector<vector<int>>&dp)
    {
        if(i1==s1.size() && i2==s2.size())
            return 0;
        
        if(i1==s1.size())
        {
            int a=0;
            while(i2<s2.size())
            {
                a+=(int)s2[i2];
                i2++;
            }
            return a;
        }
        if(i2==s2.size())
        {
            int a=0;
            while(i1<s1.size())
            {
                a+=s1[i1];
                i1++;
            }
            return a;
        }

        if(dp[i1][i2]!=-1)
            return dp[i1][i2];

        long long ans=INT_MAX;
        if(s1[i1]==s2[i2])
             ans=helper(s1,s2,i1+1,i2+1,dp);
        else 
        {
            ans=min(s1[i1]+helper(s1,s2,i1+1,i2,dp),ans);
            ans=min(s2[i2]+helper(s1,s2,i1,i2+1,dp),ans);
        }
        return dp[i1][i2]=ans;
        
    }


    int minimumDeleteSum(string s1, string s2) 
    {
        vector<vector<int>> dp(s1.size(),vector<int>(s2.size(),-1));
        return helper(s1,s2,0,0,dp);
    }
};
