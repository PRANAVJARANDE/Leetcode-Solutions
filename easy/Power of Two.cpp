class Solution {
public:
    bool isPowerOfTwo(int n) 
    {
        int k=0;
        if(n<=0)
        {
            return 0;
        }
        while(n!=0)
        {
            if(n%2==1)
            {
                k++;
            }
            if(k==2)
            {
                return 0;
            }
            n=n>>1;
        }
        if(k==1)
        {
            return 1;
        }
        return 0;
        
    }
};
