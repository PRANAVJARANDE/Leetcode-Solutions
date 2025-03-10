#define ll long long
class Solution {
public:
    
    void build(int node,int i,int j,vector<int>&a,vector<int>&tree)
    {
        if(i==j)
        {
            tree[node]=a[i];
            return;
        }
        int mid=(i+j)/2;
        build(2*node+2,mid+1,j,a,tree);
        build(2*node+1,i,mid,a,tree);
        tree[node]=max(tree[2*node+2],tree[2*node+1]);
    }

    int query(int node,int i,int j,vector<int>&tree,int val)
    {
        if(tree[node]<val)return -1;
        if(i==j)return i;
        int mid=(i+j)/2;
        int b1=query(2*node+1,i,mid,tree,val);
        if(b1!=-1)return b1;
        int b2=query(2*node+2,mid+1,j,tree,val);
        if(b2!=-1)return b2;
        return -1;
    }

    void update(int node,int i,int j,vector<int>&tree,int in)
    {
        if(i==j)
        {
            tree[node]=0;
            return;
        }

        int mid=(i+j)/2;
        if(in<=mid)
        {
            update(2*node+1,i,mid,tree,in);
        }
        else
        {
            update(2*node+2,mid+1,j,tree,in);
        }
        tree[node]=max(tree[2*node+1],tree[2*node+2]);
    }
    
    int numOfUnplacedFruits(vector<int>& a, vector<int>& b) 
    {
        int n=a.size();
        vector<int>tree(4*n,0);
        build(0,0,n-1,b,tree);
        
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int y=query(0,0,n-1,tree,a[i]);
            if(y!=-1)
            {
                update(0,0,n-1,tree,y);
            }
            else
            {
                ans++;
            }
        }
        return ans;
    }
};
