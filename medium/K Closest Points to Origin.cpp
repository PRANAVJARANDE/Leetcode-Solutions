class Solution {
  public:
  
    static bool cmp(vector<int>&a,vector<int>&b)
    {
        long long d1=(long long)a[0]*a[0] + (long long)a[1]*a[1];
        long long d2=(long long)b[0]*b[0] + (long long)b[1]*b[1];
        return d1<d2;
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& a, int k) {
        sort(a.begin(),a.end(),cmp);
        while(a.size()>k)a.pop_back();
        return a;
    }
};
