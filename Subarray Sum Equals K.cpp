class Solution {
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        int n=nums.size(),ans=0,csum=0;
        unordered_map<int,int> m;
        for(int i=0;i<n;i++)
        {
            csum+=nums[i];
            if(csum==k)
            {
                ans++;
            }
            if(m.find(csum-k)!=m.end())
            {
                ans+=m[csum-k];
            }
            m[csum]++;
        }
        return ans;
    }
};
