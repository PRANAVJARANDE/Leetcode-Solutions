class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int s, int t) 
    {
        if(s==t)return 0;
        int n=routes.size();

        map<int,vector<int>>adj;
        for(int i=0;i<n;i++) 
        {
            for(int x:routes[i]) 
            {
                adj[x].push_back(i);
            }
        }

        queue<int> q;
        vector<int>dist(n,INT_MAX);

        for(int x:adj[s]) 
        {
            dist[x]=1;
            q.push(x);
        }

        while(!q.empty()) 
        {
            int x=q.front();
            q.pop();

            if(find(routes[x].begin(),routes[x].end(),t)!=routes[x].end())return dist[x];
            
            for (int stop:routes[x]) 
            {
                for(int nx:adj[stop]) 
                {
                    if(dist[nx]>dist[x]+1)
                    {
                        dist[nx]=dist[x]+1;
                        q.push(nx);
                    }
                }
            }
        }

        return -1;
    }
};
