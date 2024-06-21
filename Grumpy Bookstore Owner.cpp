class Solution {
public:
    int maxSatisfied(vector<int>&c,vector<int>&g,int k){
        int n=c.size();
        vector<int> psum(n,0);
        int ans=0;
        if(g[0]==1)psum[0]=c[0];
        else ans=c[0];
        
        for(int i=1;i<n;i++)
        {
            psum[i]=psum[i-1];
            if(g[i]==1)psum[i]+=c[i];
            else ans+=c[i];
        }
        int ta=psum[k-1];
        for(int i=k;i<n;i++)
        {
            ta=max(ta,psum[i]-psum[i-k]);
        }
        return ans+ta;
    }
};
