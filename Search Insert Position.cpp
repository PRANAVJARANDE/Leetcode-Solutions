class Solution {
public:
    int searchInsert(vector<int>& arr, int t) {
        int l=0;
        int r=arr.size()-1;
        int mid;
        if(t>arr[r])
        {
            return r+1;
        }

        while(l<=r)
        {
            mid=(l+r)/2;
            if(arr[mid]==t)
            {
                return mid;
            }
            else if(arr[mid]>t)
            {
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }

        return l;

    }
};
