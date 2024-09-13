class Solution {
public:
    int findMin(vector<int>& arr) 
    {
        int l=0;
        int r=arr.size()-1;

        if(arr.size()==1)
        {
            return arr[0];
        }

        int m=INT_MAX;
        while(l<r)
        {
            int mid=(l+r)/2;
            if(arr[l]<=arr[r])
            {
                return arr[l];
            }

            
            if(arr[mid]<arr[l])
            {
                r=mid;
            }
            else if(arr[r]<arr[mid])
            {
                l=mid+1;
            }
        }
         if(arr[l]<=arr[r])
            {
                return arr[l];
            }


        return -1;
    }
};
