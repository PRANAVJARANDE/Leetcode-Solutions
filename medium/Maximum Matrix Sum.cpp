class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& a) {
        int n=a.size();
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(a[i][j-1]<0)
                {
                    a[i][j-1]=-a[i][j-1];
                    a[i][j]=-a[i][j];
                }
            }
        }
        for(int j=1;j<n;j++)
        {
            if(a[j-1][n-1]<0)
            {
                a[j-1][n-1]=-a[j-1][n-1];
                a[j][n-1]=-a[j][n-1];
            }
        }

        long long s=0;
        int mini=INT_MAX;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<a[i][j]<<" ";
                s+=a[i][j];
                mini=min(mini,abs(a[i][j]));
            }
            cout<<endl;
        }
        if(a[n-1][n-1]>=0)return s;
        long long ans=s;
        s+=2*abs(a[n-1][n-1])-2*mini;
        ans=max(ans,s);
        return ans;

    }
};
