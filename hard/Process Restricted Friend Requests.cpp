class Solution {
public:

    class dsu 
    {
        public:
        vector<int>sz;
        vector<int>par;

        dsu(int n)
        {
            sz=vector<int>(n,1);
            par=vector<int>(n,0);
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
                sz[a]+=sz[b];
                par[b]=a;
            }
            else
            {
                sz[b]+=sz[a];
                par[a]=b;
            }
        }
    };

    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& req) 
    {
        dsu d1(n);
        vector<bool>ans;
        for(auto x:req)
        {
            int u=d1.find_set(x[0]);
            int v=d1.find_set(x[1]);
            if(u==v)ans.push_back(1);
            else
            {
                bool flag=1;
                for(auto z:restrictions)
                {
                    int i=z[0],j=z[1];
                    if(d1.find_set(i)==u && d1.find_set(j)==v)
                    {
                        flag=0;
                        break;
                    }
                    if(d1.find_set(j)==u && d1.find_set(i)==v)
                    {
                        flag=0;
                        break;
                    }
                }
                ans.push_back(flag);
            }
            if(ans.back()==1)
            {
                d1.union_set(u,v);
            }
        }
        return ans;
    }
};
