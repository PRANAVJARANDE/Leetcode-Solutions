class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) 
    {
            long long a=0,b=0,s1=0,s2=0;
            for(int x: nums1)
            {
                s1+=x;
                if(x==0)
                {
                        a++;
                }
            }
            for(int x: nums2)
            {
                s2+=x;
                if(x==0)
                {
                        b++;
                }
            }
            
            if(a==0 && b==0)
            {
                if(s1==s2)
                {
                        return s1;
                }
                return -1;
            }
            else if(b==0)
            {
                if(s1+a<=s2)
                {
                        return s2;
                }
                return -1;
            }
            else if(a==0)
            {
                if(s2+b<=s1)
                {
                        return s1;
                }
                    return -1;
            }
            else
            {
                    return max(s1+a,s2+b);
            }
    }
};
