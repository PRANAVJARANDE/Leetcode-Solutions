class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.size();
        vector<int>as(n,0),bs(n,0);
        for(int i=0;i<n;i++)
        {
            if(s[i]=='b')bs[i]++;
            if(i-1>=0)bs[i]+=bs[i-1];
        }
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]=='a')as[i]++;
            if(i+1<n)as[i]+=as[i+1];
        }
        int ans=n;
        for(int i=0;i<n;i++)
        {
            int res=as[i]+bs[i]-1;
            ans=min(ans,res);
        }
        return ans;
    }
};
