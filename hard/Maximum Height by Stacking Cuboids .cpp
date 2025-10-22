class Solution {
public:

    int n;
    int helper(int in,int m1,int m2,vector<vector<int>>&a,vector<vector<vector<int>>>&dp)
    {
        if(in>=n)return 0;
        if(dp[in][m1][m2]!=-1)return dp[in][m1][m2];
        int op1=helper(in+1,m1,m2,a,dp);
        int op2=INT_MIN;
        if(m1<=a[in][1] && m2<=a[in][2])
        {
            op2=a[in][2]+helper(in+1,a[in][1],a[in][2],a,dp);
        }
        return dp[in][m1][m2]=max(op1,op2);
    }

    int maxHeight(vector<vector<int>>&a) 
    {
        n=a.size();
        for(auto &x:a)sort(x.begin(),x.end());
        sort(a.begin(),a.end());
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(101,vector<int>(101,-1)));
        int ans=helper(0,0,0,a,dp);
        return ans;
    }
};
