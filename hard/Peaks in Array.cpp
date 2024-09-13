#define ll long long

class Solution 
{
public:   
    int n;
    ll query(int node, int i, int j, vector<ll>& tree, int l, int r) {
        if (i > r || j < l) {
            return 0;
        }
        if (l <= i && j <= r) {
            return tree[node];
        }
        int mid = (i + j) / 2;
        return query(2*node+1,i,mid,tree,l,r)+query(2*node+2,mid+1,j,tree,l,r);
    }

    void update(int node, int i, int j, vector<ll>& tree, int in, vector<int>&a){
        if (i == j) {
            if(i==0 || i==n-1)tree[node]=0;
            else 
            {
                if(a[i]>a[i+1] && a[i]>a[i-1])tree[node]=1;
                else tree[node]=0;
            }
            return;
        }
        int mid = (i + j) / 2;
        if (in <= mid) {
            update(2*node+1,i,mid,tree,in,a);
        } else {
            update(2*node+2,mid+1,j,tree,in,a);
        }
        tree[node]=tree[2*node+1]+tree[2*node+2];
    }

    vector<int> countOfPeaks(vector<int>& a, vector<vector<int>>& que) {
        n = a.size();
        vector<ll> tree(4*n,0);
        for(int i=1;i<n-1;i++)
        {
            if(a[i]>a[i+1] && a[i-1]<a[i])
            {
                update(0,0,n-1,tree,i,a);
            }
        }


        vector<int> ans;
        for (auto x : que) {
            if (x[0] == 1) {
                if(x[1]==x[2])ans.push_back(0);
                else
                {
                    int ta=query(0,0,n-1,tree,x[1],x[2]);
                    int l=x[1],r=x[2];
                    if(l-1>=0 && l+1<n && a[l]>a[l-1] && a[l]>a[l+1])ta--;
                    if(r-1>=0 && r+1<n && a[r]>a[r-1] && a[r]>a[r+1])ta--;
                    ans.push_back(ta);
                }
            } 
            else 
            {
                int in=x[1];
                int val=x[2];
                a[in]=val;
                update(0, 0, n - 1, tree, in, a);
                if(in!=0)update(0,0,n-1,tree,in-1,a);
                if(in!=n-1)update(0,0,n-1,tree,in+1,a);
            }
        }
        return ans;
    }
};
