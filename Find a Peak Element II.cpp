class Solution {
public:
    int n,m;
    vector<int> findPeakGrid(vector<vector<int>>& arr) 
    {
        n=arr.size();
        m=arr[0].size();
        int i=0,j=m-1;
        while(i>=0 && i<n && j>=0 && j<m)
        {
            int op1=(i==0)?-1 : arr[i-1][j];
            int op2=(j==0)?-1 : arr[i][j-1];
            int op3=(i==n-1)? -1 : arr[i+1][j];
            int op4=(j==m-1)? -1 : arr[i][j+1];
            int maxi=max(max(op1,op2),max(op3,op4));
            if(arr[i][j]>maxi)
            {
                return {i,j};
            }
        
            if(maxi==op1)
            {
                i--;
            }
            else if(maxi==op2)
            {
                j--;
            }
            else if(maxi==op3)
            {
                i++;
            }
            else 
            {
                j++;
            }
        }
        return {-1,-1};
    }
};
