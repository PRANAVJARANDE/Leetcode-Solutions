class Solution {
public:

    bool isvalid(int i,int j,int m,int n)
    {
        if(i<0 || j<0 || i>=m || j>=n)
            return 0;
        return 1;
    }
    vector<int>dx={1,-1,0,0};
    vector<int>dy={0,0,1,-1};

    vector<vector<int>> updateMatrix(vector<vector<int>>& arr) 
    {
        int m=arr.size();
        int n=arr[0].size();
        vector<vector<int>> ans(m,vector<int>(n,-1));
        queue<pair<int,int>> q1;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(arr[i][j]==0)
                {
                    ans[i][j]=0;
                    q1.push({i,j});
                }
            }
        }
        while(!q1.empty())
        {
            pair<int,int> temp=q1.front();
            q1.pop();
            for(int k=0;k<4;k++)
            {
                int nx=temp.first+dx[k];
                int ny=temp.second+dy[k];

                if(isvalid(nx,ny,m,n) && ans[nx][ny]==-1)
                {
                    ans[nx][ny]=1+ans[temp.first][temp.second];
                    q1.push({nx,ny});
                }
            }
        }
        return ans;
    }
};
