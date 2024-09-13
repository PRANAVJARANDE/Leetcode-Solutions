class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int l=0,r=n-1;
        double res=INT_MAX;
        while(l<r)
        {
            double ans=(nums[l]+nums[r])/2.0;
            res=min((double)res,ans);
            l++;
            r--;
        }
        return res;
    }
};
