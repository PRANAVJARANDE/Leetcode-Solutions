class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        
        int n=nums1.size();
        int m=nums2.size();
        vector<int> arr(m+n);
        int ptr1=0;
        int ptr2=0;
        int k=0;
        while(ptr1<n && ptr2<m)
        {
            if(nums1[ptr1]<=nums2[ptr2])
            {
                arr[k]=nums1[ptr1];
                ptr1++;
                k++;
            }
            else
            {
                arr[k]=nums2[ptr2];
                ptr2++;
                k++;
            }
        }

        while(ptr1<n)
        {
            arr[k]=nums1[ptr1];
                ptr1++;
                k++;
        }

        while(ptr2<m)
        {
            arr[k]=nums2[ptr2];
                ptr2++;
                k++;
        }

        if((m+n)%2==1)
        {
            return arr[(m+n)/2];
        }
        else
        {
            return (arr[(m+n)/2]+arr[((m+n)/2)-1])/2.0;
            
        }


    }
};
