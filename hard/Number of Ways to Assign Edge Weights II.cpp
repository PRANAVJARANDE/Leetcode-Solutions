#define ll long long
class Solution {
public:

    ll mod_pow(ll a,ll b, ll m) { 
        ll res=1;
        while(b>0){
            if(b&1){
                res=(res*a)%m;
            }
            a=(a*a)%m;
            b=b>>1;
        }
        return res;
    }

    const int LOG = 20;
    const int MOD = 1e9 + 7;
    vector<vector<int>> up;
    vector<int> depth;

    void dfs(int node, int parent, vector<vector<int>>& adj) {
        up[node][0] = parent;
        for (int i = 1; i < LOG; i++) {
            if (up[node][i - 1] != -1)
                up[node][i] = up[up[node][i - 1]][i - 1];
            else
                up[node][i] = -1;
        }

        for (int neighbor : adj[node]) {
            if (neighbor != parent) {
                depth[neighbor] = depth[node] + 1;
                dfs(neighbor, node, adj);
            }
        }
    }

    int lca(int u, int v) {
        if (depth[u] < depth[v])
            swap(u, v);

        for (int i = LOG - 1; i >= 0; i--) {
            if (up[u][i] != -1 && depth[up[u][i]] >= depth[v])
                u = up[u][i];
        }

        if (u == v) return u;

        for (int i = LOG - 1; i >= 0; i--) {
            if (up[u][i] != -1 && up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }

        return up[u][0];
    }

    vector<int> assignEdgeWeights(vector<vector<int>>& e, vector<vector<int>>& queries) {
        int n = e.size() + 1;
        vector<vector<int>> adj(n);
        for (auto x : e) {
            x[0]--;
            x[1]--;
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }

        depth.resize(n);
        up.assign(n, vector<int>(LOG, -1));
        dfs(0, -1, adj);  

        vector<int> ans;
        for (auto x : queries) {
            int u = x[0] - 1;
            int v = x[1] - 1;
            int ancestor = lca(u, v);
            int dis = depth[u] + depth[v] - 2 * depth[ancestor];
            if(dis==0)ans.push_back(0);
            else ans.push_back(mod_pow(2, dis - 1, MOD));
        }

        return ans;
    }
};
