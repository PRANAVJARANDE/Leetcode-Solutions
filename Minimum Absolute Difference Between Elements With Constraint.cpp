class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) 
    {
            set<int> s1;
            int n=nums.size();
            int ans=INT_MAX;
            for(int i=x;i<n;i++)
            {
                s1.insert(nums[i-x]);
                auto it=s1.lower_bound(nums[i]);
                if(it!=s1.end())
                {
                    ans=min(ans,abs(nums[i]-*it));
                }
                if(it!=s1.begin())
                {
                    it--;
                    ans=min(ans,abs(nums[i]-*it));
                }
            }
            return ans;
        
    }
};
