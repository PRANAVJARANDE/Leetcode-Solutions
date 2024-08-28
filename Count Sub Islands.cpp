class Solution {
public:
    int n,m;
    vector<int> dx={1,0,-1,0};
    vector<int> dy={0,1,0,-1};

    int countSubIslands(vector<vector<int>>& a, vector<vector<int>>& b) {
        n=a.size();
        m=a[0].size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(b[i][j]==1)
                {
                    bool res=1;
                    queue<pair<int,int>> q1;
                    q1.push({i,j});
                    b[i][j]=0;
                    while(!q1.empty())
                    {
                        int x=q1.front().first;
                        int y=q1.front().second;
                        q1.pop();
                        if(a[x][y]==0)res=0;

                        for(int z=0;z<4;z++)
                        {
                            int nx=x+dx[z];
                            int ny=y+dy[z];
                            if(nx>=0 && ny>=0 && nx<n && ny<m && b[nx][ny]==1)
                            {
                                b[nx][ny]=0;
                                q1.push({nx,ny});
                            }
                        }
                    }
                    if(res)ans++;
                }
            }
        }
        return ans;
    }
};
