class Solution {
public:
    bool checkMove(vector<vector<char>>& arr, int r, int c, char color) 
    {
        int n=arr.size();
        int m=arr[0].size();

        vector<int>dx{-1,-1,-1,0,1,1,1,0};
        vector<int>dy{-1,0,1,1,1,0,-1,-1};

        char ch;
        if(color=='B')
        {
            ch='W';
        }
        else
        {
            ch='B';
        }
 
        for(int k=0;k<8;k++)
        {
            int i=r+dx[k];
            int j=c+dy[k];
            int d=1;
            while(i>=0 && j>=0 && i<n && j<m && arr[i][j]!='.')
            {
                if(color==arr[i][j] && d>=2)
                {
                    return 1;
                }
                else if(arr[i][j]!=ch)
                {
                    break;
                }
                d++;
                i+=dx[k];
                j+=dy[k];

            }
        }
        return 0;
        
    }
};
