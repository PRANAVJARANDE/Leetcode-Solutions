class Solution {
  public:
  
    int query(int node,int i,int j,vector<int>&tree,int l,int r)
    {
        if(r<i || j<l)return -1;
        if(l<=i && j<=r)return tree[node];
        
        int mid=i+(j-i)/2;
        return max(query(2*node+1,i,mid,tree,l,r),query(2*node+2,mid+1,j,tree,l,r));
    }
    
    void update(int node,int i,int j,vector<int>&tree,int in,int val)
    {
        if(i==j)
        {
            tree[node]=max(tree[node],val);
            return;
        }
        int mid=i+(j-i)/2;
        if(in<=mid)update(2*node+1,i,mid,tree,in,val);
        else update(2*node+2,mid+1,j,tree,in,val);
        tree[node]=max(tree[2*node+1],tree[2*node+2]);
    }
  
    vector<int> farMin(vector<int>& a) 
    {
        //segment tree -------
        int sz=1e6 + 5;
        vector<int>tree(4*sz,-1);
        int n=a.size();
        vector<int>ans(n,-1);
        
        for(int i=n-1;i>=0;i--)
        {
            int v=a[i];
            int res=query(0,0,sz-1,tree,0,v-1);
            ans[i]=res;
            update(0,0,sz-1,tree,v,i);
        }
        return ans;
    }          
};        
  
