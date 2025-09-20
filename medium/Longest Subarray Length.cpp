class Solution {
  public:

    int longestSubarray(vector<int>& a) 
    {
        int n=a.size();
        vector<int>nmax(n,n);
        vector<int>pmax(n,-1);
        
        stack<int>s1,s2;
        for(int i=0;i<n;i++)
        {
            while(!s1.empty() && a[s1.top()]<=a[i])s1.pop();
            if(!s1.empty())pmax[i]=s1.top();
            s1.push(i);
        }
    
        for(int i=n-1;i>=0;i--)
        {
            while(!s2.empty() && a[s2.top()]<=a[i])s2.pop();
            if(!s2.empty())nmax[i]=s2.top();
            s2.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int l=pmax[i];
            int r=nmax[i];
            int sz=r-l-1;
            if(sz>=a[i])ans=max(ans,sz);
        }
        return ans;
    }
};
