class Solution {
public:
    vector<int> avoidFlood(vector<int>& a) 
    {
        int n=a.size();
        vector<int>ans(n,-1);
        map<int,int>m;
        set<int>s1;
        for(int i=0;i<n;i++)
        {
            if(a[i]==0)s1.insert(i);
            else
            {
                if(m.find(a[i])==m.end())m[a[i]]=i;
                else
                {
                    // repetition occurred
                    auto in=s1.lower_bound(m[a[i]]);
                    if(in==s1.end())return {};
                    else
                    {
                        ans[*in]=a[i];
                        s1.erase(in);
                    }
                    m[a[i]]=i;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            if(a[i]==0 && ans[i]==-1)ans[i]=1;
        }
        return ans;
    }
};
