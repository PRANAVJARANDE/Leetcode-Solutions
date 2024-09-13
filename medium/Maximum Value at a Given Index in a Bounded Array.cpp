class Solution {
public:
    int maxValue(int n, int in, int maxsum) 
    {
        long long l=1;
        long long r=maxsum,ans;

        while(l<=r)
        {
            long long mid=l+(r-l)/2;
            long long rs=0;
            if(n-in-1>=mid)
            {
                rs=rs+(mid*(mid-1))/2;
                rs=rs+n-in-mid;
            }
            else
            {
                rs=rs+((n-in-1)*(2*mid-n+in))/2;
            }

            if(in>=mid)
            {
                rs=rs+(mid*(mid+1))/2;
                rs=rs+in-mid+1;
            }
            else
            {
                rs=rs+((in+1)*(2*mid-in))/2;
            }

            if(rs<=maxsum)
            {
                ans=mid;
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        return ans;
        
    }
};
