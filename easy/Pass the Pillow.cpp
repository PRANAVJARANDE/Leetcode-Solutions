class Solution {
public:
    int passThePillow(int n, int t) {
        int y=(2*n-2);
        int rem=t%y;
        int in=1;
        bool b=0;
        while(rem--)
        {
            if(in==n)b=1;
            if(b==0)in++;
            else in--;
        }
        return in;
    }
};
