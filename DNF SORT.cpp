class Solution {
public:
    void sortColors(vector<int>& arr) 
    {
        int l=0;
        int mid=0;
        int r=arr.size()-1;
        while(mid<=r)
        {
            if(arr[mid]==2)
            {
                swap(arr[mid],arr[r]);
                r--;
            }
            else if(arr[mid]==0)
            {
                swap(arr[mid],arr[l]);
                l++;
                mid++;
            }
            else if(arr[mid]==1)
            {
                mid++;
            }
        }
    }
};
