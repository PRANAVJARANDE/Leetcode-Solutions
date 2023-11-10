class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& arr) 
    {
        unordered_map<int,vector<int>> m;
        for(auto x: arr)
        {
            m[x[0]].push_back(x[1]);
            m[x[1]].push_back(x[0]);
        }
        int s=-1;
        for(auto x: m)
            if(x.second.size()==1)s=x.first;

        int n=arr.size()+1;
        unordered_map<int,int> vis;
        vector<int> ans;
        ans.push_back(s);
        vis[s]=1;

        for(int i=1;i<n;i++)
        {
            for(int x: m[s])
            {
                if(vis[x]==0)
                {
                    vis[x]=1;
                    ans.push_back(x);
                    s=x;
                }
            }
        }
        return ans;
    }
};
