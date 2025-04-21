class Solution {
public:
    int numberOfArrays(vector<int>& d, int lower, int upper) 
    {
        long long n=d.size();
        long long mini=0,maxi=0;
        long long r=0;
        for(int i=0;i<n;i++)
        {
            long long nr=r+d[i];
            maxi=max(maxi,nr);
            mini=min(mini,nr);
            r=nr;
        }
        long long sz=maxi-mini+1;
        long long msz=upper-lower+1;
        long long ans=max(0ll,msz-sz+1);
        return ans;
    }
};
