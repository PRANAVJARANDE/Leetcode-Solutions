class Solution {
public:

    int build(int in, int par, vector<vector<int>>& adj, vector<int>& res) {
        int depth = 0;
        for (auto x : adj[in]) {
            if (x != par) {
                depth = max(depth, build(x, in, adj, res) + 1);
            }
        }
        res[in] = depth;
        return depth;
    }

    int helper(int in, int par, int extra, vector<int>& res, vector<vector<int>>& adj) {
        int ans = max(extra, res[in]);
        int m1 = -1, m2 = -1;  
        for (auto x : adj[in]) {
            if (x != par) {
                if (res[x] > m1) {
                    m2 = m1;
                    m1 = res[x];
                } else if (res[x] > m2) {
                    m2 = res[x];
                }
            }
        }

        for (auto x : adj[in]) {
            if (x != par) {
                int nextra;
                if (res[x] == m1)
                    nextra = max(extra, m2 + 1) + 1;
                else
                    nextra = max(extra, m1 + 1) + 1;
                ans = max(ans, helper(x, in, nextra, res, adj));
            }
        }
        return ans;
    }

    int diameter(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto& x : edges) {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }

        vector<int> res(n, 0);
        int ans = 0;
        vector<int> vis(n, 0);

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                vector<int> nodes;
                queue<int> q;
                q.push(i);
                vis[i] = 1;
                while (!q.empty()) {
                    int u = q.front(); q.pop();
                    nodes.push_back(u);
                    for (auto v : adj[u])
                        if (!vis[v]) vis[v] = 1, q.push(v);
                }

                build(i, -1, adj, res);
                ans = max(ans, helper(i, -1, 0, res, adj));
            }
        }

        return ans; 
    }
};
