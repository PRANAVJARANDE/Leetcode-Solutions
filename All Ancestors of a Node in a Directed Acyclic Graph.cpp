class Solution {
public:
   
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<set<int>>ans(n);
        vector<int> deg(n,0);
        vector<vector<int>> adj(n);
        for(auto x: edges)
        {
            adj[x[0]].push_back(x[1]);
            deg[x[1]]++;
        }
        queue<int> q1;
        for(int i=0;i<n;i++)
        {
            if(deg[i]==0)q1.push(i);
        }
        while(!q1.empty())
        {
            int in=q1.front();
            q1.pop();

            for(int x: adj[in])
            {
                for(int y:ans[in])
                {
                    ans[x].insert(y);
                }
                ans[x].insert(in);
                deg[x]--;
                if(deg[x]==0)
                {
                    q1.push(x);
                }
            }
        }
        vector<vector<int>>res(n);
        for(int i=0;i<n;i++)
        {
            for(int x: ans[i])
            {
                res[i].push_back(x);
            }
        }
        return res;


    }
};
