class Solution {
  public:
    int median(vector<vector<int>> &a) 
    {
        int n=a.size();
        int m=a[0].size();
        vector<int>v1;
        for(auto x:a)
        {
            for(auto y:x)
            {
                v1.push_back(y);
            }
        }
        sort(v1.begin(),v1.end());
        return v1[(n*m) /2];
    }
};
