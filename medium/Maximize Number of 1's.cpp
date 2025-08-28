class Solution {
  public:
    int maxOnes(vector<int>& a, int k) {
        
        int l=0;
        int zc=0;
        int ans=0;
        for(int i=0;i<a.size();i++)
        {
            if(a[i]==0)zc++;
            while(zc>k)
            {
                if(a[l]==0)zc--;
                l++;
            }
            ans=max(ans,i-l+1);
        }
        return ans;
    }
};
