class Solution {
public:
    map<pair<int,int>,int>vis;
    map<int,vector<int>> row;
    map<int,vector<int>> col;
    int bfs(vector<int>v1)
    {
        queue<vector<int>> q1;
        q1.push(v1);
        int res=0;
        while(!q1.empty())
        {
            int i=q1.front()[0];
            int j=q1.front()[1];
            q1.pop();
            for(int x: row[i])
            {
                if(vis[{i,x}]==0)
                {
                    vis[{i,x}]=1;
                    q1.push({i,x});
                    res++;
                }
            }
            for(int y: col[j])
            {
                if(vis[{y,j}]==0)
                {
                    vis[{y,j}]=1;
                    q1.push({y,j});
                    res++;
                }
            }
        }
        return res;
    }

    int removeStones(vector<vector<int>>& a) {
        
        for(auto x:a)
        {
            row[x[0]].push_back(x[1]);
            col[x[1]].push_back(x[0]);
        }
        int ans=0;
        for(auto x:a)
        {
            if(vis[{x[0],x[1]}]==0)
            {
                vis[{x[0],x[1]}]=1;
                ans+=bfs(x);
            }
        }
        return ans;
    }
};
