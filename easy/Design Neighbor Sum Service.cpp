class neighborSum {
public:
    int n;
    vector<vector<int>> a;
    
    neighborSum(vector<vector<int>>& a1) {
        n=a1.size();
        a=a1;
        
    }
    
    int adjacentSum(int v) {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(a[i][j]==v)
                {
                    int s=0;
                    if(i-1>=0)s+=a[i-1][j];
                    if(i+1<n)s+=a[i+1][j];
                    if(j-1>=0)s+=a[i][j-1];
                    if(j+1<n)s+=a[i][j+1];
                    return s;
                }
            }
        }
        return 0;
    }
    
    int diagonalSum(int v) {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(a[i][j]==v)
                {
                    int s=0;
                    if(i-1>=0 && j-1>=0)s+=a[i-1][j-1];
                    if(i-1>=0 && j+1<n)s+=a[i-1][j+1];
                    if(i+1<n && j-1>=0)s+=a[i+1][j-1];
                    if(i+1<n && j+1<n)s+=a[i+1][j+1];
                    return s;
                }
            }
        }
        return 0;
    }
};

/**
 * Your neighborSum object will be instantiated and called as such:
 * neighborSum* obj = new neighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */
