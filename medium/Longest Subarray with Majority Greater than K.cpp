class Solution {
  public:
  
    int longestSubarray(vector<int> &a, int k) 
    {
        int n=a.size();
        int s=0;
        int ans=0;
        map<int,int>m;
        for(int i=0;i<n;i++)
        {
            if(a[i]>k)s++;
            else s--;
            if(s>0)ans=max(ans,i+1);
            else if(m.find(s-1)!=m.end())ans=max(ans,i-m[s-1]);
            if(m.find(s)==m.end())m[s]=i;
        }
        return ans;
    }
};
