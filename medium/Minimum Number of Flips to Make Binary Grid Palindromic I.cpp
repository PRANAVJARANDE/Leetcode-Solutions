class Solution {
public:
    int minFlips(vector<vector<int>>& a) {
        int f1=0;
        int n=a.size(),m=a[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m/2;j++)
            {
                if(a[i][j]!=a[i][m-j-1])
                {
                    f1++;
                }
            }
        }
        int f2=0;
        for(int j=0;j<m;j++)
        {
            for(int i=0;i<n/2;i++)
            {
                if(a[i][j]!=a[n-i-1][j])
                {
                    f2++;
                }
            }
        }
        return min(f1,f2);
    }
};
