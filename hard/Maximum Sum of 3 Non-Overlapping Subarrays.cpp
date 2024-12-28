class Solution {
public:

    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) 
    {
        int n=nums.size();
        vector<int>ps(n,0);
        int s=0;
        for(int i=n-1;i>=0;i--)
        {
            s+=nums[i];
            if(i+k<n)s-=nums[i+k];
            if(i<=n-k)ps[i]=s;
        }

        vector<int>pmaxi(n,0);
        pmaxi[n-k]=n-k;
        for(int i=n-k-1;i>=0;i--)
        {
            if(ps[pmaxi[i+1]]>ps[i])pmaxi[i]=pmaxi[i+1];
            else pmaxi[i]=i;
        }
        

        int p1=-1,p2=-1,p3=-1;
        int ans=0;
        for(int i=0;i<=n-3*k;i++)
        {
            for(int j=i+k;j<=n-2*k;j++)
            {
                int z=j+k;
                if(z<=n-k)
                {
                    int s=ps[i]+ps[j]+ps[pmaxi[z]];
                    if(s>ans)
                    {
                        ans=s;
                        p1=i;
                        p2=j;
                        p3=pmaxi[z];
                    }
                }
            }
        }
        return {p1,p2,p3};
    }
};
