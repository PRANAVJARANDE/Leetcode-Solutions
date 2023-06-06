class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) 
    {
        nums.push_back(INT_MIN);
        int k=0,kmax=0;
        bool b=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]==1)
            {
                b=1;
            }
            if(nums[i]==1 && nums[i+1]==1)
            {
                k++;
            }
            else
            {
                kmax=max(kmax,k);
                k=0;
            }
        }
        
        if(kmax==0 && b==0)
        {
            return 0;
        }
        return kmax+1;
    }
};
