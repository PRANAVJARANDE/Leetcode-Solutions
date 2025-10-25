class Solution {
public:

    vector<int>dx{-1,1,0,0};
    vector<int>dy{0,0,-1,1};

    int n,m;
    bool issafe(int i,int j)
    {
        if(i>=0 && j>=0 && i<n && j<m)return 1;
        return 0;
    }

    int shortestPath(vector<vector<int>>& a, int k) 
    {
        n=a.size();
        m=a[0].size();
        vector<vector<vector<int>>>dis(n,vector<vector<int>>(m,vector<int>(k+1,INT_MAX)));
        dis[0][0][k]=0;
        
        priority_queue<pair<int,pair<pair<int,int>,int>>,vector<pair<int,pair<pair<int,int>,int>>>,greater<pair<int,pair<pair<int,int>,int>>>>q1;
        q1.push({0,{{0,0},k}});
        while(!q1.empty())
        {
            auto pr=q1.top();
            q1.pop();
            int d=pr.first;
            int x=pr.second.first.first;
            int y=pr.second.first.second;
            int kp=pr.second.second;
            if(x==n-1 && y==m-1)return d;
            if(d>dis[x][y][k])continue;
            for(int z=0;z<4;z++)
            {
                int nx=x+dx[z];
                int ny=y+dy[z];
                if(issafe(nx,ny))
                {
                    int nk=kp;
                    if(a[nx][ny])nk--;
                    if(nk>=0 && dis[nx][ny][nk]>d+1)
                    {
                        dis[nx][ny][nk]=d+1;
                        q1.push({dis[nx][ny][nk],{{nx,ny},nk}});
                    }
                }
            }
        }
        return -1;
    }
};
