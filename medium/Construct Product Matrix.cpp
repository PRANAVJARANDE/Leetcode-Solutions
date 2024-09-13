class Solution {
public:

    vector<vector<int>> constructProductMatrix(vector<vector<int>>& arr) 
    {   
            int M=12345;
            int n=arr.size();
            int m=arr[0].size();
            vector<vector<long long>>left(n,vector<long long>(m,1)),right(n,vector<long long>(m,1));
            vector<vector<int>> ans(n,vector<int>(m,1));
            long long p=1;
            for(int i=0;i<n;i++)
            {
                    for(int j=0;j<m;j++)
                    {
                        left[i][j]=p;
                        p=((p%M)*(arr[i][j]%M))%M;
                    }
            }
            p=1;
            for(int i=n-1;i>=0;i--)
            {
                for(int j=m-1;j>=0;j--)
                {
                    right[i][j]=p;
                    p=((p%M)*(arr[i][j]%M))%M;
                }
            }

            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {       
                    ans[i][j]=(left[i][j]*right[i][j])%M;
                }
            }
        return ans;
    }
};
