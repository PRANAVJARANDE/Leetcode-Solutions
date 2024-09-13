class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int t) 
    {
        int rs=arr.size();
        int cs=arr[0].size();
        int i=0;
        int j=cs-1;

        while(j>=0 && i<rs)
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
