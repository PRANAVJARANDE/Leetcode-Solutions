class Solution {
public:
    int countDays(int days, vector<vector<int>>& a) 
    {
        sort(a.begin(),a.end());
        int ans=a[0][0]-1;
        int n=a.size();
        int maxi=a[0][1];
        for(int i=1;i<n;i++)
        {
            int diff=max(0,a[i][0]-maxi-1);
            maxi=max(maxi,a[i][1]);
            ans+=diff;
        }
        ans+=days-maxi;
        return ans;

    }
};
