class Solution {
public:

    bool gb(int n,int p)
    {
        return n & 1<<p;
    }

    int minFlips(int a, int b, int c) 
    {
        int s=a | b;
        int k=0;
        for(int i=0;i<32;i++)
        {
            if(gb(c,i)==gb(s,i))
            {
                continue;
            }
            if(gb(c,i)==1 && gb(s,i)==0)
            {
                k++;
            }
            if(gb(c,i)==0 && gb(s,i)==1)
            {
                if(gb(a,i)==1)
                {
                    k++;
                }
                if(gb(b,i)==1)
                {
                    k++;
                }
            }
        }
        return k;
        
    }
};
