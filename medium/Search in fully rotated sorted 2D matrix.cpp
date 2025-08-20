class Solution {
  public:
    bool searchMatrix(vector<vector<int>> &a, int k) {
        
        for(auto x:a)
        {
            for(auto y:x)
            {
                if(y==k)return 1;
            }   
        }
        return 0;
    }
};
