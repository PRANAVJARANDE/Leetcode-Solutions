class Solution {
public:

    int helper(int in,int par,vector<vector<int>>&adj)
    {
        int h=0;
        for(auto x:adj[in])
        {
            if(x!=par)
            {
                int ch=helper(x,in,adj);
                h=max(h,ch);
            }
        }
        return 1+h;
    }



    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) 
    {
        vector<int>ans(n-1,0);
        for(int i=1;i<(1<<n);i++)
        {
            vector<vector<int>>adj(n);
            for(auto x:edges)
            {
                int u=x[0]-1,v=x[1]-1;
                if((i & (1<<u)) && (i & (1<<v)))
                {
                    adj[u].push_back(v);
                    adj[v].push_back(u);
                }
            }

            //check if connected
            int st=-1;
            for(int j=0;j<n;j++)
            {
                if(i & (1<<j))
                {
                    st=j;
                    break;
                }
            }
            if(st!=-1)
            {
                vector<int>vis(n,0);
                queue<int>q1;
                q1.push(st);
                vis[st]=1;
                while(!q1.empty())
                {
                    auto in=q1.front();
                    q1.pop();
                    for(auto x:adj[in])
                    {
                        if(vis[x]==0)
                        {
                            vis[x]=1;
                            q1.push(x);
                        }
                    }
                }
                bool flag=1;
                for(int j=0;j<n;j++)
                {
                    if(i & (1<<j))
                    {
                        if(vis[j]==0)flag=0;
                    }
                }
                if(flag==0)continue;

                //find diameter
                int h=0;
                for(int j=0;j<n;j++)
                {
                    if(i & (1<<j))
                    {
                        int ch=helper(j,-1,adj)-1;
                        h=max(ch,h);
                    }
                }
                if(h-1>=0 && h-1<n-1)
                {
                    ans[h-1]++;
                }
            }
        }
        return ans;


        
    }
};
