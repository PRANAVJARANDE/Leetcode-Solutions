class Solution {
public:

    class dsu
    {
        public:
        vector<int>par;
        vector<int>sz;
        dsu(int n)
        {
            par=vector<int>(n,0);
            sz=vector<int>(n,1);
            for(int i=0;i<n;i++)par[i]=i;
        }

        int find_set(int a)
        {
            if(par[a]==a)return a;
            return par[a]=find_set(par[a]);
        }

        void union_set(int a,int b)
        {
            a=find_set(a);
            b=find_set(b);
            if(a==b)return;
            if(sz[a]>sz[b])
            {
                par[b]=a;
                sz[a]+=sz[b];
            }
            else
            {
                par[a]=b;
                sz[b]+=sz[a];
            }
        }

    };

    vector<bool> areConnected(int n, int th, vector<vector<int>>& q) 
    {
        dsu d1(n+1);
        vector<int>vis(n+1,0);
        for(int i=th+1;i<=n;i++)
        {
            if(vis[i]==0)
            {
                for(int j=i;j<=n;j+=i)
                {
                    vis[j]=1;
                    d1.union_set(i,j);
                }
            }
        }   
        vector<bool>ans; 
        for(auto x:q)
        {
            if(d1.find_set(x[0])==d1.find_set(x[1]))ans.push_back(1);
            else ans.push_back(0);
        }
        return ans;
    }
};
