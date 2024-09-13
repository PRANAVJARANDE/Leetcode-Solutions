class Solution {
public:
    vector<vector<int>> generateMatrix(int n) 
    {
        int rs=0;
        int cs=0;
        int re=n-1;
        int ce=n-1;

        int arr[n][n];

        int k=1;
        while(rs<=re && cs<=ce)
        {
            for(int i=cs;i<=ce;i++)
            {
                arr[rs][i]=k;
                k++;
            }
            rs++;

            for(int i=rs;i<=re;i++)
            {
                arr[i][ce]=k;
                k++;
            }
            ce--;

            for(int i=ce;i>=cs;i--)
            {
                arr[re][i]=k;
                k++;
            }
            re--;

            for(int i=re;i>=rs;i--)
            {
                arr[i][cs]=k;
                k++;
            }
            cs++;
        }

        vector<vector<int>> v1;

        for(int i=0;i<n;i++)
        {
            vector<int> v2;
            for(int j=0;j<n;j++)
            {
                v2.push_back(arr[i][j]);
            }
            v1.push_back(v2);

        }


        return v1;


    }
};
