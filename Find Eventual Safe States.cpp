class Solution {
public:

    bool dfs(int k,vector<vector<int>> &graph,vector<bool> &vis,vector<bool> &cvis,vector<bool> &safe)
    {
        vis[k]=1;
        cvis[k]=1;
        
        for(int x: graph[k])
        {
            if(vis[x]==0 )
            {
                if(dfs(x,graph,vis,cvis,safe)==0){
                    safe[k]=0;
                    return 0;
                }
            }
            else if(vis[x]==1 && cvis[x]==1)
            {
                safe[k]=0;
                return 0;
            }
        }
        cvis[k]=0;
        return 1;
    }


    vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
    {
        int n=graph.size();
        vector<bool> vis(n,0);
        vector<bool> cvis(n,0);
        vector<bool> safe(n,1);
        

        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                dfs(i,graph,vis,cvis,safe);
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if(safe[i]==1)
            {
                ans.push_back(i);
            }
        }
        
        return ans;

    }
};
