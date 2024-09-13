class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& arr) 
    {
        int n=arr.size();
        vector<vector<int>>ans(n-2,vector<int>(n-2,0));

        for(int i=1;i<n-1;i++)
        {
            for(int j=1;j<n-1;j++)
            {
                for(int k=i-1;k<=i+1;k++)
                {
                    for(int z=j-1;z<=j+1;z++)
                    {
                        ans[i-1][j-1]=max(ans[i-1][j-1],arr[k][z]);
                    }
                }
            }
        }
        return ans;
    }
};
