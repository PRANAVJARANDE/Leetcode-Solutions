class Solution {
public:

    int n,m;

    string shortestCommonSupersequence(string a, string b) 
    {
        n=a.size();
        m=b.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1));
        for(int i=0;i<=n;i++) 
        {
            for(int j=0;j<=m;j++) 
            {
                if(i==0)dp[i][j]=j;
                else if(j==0)dp[i][j]=i;
                else if(a[i-1]==b[j-1])dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=1+min(dp[i-1][j],dp[i][j-1]);
            }
        }

        int i=n,j=m;
        string res="";
        while(i>0 && j>0)
        {
            if(a[i-1]==b[j-1])
            {
                res+=a[i-1];
                i--;
                j--;
            }
            else if(dp[i][j-1]<dp[i-1][j])
            {
                res+=b[j-1];
                j--;
            }
            else
            {
                res+=a[i-1];
                i--;
            }
        }

        while(j>0)
        {
            res+=b[j-1];
            j--;
        }
        while(i>0)
        {
            res+=a[i-1];
            i--;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
