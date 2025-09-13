class Solution {
  public:
  
    int minJumps(vector<int>& a) 
    {
        int ans=0;
        int l=0;
        int r=0;
        int n=a.size();
        while(r<n-1)
        {
            int nin=r;
            while(l<=r)
            {
                nin=max(nin,a[l]+l);
                l++;
            }
            if(nin==r)return -1;
            r=nin;
            ans++;
        }
        return ans;
    }
};

