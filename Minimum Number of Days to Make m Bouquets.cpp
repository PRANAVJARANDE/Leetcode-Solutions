class Solution {
public:

    int n;
    bool checker(vector<int>& a, int m, int k,int mid)
    {
        int cnt=0;
        int i=0;
        while(i<n)
        {   
            int curr=0;
            while(i<n && curr<k && a[i]<=mid)
            {
                curr++;
                i++;
            }
            if(curr==k)
            {
                cnt++;
                if(cnt==m)return 1;
            }
            else
            {
                i++;
            }
        }
        return 0;
    }

    int minDays(vector<int>& a, int m, int k) {
        n=a.size();
        if((long long)m*k>n)return -1;
        int r=INT_MIN,l=INT_MAX;
        for(int x:a)
        {
            r=max(r,x);
            l=min(l,x);
        }
        int ans=r;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(checker(a,m,k,mid))
            {
                ans=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return ans;
    }
};
