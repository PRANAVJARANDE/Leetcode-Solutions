class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) 
    {
        if(nums.size()==1)
        {
            return 0;
        }
        set<int> s1;
        if(nums.size()<=k)
        {
            for(int i=0;i<nums.size();i++)
            {
                s1.insert(nums[i]);
            }
            if(s1.size()<nums.size())
            {
                return 1;
            }
            return 0;
        }
        
        int ws=k+1;
        for(int i=0;i<ws;i++)
        {
            s1.insert(nums[i]);
        }
        if(s1.size()<ws)
        {
            return 1;
        }

        for(int i=ws;i<nums.size();i++)
        {
            s1.erase(nums[i-ws]);
            s1.insert(nums[i]);
            if(s1.size()<ws)
            {
                return 1;
            }
        }
        return 0;
    }
};
