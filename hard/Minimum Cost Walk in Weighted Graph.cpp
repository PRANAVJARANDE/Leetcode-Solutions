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
    
     
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) 
    {
        dsu d1(n);
        vector<vector<vector<int>>> adj(n);
        vector<int> ans(n,pow(2,31)-1);
        for(auto x: edges)
        {
            d1.union_set(x[0],x[1]);
            ans[x[1]]=ans[x[1]] & x[2];
            ans[x[0]]=ans[x[0]] & x[2];
        }
        
        
        for(int i=0;i<n;i++)
        {
            int pa=d1.find_set(i);
            ans[pa]=ans[pa] & ans[i];
        }
        
        vector<int> res;
        for(auto x: query)
        {
            if(x[0]==x[1])res.push_back(0);
            else if(d1.find_set(x[1])!=d1.find_set(x[0]))res.push_back(-1);
            else
            {
                int pa=d1.find_set(x[0]);
                res.push_back(ans[pa]);
            }
        }
        return res;
        
    }
};
