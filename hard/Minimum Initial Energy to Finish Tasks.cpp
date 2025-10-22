class Solution {
public:

    static bool cmp(vector<int>&a,vector<int>&b)
    {
        int l1=a[1]-a[0];
        int l2=b[1]-b[0];
        return l1>l2;
    }

    bool check(int mid,vector<vector<int>>&a)
    {
        int h=mid;
        for(auto x:a)
        {
            if(h>=x[1])h-=x[0];
            else return 0;
        }
        return 1;
    }

    int minimumEffort(vector<vector<int>>& a) 
    {
        sort(a.begin(),a.end(),cmp);
        for(auto x:a)cout<<x[0]<<" "<<x[1]<<endl;
        int l=a[0][1],r=1e9;
        int ans=1e9;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(check(mid,a))
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
