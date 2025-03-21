class Solution {
public:
    vector<string> findAllRecipes(vector<string>& r, vector<vector<string>>& ing, vector<string>& sup) {
        int n=r.size();
        set<string>s;
        for(auto x:sup)s.insert(x);
        vector<int>deg(n,0);
        map<string,vector<int>>adj;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<ing[i].size();j++)
            {
                if(s.find(ing[i][j])==s.end())deg[i]++;
                adj[ing[i][j]].push_back(i);
            }
        }
        queue<int>q1;
        for(int i=0;i<n;i++)
        {
            if(deg[i]==0)
            {
                q1.push(i);
            }
        }
        vector<string>ans;
        while(!q1.empty())
        {
            int in=q1.front();
            q1.pop();
            ans.push_back(r[in]);
            for(auto x:adj[r[in]])
            {
                deg[x]--;
                if(deg[x]==0)q1.push(x);
            }
        }
        return ans;
    }
};
