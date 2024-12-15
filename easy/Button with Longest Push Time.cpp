class Solution {
public:
    int buttonWithLongestTime(vector<vector<int>>& a) {
        int n=a.size();
        int maxi=-1;
        int ans=-1;
        for(int i=0;i<n;i++)
        {
            int tm=a[i][1];
            if(i-1>=0)tm-=a[i-1][1];
            if(tm>maxi)
            {
                maxi=tm;
                ans=a[i][0];
            }
            if(tm==maxi)
            {
                ans=min(ans,a[i][0]);
            }
        }
        return ans;
    }
};
