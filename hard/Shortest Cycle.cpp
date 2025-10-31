class Solution {
public:
    int shortCycle(int n, vector<vector<int>>& e) 
    {
        vector<vector<int>> adj(n);
        for (auto &x : e) {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }

        int ans = INT_MAX;

        for (int st = 0; st < n; st++) 
        {
            vector<int> lvl(n, -1);
            vector<int> par(n, -1);  

            queue<int> q;
            q.push(st);
            lvl[st] = 0;

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (auto v : adj[u]) {
                    if (lvl[v] == -1) 
                    {
                        lvl[v] = lvl[u] + 1;
                        par[v] = u;
                        q.push(v);
                    }
                    else if (par[u] != v) 
                    {
                        ans = min(ans, lvl[u] + lvl[v] + 1);
                    }
                }
            }
        }

        return (ans == INT_MAX ? -1 : ans);
    }
};
