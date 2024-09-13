class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) 
    {
        int n1=nums1.size(),n2=nums2.size(),a=0,b=0;
        if(n1%2==0 && n2%2==0)
        {
            return 0;
        }
        for(int x: nums1)
            a=a^x;
        
        for(int x: nums2)
            b=b^x;
        
        if(n1%2==1 && n2%2==1)
        {
            return a^b;
        }
        else if(n1%2==0 && n2%2==1)
        {
            return a;
        }
        return b;
    }
};
