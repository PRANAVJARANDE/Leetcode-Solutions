class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& a) {
        int n=a.size();
        int m=a[0].size();
        vector<vector<char>> ans(m,vector<char>(n,'0'));
        for(int i=0;i<n;i++)
        {
            int cnt=0;
            for(int j=0;j<m;j++)
            {
                if(a[i][j]=='#')
                {
                    a[i][j]='.';
                    cnt++;
                }
                else if(a[i][j]=='*')
                {
                    int in=j-1;
                    while(cnt-- && in>=0)
                    {
                        a[i][in]='#';
                        in--;
                    }
                    cnt=0;
                }
            }
            int in=m-1;
            while(cnt-- && in>=0)
            {
                a[i][in]='#';
                in--;
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cout<<a[i][j]<<" ";
                ans[j][n-i-1]=a[i][j];
            }
            cout<<endl;
        }
        return ans;



    }
};
