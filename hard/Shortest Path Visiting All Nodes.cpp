class Solution {
public:
    int shortestPathLength(vector<vector<int>>& adj)
    {
        int n=adj.size();
        if(n==1)return 0;
        
        queue<pair<int,int>>q1;
        vector<vector<int>>vis(n,vector<int>((1<<n),0));
        for(int i=0;i<n;i++)
        {
            q1.push({i,(1<<i)});
            vis[i][(1<<i)]=1;
        }

        int cans=1;
        while(!q1.empty())
        {
            int sz=q1.size();
            while(sz--)
            {
                int in=q1.front().first;
                int mask=q1.front().second;
                q1.pop();

                if(mask==((1<<n)-1))return cans-1;

                for(auto x:adj[in])
                {
                    int nmask=mask | (1<<x);
                    if(vis[x][nmask]==0)
                    {
                        vis[x][nmask]=1;
                        q1.push({x,nmask});
                    }
                }
            }
            cans++;
        }
        return cans;
    }
};
