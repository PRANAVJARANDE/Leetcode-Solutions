class Solution {
public:
    int n,m;
    bool helper(vector<vector<char>>&arr,int i,int j,string s,int in)
    {
        if(in>=s.size())
        {
            return 1;
        }
        if(i<0 || j<0 || i>=m || j>=n || arr[i][j]=='#' || s[in]!=arr[i][j])
        {
            return 0;
        }
        char ch=arr[i][j];
        arr[i][j]='#';
        bool b1=helper(arr,i+1,j,s,in+1);
        bool b2=helper(arr,i-1,j,s,in+1);
        bool b3=helper(arr,i,j+1,s,in+1);
        bool b4=helper(arr,i,j-1,s,in+1);
        arr[i][j]=ch;
        return b1 || b2 || b3 || b4;
    }


    bool exist(vector<vector<char>>& board, string s) 
    {
        m=board.size();
        n=board[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(helper(board,i,j,s,0))
                {
                    return 1;
                }
            }
        }
        return 0;
    }
};
