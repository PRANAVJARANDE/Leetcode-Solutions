class Solution {
public:

    bool helper(long long in,long long k)
    {
        if(k==0)return 1;
        if(k<0)return 0;
        for(int i=in;powl(3,i)<=k;i++)
        {
            bool b1=helper(i+1,k-powl(3,i));
            if(b1)return 1;
        }
        return 0;
    }

    bool checkPowersOfThree(int n) 
    {
        bool ans=helper(0,n);
        return ans;
    }
};
