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

    int regionsBySlashes(vector<string>& a) {
        int n=a.size();
        int ans=0;
        int pt=n+1;
        int totalpts=pt*pt;
        dsu d1(totalpts);

        for (int i = 0; i < pt; i++) {
            d1.union_set(0, i); 
            d1.union_set(0, i * pt); 
            d1.union_set(0, (pt - 1) * pt + i); 
            d1.union_set(0, i * pt + (pt - 1)); 
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(a[i][j]=='/')
                {
                    int p1=(i+1)*pt + j;
                    int p2=i*pt + j+1;
                    if(d1.find_set(p1)==d1.find_set(p2))
                    {
                        ans++;
                    }
                    else
                    {
                        d1.union_set(p1,p2);
                    }
                }
                else if(a[i][j]=='\\')
                {
                    int p1=i*pt + j;
                    int p2=(i+1)*pt + j+1;
                    if(d1.find_set(p1)==d1.find_set(p2))
                    {
                        ans++;
                    }
                    else
                    {
                        d1.union_set(p1,p2);
                    }
                }
                
            }
        }

        return ans+1;
    }
};
