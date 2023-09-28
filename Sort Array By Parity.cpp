class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) 
    {
        vector<int>res,v1;
        for(int x: nums)
        {
            if(x%2==0)
            {
                res.push_back(x);
            }
            else
            {
                v1.push_back(x);
            }
        }
        for(int x: v1)
        {
            res.push_back(x);
        }
        return res;
    }
};
