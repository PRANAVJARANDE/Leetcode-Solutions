class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int k) 
    {
        int n=nums.size();
        unordered_map<int,int> m;
        int ans=0;
        int p=0;
        for(int i=0;i<n;i++)
        {
            p+=nums[i];
            if(p==k)
            {
                ans++;
            }
            ans+=m[p-k];
            m[p]++;
        }
        return ans;
    }
};
