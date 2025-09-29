class Solution {
  public:

    int countPS(string &a) 
    {
        int n=a.size();
        
        int ans=0;
        //odd length
        for(int i=0;i<n;i++)
        {
            int l=i,r=i;
            while(l>=0 && r<n && a[l]==a[r])
            {
                ans++;
                l--;
                r++;
            }
        }
        
        //even
        for(int i=0;i<n-1;i++)
        {
            int l=i,r=i+1;
            while(l>=0 && r<n && a[l]==a[r])
            {
                ans++;
                l--;
                r++;
            }
        }
        return ans-n;
    }
};
