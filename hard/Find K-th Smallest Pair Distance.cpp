class Solution {
public:

    int getcount(vector<int> nums,int mid)
    {
        int n=nums.size();
        int i=0;
        int j=1;
        int count=0;
        while(i<n && j<n)
        {
            if(nums[j]-nums[i]<=mid)
            {
                count+=(j-i);
                j++;
            }
            else
            {
                i++;
            }
        }
        return count;
    }


    int smallestDistancePair(vector<int>& nums, int k) 
    {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int r=nums[n-1]-nums[0];

        int l=INT_MAX;
        for(int i=0;i<n-1;i++)
        {
            l=min(l,nums[i+1]-nums[i]);
        }

        while(l<r)
        {
            int mid=(l+r)/2;
            int count=getcount(nums,mid);
            if(count<k)
            {
                l=mid+1;
            }
            else
            {
                r=mid;
            }
        }
        return l;
    }
};
