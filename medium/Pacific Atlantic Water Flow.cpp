class Solution {
public:

    vector<int>dx{-1,1,0,0};
    vector<int>dy{0,0,1,-1};
    int n,m;
    bool issafe(int x,int y)
    {
        if(x<0 || y<0 || x>=n || y>=m)return 0;
        return 1;
    }

    void helper(queue<pair<int,int>>&q1,vector<vector<int>>& a,vector<vector<int>>& vis1)
    {
        while(!q1.empty())
        {
            int x=q1.front().first;
            int y=q1.front().second;
            q1.pop();

            for(int z=0;z<4;z++)
            {
                int nx=dx[z]+x;
                int ny=dy[z]+y;
                if(issafe(nx,ny) && vis1[nx][ny]==0 && a[x][y]<=a[nx][ny])
                {
                    vis1[nx][ny]=1;
                    q1.push({nx,ny});
                }
            }
        }
    }


    vector<vector<int>> pacificAtlantic(vector<vector<int>>& a) 
    {
        n=a.size();
        m=a[0].size();
        vector<vector<int>>vis1(n,vector<int>(m,0)),vis2(n,vector<int>(m,0));
        queue<pair<int,int>>q1,q2;
        for(int i=0;i<n;i++)
        {
            vis1[i][0]=1;
            vis2[i][m-1]=1;
            q1.push({i,0});
            q2.push({i,m-1});
        }
        for(int i=0;i<m;i++)
        {
            vis1[0][i]=1;
            vis2[n-1][i]=1;
            q1.push({0,i});
            q2.push({n-1,i});
        }

        
        helper(q1,a,vis1);
        helper(q2,a,vis2);

        
        vector<vector<int>>ans;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                if(vis1[i][j]==1 && vis2[i][j]==1)ans.push_back({i,j});
        }
        return ans;
        
    }
};
