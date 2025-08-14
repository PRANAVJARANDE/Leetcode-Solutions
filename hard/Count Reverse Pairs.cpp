class Solution {
  public:
    
    
    void update(int node,int i,int j,vector<int>&tree,int in,int val)
    {
        if(i==j)
        {
            tree[node]=val;
            return;
        }
        int mid=i+(j-i)/2;
        if(in<=mid)update(2*node+1,i,mid,tree,in,val);
        else update(2*node+2,mid+1,j,tree,in,val);
        tree[node]=tree[2*node+1]+tree[2*node+2];
    }
  
    int query(int node,int i,int j,vector<int>&tree,int l,int r)
    {
        if(j<l || r<i)return 0;
        if(l<=i && j<=r)return tree[node];
        int mid=i+(j-i)/2;
        return query(2*node+1,i,mid,tree,l,r)+query(2*node+2,mid+1,j,tree,l,r);
    }
  
  
    int countRevPairs(vector<int> &a) 
    {
        int n=a.size();
        vector<pair<int,int>>v1(n);
        for(int i=0;i<n;i++)v1[i]={a[i],i};
        sort(v1.begin(),v1.end());
        
        vector<int>tree(4*n);
        int ans=0;
        int r=n-1;
        for(int i=n-1;i>=0;i--)
        {
            int val=v1[i].first;
            int in=v1[i].second;
            int maxi=2*val;
            
            while(v1[r].first>maxi)
            {
                update(0,0,n-1,tree,v1[r].second,1);
                r--;
            }
            int to_add=query(0,0,n-1,tree,0,v1[i].second-1);
            ans+=to_add;
        }
        return ans;
    }
};
