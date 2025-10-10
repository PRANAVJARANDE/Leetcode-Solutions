class Solution {
public:

    int helper(int i,int j,int extra,vector<vector<int>>&a,vector<vector<vector<int>>>&dp)
    {   
        if(i>j)return 0;
        if(dp[i][j][extra]!=-1)return dp[i][j][extra];
        if(i==j)return dp[i][j][extra]=(a[i][1]+extra)*(a[i][1]+extra);
        int op1=((extra+a[i][1])*(extra+a[i][1]))+helper(i+1,j,0,a,dp);
        int op2=-1e5;
        for(int z=i+1;z<=j;z++)
        {
            if(a[i][0]==a[z][0])
            {
                int res=helper(i+1,z-1,0,a,dp)+helper(z,j,extra+a[i][1],a,dp);
                op2=max(op2,res);
            }
        }
        return dp[i][j][extra]=max(op1,op2);
    }

    int removeBoxes(vector<int>& a) 
    {
        vector<vector<int>>v1;
        v1.push_back({a[0],1});
        for(int i=1;i<a.size();i++)
        {
            if(a[i]==a[i-1])v1.back()[1]++;
            else v1.push_back({a[i],1});
        }        

        int s=0;
        for(auto x:v1)s+=x[1];


        int n=v1.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(s+1,-1)));
        int ans=helper(0,n-1,0,v1,dp);
        return ans;
    }
};
