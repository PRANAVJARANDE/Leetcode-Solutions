class Solution {
public:
    int facto(int n)
    {
        long long f=1;
        for(int i=1;i<=n;i++)
        {
            f=f*i;
        }
        return f;
    }

    int uniquePaths(int m, int n) 
    {
      if(m==1 || n==1)
      {
          return 1;
      }

      int i=max(m,n);
      int j=min(m,n);

      if(m==n)
      {
          i=m;
          j=n;
      }
    i--;
    j--;

    long long f=1;
    for(int k=i+1,l=1;k<=i+j;k++,l++)
    {
        f=f*k;
        f=f/l;
    }

    return f;

    }
};
