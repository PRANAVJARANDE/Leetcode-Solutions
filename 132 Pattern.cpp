class Solution {
public:
    bool find132pattern(vector<int>& nums) 
    {
        int n=nums.size();
        multiset<int> s1;
        for(int i=1;i<n;i++)
            s1.insert(nums[i]);

        int mini=nums[0];
        for(int i=1;i<n;i++)
        {
            if(s1.upper_bound(mini)!=s1.end() && *(s1.upper_bound(mini))<nums[i] && *(s1.upper_bound(mini))!=mini)
            {
                return 1;
            }
            s1.erase(s1.find(nums[i]));
            mini=min(mini,nums[i]);
        }
        return 0;
    }
};
