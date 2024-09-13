class Solution {
public:
    int totalFruit(vector<int>& nums) {
        int l=0,n=nums.size(),ans=0;
        unordered_map<int,int> m;
        for(int i=0;i<n;i++)
        {
            m[nums[i]]++;
            while(m.size()>2)
            {
                m[nums[l]]--;
                if(m[nums[l]]==0)
                {
                    m.erase(nums[l]);
                }
                l++;
            }
            ans=max(ans,i-l+1);
        }
        return ans;
    }
};
