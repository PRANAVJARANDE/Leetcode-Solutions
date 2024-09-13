class Solution {
public:

unsigned long long bino(int n,int r)
{
    if(r>n-r)
    {
        r=n-r;
    }
    unsigned long long res=1;
    for(int i=1;i<=r;i++)
    {
        res=res*(n-i+1);
        res=res/i;
    }
    return res;
}


    int numTrees(int n) 
    {
    unsigned long long c=bino(2*n,n);
    return c/(n+1);
        
    }
};
