class Solution {
  public:
    int assignHole(vector<int>& a, vector<int>& b) {
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        int n=a.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans=max(ans,abs(a[i]-b[i]));
        }
        return ans;
        
    }
};
