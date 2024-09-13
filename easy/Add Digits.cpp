class Solution {
public:

    int addDigits(int n)
    {
        if(n<10)
        {
            return n;
        }
        int s=0;
        while(n!=0)
        {
            int rem=n%10;
            s=s+rem;
            n=n/10;
        }
        return addDigits(s);
    }
};
