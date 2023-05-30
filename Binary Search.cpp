class Solution {
public:
    int search(vector<int>& nums, int t) 
    {
        int l=0;
        int r=nums.size()-1;

        while(l<=r)
        {
            int mid=r+(l-r)/2;
            if(nums[mid]==t)
            {
                return mid;
            }
            else if(nums[mid]>t)
            {
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }    
        return -1;
    }
};
