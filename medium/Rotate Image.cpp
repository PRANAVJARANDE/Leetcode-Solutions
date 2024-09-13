class Solution {
public:
    void rotate(vector<vector<int>>& arr) 
    {
        int n=arr.size();

        vector<vector<int>> temp(n, vector<int> (n,0));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                temp[j][n-i-1]=arr[i][j];
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                arr[i][j]=temp[i][j];
            }
        }
    }
};
