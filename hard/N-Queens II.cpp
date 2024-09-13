class Solution {
public:

    bool issafe(vector<string>&arr,int x,int y)
    {
        for(int i=0;i<x;i++)
        {
            if(arr[i][y]=='Q')
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
        r=x,c=y;

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

    void place(vector<string> &arr,int x,int &ans)
    {
        int n=arr.size();
        if(x>=n)
        {
            ans++;
            return;
        }
        for(int col=0;col<n;col++)
        {
            if(issafe(arr,x,col))
            {
                arr[x][col]='Q';
                place(arr,x+1,ans);
                arr[x][col]='.';
            }
        }
    }

    int totalNQueens(int n) 
    {
        vector<string> v1(n, string(n, '.'));
        int ans=0;
        place(v1,0,ans);
        return ans;
    }
};
