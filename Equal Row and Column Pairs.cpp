class Solution {
public:
    int equalPairs(vector<vector<int>>& arr) 
    {
        int n=arr.size();
        vector<vector<int>> v1(n,vector<int>(n,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                v1[i][j]=arr[j][i];
            }
        }
        int k=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(arr[i]==v1[j])
                {
                    k++;
                }
            }
        }
        return k;
    }
};
