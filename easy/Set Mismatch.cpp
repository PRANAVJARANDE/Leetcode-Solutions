class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        int a,n=nums.size();
        int in=1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==in)
            {
                in++;
            }
            if(i+1<n && nums[i]==nums[i+1])
            {
                a=nums[i];
            }
        }
        return {a,in};
    }
};
