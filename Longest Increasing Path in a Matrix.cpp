class Solution {
public:
    int memorize(vector<vector<int>> &memo,vector<vector<int>> &arr,int i,int j)
    {
        int n=arr.size();
        int m=arr[0].size();
        
        if(memo[i][j]!=0)
        {
            return memo[i][j];
        }

        int cmax=1;
        //check left
        if(i!=0 && arr[i-1][j] > arr[i][j])
        {
            cmax=max(cmax,1+memorize(memo,arr,i-1,j));
        }


        //check right
        if(i!=n-1 && arr[i+1][j] > arr[i][j])
        {
            cmax=max(cmax,1+memorize(memo,arr,i+1,j));
        }

        //check up
        if(j!=0 && arr[i][j-1] > arr[i][j])
        {
            cmax=max(cmax,1+memorize(memo,arr,i,j-1));
        }

        //check down
        if(j!=m-1 && arr[i][j+1] > arr[i][j])
        {
            cmax=max(cmax,1+memorize(memo,arr,i,j+1));
        }
        memo[i][j]=cmax;
        return cmax;
    }

    int longestIncreasingPath(vector<vector<int>>& arr) 
    {
        int n=arr.size();
        int m=arr[0].size();
        vector<vector<int>>  memo(n,vector<int>(m,0));

        int ans=1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                memo[i][j]=memorize(memo,arr,i,j);
                ans=max(ans,memo[i][j]);
            }
        }
        return ans;
    }
};
