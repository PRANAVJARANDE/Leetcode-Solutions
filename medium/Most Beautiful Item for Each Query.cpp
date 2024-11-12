class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& a, vector<int>& q) {
        sort(a.begin(),a.end());
        int n=a.size();
        for(int i=1;i<n;i++)
        {
            a[i][1]=max(a[i][1],a[i-1][1]);
        }
        int qs=q.size();
        vector<int> res(qs,0);
        for(int i=0;i<qs;i++)
        {
            int qr=q[i];
            int l=0,r=n-1;
            int ans=0;
            while(l<=r)
            {
                int mid=l+(r-l)/2;
                if(qr>=a[mid][0])
                {
                    ans=a[mid][1];
                    l=mid+1;
                }
                else
                {
                    r=mid-1;
                }
            }
            res[i]=ans;
        }
        return res;




    }
};
