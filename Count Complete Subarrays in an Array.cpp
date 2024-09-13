class Solution {
public:
        
        
        int helper(vector<int>&nums,int k)
        {
            unordered_map<int,int> m;
            int n=nums.size(),l=0,ans=0;
            for(int i=0;i<n;i++)
            {
                    m[nums[i]]++;
                    while(m.size()>k)
                    {
                           m[nums[l]]--;
                           if(m[nums[l]]==0)
                           {
                                   m.erase(nums[l]);
                           }
                           l++;
                    }
                    ans+=i-l+1;
            }
            return ans;
        }
        
        
    int countCompleteSubarrays(vector<int>& nums) 
    {
            unordered_map<int,int> temp;
            for(int x: nums)
            {
                temp[x]++;
            }
            int k=temp.size();
            return helper(nums,k)-helper(nums,k-1);
    }
};
