class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) 
    {
        int n=nums1.size(),a1=nums1[n-1],a2=nums2[n-1];
        int c=0;
        bool b1=1;
        for(int i=0;i<n-1;i++)
        {
            if(nums1[i]<=a1 && nums2[i]<=a2)
                continue;
            else if(nums1[i]<=a2 && nums2[i]<=a1)
                c++;
            else
            {
                b1=0;
                break;
            }
        }

        int c2=1;
        bool b2=1;
        for(int i=0;i<n-1;i++)
        {
            if(nums1[i]<=a2 && nums2[i]<=a1)
                continue;
            else if(nums1[i]<=a1 && nums2[i]<=a2)
                c2++;
            else
            {
                b2=0;
                break;
            }
        }    
        if(b1==0 && b2==0)
            return -1;
        return min(c,c2);       
    }
};
