class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& q) 
    {
        set<int>tot;
        map<int,vector<int>>m1,m2;

        for(auto x:intervals)
        {
            int sz=x[1]-x[0]+1;
            tot.insert(x[0]);
            tot.insert(x[1]);
            m1[x[0]].push_back(sz);
            m2[x[1]].push_back(sz);
        }

        for(auto x:q)tot.insert(x);

        map<int,int>dp;
        multiset<int>s1;
        for(auto i:tot)
        {
            for(auto x:m1[i])s1.insert(x);
            if(!s1.empty())dp[i]=*s1.begin();
            else dp[i]=-1;
            for(auto x:m2[i])s1.erase(s1.find(x));
        }

        int qs=q.size();
        vector<int>ans(qs,-1);
        for(int i=0;i<qs;i++)
        {
            ans[i]=dp[q[i]];
        }
        return ans;
    }
};
