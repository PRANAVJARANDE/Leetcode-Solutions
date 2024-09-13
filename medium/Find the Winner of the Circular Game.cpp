class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> vis(n,0);
        int kills=0;
        int in=0;
        while(kills<n-1)
        {
            int tj=k-1;
            while(tj!=0)
            {
                if(vis[in]==0)
                {
                    tj--;
                }
                in++;
                if(in==n)in=0;
            }
            while(vis[in])
            {
                in++;
                if(in==n)in=0;
            }
            vis[in]=1;
            in++;
            if(in==n)in=0;
            kills++;
        }
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)return i+1;
        }
        return n;
    }
};
