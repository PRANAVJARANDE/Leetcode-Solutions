class Solution {
public:

    int n,m;
    vector<int>dx{-1,1,0,0};
    vector<int>dy{0,0,1,-1};

    bool issafe(int i,int j)
    {
        if(i<0 || j<0 || i>=n || j>=m)return 0;
        return 1;
    }

    int connect(int i,int j,vector<vector<int>>&a,vector<vector<int>>&vis)
    {
        queue<pair<int,int>>q1;
        vis[i][j]=1;
        q1.push({i,j});
        int cnt=0;
        while(!q1.empty())
        {
            auto x=q1.front().first;
            auto y=q1.front().second;
            q1.pop();
            for(int z=0;z<4;z++)
            {
                int nx=x+dx[z];
                int ny=y+dy[z];
                if(issafe(nx,ny) && a[nx][ny]==1 && vis[nx][ny]==0)
                {
                    cnt++;
                    vis[nx][ny]=1;
                    q1.push({nx,ny});
                }
            } 
        }
        return cnt;
    }

    vector<int> hitBricks(vector<vector<int>>& a, vector<vector<int>>& q) 
    {
        n=a.size();
        m=a[0].size();
        int qs=q.size();
        vector<int>ans(qs,0);
        vector<vector<int>>grid=a;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(auto x:q)grid[x[0]][x[1]]=0;
        for(int i=0;i<m;i++)if(grid[0][i]==1)connect(0,i,grid,vis);

        for(int i=qs-1;i>=0;i--)
        {
            int x=q[i][0],y=q[i][1];
            if(a[x][y]==0)continue;

            grid[x][y]=1;
            bool flag=0;
            if(x==0)flag=1;
            for(int z=0;z<4;z++)
            {
                int nx=x+dx[z];
                int ny=y+dy[z];
                if(issafe(nx,ny) && vis[nx][ny])
                {
                    flag=1;
                    break;
                }
            }
            if(flag)
            {
                int res=connect(x,y,grid,vis);
                ans[i]=res;
            }
        }
        return ans;
    }
};
