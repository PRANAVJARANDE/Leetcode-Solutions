class Solution {
public:

    int helper(vector<int>&a,int v)
    {
        int s=0,ans=0;
        for(auto x:a)
        {
            x*=v;
            s+=x;
            if(s<0)s=0;
            ans=max(ans,s);
        }
        return ans;
    }


    int maxAbsoluteSum(vector<int>& nums) 
    {
        int a1=helper(nums,1);
        int a2=helper(nums,-1);
        return max(a1,a2);
    }
};
