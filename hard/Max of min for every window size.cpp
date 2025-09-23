class Solution {
  public:
    vector<int> maxOfMins(vector<int>& a) 
    {
        int n=a.size();
        vector<int>nmax(n,n),pmax(n,-1);
        stack<int>s1,s2;
        for(int i=0;i<n;i++)
        {
            while(!s1.empty() && a[s1.top()]>=a[i])s1.pop();
            if(!s1.empty())pmax[i]=s1.top();
            s1.push(i);
        }
        for(int i=n-1;i>=0;i--)
        {
            while(!s2.empty() && a[s2.top()]>=a[i])s2.pop();
            if(!s2.empty())nmax[i]=s2.top();
            s2.push(i);
        }
        vector<int>ans(n,0);
        for(int i=0;i<n;i++)
        {
            int dis=nmax[i]-pmax[i]-1;
            ans[dis-1]=max(ans[dis-1],a[i]);
        }
        for(int i=n-1;i>=0;i--)
        {
            if(i+1<n)ans[i]=max(ans[i],ans[i+1]);
        }
        return ans;
    }
};
