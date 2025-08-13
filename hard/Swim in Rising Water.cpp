class Solution {
public:

    vector<int>dx{-1,1,0,0};
    vector<int>dy{0,0,-1,1};

    int swimInWater(vector<vector<int>>& a) 
    {
        int n=a.size();
        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
        dist[0][0]=a[0][0];

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q1;
        q1.push({dist[0][0],{0,0}});

        while(!q1.empty())
        {
            int dis=q1.top().first;
            int x=q1.top().second.first;
            int y=q1.top().second.second;
            q1.pop();

            if(dis>dist[x][y])continue;

            for(int z=0;z<4;z++)
            {
                int nx=x+dx[z];
                int ny=y+dy[z];

                if(nx>=0 && ny>=0 && nx<n && ny<n && dist[nx][ny]>max(dis,a[nx][ny]))
                {
                    dist[nx][ny]=max(dis,a[nx][ny]);
                    q1.push({dist[nx][ny],{nx,ny}});
                }
            }


        }
        return dist[n-1][n-1];
    }
};
