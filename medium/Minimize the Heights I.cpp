// User function Template for C++

class Solution {
  public:
    int getMinDiff(vector<int> &a, int k) {
        sort(a.begin(),a.end());
        int n=a.size();
        int ans=a[n-1]-a[0];
        
        for(int i=0;i<n-1;i++)
        {
            int maxi=max(a[i]+k,a[n-1]-k);
            int mini=min(a[0]+k,a[i+1]-k);
            //if(mini<0)continue;
            ans=min(ans,maxi-mini);
        }
        return ans;
    }
};
