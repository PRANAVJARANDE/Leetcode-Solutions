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

class Solution 
{
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) 
    {
        int n=edges.size();
        vector<int> indeg(n,0);
        bool b=0;
        int h=-1;
        for(auto x: edges)
        {
            indeg[x[1]-1]++;
            if(indeg[x[1]-1]==2)
            {
                b=1;
                h=x[1];
                break;
            }
        }

        dsu d1(n);
        vector<vector<int>> e;
        vector<int> ans;

        if(b==0)
        {
            //dsu from start point edge
            for(int i=0;i<n;i++)
            {
                if(d1.find_set(edges[i][0]-1)!=d1.find_set(edges[i][1]-1))
                    {
                        d1.union_set(edges[i][0]-1,edges[i][1]-1);
                    }
                    else
                    {
                        ans.push_back(edges[i][0]);
                        ans.push_back(edges[i][1]);
                        return ans;
                    }
            }
        }
        else
        {
            for(int i=n-1;i>=0;i--)
            {
                if(edges[i][1]!=h)
                {
                    //dsu include
                    if(d1.find_set(edges[i][0]-1)!=d1.find_set(edges[i][1]-1))
                    {
                        d1.union_set(edges[i][0]-1,edges[i][1]-1);
                    }
                }
                else
                {
                    e.push_back({edges[i][0],edges[i][1]});
                }
            }

            d1.union_set(e[1][1]-1,e[1][0]-1);
            if(d1.find_set(e[0][0]-1)==d1.find_set(e[0][1]-1))
            {
                return e[0];
            }
            else
            {
                return e[1];
            }
        }
        return ans;
    }
};
