class Solution {
public:
    bool judgeSquareSum(int c) 
    {
        long long i=0;
        long long j=sqrt(c);
        while(i<=j)
        {
            long long s=i*i+j*j;
            if(s==c)
            {
                return 1;
            }
            else if(s>c)
            {
                j--;
            }
            else
            {
                i++;
            }
        }
        return 0;
        
    }
};
