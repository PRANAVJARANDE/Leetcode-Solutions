class Solution {
public:

    int trailingZeroes(int n) 
    {
        int ans=0;

        for(int i=5;i<=n;i++)
        {
            if(i%5==0)
            {
                int a=0;
                int x=i;
                while(x%5==0)
                {
                    a++;
                    x=x/5;
                }
                ans=ans+a;
            }
        }
        
        return ans;

       
    }
};
