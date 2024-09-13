class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) 
    {
        int ans=0,l=0;  
        map<int,int> freq;
        for(int i=0;i<nums.size();i++)
        {
            int x=nums[i];
            freq[x]++;
            while(freq[x]>k)
            {
                freq[nums[l]]--;
                l++;
            }
            ans=max(ans,i-l+1);
        }
        return ans;
    }
};
