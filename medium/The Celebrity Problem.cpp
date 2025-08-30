class Solution {
  public:
    int celebrity(vector<vector<int>>& a) 
    {
        int n=a.size();
        vector<int>r(n,0),c(n,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(a[i][j])
                {
                    r[i]++;
                    c[j]++;
                }
            }
        }
        
        for(int i=0;i<n;i++)
        {
            if(r[i]==1 && c[i]==n)
            {
                return i;
            }
        }
        return -1;
        
    }
};
