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
                par[b]=par[a];
                sz[a]+=sz[b];
            }
            else
            {
                par[a]=par[b];
                sz[b]+=sz[a];
            }
        }

    };


    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) 
    {
        int n=vals.size();
        map<int,vector<int>>m;
        for(int i=0;i<n;i++)m[vals[i]].push_back(i);
        vector<vector<int>>adj(n);
        for(auto x:edges)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        dsu d1(n);
        int ans=0;
        for(auto z:m)
        {
            for(auto in:z.second)
            {
                for(auto x:adj[in])
                {
                    if(vals[x]<=vals[in])
                    {
                        d1.union_set(x,in);
                    }
                }
            }
            map<int,int>cnt;
            for(auto in:z.second)
            {
                ans+=cnt[d1.find_set(in)];
                cnt[d1.find_set(in)]++;
            }
        }
        return ans+n;
    }
};
