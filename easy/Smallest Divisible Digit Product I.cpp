class Solution {
public:
    int smallestNumber(int n, int t) {
        for(int i=n;;i++)
        {
            int pro=1;
            int j=i;
            while(j)
            {
                int rem=j%10;
                pro*=rem;
                j/=10;
            }
            if(pro%t==0)return i;
        }
    }
};
