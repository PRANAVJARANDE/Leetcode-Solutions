class Solution {
public:

    int helper(vector<int>&nums,int t)
    {
        int n=nums.size();
        int i=0,j=n-1;
        int ans=-1;
        while(i<=j)
        {
            int mid=i+(j-i)/2;
            if(nums[mid]==t)
            {
                ans=mid;
                j=mid-1;
            }
            else if(nums[mid]<t)
            {
                i=mid+1;
            }
            else
            {
                j=mid-1;
            }
        }
        return ans;
    }

    int helper1(vector<int>&nums,int t)
    {
        int n=nums.size();
        int i=0,j=n-1;
        int ans=-1;
        while(i<=j)
        {
            int mid=i+(j-i)/2;
            if(nums[mid]==t)
            {
                ans=mid;
                i=mid+1;
            }
            else if(nums[mid]<t)
            {
                i=mid+1;
            }
            else
            {
                j=mid-1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int t) 
    {
        int a=helper(nums,t);
        int b=helper1(nums,t);
        return {a,b};
    }
};
