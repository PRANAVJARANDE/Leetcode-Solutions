class Solution {
public:

    vector<int>dx{-1,1,0,0};
    vector<int>dy{0,0,1,-1};
    int n,m;
    bool issafe(int i,int j)
    {
        if(i<0 || j<0 || i>=n || j>=m)return 0;
        return 1;
    }
    int minTimeToReach(vector<vector<int>>& a) 
    {
        n=a.size();
        m=a[0].size();
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        dist[0][0]=0;
        priority_queue<pair<pair<int,int>,pair<int,int>>,vector<pair<pair<int,int>,pair<int,int>>>,greater<pair<pair<int,int>,pair<int,int>>>>q1;
        q1.push({{0,0},{0,0}});

        while(!q1.empty())
        {
            int dis=q1.top().first.first;
            int in=q1.top().first.second;
            int x=q1.top().second.first;
            int y=q1.top().second.second;
            q1.pop();

            if(x==n-1 && y==m-1)return dis;

            for(int z=0;z<4;z++)
            {
                int nx=dx[z]+x;
                int ny=dy[z]+y;
                int np=0;
                int ta=2;
                if(in==0)
                {
                    ta=1;
                    np=1;
                }
                if(issafe(nx,ny) && dist[x][y]+ta+max(0,a[nx][ny]-dis)<dist[nx][ny])
                {
                    dist[nx][ny]=dist[x][y]+ta+max(0,a[nx][ny]-dis);
                    q1.push({{dist[nx][ny],np},{nx,ny}});
                }
            }
        }
        return dist[n-1][m-1];
    }
};
