class Solution {
public:
    int maxChunksToSorted(vector<int>& a) {
        int n=a.size();
        vector<int>vis(n+1,0);
        int mx=0,ans=0,in=0;
        for(int i=0;i<n;i++)
        {
            vis[a[i]]=1;
            while(vis[in]==1)in++;
            if(in>i)ans++;
        }
        return ans;
    }
};
