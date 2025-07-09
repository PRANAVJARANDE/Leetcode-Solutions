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

    void union_set(int a,int b)
    {
        a=find_set(a);
        b=find_set(b);
        if(a==b)
        {
            return;
        }

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
    }
};

    int maxStability(int n, vector<vector<int>>& edges, int k) 
    {
        vector<int>vis(n,0);
        int ans=INT_MAX;
        dsu d1(n);
        vector<vector<int>>v1;
        for(auto x:edges)
        {
            int must=x[3];
            int u=x[0];
            int v=x[1];
            int s=x[2];
            if(must)
            {
                if(d1.find_set(u)==d1.find_set(v))return -1;
                d1.union_set(u,v);
                ans=min(ans,s);
            }
            else
            {
                v1.push_back({s,u,v});
            }
        }
        sort(v1.begin(),v1.end(),greater<vector<int>>());
        vector<int>to_add;
        for(auto x:v1)
        {
            if(d1.find_set(x[1])==d1.find_set(x[2]))continue;
            d1.union_set(x[1],x[2]);
            to_add.push_back(x[0]);
        }
        sort(to_add.begin(),to_add.end());
        int pr=d1.find_set(0);
        for(int i=1;i<n;i++)
        {
            if(d1.find_set(i)!=pr)return -1;
        }

        for(auto &x:to_add)
        {
            if(k>0)
            {
                k--;
                x*=2;
            }
            ans=min(ans,x);
        }
        return ans;   
    }
};
