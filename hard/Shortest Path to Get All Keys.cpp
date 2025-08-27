class Solution {
public:

    int n,m;
    vector<int>dx{-1,1,0,0};
    vector<int>dy{0,0,-1,1};
    bool issafe(int i,int j)
    {
        if(i<0 || j<0 || i>=n || j>=m)return 0;
        return 1;
    }

    int shortestPathAllKeys(vector<string>& a)
    {
        n=a.size();
        m=a[0].size();

        int sx,sy;
        int k=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(a[i][j]=='@')
                {
                    sx=i;
                    sy=j;
                }
                if('a'<=a[i][j] && a[i][j]<='z')
                {
                    k++;
                }
            }
        }
        if(k==0)return 0;
        vector<vector<vector<int>>>vis(n,vector<vector<int>>(m,vector<int>((1<<k)+2,0)));
        
        queue<pair<pair<int,int>,int>>q1;
        q1.push({{sx,sy},0});
        vis[sx][sy][0]=1;

        int cans=1;
        while(!q1.empty())
        {
            int sz=q1.size();
            while(sz--)
            {
                int i=q1.front().first.first;
                int j=q1.front().first.second;
                int mask=q1.front().second;
                q1.pop();

                if(mask==((1<<k)-1))return cans-1;

                for(int z=0;z<4;z++)
                {
                    int nx=i+dx[z];
                    int ny=j+dy[z];

                    if(issafe(nx,ny) && a[nx][ny]!='#')
                    {
                        int nmask=mask;
                        if('a'<=a[nx][ny] && a[nx][ny]<='z')nmask=mask | (1<<(a[nx][ny]-'a'));
                        if(vis[nx][ny][nmask]==0)
                        {
                            if('A'<=a[nx][ny] && a[nx][ny]<='Z')
                            {
                                if(nmask & (1<<(a[nx][ny]-'A')))
                                {
                                    vis[nx][ny][mask]=1;
                                    q1.push({{nx,ny},nmask});
                                }
                            }
                            else
                            {
                                vis[nx][ny][nmask]=1;
                                q1.push({{nx,ny},nmask});
                            }
                        }
                    }
                }
            }
            cans++;
        }
        return -1;
    }
};
