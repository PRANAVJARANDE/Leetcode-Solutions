class Solution {
  public:
    
    bool check(int mid,vector<int>&a,int k,int m)
    {
        int res=0;
        int cr=0;
        for(auto x:a)
        {
            if(x>mid)cr=0;
            else
            {
                cr++;
                if(cr==k)
                {
                    cr=0;
                    res++;
                }
            }
        }
        
        if(res>=m)return 1;
        return 0;
    }
  
  
  
    int minDaysBloom(vector<int>& a, int k, int m) 
    {
        int ans=-1;
        int l=0,r=0;
        for(auto x:a)r=max(r,x);
        
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(check(mid,a,k,m))
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
