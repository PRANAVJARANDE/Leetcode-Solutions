class Solution {
public:
    int maxDistance(vector<vector<int>>& a) {
        int n=a.size();
        vector<int> nmax(n,0),nmin(n,0),pmax(n,0),pmin(n,0);
        int maxi=INT_MIN,mini=INT_MAX;
        for(int i=0;i<n;i++)
        {
            pmax[i]=maxi;
            pmin[i]=mini;
            maxi=max(maxi,a[i][a[i].size()-1]);
            mini=min(mini,a[i][0]);
        }
        maxi=INT_MIN,mini=INT_MAX;
        for(int i=n-1;i>=0;i--)
        {
            nmax[i]=maxi;
            nmin[i]=mini;
            maxi=max(maxi,a[i][a[i].size()-1]);
            mini=min(mini,a[i][0]);
        }
        int ans=INT_MIN;
        for(int i=0;i<n;i++)
        {
            int p1=max(pmax[i],nmax[i]);
            int p2=min(pmin[i],nmin[i]);
            int r1=max(abs(a[i][a[i].size()-1]-p1),abs(a[i][a[i].size()-1]-p2));
            int r2=max(abs(a[i][0]-p1),abs(a[i][0]-p2));
            ans=max(ans,max(r1,r2));
        }
        return ans;

    }
};
