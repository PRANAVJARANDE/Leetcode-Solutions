class Solution {
public:

    int n,m;
    bool issafe(int x,int y)
    {
        if(x<0 || y<0 || x>=n || y>=m)return 0;
        return 1;
    }
    vector<int>dx{-1,1,0,0};
    vector<int>dy{0,0,1,-1};


    int trapRainWater(vector<vector<int>>& a) 
    {   
        n=a.size();
        m=a[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q1;
        for(int c=0;c<m;c++)
        {
            vis[0][c]=1;
            vis[n-1][c]=1;
            q1.push({a[0][c],{0,c}});
            q1.push({a[n-1][c],{n-1,c}});
        }
        for(int r=1;r<n-1;r++)
        {
            vis[r][0]=1;
            vis[r][m-1]=1;
            q1.push({a[r][0],{r,0}});
            q1.push({a[r][m-1],{r,m-1}});
        }
        int ans=0;
        while(!q1.empty())
        {
            int h=q1.top().first;
            int x=q1.top().second.first;
            int y=q1.top().second.second;
            q1.pop();
            for(int z=0;z<4;z++)
            {
                int nx=x+dx[z];
                int ny=y+dy[z];
                if(issafe(nx,ny) && vis[nx][ny]==0)
                {
                    vis[nx][ny]=1;
                    ans+=max(0,h-a[nx][ny]);
                    q1.push({max(a[nx][ny],h),{nx,ny}});
                }

            }


        }



        return ans;
    }
};
