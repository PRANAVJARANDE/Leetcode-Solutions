class Solution {
public:
    int matrixSum(vector<vector<int>>& arr) 
    {
        for(int i=0;i<arr.size();i++)
        {
            sort(arr[i].begin(),arr[i].end());
        }

        int s=0;
        for(int i=0;i<arr[0].size();i++)
        {
            int m=INT_MIN;
            for(int j=0;j<arr.size();j++)
            {
                m=max(m,arr[j][i]);
            }
            s=s+m;
        }
        return s;
    }
};
