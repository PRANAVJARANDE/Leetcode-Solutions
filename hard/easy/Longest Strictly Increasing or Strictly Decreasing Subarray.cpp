class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) 
    {
        int n=nums.size();
        int a1=1,a2=1;
        
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                bool b=0,c=0;
                for(int k=i+1;k<=j;k++)
                {
                    if(nums[k-1]>=nums[k])
                    {
                        b=1;
                    }
                    if(nums[k-1]<=nums[k])
                    {
                        c=1;
                    }
                }
                if(b==0)a1=max(a1,j-i+1);
                if(c==0)a2=max(a2,j-i+1);
            }
        }
        return max(a1,a2);
        
    }
};
