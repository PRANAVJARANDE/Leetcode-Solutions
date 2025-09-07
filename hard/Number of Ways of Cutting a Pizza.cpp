#define ll long long 
class Solution {
public:

    int n,m;
    const int MOD=1e9 + 7;
    ll helper(int i,int j,int k,vector<vector<int>>&a,vector<vector<vector<ll>>>&dp)
    {
        if(i>=n || j>=m)return 0;
        if(dp[i][j][k]!=-1)return dp[i][j][k];
        if(k==1)
        {
            int cs=a[n-1][m-1];
            if(i-1>=0)cs-=a[i-1][m-1];
            if(j-1>=0)cs-=a[n-1][j-1];
            if(i-1>=0 && j-1>=0)cs+=a[i-1][j-1];
            return dp[i][j][k]=(cs>0);
        }
        
        //take column
        ll ans=0;
        for(int nc=j;nc<m;nc++)
        {
            int cs=a[n-1][nc];
            if(i-1>=0)cs-=a[i-1][nc];
            if(j-1>=0)cs-=a[n-1][j-1];
            if(i-1>=0 && j-1>=0)cs+=a[i-1][j-1];
            if(cs>0)ans=((ans%MOD)+(helper(i,nc+1,k-1,a,dp)%MOD))%MOD;
        }

        for(int nr=i;nr<n;nr++)
        {
            int cs=a[nr][m-1];
            if(i-1>=0)cs-=a[i-1][m-1];
            if(j-1>=0)cs-=a[nr][j-1];
            if(i-1>=0 && j-1>=0)cs+=a[i-1][j-1];
            if(cs>0)ans=((ans%MOD)+(helper(nr+1,j,k-1,a,dp)%MOD))%MOD;
        }
        return dp[i][j][k]=ans;
    }


    int ways(vector<string>&s, int k) 
    {
        n=s.size();
        m=s[0].size();
        vector<vector<int>>a(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(s[i][j]=='A')a[i][j]++;
                if(i-1>=0)a[i][j]+=a[i-1][j];
                if(j-1>=0)a[i][j]+=a[i][j-1];
                if(i-1>=0 && j-1>=0)a[i][j]-=a[i-1][j-1];
            }
        }

        vector<vector<vector<ll>>>dp(n,vector<vector<ll>>(m,vector<ll>(k+1,-1)));
        int ans=helper(0,0,k,a,dp);
        return ans;
    }
};
