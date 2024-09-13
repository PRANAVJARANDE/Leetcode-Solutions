class Solution {
public:

    bool helper(vector<int>&nums,int k,int h)
    {
        int a=0;
        for(int i=0;i<nums.size();i++)
        {
            double hh=nums[i]*1.0/k;
            a+=ceil(hh);
        }
        return a<=h;
    }

    
    int minEatingSpeed(vector<int>& nums, int h) 
    {
        int n=nums.size();
        int s=1;
        int e=INT_MIN;
        for(int i=0;i<n;i++)
        {
            e=max(e,nums[i]);
        }

        while(s<e)
        {
            int mid=(s+e)/2;
            if(helper(nums,mid,h))
            {
                e=mid;
            }
            else
            {
                s=mid+1;
            }

        }
        return s;
        
    }

};
