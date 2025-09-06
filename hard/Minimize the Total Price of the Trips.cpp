class Solution {
public:

    bool helper(int in,int par,vector<vector<int>>&adj,vector<int>&count,int tar)
    {
        count[in]++;
        if(in==tar)return 1;
        for(auto x:adj[in])
        {
            if(x!=par)
            {
                bool ch=helper(x,in,adj,count,tar);
                if(ch==1)return 1;
            }
        }
        count[in]--;
        return 0;
    }


    int getans(int in,int par,int flag,vector<vector<int>>&adj,vector<int>&price,vector<int>&count,vector<vector<int>>&dp)
    {
        if(dp[in][flag]!=-1)return dp[in][flag];
        int op1=INT_MAX;
        if(flag==0)
        {
            //can halve the price of node 
            op1=(price[in]/2)*count[in];
            for(auto x:adj[in])
            {
                if(x!=par)
                {
                    op1+=getans(x,in,1,adj,price,count,dp);
                }
            }
        }
        //not halve
        int op2=price[in]*count[in];
        for(auto x:adj[in])
        {
            if(x!=par)
            {
                op2+=getans(x,in,0,adj,price,count,dp);
            }
        }
        return dp[in][flag]=min(op1,op2);
    }

    int minimumTotalPrice(int n, vector<vector<int>>& edg, vector<int>& price, vector<vector<int>>& trips) 
    {
        // adj
        vector<vector<int>>adj(n);
        for(auto x:edg)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }

        vector<int>count(n,0);
        for(auto x:trips)helper(x[0],-1,adj,count,x[1]);
        
        //for(auto x:count)cout<<x<<" ";
        vector<vector<int>>dp(n,vector<int>(2,-1));
        int ans1=getans(0,-1,0,adj,price,count,dp);
        int ans2=getans(0,-1,1,adj,price,count,dp);
        return min(ans1,ans2);
    }
};
