class Solution {
public:

    int m,n;
    bool isvalid(int i,int j)
    {
        if(i<0 || j<0 || i>=m || j>=n)
        {
            return 0;
        }
        return 1;
    }

    int minimumEffortPath(vector<vector<int>>& arr) 
    {
        m=arr.size();
        n=arr[0].size();
        vector<vector<int>>dist(m,vector<int>(n,INT_MAX));
        dist[0][0]=0;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>q1;
        q1.push({0,0,0});
        vector<int>dx={0,0,-1,1};
        vector<int>dy={1,-1,0,0};
        while(!q1.empty())
        {
            int e=q1.top()[0];
            int i=q1.top()[1];
            int j=q1.top()[2];
            q1.pop();
            if(i==m-1 && j==n-1)
            {
                return e;
            }

            for(int k=0;k<4;k++)
            {
                int nx=i+dx[k];
                int ny=j+dy[k];
                if(isvalid(nx,ny))
                {
                    int ne=max(e,abs(arr[i][j]-arr[nx][ny]));
                    if(dist[nx][ny]>ne)
                    {
                        dist[nx][ny]=ne;
                        q1.push({ne,nx,ny});
                    }
                }
            }
        }
        return -1;
    }
};
