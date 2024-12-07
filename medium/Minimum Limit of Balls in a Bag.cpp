class Solution {
public:

    bool check(int k,vector<int>&nums,int op)
    {
        int s=0;
        for(int x:nums)
        {
            int ta=x/k;
            if(x%k==0)ta--;
            s+=ta;
        }
        if(s<=op)return 1;
        return 0;
    }

    int minimumSize(vector<int>& nums, int op) 
    {
        int ans=0;
        for(int x:nums)ans=max(ans,x);
        int l=1,r=ans;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(check(mid,nums,op))
            {
                ans=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return ans;
    }
};
