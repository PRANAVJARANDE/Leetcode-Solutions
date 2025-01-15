class Solution {
public:
    int minimizeXor(int n1, int n2) 
    {
        int cnt=0;
        while(n2)
        {
            if(n2%2)cnt++;
            n2/=2;
        }
    
        int x=0;
        for(int i=31;i>=0;i--)
        {
            if(n1 & (1<<i))
            {
                if(cnt)
                {
                    x= x | (1<<i);
                    cnt--;
                }
            }
        }

        for(int i=0;i<=31;i++)
        {
            if(!(x & (1<<i)))
            {
                if(cnt)
                {
                    cnt--;
                    x= x | (1<<i);
                }

            }
        }
        return x;
    }
};
