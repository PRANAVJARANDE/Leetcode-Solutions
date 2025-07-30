

class Solution {
  public:
    // Function to return the minimum cost to react at bottom
    // right cell from top left cell.
    vector<int>dx{-1,1,0,0};
    vector<int>dy{0,0,-1,1};
    int n,m;
    bool issafe(int x,int y)
    {
        if(x<0 || y<0 || x>=n || y>=m)return 0;
        return 1;
    }
    
    int minimumCostPath(vector<vector<int>>& a) 
    {
        n=a.size();
        m=a[0].size();
        vector<vector<int>>dis(n,vector<int>(m,INT_MAX));
        dis[0][0]=0;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q1;
        q1.push({0,{0,0}});
        
        while(!q1.empty())
        {
            int d=q1.top().first;
            int x=q1.top().second.first;
            int y=q1.top().second.second;
            q1.pop();
            if(d>dis[x][y])continue;
            
            if(x==n-1 && y==m-1)return d+a[x][y];
            for(int z=0;z<4;z++)
            {
                int nx=x+dx[z];
                int ny=y+dy[z];
                if(issafe(nx,ny) && dis[nx][ny]>dis[x][y]+a[x][y])
                {
                    dis[nx][ny]=a[x][y]+dis[x][y];
                    q1.push({dis[nx][ny],{nx,ny}});
                }
            }
        }
        
        return dis[n-1][m-1];
    }
};
