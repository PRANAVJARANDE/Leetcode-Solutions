class Solution {
public:

    int n,m;
    bool issafe(int x,int y)
    {
        if(x>=0 && y>=0 && x<n && y<m)return 1;
        return 0;
    }

    vector<int>dx{-1,1,0,0};
    vector<int>dy{0,0,-1,1};

    int cutOffTree(vector<vector<int>>& a) 
    {
        n=a.size();
        m=a[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>trees;
        for(int i=0;i<n;i++)for(int j=0;j<m;j++)if(a[i][j]>1)trees.push({a[i][j],{i,j}});
        int ans=0;
        int x=0,y=0;
        while(!trees.empty())
        {
            auto temp=trees.top();
            trees.pop();
            int tx=temp.second.first;
            int ty=temp.second.second;

            vector<vector<int>>vis(n,vector<int>(m,-1));
            queue<pair<int,int>>q1;
            q1.push({x,y});
            vis[x][y]=0;
            while(!q1.empty())
            {
                auto px=q1.front().first;
                auto py=q1.front().second;
                q1.pop();

                for(int z=0;z<4;z++)
                {
                    int nx=px+dx[z];
                    int ny=py+dy[z];
                    if(issafe(nx,ny) && a[nx][ny]>0 && vis[nx][ny]==-1)
                    {
                        q1.push({nx,ny});
                        vis[nx][ny]=1+vis[px][py];
                    }
                }
            }
            if(vis[tx][ty]==-1)return -1;
            ans+=vis[tx][ty];
            x=tx;
            y=ty;
        }
        return ans;
    }
};
