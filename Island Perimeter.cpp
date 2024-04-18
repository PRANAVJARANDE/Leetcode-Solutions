class Solution {
public:
    int n,m;
    int helper(int i,int j,vector<vector<int>>&arr)
    {
        if(i<0 || j<0 || i>=n || j>=m)return 1;
        if(arr[i][j]==0)return 1;
        if(arr[i][j]==-1)return 0;
        
        arr[i][j]=-1;
        int op1=helper(i+1,j,arr);
        int op2=helper(i,j+1,arr);
        int op3=helper(i-1,j,arr);
        int op4=helper(i,j-1,arr);
        return op1+op2+op3+op4;
    }


    int islandPerimeter(vector<vector<int>>& grid) 
    {
        n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    return helper(i,j,grid);
                }
            }
        }
        return 0;
        
    }
};
