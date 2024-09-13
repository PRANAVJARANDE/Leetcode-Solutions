class Solution {
public:

    int n,m;
    void mark(vector<vector<char>>&arr,int i,int j)
    {
        if(i<0 || j<0 || i>=n || j>=m || arr[i][j]=='X' || arr[i][j]=='M') return;
        arr[i][j]='M';
        mark(arr,i,j-1);
        mark(arr,i,j+1);
        mark(arr,i-1,j);
        mark(arr,i+1,j);
    }

    void solve(vector<vector<char>>& arr) 
    {
        n=arr.size();
        m=arr[0].size();
        for(int i=0;i<m;i++)
        {
            if(arr[0][i]=='O')mark(arr,0,i);
            if(arr[n-1][i]=='O')mark(arr,n-1,i);
        }

        for(int i=1;i<n-1;i++)
        {
            if(arr[i][0]=='O')mark(arr,i,0);
            if(arr[i][m-1]=='O')mark(arr,i,m-1);
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(arr[i][j]=='M')arr[i][j]='O';
                else if(arr[i][j]=='O')arr[i][j]='X';
            }
        }
        
    }
};
