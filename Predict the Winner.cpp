class Solution {
public:

    int helper(vector<int>&nums,int s1,int s2,bool b,int s,int e)
    {
        if(s>e)
        {
            if(s1>=s2)
            {
                return 1;
            }
            return 0;
        }
        if(b==1)
        {
            return helper(nums,s1+nums[s],s2,0,s+1,e) || helper(nums,s1+nums[e],s2,0,s,e-1);
        }
        else
        {
            return helper(nums,s1,s2+nums[s],1,s+1,e) && helper(nums,s1,s2+nums[e],1,s,e-1);
        }
    }


    bool PredictTheWinner(vector<int>& nums) 
    {
        return helper(nums,0,0,1,0,nums.size()-1);
    }
};
