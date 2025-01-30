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

    int helper(int s,vector<vector<int>>&adj,int n)
    {
        queue<int>q1;
        q1.push(s);
        vector<int>vis(n,0);
        vis[s]=1;

        int cnt=0;
        while(!q1.empty())
        {
            int sz=q1.size();
            vector<int>v1;
            while(sz--)
            {
                int in=q1.front();
                q1.pop();

                for(int i=0;i<n;i++)
                {
                    if(adj[in][i]==1 && vis[i]==0)
                    {
                        vis[i]=1;
                        v1.push_back(i);
                    }
                }
            }
            for(int j=0;j<v1.size();j++)
            {
                for(int i=j+1;i<v1.size();i++)
                {
                    if(adj[v1[i]][v1[j]]==1)return -1;
                }
            }
            for(auto x:v1)
            {
                q1.push(x);
            }
            cnt++;
        }

        return cnt;
    }

    int magnificentSets(int n, vector<vector<int>>& e) {
        vector<vector<int>>adj(n,vector<int>(n,0));
        dsu d1(n);
        for(auto x:e)
        {
            x[0]--;
            x[1]--;
            d1.union_set(x[0],x[1]);
            adj[x[0]][x[1]]=1;
            adj[x[1]][x[0]]=1;
        }

        map<int,vector<int>>m;
        for(int i=0;i<n;i++)
        {
            m[d1.find_set(i)].push_back(i);
        }

        int ans=0;
        for(auto x:m)
        {
            int ta=0;
            for(auto y:x.second)
            {
                int res=helper(y,adj,n);
                if(res==-1)return -1;
                ta=max(ta,res);
            }
            ans+=ta;
        }
        return ans;
    }
};
