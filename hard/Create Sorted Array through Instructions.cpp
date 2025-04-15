#define ll long long
class Solution {
public:

    ll query(int node,int i,int j,vector<ll>&tree,int l,int r)
    {
        if(i>r || j<l)return 0;
        if(l<=i && j<=r)return tree[node];
        ll mid=(i+j)/2;
        return query(2*node+1,i,mid,tree,l,r)+query(2*node+2,mid+1,j,tree,l,r);
    }

    void update(int node,int i,int j,vector<ll>&tree,int in)
    {
        if(i==j)
        {
            tree[node]++;
            return;
        }

        ll mid=(i+j)/2;
        if(in<=mid)update(2*node+1,i,mid,tree,in);
        else update(2*node+2,mid+1,j,tree,in);
        tree[node]=tree[2*node+1]+tree[2*node+2];
    }

    int MOD=1E9 + 7;
    int createSortedArray(vector<int>& a) 
    {
        int sz=1e5+2; 
        vector<ll>tree(4*sz,0);
        ll ans=0;
        for(auto x:a)
        {
            ll res1=query(0,0,sz-1,tree,0,x-1);
            ll res2=query(0,0,sz-1,tree,x+1,sz-1);
            ans=((ans%MOD)+(min(res1,res2)%MOD))%MOD;
            update(0,0,sz-1,tree,x);
        }
        return ans;
    }
};
