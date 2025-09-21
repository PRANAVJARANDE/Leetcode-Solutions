class Solution {
  public:
    
    int helper(vector<int>&a)
    {
        int n=a.size();
        vector<int>nmin(n,n);
        vector<int>pmin(n,-1);
        stack<int>s1,s2;
        for(int i=0;i<n;i++)
        {
            while(!s1.empty() && a[s1.top()]>=a[i])s1.pop();
            if(!s1.empty())pmin[i]=s1.top();
            s1.push(i);
        }
        for(int i=n-1;i>=0;i--)
        {
            while(!s2.empty() && a[s2.top()]>=a[i])s2.pop();
            if(!s2.empty())nmin[i]=s2.top();
            s2.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int w=nmin[i]-pmin[i]-1;
            ans=max(ans,w*a[i]);
        }
        return ans;
    }
    
  
    int maxArea(vector<vector<int>>&a) 
    {
        int n=a.size(),m=a[0].size();
        for(int j=0;j<m;j++)
        {
            int cnt=0;
            for(int i=0;i<n;i++)
            {
                if(a[i][j]==0)cnt=0;
                else cnt++;
                a[i][j]=cnt;
            }
        }
        
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans=max(ans,helper(a[i]));
        }
        return ans;
    }
};
