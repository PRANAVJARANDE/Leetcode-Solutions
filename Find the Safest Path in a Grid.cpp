class Solution {
public:
        int n;

    bool isvalid(int i ,int j,int n)
    {
        if(i>=0 && j>=0 && i<n && j<n)
        {
            return 1;
        }
        return 0;
    }

    bool checker(vector<vector<int>>&dist,vector<vector<int>>&vis,int i,int j,int tar)
    {
        if(i>=n || j>=n || i<0 || j<0)
        {
            return 0;
        }
        
        if(dist[i][j]<tar)
        {
            return 0;
        }
        if(i==n-1 && j==n-1)
        {
            return 1;
        }
        vis[i][j]=1;
        
        if(isvalid(i+1,j,n) && vis[i+1][j]==0 && checker(dist,vis,i+1,j,tar))
        {
            return 1;
        }
        if(isvalid(i,j+1,n) && vis[i][j+1]==0 && checker(dist,vis,i,j+1,tar))
        {
            return 1;
        }
        if(isvalid(i-1,j,n) && vis[i-1][j]==0 && checker(dist,vis,i-1,j,tar))
        {
            return 1;
        }
        if(isvalid(i,j-1,n) && vis[i][j-1]==0 && checker(dist,vis,i,j-1,tar))
        {
            return 1;
        }
        return 0;
    
    }
         
    int maximumSafenessFactor(vector<vector<int>>& arr) 
    {
            n=arr.size();
            if(arr[0][0]==1 || arr[n-1][n-1]==1)
            {
                return 0;
            }

            vector<vector<int>>vis1(n,vector<int>(n,0));
            vector<vector<int>>dist(n,vector<int>(n,0));
            queue<pair<int,int>>q1;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(arr[i][j]==1)
                    {
                        q1.push({i,j});
                        dist[i][j]=0;
                        vis1[i][j]=1;
                    }
                }
            }

            //calculate distance in grid
            while(!q1.empty())
            {
                int i=q1.front().first;
                int j=q1.front().second;
                q1.pop();
                vector<int> dx{1,-1,0,0};
                vector<int> dy{0,0,1,-1};
                for(int k=0;k<4;k++)
                {
                    int nx=i+dx[k];
                    int ny=j+dy[k];
                    if(isvalid(nx,ny,n) && vis1[nx][ny]==0)
                    {
                        q1.push({nx,ny});
                        dist[nx][ny]=1+dist[i][j];
                        vis1[nx][ny]=1;
                    }
                }
            }


            int e=1000,s=0,ans=-1;
            while(s<=e)
            {
                int mid=(s+e)/2;
                vector<vector<int>> vis(n,vector<int> (n,0));
                bool b1=checker(dist,vis,0,0,mid);
                if(b1==0)
                {
                    e=mid-1;
                }
                else
                {
                    ans=mid;
                    s=mid+1;
                }
            }
            return ans;
            
    }
};
