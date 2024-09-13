class Solution {
public:

    int findCheapestPrice(int n, vector<vector<int>>& fli, int a, int b, int k) 
    {
        vector<int> dist(n,INT_MAX);
        dist[a]=0;
        for(int i=0;i<=k;i++)
        {
            vector<int> temp=dist;
            for(auto f:fli)
            {
                if(dist[f[0]]!=INT_MAX)
                {
                    temp[f[1]]=min(temp[f[1]],dist[f[0]]+f[2]);
                }
            }
            dist=temp;
        }
        if(dist[b]==INT_MAX)
        {
            return -1;
        }
        return dist[b];
    }
};
