class Solution {
public:

    int dijkstra(int start, vector<vector<pair<int, int>>>& adj,int k, int n) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n, INT_MAX);
        dist[start] = 0;
        pq.push({0, start});
        
        while (!pq.empty())
        {
            int u = pq.top().second;
            int d = pq.top().first;
            pq.pop();
            
            if (d > dist[u]) continue;
    
            for (auto& edge : adj[u]) {
                int v = edge.first;
                int weight = edge.second;
                
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(dist[i]<=k)cnt++;
        }
        return cnt;
    }

    int findTheCity(int n, vector<vector<int>>& edges, int k) 
    {
        vector<vector<pair<int,int>>>adj(n);
        for(auto x: edges)
        {
            adj[x[0]].push_back({x[1],x[2]});
            adj[x[1]].push_back({x[0],x[2]});
        }

        int res=0;
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
            int cnt=dijkstra(i,adj,k,n);
            if(ans>=cnt)
            {
                ans=cnt;
                res=i;
            }

        }
        return res;
        
    }
};
