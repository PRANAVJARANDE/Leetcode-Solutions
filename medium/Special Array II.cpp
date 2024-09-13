class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& q) 
    {
        set<int> s1;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]%2 ==nums[i+1]%2)
            {
                s1.insert(i);
            }
        }
        vector<bool> ans;
        for(auto x: q)
        {
            int l=x[0],r=x[1];
            auto itr=s1.lower_bound(x[0]);
            if(itr==s1.end())
            {
                ans.push_back(1);
                continue;
            }
            int nx=*itr;
            if(nx>=r)
            {
                ans.push_back(1);
            }
            else
            {
                ans.push_back(0);
            }
        }
        return ans;
        
    }
};
