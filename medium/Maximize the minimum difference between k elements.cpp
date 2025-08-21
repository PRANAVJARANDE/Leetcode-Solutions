class Solution {
  public:
  
    bool check(int mid,vector<int>&a,int k)
    {
        int cnt=0;
        
        int pv=-1;
        for(auto x:a)
        {
            if(pv<=x)
            {
                cnt++;
                pv=x+mid;
            }
        }
        return cnt>=k;
    }

  
    int maxMinDiff(vector<int>& a, int k) 
    {
        int n=a.size();
        sort(a.begin(),a.end());
        int ans=0;
        int l=0,r=a[n-1]-a[0];
        
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(check(mid,a,k))
            {
                ans=mid;
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        return ans;
    }
};
