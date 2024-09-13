class Solution {
public:

    void helper(int k,vector<vector<int>> graph,vector<vector<int>> &ans,vector<int> &v1)
    {
        int n=graph.size();
        if(k==n-1)
        {
            ans.push_back(v1);
            return;
        }

        vector<int> ts=graph[k];
        for(int i=0;i<ts.size();i++)
        {
            v1.push_back(ts[i]);
            helper(ts[i],graph,ans,v1);
            v1.pop_back();
        }
        

    }


    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) 
    {
        vector<vector<int>> ans;
        vector<int> v1;
        v1.push_back(0);
        helper(0,graph,ans,v1);
        return ans;
    }
};
