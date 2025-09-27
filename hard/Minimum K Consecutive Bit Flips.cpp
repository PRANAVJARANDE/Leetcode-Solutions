class Solution {
  public:
    int kBitFlips(vector<int>& a, int k) {
        
        int ans=0;
        int n=a.size();
        vector<int>flag(n+1,0);
        
        int pv=0;
        for(int i=0;i<n;i++)
        {
            if(flag[i])pv=1-pv;
            if(a[i]==pv)
            {
                //do op
                if(i+k<=n)flag[i+k]=1;
                else return -1;
                pv=1-pv;
                ans++;
            }
        }
        return ans;
    }
};
