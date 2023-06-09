class Solution {
public:
    int minSubArrayLen(int t, vector<int>& arr) 
    {
        int n=arr.size();
        int s=0;
        int l=0;
        int r=0;
        int ans=INT_MAX;        
        while(r<n)
        {
            s=s+arr[r];
            while(s>=t)
            {
                ans=min(ans,r-l+1);
                s=s-arr[l];
                l++;
            }
            r++;
        }
        if(ans==INT_MAX)
        {
            return 0;
        }
        return ans;
    }
};
