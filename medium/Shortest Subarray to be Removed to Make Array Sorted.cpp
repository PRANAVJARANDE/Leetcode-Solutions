class Solution {
public:

    int n;
    bool check(int k,vector<int>&a,vector<vector<int>>&v1)
    {
        if(v1[k][1])return 1;
        if(v1[n-k-1][0])return 1;
        for(int i=k+1;i<n;i++)
        {
            if(v1[i][1] && v1[i-k-1][0] && a[i-k-1]<=a[i])
            {
                return 1;
            }
        }
        return 0;
    }

    int findLengthOfShortestSubarray(vector<int>& a) {
        n=a.size();

        bool b=0;
        for(int i=1;i<n;i++)
        {
            if(a[i-1]>a[i])
            {
                b=1;
                break;
            }
        }
        if(b==0)return 0;

        vector<vector<int>> v1(n,vector<int>(2,0));
        v1[0][0]=1;
        v1[n-1][1]=1;
        for(int i=1;i<n;i++)
        {
            if(a[i-1]<=a[i])
            {
                v1[i][0]=1;
            }
            else
            {
                break;
            }
        }
        for(int i=n-2;i>=0;i--)
        {
            if(a[i]<=a[i+1])
            {
                v1[i][1]=1;
            }
            else
            {
                break;
            }
        }


        int ans=n-1;
        int l=0,r=n-1;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(check(mid,a,v1))
            {
                ans=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return ans;
    }
};
