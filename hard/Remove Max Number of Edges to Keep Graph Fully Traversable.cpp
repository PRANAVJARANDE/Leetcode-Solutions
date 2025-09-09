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
            if(a==par[a])return a;
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


    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) 
    {
        dsu d1(n);
        dsu d2(n);
        int ans=0;
        for(auto x:edges)
        {
            int t=x[0],u=x[1]-1,v=x[2]-1;
            if(t==3)
            {
                if(d1.find_set(u)==d1.find_set(v))ans++;
                else
                {
                    d1.union_set(u,v);
                    d2.union_set(u,v);
                }
            }
        }
        for(auto x:edges)
        {
            int t=x[0],u=x[1]-1,v=x[2]-1;
            if(t==1)
            {
                if(d1.find_set(u)==d1.find_set(v))ans++;
                else d1.union_set(u,v);
            }
            else if(t==2)
            {
                if(d2.find_set(u)==d2.find_set(v))ans++;
                else d2.union_set(u,v);
            }
        }
        for(int i=1;i<n;i++)
        {
            if(d1.find_set(i)!=d1.find_set(0))return -1;
            if(d2.find_set(i)!=d2.find_set(0))return -1;
        }
        return ans;
    }
};
