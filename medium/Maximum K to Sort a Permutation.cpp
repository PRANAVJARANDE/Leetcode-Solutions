class Solution {
public:
    int sortPermutation(vector<int>& nums) 
    {   
        int maxi=(1<<30)-1;
        bool flag=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=i)
            {
                flag=1;
                maxi&=nums[i];
            }
        }
        if(flag==0)maxi=0;
        return maxi;
    }
};
