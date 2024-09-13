class Solution {
public:


    bool gb(int n,int p)
    {
        return n & 1<<p;
    }

    bool isPowerOfFour(int n) 
    {
        if(n==1)
        {
            return 1;
        }
        int t=0;
        int k=0;
        int c=0;
        while(n!=0)
        {
            if(gb(n,0))
            {
                if(t==0)
                {
                    t=k;
                }
                c++;
            }
            if(c==2)
            {
                return 0;
            }
            k++;
            n=n>>1;
        }
        if(c==1 && t%2==0)
        {
            return 1;
        }
        return 0;
        
    }
};
