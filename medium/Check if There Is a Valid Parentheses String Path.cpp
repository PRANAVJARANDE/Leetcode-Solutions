class Solution {
public:

    int n,m;
    bool helper(int i,int j,int cnt,vector<vector<char>>&a,vector<vector<vector<int>>>&dp)
    {
        if(cnt<0)return 0;
        if(i==n-1 && j==m-1)
        {
            if(cnt==1 && a[i][j]==')')return 1;
            return 0;
        }
        if(dp[i][j][cnt]!=-1)return dp[i][j][cnt];

        //move right
        if(j+1<m)
        {
            bool op=helper(i,j+1,cnt+((a[i][j]=='(')? 1:-1),a,dp);
            if(op)return dp[i][j][cnt]=1;
        }
        //move down
        if(i+1<n)
        {
            bool op=helper(i+1,j,cnt+((a[i][j]=='(')? 1:-1),a,dp);
            if(op)return dp[i][j][cnt]=1;
        }
        return dp[i][j][cnt]=0;
    }

    bool hasValidPath(vector<vector<char>>& a) 
    {
        n=a.size();
        m=a[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m+n+1,-1)));
        return helper(0,0,0,a,dp);
    }
};
