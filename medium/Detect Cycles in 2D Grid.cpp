class Solution {
public:
    int n,m;
    bool issafe(int i,int j)
    {
        if(i<0 || j<0 || i>=n || j>=m)return 0;
        return 1;
    }

    vector<int>dx{-1,1,0,0};
    vector<int>dy{0,0,-1,1};

    bool dfs(int i,int j,int pxin,vector<vector<int>>&vis,vector<vector<char>>&a,vector<vector<int>>&fvis)
    {
        fvis[i][j]=1;
        for(int z=0;z<4;z++)
        {
            int nx=i+dx[z];
            int ny=j+dy[z];
            if(issafe(nx,ny) && a[nx][ny]==a[i][j] && pxin!=(nx*n+ny))
            {
                if(vis[nx][ny]==0)
                {   
                    vis[nx][ny]=1;
                    bool b=dfs(nx,ny,i*n+j,vis,a,fvis);
                    if(b==1)return 1;
                    vis[nx][ny]=0;
                }
                else
                {
                    return 1;
                }   
            }
        }
        return 0;
    }

    bool containsCycle(vector<vector<char>>& a) 
    {
        n=a.size();
        m=a[0].size();
        vector<vector<int>>fvis(n,vector<int>(m,0));
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(fvis[i][j]==0)
                {
                    vis[i][j]=1;
                    if(dfs(i,j,-1,vis,a,fvis))
                    {
                        return 1;
                    }
                    vis[i][j]=0;
                }
            }
        }
        return 0;
    }
};
