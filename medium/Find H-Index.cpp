class Solution {
  public:
    int hIndex(vector<int>& a) {
        int n=a.size();
        sort(a.begin(),a.end(),greater<int>());
        for(int i=0;i<n;i++)
        {
            if(a[i]<i+1)return i;
        }
        return n;
    }
};
