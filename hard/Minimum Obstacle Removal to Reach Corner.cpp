class Solution {
public:
    int n,m;
    int INF=1e6;
    vector<int>dx={1,-1,0,0};
    vector<int>dy={0,0,1,-1};
    int minimumObstacles(vector<vector<int>>& a) {
        n=a.size();
        m=a[0].size();
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>q1;
        vector<vector<int>>dis(n,vector<int>(m,INF));
        q1.push({a[0][0],0,0});
        dis[0][0]=0;
        while(!q1.empty())
        {
            auto fr=q1.top();
            q1.pop();
            int distt=fr[0];
            int x=fr[1];
            int y=fr[2];
            if(x==n-1 && y==m-1)return distt;

            for(int i=0;i<4;i++)
            {
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx<n && ny<m && nx>=0 && ny>=0)
                {
                    if(dis[x][y]+a[x][y]<dis[nx][ny])
                    {
                        dis[nx][ny]=dis[x][y]+a[x][y];
                        q1.push({dis[nx][ny],nx,ny});
                    }
                }
            }
        }
        return n*m;
    }
};
