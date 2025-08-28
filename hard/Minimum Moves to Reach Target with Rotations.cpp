class Solution {
public:

    int n;
    bool issafe(int i,int j)
    {
        return i>=0 && j>=0 && i<n && j<n;
    }

    int minimumMoves(vector<vector<int>>& a) 
    {
        n=a.size();
        
        vector<vector<vector<int>>>vis(n,vector<vector<int>>(n,vector<int>(2,0)));
        vis[0][0][0]=1;
        queue<pair<pair<int,int>,int>>q1;
        q1.push({{0,0},0});

        int cans=1;
        while(!q1.empty())
        {
            int sz=q1.size();
            while(sz--)
            {
                int i=q1.front().first.first;
                int j=q1.front().first.second;
                int dir=q1.front().second;
                q1.pop();

                if(i==n-1 && j==n-2 && dir==0)return cans-1;

                if(dir==0)
                {   
                    if(issafe(i,j+2) && a[i][j+1]==0 && a[i][j+2]==0)
                    {
                        if(vis[i][j+1][0]==0)
                        {
                            vis[i][j+1][0]=1;
                            q1.push({{i,j+1},0});
                        }
                    }
                    if(issafe(i+1,j) && issafe(i+1,j+1) && a[i+1][j]==0 && a[i+1][j+1]==0)
                    {
                        if(vis[i+1][j][0]==0)
                        {
                            vis[i+1][j][0]=1;
                            q1.push({{i+1,j},0});
                        }
                        if(vis[i][j][1]==0)
                        {
                            vis[i][j][1]=1;
                            q1.push({{i,j},1});
                        }
                    }

                }
                else
                {
                    if(issafe(i+2,j) && a[i+1][j]==0 && a[i+2][j]==0)
                    {
                        if(vis[i+1][j][1]==0)
                        {
                            vis[i+1][j][1]=1;
                            q1.push({{i+1,j},1});
                        }
                    }
                    if(issafe(i,j+1) && issafe(i+1,j+1) && a[i][j+1]==0 && a[i+1][j+1]==0)
                    {
                        if(vis[i][j+1][1]==0)
                        {
                            vis[i][j+1][1]=1;
                            q1.push({{i,j+1},1});
                        }
                        if(vis[i][j][0]==0)
                        {
                            vis[i][j][0]=1;
                            q1.push({{i,j},0});
                        }
                    }
                }
            }
            cans++;
        }
        return -1;
    }
};

