class Solution {
  public:
  int MOD=1e9 +7;
    int CountPairs(int n, int k, vector<int> &a) {
       map<int,map<int,int>> m;
       long long ans=0;
       for(int i=0;i<n;i++)
       {
           int in=(i+1)%k;
           int req=(k-in)%k;
           ans=((ans%MOD)+(m[req][a[i]])%MOD)%MOD;
           m[in][a[i]]++;
       }
       return ans;
    }
};
