class Solution {
public:
    int countPrimes(int n) 
    {
        vector<bool> v(n+1,1);
        v[0]=0;
        v[1]=0;
        for(int i=2;i*i<=n;i++)
        {
            if(v[i]==1)
            {   
            for(int j=i*i;j<=n;j=j+i)
            {
                v[j]=0;
            }
            }
        }
        int k=0;
        for(int i=2;i<n;i++)
        {
            if(v[i]==1)
            {
                k++;
            }
        }
        return k;

    }
};
