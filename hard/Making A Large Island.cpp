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


    int largestIsland(vector<vector<int>>& a) {
        int n=a.size();
        dsu d1(n*n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(a[i][j]==1)
                {
                    if(i-1>=0 && a[i-1][j]==1)d1.union_set(i*n+j,(i-1)*n+j);
                    if(j-1>=0 && a[i][j-1]==1)d1.union_set(i*n+j,i*n+j-1);
                    if(i+1<n && a[i+1][j]==1)d1.union_set(i*n+j,(i+1)*n+j);
                    if(j+1<n && a[i][j+1]==1)d1.union_set(i*n+j,i*n+j+1);
                }
            }
        }
        int ans=1;
        map<int,int>m;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                ans=max(ans,++m[d1.find_set(i*n+j)]);
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(a[i][j]==0)
                {
                    int res=1;
                    set<int>s1;
                    if(i-1>=0 && a[i-1][j]==1)s1.insert(d1.find_set((i-1)*n+j));
                    if(j-1>=0 && a[i][j-1]==1)s1.insert(d1.find_set(i*n+j-1));
                    if(i+1<n && a[i+1][j]==1)s1.insert(d1.find_set((i+1)*n+j));
                    if(j+1<n && a[i][j+1]==1)s1.insert(d1.find_set(i*n+j+1));
                    for(auto x:s1)
                    {
                        res+=m[x];
                    }
                    ans=max(ans,res);
                }
            }
        }
        return ans;
    }
};
