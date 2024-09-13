class Solution {
public:

    int gett(int k,vector<vector<int>>&v1)
    {
        int l=0,r=v1.size()-1;
        int ans=-1;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(v1[mid][0]>k)
            {
                r=mid-1;
            }
            else
            {
                ans=mid;
                l=mid+1;
            }
        }
        if(ans==-1)return 0;
        return v1[ans][1];
    }



    int maxProfitAssignment(vector<int>& d, vector<int>& p, vector<int>& w) {
        vector<vector<int>> v1;
        int n=d.size();
        for(int i=0;i<n;i++)
        {
            v1.push_back({d[i],p[i]});
        }
        sort(v1.begin(),v1.end());
        for(int i=1;i<n;i++)
        {
            v1[i][1]=max(v1[i][1],v1[i-1][1]);
        }
        int ans=0;
        for(int x: w)
        {
            cout<<gett(x,v1)<<" ";
            ans+=gett(x,v1);
        }
        return ans;
    }
};
