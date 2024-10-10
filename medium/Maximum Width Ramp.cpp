class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n=nums.size();
        map<int,int>m;
        multiset<int> s1;
        
        for(int i=n-1;i>=0;i--)
        {
            auto itr=s1.lower_bound(nums[i]);
            if(itr!=s1.end())
            {
                m[nums[i]]=m[*itr];
            }
            else
            {
                m[nums[i]]=i;
            }
            s1.insert(nums[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            s1.erase(s1.find(nums[i]));
            auto itr=s1.lower_bound(nums[i]);
            if(itr!=s1.end())
            {
                int res=m[*itr]-i;
                ans=max(ans,res);
            }
        }
        return ans;

    }
};
