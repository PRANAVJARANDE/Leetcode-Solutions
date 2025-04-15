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
            tree[node]=1;
            return;
        }

        ll mid=(i+j)/2;
        if(in<=mid)
        {
            update(2*node+1,i,mid,tree,in);
        }
        else
        {
            update(2*node+2,mid+1,j,tree,in);
        }
        tree[node]=tree[2*node+1]+tree[2*node+2];
    }

    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) 
    {
        int n=nums1.size();
        vector<vector<int>>v1(n,vector<int>(2,0));
        for(int i=0;i<n;i++)
        {
            v1[nums1[i]][0]=i;
            v1[nums2[i]][1]=i;
        }
        vector<ll>tree(4*n,0);
        ll ans=0;
        for(int i=0;i<n;i++)
        {
            ll n2=v1[nums1[i]][1];
            ll pv=query(0,0,n-1,tree,0,n2);
            ll c1=i-pv;
            ll c2=n2-pv;
            ll nx=n-c1-c2-1-pv;
            ans+=pv*nx;
            update(0,0,n-1,tree,n2);
        }
        return ans;
    }
};
