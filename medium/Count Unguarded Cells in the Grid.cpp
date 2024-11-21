class Solution {
public:
    int countUnguarded(int n, int m, vector<vector<int>>& g, vector<vector<int>>& w) {
        vector<vector<char>> a(n,vector<char>(m,'0'));
        for(auto x:g)a[x[0]][x[1]]='G';
        for(auto x:w)a[x[0]][x[1]]='W';
        
        for(int i=0;i<n;i++)
        {
            bool b=0;
            for(int j=0;j<m;j++)
            {
                if(a[i][j]=='W')b=0;
                else if(a[i][j]=='G')b=1;
                else{
                    if(b)a[i][j]='X';
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            bool b=0;
            for(int j=m-1;j>=0;j--)
            {
                if(a[i][j]=='W')b=0;
                else if(a[i][j]=='G')b=1;
                else{
                    if(b)a[i][j]='X';
                }
            }
        }
        
        for(int j=0;j<m;j++)
        {
            bool b=0;
            for(int i=n-1;i>=0;i--)
            {
                if(a[i][j]=='W')b=0;
                else if(a[i][j]=='G')b=1;
                else{
                    if(b)a[i][j]='X';
                }
            }
        }

        for(int j=0;j<m;j++)
        {
            bool b=0;
            for(int i=0;i<n;i++)
            {
                if(a[i][j]=='W')b=0;
                else if(a[i][j]=='G')b=1;
                else{
                    if(b)a[i][j]='X';
                }
            }
        }

        
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cout<<a[i][j]<<" ";
                if(a[i][j]=='0')ans++;
            }
            cout<<endl;
        }
        return ans;

    }
};
