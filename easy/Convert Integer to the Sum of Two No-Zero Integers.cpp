class Solution {
public:

    bool check(int n)
    {
        while(n)
        {
            if(n%10==0)return 0;
            n/=10;
        }
        return 1;
    }

    vector<int> getNoZeroIntegers(int n) 
    {
        for(int i=1;i<n;i++)
        {
            int n1=i;
            int n2=n-i;
            if(check(n1) && check(n2))return {n1,n2};
        }
        return {1,n-1};
    }
};
