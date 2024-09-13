class Solution {
public:
    
    int helper(int in, vector<vector<int>>& adj) {
        int n=adj.size();
        vector<int> vis(n, 0);
        vector<int> dist(n, INT_MAX);
        queue<int> q;

        q.push(0);
        dist[0] = 0;  

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int neighbor : adj[node]) {
                if (dist[node] + 1 < dist[neighbor]) {
                    dist[neighbor] = dist[node] + 1;
                    q.push(neighbor);
                }
            }
        }

        return dist[n-1];  
    }
    
    
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& q) {
        int qn=q.size();
        vector<int> ans(qn);
        vector<vector<int>>adj(n);
        for(int i=0;i<n-1;i++)
        {
            adj[i].push_back(i+1);
        }
        int in=0;
        for(auto x: q)
        {
            adj[x[0]].push_back(x[1]);
            ans[in]=helper(0,adj);
            in++;
        }
        return ans;
    }
};
