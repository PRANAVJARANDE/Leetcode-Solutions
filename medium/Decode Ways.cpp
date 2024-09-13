class Solution {
public:

    int helper(string s,int in,int dest,vector<int>&dp)
    {
        if(in==dest)
            return 1;

        if(s[in]=='0')
            return 0;

        if(in==dest-1)
            return 1;

        if(dp[in]!=-1)
            return dp[in];

        int a=helper(s,in+1,dest,dp);
        int i2=stoi(s.substr(in,2));
        if(i2<=26 && i2>=1)
            a+=helper(s,in+2,dest,dp);

        return dp[in]=a;
    }

    int numDecodings(string s) 
    {
        int n=s.size();
        vector<int> dp(n+1,-1);
        return helper(s,0,s.size(),dp);   
    }
};
