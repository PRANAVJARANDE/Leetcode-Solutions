class Solution {
public:
    char nextGreatestLetter(vector<char>& arr, char t) 
    {
        int l=0;
        int r=arr.size()-1;
        while(l<=r)
        {
            if(arr[l]>t)
            {
                return arr[l];
            }
            int mid=l+(r-l)/2;
            if(arr[mid]<=t)
            {
                l=mid+1;
            }
            else if(arr[mid]>t)
            {
                r=mid;
            }
        }
        return arr[0];
    }
};
