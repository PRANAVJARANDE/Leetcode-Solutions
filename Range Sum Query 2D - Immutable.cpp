class NumMatrix {
public:
    
    vector<vector<int>> temp;

    NumMatrix(vector<vector<int>>& arr) 
    {
        int m=arr.size(),n=arr[0].size();
        temp.resize(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++)
                temp[i][j]=temp[i-1][j]+temp[i][j-1]-temp[i-1][j-1]+arr[i-1][j-1];
    }
    
    int sumRegion(int a, int b, int i, int j) 
    {
        return temp[i+1][j+1]+temp[a][b]-temp[a][j+1]-temp[i+1][b]; 
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
