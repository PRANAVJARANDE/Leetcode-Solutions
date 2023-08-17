class Solution {
public:

    vector<int> toptlogicalsort(int n,vector<vector<int>>&adj,vector<int>&indeg)
    {
        vector<int> ans;
        queue<int> q1;
        for(int i=0;i<n;i++)
        {
            if(indeg[i]==0 )
            {
                q1.push(i);
            }
        }
            while(!q1.empty())
            {
                int k=q1.front();
                q1.pop();
                ans.push_back(k);
                for(int x: adj[k])
                {
                    indeg[x]--;
                    if(indeg[x]==0)
                    {
                        q1.push(x);
                    }
                }
            }
        
        if(ans.size()==n)
        {
            return ans;
        }
        return {};
    }

    vector<int> findOrder(int n, vector<vector<int>>& pre) 
    {
        vector<int> indeg(n,0);
        vector<vector<int>> adj(n);
        for(auto x: pre)
        {
            indeg[x[0]]++;
            adj[x[1]].push_back(x[0]);
        }
    
        return toptlogicalsort(n,adj,indeg);
    }
};
