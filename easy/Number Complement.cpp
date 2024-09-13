class Solution {
public:
    int findComplement(int n) 
    {
        long long k=0;
        int ans=0;
        while(n>0)
        {
            int rem=n%2;
            if(rem==0)
            {
                ans=ans+pow(2,k);
            }
            k++;
            n=n>>1;
        }
        return ans;
    }
};
