//CORRECT BUT TLE
class Solution {
public:

    vector<int>dx{1,-1,0,0};
    vector<int>dy{0,0,1,-1};


    bool issafe(int i,int j,int m,int n)
    {
        return i>=0 && j>=0 && i<m && j<n;
    }

    int minCost(vector<int>& sp, vector<int>& hp, vector<int>& rc, vector<int>& cc) {
        int sx=sp[0],sy=sp[1],hx=hp[0],hy=hp[1];
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> q1;
        int m=rc.size(),n=cc.size();
        vector<vector<int>>dist(m,vector<int>(n,INT_MAX));
        dist[sx][sy]=0;
        q1.push({0,sx,sy});

        while(!q1.empty())
        {
            int d=q1.top()[0];
            int i=q1.top()[1];
            int j=q1.top()[2];
            q1.pop();

            if(i==hx && j==hy)
            {
                return d;
            }

            for(int k=0;k<4;k++)
            {
                int nx=i+dx[k];
                int ny=j+dy[k];

                if(issafe(nx,ny,m,n) && dist[nx][ny]>d+rc[nx]*abs(dx[k])+cc[ny]*abs(dy[k]))
                {
                    dist[nx][ny]=d+ rc[nx]*abs(dx[k]) + cc[ny]*abs(dy[k]);
                    q1.push({dist[nx][ny],nx,ny});
                }
            }
        }
        return -1;

    }
};

//RIGHT METHOD
class Solution {
public:
    int minCost(vector<int>& sp, vector<int>& hp, vector<int>& r, vector<int>& c) 
    {
        int sx=sp[0],sy=sp[1],hx=hp[0],hy=hp[1];
        int ans=0;
        while(sx<hx)
        {
            sx++;
            ans+=r[sx];
        }
        while(sy<hy)
        {
            sy++;
            ans+=c[sy];
        }
        while(hx<sx)
        {
            sx--;
            ans+=r[sx];
        }
        while(hy<sy)
        {
            sy--;
            ans+=c[sy];
        }
        return ans;
    }
};
