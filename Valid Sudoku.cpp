class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& arr) {
    vector<map<int,int>> r(9);
    vector<map<int,int>> c(9);
    map<pair<int,int>,map<int,int>>m;
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(arr[i][j]!='.')
            {
                r[i][arr[i][j]-'0']++;
                if(r[i][arr[i][j]-'0']==2)
                {
                    return 0;
                }
                c[j][arr[i][j]-'0']++;
                if(c[j][arr[i][j]-'0']==2)
                {
                    return 0;
                }
                m[{i/3,j/3}][arr[i][j]-'0']++;
                if(m[{i/3,j/3}][arr[i][j]-'0']==2)
                {
                    return 0;
                }
            }
        }
    }
    return 1;
    }
};
