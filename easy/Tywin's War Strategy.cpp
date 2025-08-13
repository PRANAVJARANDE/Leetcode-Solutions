class Solution {
  public:
    int minSoldiers(vector<int>& a, int k) {
        for(auto &x:a)x=(k - (x%k))%k;
        int ans=0;
        int n=a.size();
        sort(a.begin(),a.end());
        int rem=(n-1)/2;
        for(int i=0;i<=rem;i++)ans+=a[i];
        return ans;
    }
};
