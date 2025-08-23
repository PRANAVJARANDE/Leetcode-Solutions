class Solution {
  public:
  
    bool check(int mx,vector<int>&a,int k)
    {
        int n=a.size();
        int cnt=0;
        for(int i=0;i<n;)
        {
            int cr=0;
            while(i<n && cr+a[i]<=mx)
            {
                cr+=a[i];
                i++;
            }
            cnt++;
        }
        //cout<<cnt<<endl;
        if(cnt<=k)return 1;
        return 0;
    }
  
    int findPages(vector<int> &a, int k) 
    {
        if(a.size()<k)return -1;
        int l=0,r=0;
        for(auto x:a)
        {
            r+=x;
            l=max(l,x);
        }
        
        //cout<<check(113,a,k)<<endl;
        
        int ans=r;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(check(mid,a,k))
            {
                ans=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return ans;
    }
};
