class Solution {
  public:
    vector<int> minMaxCandy(vector<int>& a, int k)
    {
        int n=a.size();
        sort(a.begin(),a.end());
        int cnt=ceil((double)n/(k+1));
        int maxi=0;
        int mini=0;
        int i=0,j=n-1;
        while(cnt--)
        {
            mini+=a[i++];
            maxi+=a[j--];
        }
        return {mini,maxi};
    }
};
