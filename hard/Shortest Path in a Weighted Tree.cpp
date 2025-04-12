#define ll long long
class Solution {
public:


void build(int node,int i,int j,vector<ll>&a,vector<ll>&tree)
{
    if(i==j)
    {
        tree[node]=a[i];
        return;
    }
    ll mid=(i+j)/2;
    build(2*node+2,mid+1,j,a,tree);
    build(2*node+1,i,mid,a,tree);
    tree[node]=tree[2*node+2]+tree[2*node+1];
}

int query(int node,int i,int j,vector<ll>&tree,int l,int r)
{
    if(i>r || j<l)
    {
        return 0;
    }

    if(l<=i && j<=r)
    {
        return tree[node];
    }
    ll mid=(i+j)/2;
    return query(2*node+1,i,mid,tree,l,r)+query(2*node+2,mid+1,j,tree,l,r);
}

void update(int node,int i,int j,vector<ll>&a,vector<ll>&tree,int in,ll val)
{
    if(i==j)
    {
        a[i]=val;
        tree[node]=val;
        return;
    }

    ll mid=(i+j)/2;
    if(in<=mid)
    {
        update(2*node+1,i,mid,a,tree,in,val);
    }
    else
    {
        update(2*node+2,mid+1,j,a,tree,in,val);
    }
    tree[node]=tree[2*node+1]+tree[2*node+2];
}


    vector<ll>v1,v2;
    map<pair<int,int>,int>m;
    map<int,int>vin;
    void dfs(int in,int par,vector<vector<vector<int>>>&adj)
    {
        for(auto x:adj[in])
        {
            if(x[0]!=par)
            {
                m[{in,x[0]}]=v1.size();
                vin[x[0]]=v1.size();
                v1.push_back(x[0]);
                v2.push_back(x[1]);
                dfs(x[0],in,adj);
                m[{x[0],in}]=v1.size();
                v1.push_back(x[0]);
                v2.push_back(-x[1]);
            }
        }
    }

    vector<int> treeQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) 
    {
        vector<vector<vector<int>>>adj(n);
        for(auto x:edges)
        {
            x[0]--;
            x[1]--;
            adj[x[0]].push_back({x[1],x[2]});
            adj[x[1]].push_back({x[0],x[2]});
        }
        v1.push_back(0);
        v2.push_back(0);
        dfs(0,-1,adj);

        int sz=v1.size();
        vector<ll>tree(4*sz);
        build(0,0,sz-1,v2,tree);
        vector<int>ans;

        for(auto x:queries)
        {
            if(x[0]==1)
            {
                int u=x[1]-1;
                int v=x[2]-1;
                int w=x[3];
                int i1=m[{u,v}];
                int i2=m[{v,u}];

                if(v2[i1]<0)
                {
                    update(0,0,sz-1,v2,tree,i1,-w);
                    update(0,0,sz-1,v2,tree,i2,w);
                }
                else
                {
                    update(0,0,sz-1,v2,tree,i2,-w);
                    update(0,0,sz-1,v2,tree,i1,w);
                }
            }
            else
            {
                int in=x[1]-1;
                if(in==0)ans.push_back(0);
                else
                {
                    int res=query(0,0,sz-1,tree,0,vin[in]);
                    ans.push_back(res);
                }
            }
        }


        return ans;
    }
};
