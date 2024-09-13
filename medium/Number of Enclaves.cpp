class Solution {
public:

    int n,m;
    bool issafe(int i,int j)
    {
        if(i>=0 && j>=0 && i<n && j<m)return 1;
        return 0;
    }
    vector<int> dx={1,-1,0,0};
    vector<int> dy={0,0,-1,1};

    void f1(int i,int j,vector<vector<int>>& arr)
    {
        arr[i][j]=0;
        queue<pair<int,int>> q1;
        q1.push({i,j});
        while(!q1.empty())
        {
            int x=q1.front().first;
            int y=q1.front().second;
            q1.pop();
            for(int z=0;z<4;z++)
            {
                int nx=x+dx[z];
                int ny=y+dy[z];
                if(issafe(nx,ny) && arr[nx][ny]==1)
                {
                    arr[nx][ny]=0;
                    q1.push({nx,ny});
                }
            }
        }
    }

    int numEnclaves(vector<vector<int>>& arr) 
    {
        n=arr.size();
        m=arr[0].size();
        for(int i=0;i<m;i++)
        {
            if(arr[0][i]==1) f1(0,i,arr);
            if(arr[n-1][i]==1)f1(n-1,i,arr);
        }

        for(int i=0;i<n;i++)
        {
            if(arr[i][0]==1) f1(i,0,arr);
            if(arr[i][m-1]==1) f1(i,m-1,arr);
        }
        
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(arr[i][j]==1)ans++;
            }
        }
        return ans;
    }
};
