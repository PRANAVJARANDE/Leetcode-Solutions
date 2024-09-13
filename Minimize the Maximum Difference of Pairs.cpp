class Solution {
public:

    bool helper(vector<int>&nums,int mid,int p)
    {
        int c=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i+1]-nums[i]<=mid)
            {
                c++;
                i++;
            }
        }
        if(c<p)
        {
            return 1;
        }
        return 0;
    }



    int minimizeMax(vector<int>& nums, int p) {
        int s=0;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int e=nums[n-1]-nums[0];

        while(s<e)
        {
            int mid=(s+e)/2;
            if(helper(nums,mid,p)==1)
            {
                s=mid+1;
            }
            else
            {
                e=mid;
            }
        }
        return s;
    }
};
