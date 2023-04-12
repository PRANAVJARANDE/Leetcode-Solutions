class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int t) 
    {
        int r=arr.size();
        int c=arr[0].size();

        int i=0;
        int j=c-1;

        while(i<r && j>=0)
        {
            if(arr[i][j]==t)
            {
                return 1;
            }
            else if(arr[i][j]>t)
            {
                j--;
            }
            else
            {
                i++;
            }
        }
        return 0;
        
    }
};
