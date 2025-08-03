class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& a, int st, int k) 
    {
        int n=a.size();
        int l=0,s=0,ans=0;
        for(int i=0;i<n;i++) 
        {
            s+=a[i][1];
            while(l<=i) 
            {
                int lp=a[l][0],rp=a[i][0];
                int dist=min(abs(st-lp)+(rp-lp),abs(st - rp)+(rp-lp));
                if(dist<=k)break;
                s-=a[l][1];
                l++;
            }
            ans=max(ans,s);
        }
        return ans;
    }
};
