class Solution {
public:

bool helper(int x,int y,vector<vector<char>> &arr,vector<unordered_map<int,int>> &r,vector<unordered_map<int,int>> &c,map<pair<int,int>,unordered_map<int,int>> &m)
{
    if(x==9)
    {
        return 1;
    }
    if(y==9)
    {
        return helper(x+1,0,arr,r,c,m);
    }
    if(arr[x][y]!='.')
    {
        return helper(x,y+1,arr,r,c,m);
    }
    for(int i=1;i<=9;i++)
    {
        if(r[x][i]==0 && c[y][i]==0 && m[{x/3,y/3}][i]==0)
        {
            arr[x][y]=i+'0';
            r[x][i]=1;
            c[y][i]=1;
            m[{x/3,y/3}][i]=1;
            bool bb=helper(x,y+1,arr,r,c,m);
            if(bb==1)
            {
                return 1;
            }
            arr[x][y]='.';
            r[x][i]=0;
            c[y][i]=0;
            m[{x/3,y/3}][i]=0;
        }
    }
    return 0;
}



    void solveSudoku(vector<vector<char>>& arr) 
    {

    vector<unordered_map<int,int>> r(9);
    vector<unordered_map<int,int>> c(9);
    map<pair<int,int>,unordered_map<int,int>>m;
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(arr[i][j]!='.')
            {
                r[i][arr[i][j]-'0']=1;
                c[j][arr[i][j]-'0']=1;
                m[{i/3,j/3}][arr[i][j]-'0']=1;
            }
        }
    }
    helper(0,0,arr,r,c,m);  
    }
};
