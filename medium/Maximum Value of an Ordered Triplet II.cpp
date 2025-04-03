class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int>nmax(n,0);
        int maxi=0;
        for(int i=n-1;i>=0;i--)
        {
            nmax[i]=maxi;
            maxi=max(maxi,nums[i]);
        }
        vector<int>pmax(n,0);
        maxi=0;
        for(int i=0;i<n;i++)
        {
            pmax[i]=maxi;
            maxi=max(maxi,nums[i]);
        }

        long long ans=0;
        for(int i=0;i<n;i++)
        {
            long long res=(long long)((long long)pmax[i]-nums[i])*nmax[i];
            ans=max(ans,res);
        }
        return ans;
    }
};
