class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& arr) 
    {
        int m=arr.size(),n=arr[0].size();
        vector<int>orr(m,0),oc(n,0);
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(arr[i][j]==1)
                {
                    orr[i]++;
                    oc[j]++;
                }
            }
        }
        
        vector<vector<int>>diff(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                diff[i][j]=2*(orr[i]+oc[j])-n-m;
            }
        }
        return diff;
    }
};
