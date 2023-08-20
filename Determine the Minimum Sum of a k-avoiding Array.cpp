class Solution {
public:

        int getsum(int n,int a,int b)
        {
                if(n<=0)
                {
                     return 0;   
                }
                if(a>b)
                {
                        return 0;
                }
                int ans=(n*(a+b))/2;
                return ans;
        }
        
        
    int minimumSum(int n, int k) 
    {
            int temp=k/2;
            int a1=getsum(min(temp,n),1,min(temp,n));
            n=n-temp;
            int a2=getsum(n,k,k+n-1);
            return a1+a2;
    }
};
