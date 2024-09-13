class Solution {
public:

    void helper(vector<vector<int>>& v1, int& k,int emptysq,int i,int j)
    {
        int m = v1.size();
        int n = v1[0].size();

        if(i<0 || i>=m || j<0  || j>=n || v1[i][j]==-1 || v1[i][j]==3)
        {
            return;
        }
        if(v1[i][j]==2)
        {
            if(emptysq==-1)
            {
                k++;
            }
            return;
        }
        
        int temp=v1[i][j];
        v1[i][j]=3;
        helper(v1,k,emptysq-1,i+1,j);
        helper(v1,k,emptysq-1,i-1,j);
        helper(v1,k,emptysq-1,i,j+1);
        helper(v1,k,emptysq-1,i,j-1);
        v1[i][j]=temp;

    }


    int uniquePathsIII(vector<vector<int>>& grid) 
    {
        int a=0;
        int sx,sy;
        int m = grid.size();
        int n = grid[0].size();
        int es=0;

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    sx=i;
                    sy=j;
                    break;
                }
            }
        }

        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0)
                {
                    es++;
                }
            }
        }

        
        helper(grid,a,es,sx,sy);
        return a;
        
    }
};
