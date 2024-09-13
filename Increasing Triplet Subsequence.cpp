class Solution {
public:
    bool increasingTriplet(vector<int>& nums) 
    {
        int fm=INT_MAX,sm=INT_MAX;
        for(int x: nums)
        {
            if(x<=fm)
            {
                fm=x;
            }
            else if(x<=sm)
            {
                sm=x;
            }
            else
            {
                return 1;
            }
        }
        return 0;
    }
};
