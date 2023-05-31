class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) 
    {
        int n=mat.size();
        int s=0;
        for(int i=0;i<n;i++)
        {
            s=s+mat[i][i];
        }

        int m=0;
        for(int i=0;i<n;i++)
        {
            m=m+mat[i][n-i-1];
        }

        if(n%2==0)
        {
            return s+m;
        }
        int es=mat[n/2][n/2];
        return s+m-es;
        
    }
};
