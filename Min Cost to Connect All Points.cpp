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


class Solution {
public:

    int minCostConnectPoints(vector<vector<int>>& arr) 
    {
        int n=arr.size();
        dsu d1(n);
        vector<pair<int,pair<int,int>>> v1;

        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int s=abs(arr[i][0]-arr[j][0])+abs(arr[i][1]-arr[j][1]);
                v1.push_back({s,{i,j}});
            }
        }
        sort(v1.begin(),v1.end());
        int cost=0;
        int connects=1;

        for(auto x: v1)
        {
            int a=x.first;
            int xx=x.second.first;
            int yy=x.second.second;
            
            if(d1.find_set(xx)!=d1.find_set(yy))
            {
                d1.union_set(xx,yy);
                cost+=a;
                connects++;

                if(connects==n)
                {
                    break;
                }
            }

        }
        return cost;
    }
};
