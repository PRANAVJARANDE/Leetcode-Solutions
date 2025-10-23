class Solution {
public:

    vector<int>dx{-1,1,0,0};
    vector<int>dy{0,0,-1,1};

    bool help(vector<vector<int>>&a,vector<int>&s,vector<int>&t)
    {
        int l=1e5;
        queue<pair<int,int>>q1;
        map<pair<int,int>,bool>vis;
        for(auto x:a)vis[{x[0],x[1]}]=1;
        vis[{s[0],s[1]}]=1;
        q1.push({s[0],s[1]});
        while(!q1.empty() && l--)
        {
            int x=q1.front().first;
            int y=q1.front().second;
            q1.pop();
            if(x==t[0] && y==t[1])return 1;
            for(int z=0;z<4;z++)
            {
                int nx=x+dx[z],ny=y+dy[z];
                if(nx>=0 && ny>=0 && nx<1e6 && ny<1e6 && vis[{nx,ny}]==0)
                {
                    vis[{nx,ny}]=1;
                    q1.push({nx,ny});
                }
            }
        }
        if(l<=0)return 1;
        return 0;
    }



    bool isEscapePossible(vector<vector<int>>&a, vector<int>&s, vector<int>&t) 
    {
        return help(a,s,t) && help(a,t,s);
    }
};
