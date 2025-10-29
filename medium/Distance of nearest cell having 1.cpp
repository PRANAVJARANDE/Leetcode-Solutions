class Solution {
  public:
    
    int n,m;
    vector<int>dx{-1,1,0,0};
    vector<int>dy{0,0,1,-1};
    
    bool issafe(int x,int y)
    {
        if(x>=0 && y>=0 && x<n && y<m)return 1;
        return 0;
    }
    vector<vector<int>> nearest(vector<vector<int>>& a) {
        n=a.size();
        m=a[0].size();
        queue<pair<int,int>>q1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(a[i][j]==1)
                {
                    q1.push({i,j});
                    a[i][j]=0;
                }
                else a[i][j]=INT_MAX;
            }
        }
        
        int ans=1;
        while(!q1.empty())
        {
            int sz=q1.size();
            while(sz--)
            {
                auto in=q1.front();
                int x=in.first;
                int y=in.second;
                q1.pop();
                for(int z=0;z<4;z++)
                {
                    int nx=x+dx[z];
                    int ny=y+dy[z];
                    if(issafe(nx,ny) && a[nx][ny]==INT_MAX)
                    {
                        a[nx][ny]=ans;
                        q1.push({nx,ny});
                    }
                }
            }
            ans++;
        }
        return a;
    }
};
