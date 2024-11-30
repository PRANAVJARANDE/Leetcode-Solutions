class Solution {
public:
    vector<vector<int>> ans;
    void dfs(int in,map<int,vector<int>>&adj)
    {
        while(!adj[in].empty())
        {
            int nx=adj[in].back();
            adj[in].pop_back();
            dfs(nx,adj);
            ans.push_back({in,nx});
        }
    }

    vector<vector<int>> validArrangement(vector<vector<int>>& a) 
    {
        map<int,int> m;
        map<int,vector<int>> mp;
        for(auto x:a)
        {
            m[x[0]]++;
            m[x[1]]--;
            mp[x[0]].push_back(x[1]);
        }
        
        int st=a[0][0];
        for(auto x: m)
        {
            if(x.second==1)
            {
                st=x.first;
                break;
            }
        }
        dfs(st,mp);
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};
