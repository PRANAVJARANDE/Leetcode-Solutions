class Solution {
  public:
    int maxWater(vector<int> &a) 
    {
        int n=a.size();
        int mx=10002;
        vector<int>f1(mx,n);
        vector<int>f2(mx,-1);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            f1[a[i]]=min(f1[a[i]],i);
            f2[a[i]]=max(f2[a[i]],i);
        }
        
        for(int i=0;i<mx;i++)
        {
            if(f2[i]==-1)continue;
            for(int j=0;j<mx;j++)
            {
                if(f2[j]==-1)continue;
                int d1=abs(f1[i]-f2[j]);
                int d2=abs(f2[i]-f1[j]);
                ans=max(ans,(int)min(i,j)*max(d1,d2));
            }
        }
        return ans;
    }
};
