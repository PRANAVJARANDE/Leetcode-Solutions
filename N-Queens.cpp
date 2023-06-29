class Solution {
public:


    bool issafe(vector<string> &arr,int x,int y)
    {
        for(int z=0;z<x;z++)
        {
            if(arr[z][y]=='Q')
            {
                return 0;
            }
        }

        int r=x;
        int c=y;
        while(r>=0 && c>=0)
        {
            if(arr[r][c]=='Q')
            {
                return 0;
            }
            r--;
            c--;
        }
        r=x;
        c=y;
        while(r>=0 && c<arr.size())
        {
            if(arr[r][c]=='Q')
            {
                return 0;
            }
            r--;
            c++;
        }
        return 1;
    }

    void place(vector<vector<string>> &ans,vector<string> &v1,int x)
    {
        int n=v1.size();
        if(x>=n)
        {
            ans.push_back(v1);
            return;
        }
        for(int col=0;col<n;col++)
        {
            if(issafe(v1,x,col))
            {
                v1[x][col]='Q';
                place(ans,v1,x+1);
                v1[x][col]='.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) 
    {
        int x=0;
        vector<vector<string>> ans;
        vector<string> v1(n, string(n, '.'));
        place(ans,v1,x);
        return ans;
    }
};
