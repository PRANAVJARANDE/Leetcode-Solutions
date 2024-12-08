class Solution {
public:

    int n;
    int bs(int e,vector<vector<int>>&a,vector<int>&maxi)
    {
        int l=0,r=n-1;
        int ans=INT_MIN;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(a[mid][0]>=e)
            {
                ans=maxi[mid];
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return ans;

    }

    int maxTwoEvents(vector<vector<int>>& a) {
        sort(a.begin(),a.end());
        n=a.size();
        vector<int> maxi(n,0);
        int ans=INT_MIN;
        for(int i=n-1;i>=0;i--)
        {
            ans=max(ans,a[i][2]);
            maxi[i]=max(maxi[i],a[i][2]);
            if(i+1<n)maxi[i]=max(maxi[i],maxi[i+1]);
        }
        
        for(int i=0;i<n;i++)
        {
            int ta=a[i][2];
            int en=a[i][1]+1;
            ta+=bs(en,a,maxi);
            ans=max(ans,ta);
        }
        return ans;
    }
};
