class Solution {
public:
    int m,n;
    bool isvalid(int i, int j) {
        return i >= 0 && j >= 0 && i < m && j < n;
    }

    int minCost(vector<vector<int>>& arr) 
    {
        m=arr.size();
        n=arr[0].size();
        vector<vector<int>>dist(m,vector<int>(n,INT_MAX));
        dist[0][0]=0;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> q1;
        q1.push({0,0,0});
        vector<int> dx={0,0,1,-1};
        vector<int> dy={1,-1,0,0};
        while(!q1.empty())
        {
            int c=q1.top()[0];
            int i=q1.top()[1];
            int j=q1.top()[2];
            q1.pop();
            for(int k=0;k<4;k++)
            {
                int nx=i+dx[k];
                int ny=j+dy[k];
                if(isvalid(nx,ny))
                {
                    if(k+1==arr[i][j])
                    {
                        if(dist[nx][ny]>c)
                        {
                            dist[nx][ny]=c;
                            q1.push({c,nx,ny});
                        }
                    }
                    else
                    {
                        if(dist[nx][ny]>c+1)
                        {
                            dist[nx][ny]=c+1;
                            q1.push({c+1,nx,ny});
                        }
                    }
                }
            }
            
        }
        return dist[m-1][n-1];
        
    }
};
