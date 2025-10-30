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
  
    void fill(vector<vector<char>>& a) 
    {
        n=a.size();
        m=a[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q1;
        for(int i=0;i<n;i++)
        {
            if(a[i][0]=='O')
            {
                vis[i][0]=1;
                q1.push({i,0});
            }
            if(a[i][m-1]=='O')
            {
                vis[i][m-1]=1;
                q1.push({i,m-1});
            }
        }
        for(int j=0;j<m;j++)
        {
            if(a[0][j]=='O')
            {
                vis[0][j]=1;
                q1.push({0,j});
            }
            if(a[n-1][j]=='O')
            {
                vis[n-1][j]=1;
                q1.push({n-1,j});
            }
        }
        
        while(!q1.empty())
        {
            int x=q1.front().first;
            int y=q1.front().second;
            q1.pop();
            
            for(int z=0;z<4;z++)
            {
                int nx=x+dx[z];
                int ny=y+dy[z];
                if(issafe(nx,ny) && a[nx][ny]=='O' && vis[nx][ny]==0)
                {
                    vis[nx][ny]=1;
                    q1.push({nx,ny});
                }
            }
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(a[i][j]=='O' && vis[i][j]==0)a[i][j]='X';
            }
        }
        //return a;
    }
};
