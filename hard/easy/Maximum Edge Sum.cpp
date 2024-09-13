class Solution {
  public:

    class dsu
    {
    public:
        int *parent;
        int *sz;
        int k;
    
        dsu(int x)
        {
            k=x;
            parent=new int[k];
            sz=new int[k];
            for(int i=0;i<k;i++)
            {
                parent[i]=i;
                sz[i]=1;
            }
        }
    
        int find_set(int x)
        {
            if(x==parent[x])
            {
                return x;
            }
            parent[x]=find_set(parent[x]);
            return parent[x];
        }
    
        long long union_set(int a,int b)
        {
            a=find_set(a);
            b=find_set(b);
            if(a==b)
            {
                return 0;
            }
            long long pro=sz[a]*sz[b];
            if(sz[a]>sz[b])
            {
                parent[b]=a;
                sz[a]=sz[a]+sz[b];
            }
            else
            {
                parent[a]=b;
                sz[b]=sz[b]+sz[a];
            }
            return pro;
        }
    };



    long long maxEdgeSum(int n, vector<vector<int>> &edges) {
        sort(edges.begin(), edges.end(), [](const vector<int> &a, const vector<int> &b) {
        return a[2] < b[2];
        });
        
        dsu d1(n);
        long long ans=0;
        for(auto x:edges)
        {
            long long u=x[0],v=x[1],w=x[2];
            u--;
            v--;
            long long pro=d1.union_set(u,v);
            ans+=pro*w;
        }
        return ans;
    }
};
