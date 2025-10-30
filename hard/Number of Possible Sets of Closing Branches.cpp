class Solution {
public:
    int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) 
    {
        int ans=0;
        for(int mask=0;mask<(1<<n);mask++)
        {
            vector<vector<int>>dis(n,vector<int>(n,INT_MAX));
            for(int i=0;i<n;i++)dis[i][i]=0;
            for(auto x:roads)
            {
                int u=x[0],v=x[1],w=x[2];
                if((mask & (1<<u)) && (mask & (1<<v)))
                {
                    dis[u][v]=min(dis[u][v],w);
                    dis[v][u]=min(dis[v][u],w);
                }
            }

            for(int i=0;i<n;i++)
            {
                if(!(mask & (1<<i)))continue;
                for(int j=0;j<n;j++)
                {
                    if(!(mask & (1<<j)))continue;
                    for(int k=0;k<n;k++)
                    {
                        if(!(mask & (1<<k)))continue;
                        if(dis[i][k]!=INT_MAX && dis[k][j]!=INT_MAX)
                        {
                            dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
                            dis[j][i]=min(dis[j][i],dis[i][k]+dis[k][j]);
                        }
                    }
                }
            }

            bool flag=1;
            for(int i=0;i<n;i++)
            {
                if(!(mask & (1<<i)))continue;
                for(int j=0;j<n;j++)
                {
                    if(!(mask & (1<<j)))continue;
                    if(dis[i][j]>maxDistance)
                    {
                        flag=0;
                        break;
                    }
                }
                if(flag==0)break;
            }
            if(flag)ans++;
        }
        return ans;
    }
};
