class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) 
    {
            unordered_set<int> m;
            for(auto x: nums)
            {
                    for(int i=x[0];i<=x[1];i++)
                    {
                            m.insert(i);
                    }
            }
            return (int)m.size();    
    }
};
