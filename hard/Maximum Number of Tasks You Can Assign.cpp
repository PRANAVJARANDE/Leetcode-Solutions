class Solution {
public:

    bool check(int mid,int p,int s,vector<int>&t,vector<int>&w)
    {
        multiset<int>v1(w.begin(),w.end());
        for(int i=mid-1;i>=0;i--)
        {
            int task=t[i];
            int maxi=*v1.rbegin();
            if(maxi>=task)
            {
                v1.erase(v1.find(maxi));
            }
            else if(p==0)
            {
                return 0;
            }
            else
            {
                int req=task-s;
                auto in=v1.lower_bound(req);
                if(in==v1.end())return 0;
                p--;
                v1.erase(v1.find(*in));
            }
        }
        return 1;
    }

    int maxTaskAssign(vector<int>& t, vector<int>& w, int p, int s) 
    {
        int n=t.size(),m=w.size();
        int ans=0;
        int l=1,r=min(n,m);
        sort(t.begin(),t.end());
        
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(check(mid,p,s,t,w))
            {
                ans=mid;
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        return ans;
    }
};
