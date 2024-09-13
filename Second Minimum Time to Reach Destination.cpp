class Solution {
public:
    int secondMinimum(int n, std::vector<std::vector<int>>& edges, int time, int change) {
        vector<vector<int>>adj(n+1);
        for(auto x: edges)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q1;
        q1.push({0,1});
        vector<int>dist(n+1,INT_MAX),dist2(n+1,INT_MAX);
        vector<int>vis(n+1,0);

        while (!q1.empty()) {
            int dis=q1.top().first;
            int in=q1.top().second;
            q1.pop();

            if(vis[in]==1 && in==n)
            {
                return dis;
            }
            vis[in]=1;

            for(int x: adj[in])
            {
                int ndis;

                if((dis/change)%2)
                {
                    ndis=change*(dis/change + 1)+time;
                }
                else
                {
                    ndis=dis+time;
                }

                if(dist[x]>ndis)
                {
                    dist2[x]=dist[x];
                    dist[x]=ndis;
                    q1.push({ndis,x});
                } 
                else if(dist2[x]>ndis && dist[x]!=ndis) 
                {
                    dist2[x] = ndis;
                    q1.push({ndis, x});
                }
            }
        }

        return dist2[n];
    }
};
