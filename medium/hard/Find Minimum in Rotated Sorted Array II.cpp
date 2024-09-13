class Solution {
public:

    int bs(vector<int> arr,int l,int r)
    {
        int mid=(l+r)/2;
        if(l==r)
        {
            return arr[l];
        }
        if(arr[l]<arr[r])
        {
            return arr[l];
        }
        if(arr[l]==arr[mid] && arr[mid]==arr[r])
        {
            return bs(arr,l,r-1);
        }



        //temporary
        if(arr[l]==arr[mid] && arr[r]<arr[mid])
        {
            return bs(arr,mid+1,r);
        }
        if(arr[mid]==arr[r] && arr[l]>arr[mid])
        {
            return bs(arr,l,mid);
        }


        //main cases
        if(arr[mid]>arr[r])
        {
            return bs(arr,mid+1,r);
        }
        if(arr[mid]<arr[l])
        {
            return bs(arr,l,mid);
        }
        return 0;
    }


    int findMin(vector<int>& nums) 
    {
        return bs(nums,0,nums.size()-1);
    }
};
