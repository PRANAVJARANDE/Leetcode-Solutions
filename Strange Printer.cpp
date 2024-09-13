class Solution {
public:

    int helper(int i,int j,vector<char>&a,vector<vector<int>>&dp)
    {
        if(i>j)return 0;
        if(i==j)return 1;
        if(dp[i][j]!=-1)return dp[i][j];
        int op1=1+helper(i+1,j,a,dp);
        for(int z=i+1;z<=j;z++)
        {
            if(a[i]==a[z])
            {
                int res=helper(i+1,z-1,a,dp)+helper(z,j,a,dp);
                op1=min(op1,res);
            }
        }
        return dp[i][j]=op1;
    }

    int strangePrinter(string s) {
        vector<char> a;
        a.push_back(s[0]);
        for(int i=1;i<s.size();i++)
        {
            if(s[i]!=s[i-1])a.push_back(s[i]);
        }
        int n=a.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int ans=helper(0,n-1,a,dp);
        return ans;
    }
};
