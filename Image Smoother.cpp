class Solution {
public:

    bool isval(int i,int j,int n,int m)
    {
        if(i<n && j<m && i>=0 && j>=0)return 1;
        return 0;
    }
    vector<vector<int>> imageSmoother(vector<vector<int>>& arr) 
    {
        int n=arr.size(),m=arr[0].size();
        vector<vector<int>>ans(n,vector<int>(m,0));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                vector<int> x{-1,-1,-1,0,0,1,1,1,0};
                vector<int> y{-1,0,1,1,-1,-1,0,1,0};
                int k=0;
                int s=0;
                for(int z=0;z<9;z++)
                {
                    if(isval(i+x[z],j+y[z],n,m))
                    {
                        k++;
                        s+=arr[i+x[z]][j+y[z]];
                    }
                }
                ans[i][j]=s/k;
            }
        }
        return ans;

        
    }
};
