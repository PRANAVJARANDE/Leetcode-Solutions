class Solution {
public:
    vector<int> xorQueries(vector<int>& a, vector<vector<int>>& q) {
        int n=a.size();
        vector<int>psum(n,0);
        for(int i=0;i<n;i++)
        {
            psum[i]=a[i];
            if(i-1>=0)psum[i]^=psum[i-1];
        }
        int qs=q.size();
        vector<int>ans(qs,0);
        for(int i=0;i<qs;i++)
        {
            int l=q[i][0];
            int r=q[i][1];
            int res=psum[r];
            if(l-1>=0)res^=psum[l-1];
            ans[i]=res;
        }
        return ans;
    }
};
