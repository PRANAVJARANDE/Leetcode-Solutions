class Solution {
public:
    int minimumRightShifts(vector<int>& nums) 
    {
            int n=nums.size(),j=0,ind=-1;
            if(n==1)
            {
                        return 0;
            }
            for(int i=0;i<n;i++)
            {
                if(nums[(i+1)%n]<nums[i])
                {
                        j++;
                        ind=i;
                }
            }
            if(j!=1)
            {
                    return -1;
            }
            return n-ind-1;
        
    }
};
