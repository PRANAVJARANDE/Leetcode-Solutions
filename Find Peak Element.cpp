class Solution {
public:

    int bs(vector<int> nums,int l,int r)
    {
        if(l>=r)
        {
            return -1;
        }
        int mid=(l+r)/2;
        if(l==mid || l==r || r==mid )
        {
            return -1;
        }
        
        if((mid!=r && nums[mid] > nums[mid+1] ) && (mid!=l && nums[mid]>nums[mid-1] ))
        {
            return mid;
        }

        int ls=bs(nums,l,mid);
        if(ls!=-1)
        {
            return ls;
        }
        int rs=bs(nums,mid,r);
        if(rs!=-1)
        {
            return rs;
        }
        return -1;
    }



    int findPeakElement(vector<int>& nums) 
    {
        if(nums.size()==0 || nums.size()==1)
        {
            return 0;
        }
        if(nums[0]>nums[1])
        {
            return 0;
        }
        if(nums[nums.size()-1] > nums[nums.size()-2])
        {
            return nums.size()-1;
        }
        return bs(nums,0,nums.size()-1);
    }
};
